#include<iostream>
#include<vector>
#include<string>

class Student
{
    std::string numeStud;
    int anFaculta;
    std::vector<std::string>materii;

    public:
        Student(std::string nume, int an, std::vector<std::string>mat):numeStud(nume), anFaculta(an), materii(mat){}
        ~Student(){
              delete this;
        };
        
        Student& operator=(const Student&s)
        {
            if(&s != this)
            {
                this->numeStud = s.numeStud;
                this->materii = s.materii;

            }
            return *this;
        }

        Student(const Student& stud)
        {
            numeStud = stud.numeStud;
            materii = stud.materii;
        }

        void afisareAtribute(){
            std::cout<<"Nume student:"<<this->numeStud<<" an faculta: "<<this->anFaculta<<" materii: ";
            for(auto i = materii.begin(); i != materii.end(); ++i)
                std::cout<<*i<<" ";
            std::cout<<"\n";
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
        
        private:
            Student&& operator=(const Student&&s);
             Student(Student&& s);
                   
};