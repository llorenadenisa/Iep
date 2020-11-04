#include<iostream>
#include "Student.cpp"
#include<vector>

class  SchoolClass{
    std::vector<Student> studenti;
    std::string className;
    public:
        SchoolClass(std::vector<Student> st, std::string name):studenti(st),className(name){}

        SchoolClass& operator=(SchoolClass& schoolCls)
        {
            if(&schoolCls != this)
            {
                className = schoolCls.className;
                studenti = schoolCls.studenti;
            }
            std::cout<<"Operator"<<"\n";

            return *this;
        }
        void displayStud()
        {
            for(int i = 0; i < studenti.size(); i++){
                std::cout<<studenti[i].getName();
                std::cout<<"\n";
            }
        }

};