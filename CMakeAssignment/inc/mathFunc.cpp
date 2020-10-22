#include<iostream>
#include "mathFunc.hpp"

MathFunc::MathFunc(int n1, int n2)
{
    this->numb1 = n1;
    this->numb2 = n2;
}

int MathFunc::addNumb(){
    return this->numb1 + this->numb2;
}

int MathFunc::substractNumb(){
    return this->numb1 - this->numb2;
}

int MathFunc::multiplyNumb(){
    return this->numb1 * this->numb2;
}
