#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <time.h>
#include "activetreatment.h"
//#include "program.h"

#include <QTimer>
#include <QMessageBox>
#include <QDebug>
#include <QLabel>
#include <QList>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    powerLev = 0;
    on = true;
    ui->setupUi(this);
    ui->list->setCurrentRow(0);
    mode = 1;
    segueLevel = 1; //is the menu id allowing for quick segues to prvious menu.

    QPixmap pix(":/resources/img/pwrOn.png");

    QPixmap up(":/resources/img/up.png");
    QPixmap down(":/resources/img/down.png");
    QPixmap left(":/resources/img/left.png");
    QPixmap right(":/resources/img/right.png");

    QPixmap menu(":/resources/img/menu.png");
    QPixmap back(":/resources/img/back.png");

    QIcon pow(pix);
    ui->power->setIcon(pow);
    ui->power->setIconSize(QSize(110,110));

    QIcon upIcon(up);
    ui->up->setIcon(upIcon);
    ui->up->setIconSize(QSize(60,60));

    QIcon downIcon(down);
    ui->down->setIcon(downIcon);
    ui->down->setIconSize(QSize(60,60));

    QIcon leftIcon(left);
    ui->left->setIcon(leftIcon);
    ui->left->setIconSize(QSize(60,60));

    QIcon rightIcon(right);
    ui->right->setIcon(rightIcon);
    ui->right->setIconSize(QSize(60,60));

    QIcon menuIcon(menu);
    ui->mainMenu->setIcon(menuIcon);
    ui->mainMenu->setIconSize(QSize(40,40));

    QIcon backIcon(back);
    ui->back->setIcon(backIcon);
    ui->back->setIconSize(QSize(60,60));

    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(100);
    ui->battery->display(100);

    timer = new QTimer(this);
    timer->setInterval(5000);

    connect(timer, &QTimer::timeout, this, &MainWindow::onTimeOut);
    timer->start();
    //timer->setSingleShot(true);


}

void MainWindow::onTimeOut(){
    int value = ui->progressBar->value();
    if (value <= 0){
        return;
    }
    value -= 1;
    if (value < 10){QMessageBox::about(this, "Battery low", "Please plug in charger!");}
    ui->battery->display(value);
    ui->progressBar->setValue(value);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::mainMenu(int n){

    switch (n) {
        case 0:{


            //  programs
        Program *allergy = new Program("Allergy",0.1,2);
        Program *hypertension = new Program("Hypertension",0.1,2);
        Program *bloating = new Program("Bloating",0.1,2);
        Program *throat = new Program("Throat",0.1,2);
        Program *pain = new Program("Pain",0.1,2);
        Program *severePain = new Program("Severe Pain",0.1,2);
        Program *gynaecology = new Program("Gynaecology",0.1,2);
        Program *head = new Program("Head",0.1,2);
        Program *muscles = new Program("Muscles",0.1,2);
        Program *constipation = new Program("Constipation",0.1,2);
        Program *kidneys = new Program("Kidneys",0.1,2);
        Program *joints = new Program("Joints",0.1,2);
        Program *nausea = new Program("Nausea",0.1,2);
        Program *asthma = new Program("Asthma",0.1,2);
        Program *back = new Program("Back",0.1,2);
        Program *cold = new Program("Cold",0.1,2);
        Program *cough = new Program("Cough",0.1,2);
        Program *diarrhea = new Program("Diarrhea",0.1,2);
        Program *hypotonia = new Program("Hypotonia",0.1,2);

       progVector = {allergy,hypertension,bloating,throat,pain,severePain
            ,gynaecology,head,muscles,constipation,kidneys,joints
            ,nausea,asthma,back ,cold,cough ,diarrhea,hypotonia};

            ui->list->clear();

            for (int i = 0;i < progVector.count();i++){
                ui->list->addItem(progVector[i]->getName());
            }
            segueLevel = 2;
            break;
        }

        case 1:{
            //Frequency select
            QStringList fr_Menu = {"1.0 - 9.9Hz", "10Hz","20Hz","60Hz", "77Hz",
                              "140Hz","200Hz", "<<77 10>>","<<77 AM>>"};

            displayContents(fr_Menu);
            //current_list = 3;
            segueLevel = 3;
            break;
        }
        case 2:{
            //med

            break;
        }
        case 3:{
            //baby doctor
            break;
        }
        case 4:{
            //children

        QStringList children_Menu = {"Disable", "Up to 1 Year", "1-3 Years", "4-7 Years", "7-12 Years"};
        displayContents(children_Menu);
        segueLevel = -1;

            break;
        }
        case 5:{
            //settings

        QStringList settings_Menu  = {"Sound", "Brightness","Economy","Storage of last settings", "Time",
                              "Alarm Clock"};
            displayContents(settings_Menu);
            segueLevel = 6;
            break;
        }
    }
    return 0;
}

void MainWindow::on_power_clicked()//event of pressing power button
{

    QPixmap turnOff(":/resources/img/pwrOff.png");
    QPixmap turnOn(":/resources/img/pwrOn.png");

    if (on == true){
        QIcon pow(turnOff);
        ui->power->setIcon(pow);
        ui->power->setIconSize(QSize(110,110));
        ui->frequency_label->setText("");
        //current_list = 0;
        on = false;
        ui->list->clear();
        timer->stop();
    }else{
       deviceOn();
    }
}

void MainWindow::deviceOn(){//all events ehrn turned on
    QPixmap turnOn(":/resources/img/pwrOn.png");

    QIcon pow(turnOn);
    ui->power->setIcon(pow);
    ui->power->setIconSize(QSize(110,110));
    ui->frequency_label->setText(frequency);
    on = true;
    loadMainMenu();
    timer->start();
}

void MainWindow::loadMainMenu(){
    ui->list->addItem("Program");
    ui->list->addItem("Frequency");
    ui->list->addItem("Med");
    ui->list->addItem("Baby Doctor");
    ui->list->addItem("Children");
    ui->list->addItem("Settings");
    ui->list->setCurrentRow(0);
    segueLevel = 1;
}

void MainWindow::on_up_clicked()
{
    int i = ui->list->currentRow();
    if(ui->list->currentRow() > 0){
        ui->list->setCurrentRow(i-1);
    }
}

void MainWindow::on_down_clicked()
{
    int i = ui->list->currentRow();
    if(ui->list->currentRow() < ui->list->count()){
        ui->list->setCurrentRow(i+1);
    }
}

void MainWindow::on_pushButton_clicked()
{
    if (segueLevel == 1){
        int n = ui->list->currentRow();
        /*
        if(current_list == 3){
            frequency = fr[n];
            ui->frequency_label->setText(frequency);
        } else {
               mainMenu(n);
        } */
        mainMenu(n);

    } else if(segueLevel == 2){
        //display treatment
            ActiveTreatment a;
            a.setModal(true);
            a.exec();

    } else if(segueLevel == 3){
        //set frequency
        int row = ui->list->currentRow();
        frequency = fr[row];
        ui->frequency_label->setText(frequency);

    } else if(segueLevel == 6){
        //in settings menu
        switch (ui->list->currentRow())
        {

        case 0:
        {
            //sound
            QStringList subset = {"General", "Contact", "Buttons"};
            displayContents(subset);
            segueLevel = -1;
            break;
        }
        case 1: //Brightness
        {break;}

        case 2: //Economy
        {break;}

        case 3: //Storage Of Last Settings
        {break;}

        case 4: //Time
        {break;}

        case 5: //Alarm Clock
        {
            QStringList subset = {"OFF", "Repeat", "Daily"};
            displayContents(subset);
            segueLevel = -1;
            break;
        }
      }

    } else if (segueLevel == -1){
        return;
    }
}
void MainWindow::displayContents(QStringList options)
{
    ui->list->clear();
    for(int i = 0; i < options.length(); i++){
        ui->list->addItem(options[i]);
    }
    (ui->list->setCurrentRow(0));
}

void MainWindow::on_mainMenu_clicked()
{
    ui->list->clear();
    loadMainMenu();
    segueLevel = 1;
}

void MainWindow::on_right_clicked()
{
    if (powerLev <= 4){
        powerLev += 1;
        ui->powerLevel->display(powerLev);
    }
}

void MainWindow::on_left_clicked()
{
    if (powerLev >= 1){
        powerLev -= 1;
        ui->powerLevel->display(powerLev);
    }
}
void MainWindow::on_back_clicked()
{
    ui->list->clear();
    loadMainMenu();
    segueLevel = 1;
}
