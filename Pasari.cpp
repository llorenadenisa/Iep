#include<iostream>
#include <list> 
#include <iterator> 

using namespace std;

class Pasare
{  
    protected:
        int distanta;
        Pasare(int distanta):distanta(distanta){}
    public:
        virtual void getDistanta() = 0; 
        virtual void getSunet() = 0;
};

class Papagal : public Pasare
{
    list <string> cuvinte_stiute; 
    public:
        Papagal(string cuv, int dist):Pasare(dist){
            cuvinte_stiute.push_back(cuv);
        }

        void adaugaCuvant(string cuvant_nou)
        {
            cuvinte_stiute.push_back(cuvant_nou);
        }

        void afiseazaCuvinteStiute()
        {
            for (const auto& it : cuvinte_stiute)
            {
                cout<<it<<" ";
            }
            cout<<"\n";
        }

        void getDistanta()
        {
            cout<<"Distanta parcursa de un papagal este: "<< distanta;
            cout<<"\n";

        }

        void getSunet()
        {
            cout<<"Sunetul caracteristic al papagalului este cricri ";
            cout<<"\n";
        }

};

class Gaina : public Pasare
{

};

class Strut : public Pasare
{
    int contor_gaini;
 
   Strut() {
      contor_gaini = 0;
   }

   public:
    static Strut *strut;
    static Strut *getInstance() {  
        if (!strut)
        strut = new Strut;
        return strut;
   }

   Strut operator+(const Gaina &gaina)
   {
       contor_gaini++;
       Gaina::numar--;
       return *this
   }
};

int main(void)
{
    string s0("cuv1");
    string s1("cuv2");

    Papagal papagal1(s0, 20);
    papagal1.adaugaCuvant(s1);
    papagal1.afiseazaCuvinteStiute();
    papagal1.getSunet();
    papagal1.getDistanta();
    return 0;

}
