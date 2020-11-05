#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include<vector>
#include<string>
#include "Materii.hpp"
using namespace std;

class Student
{
    public:
        Student(std::string , int , std::vector<Materii>mat);
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
    protected:
         std::string numeStud;
         int anFaculta;
         std::vector<Materii>materii;
    private:
           Student&& operator=(Student&&s);
            Student(Student&& s);
};

#endif