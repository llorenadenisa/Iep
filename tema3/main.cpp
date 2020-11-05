#include<iostream>
#include "Student.cpp"

int main(){
    Materii mat1("fis");
    Materii mat2("fic");
    std::vector<Materii> materii= {mat1, mat2};
    Student s1("Maria", 2, materii);
    s1.afisareMaterii();
    std::cout<<"\n";
    return 0;
}
