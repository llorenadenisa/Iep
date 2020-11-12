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
    virtual void setBursa(std::shared_ptr<Bursa> bursa){
       
    }
    void setValBursa(int valB){
        this->valBursa = valB;
    }
    
    int getValue(){
        return valBursa;
    }

};

class BursaMerit:Bursa{

    using Bursa::Bursa;

    void setBursa(std::shared_ptr<Bursa> bursa)
    {
        bursa->setBursa(bursa);
        Bursa::setValBursa(1000);

    }

};