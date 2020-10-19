#include<iostream>
#include "mathFunc.cpp"

int main()
{
    MathFunc ob1(7, 4);

    std::cout<<"Adundare: "<<ob1.addNumb()<<std::endl;
    std::cout<<"Scadere: "<< ob1.substractNumb()<<std::endl;
    std::cout<<"Inmultire: "<< ob1.multiplyNumb()<<std::endl;

    return 0;
}