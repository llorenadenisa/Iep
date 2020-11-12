#include<iostream>
#include "Student.hpp"
#include<memory>
class Bursa
{    
    std::string numeBursa;
    int  valBursa;
    public:
        explicit Bursa (std::string nume):numeBursa(nume), valBursa(0){}
    virtual void setBursa(std::shared_ptr<Student> stud);
    void setValBursa(int valB){
        this->valBursa = valB;
    }
    

};

class BursaMerit:Bursa{

    using Bursa::Bursa;

    void setBursa(std::shared_ptr<Student> stud)
    {
        stud->setBursa(*this);
        Bursa::setValBursa(1000);

    }

};