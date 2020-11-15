#include<iostream>
#include<string>
class Oras{
    //item 22 declare data memebers private
    private:
        std::string judet;
        std::string oras;
    public:
        Oras(std::string jud, std::string oras):judet(jud),oras(oras){}

        std::string getJudet()
        {
            return judet;
        }

        std::string getOras()
        {
            return oras;
        }
};

class Address{
    //item 22 declare data memebers private
    private:
        std::string strada;
        int nrCasa;
        Oras oras;
    public:
        Address(std::string str,int nrC, Oras& oras):strada(str),nrCasa(nrC),oras(oras){}
        void displayAddress()
        {
            std::cout<<"Strada: "<<strada<<",numar casa: "<<nrCasa<<",judet: "<<oras.getJudet()
            <<", oras: "<<oras.getOras()<<"\n";
        }

};
class InformUser{
    private:
        std::string nume;
        int varsta;
        Address adresa;
        long long int nrTel;

    public:
        InformUser(std::string num, int vars, Address&adr, long long int nr):nume(num),varsta(vars)
        ,adresa(adr),nrTel(nr){}
        void displayInfos()
        {
            std::cout<<"Nume: "<<nume<<",varsta: "<<varsta<<",numar telefon:+40"<<nrTel
            <<"\nAdresa:";
            adresa.displayAddress();
            
        }
};

class User{
    //item 22 declare data memebers private
    private:
        std::string username;
        std::string password;
        InformUser info;
    public:
        //item 18 make iterfaces easy to use coreclty
        User(const std::string usern, const std::string passw,InformUser &i):
        username(usern),password(passw),info(i){}
        void getInfoUser()
        {
            std::cout<<"Username: "<<username<<"\n";
            info.displayInfos();
            
        }
};