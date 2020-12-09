#include<iostream>
#include <list> 
#include <iterator> 

using namespace std;

class Pasare
{  
    protected:
        string sunet;
        int distanta;
        Pasare(string sunet, int distanta):sunet(sunet),distanta(distanta){}
    public:
        virtual void getDistanta() = 0; 
        virtual void getSunet() = 0;
};

class Papagal : public Pasare
{
    list <string> cuvinte_stiute; 
    string sunetCarac;


    public:
        Papagal(string cuv, int dist, string& sunet):Pasare(sunet, dist){
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
            cout<<"Sunetul caracteristic al papagalului este: "<< sunet;
            cout<<"\n";
        }

};

class Gaina : public Pasare
{

};

class Strut : public Pasare
{
    static Strut *strut;
    list<Gaina> gaini_detinute;
    int contor_gaini;
 
   Strut() {
      list<Gaina> gaini_detinute = NULL;
      contor_gaini = 0;
   }

   public:
   static Strut *getInstance() {
      if (!strut)
      strut = new Strut;
      return strut;
   }

   Strut operator+(const Gaina &gaina)
   {
       contor_gaini++;
       gaini_detinute.push_back(gaina);
   }
};

int main(void)
{
    string s0("cuv1");
    string s1("cuv2");
    string sunet1("aaa");

    Papagal papagal1(s0, 20, sunet1);
    papagal1.adaugaCuvant(s1);
    papagal1.afiseazaCuvinteStiute();
    papagal1.getSunet();
    papagal1.getDistanta();
    return 0;

}