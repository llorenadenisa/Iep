#include<iostream>
#include<vector>

class Student
{
    std::string numeStud;
    int anFaculta;
    std::vector<std::string>materii;

    public:
        Student(std::string nume, int an, std::vector<std::string>mat):numeStud(nume), anFaculta(an), materii(mat){}
        ~Student(){
            std::cout<<"Destructorul a fost apelat"<<std::endl;
        };
        Student(const Student& stud){
            numeStud = stud.numeStud;
            anFaculta = stud.anFaculta;
            copy(stud.materii.begin(), stud.materii.end(), back_inserter(materii));
            std::cout<<"S-a apelat copy constructor-ul"<<std::endl;
        }
        void afisareAtribute(){
            std::cout<<"Nume student:"<<this->numeStud<<" an faculta: "<<this->anFaculta<<" materii: ";
            for(int i = 0; i< this->materii.size(); i++)
                std::cout<<this->materii[i]<<" ";
            std::cout<<"\n";
        }
};