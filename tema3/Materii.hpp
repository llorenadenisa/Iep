#ifndef MATERII_H
#define MATERII_H
#endif
#include<iostream>
#include<vector>

class  Materii{
    std::string numeMaterie;
    public:
        Materii(std::string name):numeMaterie(name){}

        std::string getNumeMaterie(){
            return numeMaterie;
        }
    private:
        Materii& operator=(Materii& mat);
};