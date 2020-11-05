#include "Student.hpp"
 Student::Student(std::string nume, int an, std::vector<Materii>mat):numeStud(nume), anFaculta(an), materii(mat){}
 Student::~Student(){}
 
 Student::Student(Student& stud)
    {
        this->numeStud = stud.numeStud;
        copy(stud.materii.begin(), stud.materii.end(), back_inserter(materii));
    }

void Student:: subscribeMaterie(Materii&mat ){
       this->materii.push_back(mat);
    }
        
void Student:: afisareMaterii(){
        std::cout<<"Studentul: "<<this->numeStud<<" participa la: ";
        for(int i = 0; i < materii.size(); i++)
            std::cout<<this->materii[i].getNumeMaterie()<<" ";
    }
        

           
                   

