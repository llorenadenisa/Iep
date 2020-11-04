#include<iostream>
#include "SchoolClass.cpp"

int main(){
    std::vector<std::string>materii1{"mac", "ms", "mm"};
    std::vector<std::string>materii2{"fic", "si", "pw"};
    Student s1("Maria", 2, materii1);
    s1.afisareAtribute();
    //Student s2(s1);
    Student s2("xx", 2, materii1);
    Student s3("Andrei", 3, materii2);
    //s2 = s3;
    s2.setName("Sara");
    std::vector<Student> stud;
    stud.push_back(s1);
    stud.push_back(s3);

    std::vector<Student> studGol ={};
    SchoolClass class1(stud, "7B");
    class1.displayStud();
    SchoolClass class2(studGol, "4");
    class2 =class1;

    std::cout<<"This is a copy of class"<<"\n";
    class2.displayStud();

    return 0;
}
