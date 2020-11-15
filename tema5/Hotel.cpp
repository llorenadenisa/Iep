#include<iostream>
#include<vector>
#include"User.cpp"


class Rezervare
{
    private:
        User user;
        std::string numeRezervare;
    public:
        Rezervare(const User&us, std::string numeRez):user(us),numeRezervare(numeRez){}
        std::string getNumeRezervare(){
            return numeRezervare;
        }
        void getInfoRezerv(){
            user.getInfoUser();
        }
};

class Hotel
{
    private:
        std::string numeHotel;
        std::vector<Rezervare> rezervari;
    public:
        Hotel(std::string numeH):numeHotel(numeH){}
        
        //item 20 prefer pass by reference to const
        void makeReservation(const User& us, std::string numeRez)
        {
            Rezervare rez(us,numeRez);
            rezervari.push_back(rez);
        }
        void getReservations(){
            for(int i =  0; i<rezervari.size(); i++){
                std::cout<<rezervari[i].getNumeRezervare()<<"\n"<<"Info Pers:";
                rezervari[i].getInfoRezerv();
            }

        }
};