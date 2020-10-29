#include<iostream>
#include "Student.cpp"
int main(){
    std::vector<std::string>materii1{"mac", "ms", "mm"};
    std::vector<std::string>materii2{"fic", "si", "pw"};
    Student s1("Maria", 2, materii1);
    s1.afisareAtribute();
    Student s2(s1);
    Student s3("Andrei", 3, materii2);
    s2 = s3;
    return 0;
}
