#include "program.h"



Program::Program(QString n, float f, int d){
    this->name = n;
    this->frequency = f;
    this->duration = d;

}

Program::~Program(){

}

QString Program::getName(){
    return name;
}

/*
float Program::getFreq(){
    return frequency;
}
void Program::setFreq(float freq){
    this->frequency = freq;
}
*/
void Program::displayProgramList(){

}
