#include<iostream>
#include<vector>
#include<string>
#include "Materii.cpp"

class Student
{
    std::string numeStud;
    int anFaculta;
    std::vector<Materii>materii;

    public:
        Student(std::string nume, int an, std::vector<Materii>mat):numeStud(nume), anFaculta(an), materii(mat){}
        ~Student(){};
        
        Student& operator=(Student&s)
        {
            if(&s != this)
            {
                numeStud.assign (s.numeStud);
                copy(s.materii.begin(), s.materii.end(), back_inserter(materii));

            }
            return *this;
        }

        Student(Student& stud)
        {
            numeStud.assign(stud.numeStud);
            copy(stud.materii.begin(), stud.materii.end(), back_inserter(materii));
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

        void subscribeMaterie(Materii& mat)
        {
            materii.push_back(mat);
        }
        
        void afisareMaterii()
        {
            std::cout<<"Studentul: "<<this->numeStud<<" participa la: ";
            for(int i = 0; i < materii.size(); i++)
                std::cout<<materii[i].getNumeMaterie()<<" ";
        }
        
        private:
            Student&& operator=(Student&&s);
            Student(Student&& s);
                   
};