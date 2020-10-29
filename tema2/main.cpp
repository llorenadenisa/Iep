#include<iostream>
#include "Student.cpp"
int main(){
    std::vector<std::string>materii1{"mac", "ms", "mm"};
    Student s1("Maria", 2, materii1);
    s1.afisareAtribute();
    Student s2 = s1;
    Student s3(s1);
    return 0;
}
