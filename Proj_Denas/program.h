#ifndef PROGRAM_H
#define PROGRAM_H

#include "QString"

class Program{
public:
    Program(QString, float, int);
    ~Program();
    QString getName();
    void displayProgramList();
    //float getFreq();
   // void setFreq(float);

private:
    QString name;
    float frequency;
    int duration; //in minutes

};

#endif // PROGRAM_H

