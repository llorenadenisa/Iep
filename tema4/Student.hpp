#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include<vector>
#include<string>
#include "Materii.hpp"
#include "Bursa.cpp"
using namespace std;

class Student
{
    std::string numeStud;
    int anFaculta;
    std::vector<Materii>materii;
    float medie;
    std::shared_ptr<Bursa> bursa;
    public:
        Student(std::string , int , std::vector<Materii>mat, float);
        virtual ~Student();
        Student(Student& stud);
        void subscribeMaterie(Materii& mat);
        void afisareMaterii();
        Student& operator=(Student&s)
        {
        if(&s != this)
            {
                numeStud = s.numeStud;
                copy(s.materii.begin(), s.materii.end(), back_inserter(materii));

            }
        return *this;
        }
        
       std::string getName(){
            return this->numeStud;
        }

        void setName(std::string name){
            this->numeStud = name;
        }
        
        void setAn(int an){
            this->anFaculta = an;
        }
        Student getStudent(){
            return *this;
        }
        float getMedie(){
            return medie;
        }
        void setBursa(Bursa bursa)
        {
            this->bursa = bursa;
        }
        //item 15?
        void afisareValBursaFaraTaxa()
        {
            int value = taxCalc(bursa.getValue());

        }

        int taxCalc(const int s){
            return s-100;
        }
    private:
            Student&& operator=(Student&&s);
            Student(Student&& s);
            Student();
            Student(int);
            Student(std::vector<Materii>);

};

#endif