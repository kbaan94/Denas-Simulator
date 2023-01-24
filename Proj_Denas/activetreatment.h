/*#ifndef ACTIVETREATMENT_H
#define ACTIVETREATMENT_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class ActiveTreatment;
}

class ActiveTreatment : public QDialog
{
    Q_OBJECT

public:
    explicit ActiveTreatment(QWidget *parent = nullptr);
    ~ActiveTreatment();
    void onTimeOut();

private slots:
    void on_skinTouch_clicked();

private:
    Ui::ActiveTreatment *ui;
    QPushButton skinTouch;
    QTimer *timer;
    bool is_therapy;
};

#endif // ACTIVETREATMENT_H
*/
#ifndef ACTIVETREATMENT_H
#define ACTIVETREATMENT_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class ActiveTreatment;
}

class ActiveTreatment : public QDialog
{
    Q_OBJECT

public:
    explicit ActiveTreatment(QWidget *parent = nullptr);
    ~ActiveTreatment();
    void onTimeOut();
    QString current_frequency = "0.1Hz";
    void setData(const QString &labelText);

private slots:
    void on_skinTouch_clicked();

private:
    Ui::ActiveTreatment *ui;
    QPushButton skinTouch;
    QTimer *timer;

    QLabel *freq_label;
    bool is_therapy;
};

#endif // ACTIVETREATMENT_H
