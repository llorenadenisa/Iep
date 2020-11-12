#include<iostream>
#include "Student.hpp"
#include<memory>
#include<string>
class Bursa
{    
    std::string numeBursa;
    int  valBursa;
    public:
       // explicit Bursa (std::string nume):numeBursa(nume), valBursa(0){}
    virtual void setBursa(std::shared_ptr<Bursa> stud){
       
    }
    void setValBursa(int valB){
        this->valBursa = valB;
    }
    

};

class BursaMerit:Bursa{

    using Bursa::Bursa;

    void setBursa(std::shared_ptr<Bursa> stud)
    {
        stud->setBursa(stud);
        Bursa::setValBursa(1000);

    }

};