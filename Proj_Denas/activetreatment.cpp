/*#include "activetreatment.h"
#include "ui_activetreatment.h"
#include <QTimer>

ActiveTreatment::ActiveTreatment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActiveTreatment)
{
    ui->setupUi(this);
    ui->therapyTime->display(0);
    ui->skinTouch->setText("Touch Here");
    is_therapy = false;

     timer = new QTimer(this);
     timer->setInterval(1000);

     connect(timer, &QTimer::timeout, this, &ActiveTreatment::onTimeOut);
}

void ActiveTreatment::onTimeOut(){
    int value = ui->therapyTime->value();

    value += 1;
    ui->therapyTime->display(value);
}

ActiveTreatment::~ActiveTreatment()
{
    delete ui;
}

void ActiveTreatment::on_skinTouch_clicked()
{
    if(is_therapy == false){
        ui->skinTouch->setText("Stop Therapy");
        is_therapy = true;
        timer->start();
    } else {
        ui->skinTouch->setText("Touch Here");
        is_therapy = false;
        timer->stop();
    }
}
*/
#include "mainwindow.h"
#include "activetreatment.h"
#include "ui_activetreatment.h"
#include <QTimer>

ActiveTreatment::ActiveTreatment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActiveTreatment)
{
    ui->setupUi(this);
    ui->therapyTime->display(0);
    ui->skinTouch->setText("Touch Here");
    is_therapy = false;
//    current_frequency = ((MainWindow *) parent)->frequency;
     ui->freq_label->setText(current_frequency);
     timer = new QTimer(this);
     timer->setInterval(1000);

     connect(timer, &QTimer::timeout, this, &ActiveTreatment::onTimeOut);
}

void ActiveTreatment::onTimeOut(){
    int value = ui->therapyTime->value();

    value += 1;
    ui->therapyTime->display(value);
}

ActiveTreatment::~ActiveTreatment()
{
    delete ui;
}

void ActiveTreatment::on_skinTouch_clicked()
{
    if(is_therapy == false){
        ui->skinTouch->setText("Stop Therapy");
        is_therapy = true;
        timer->start();
    } else {
        ui->skinTouch->setText("Touch Here");
        is_therapy = false;
        timer->stop();
    }
}

void ActiveTreatment::setData(const QString &labelText) {
  ui->freq_label->setText(labelText);
}
