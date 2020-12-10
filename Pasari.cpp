#include<iostream>
#include <list> 
#include <iterator> 

using namespace std;

class Pasare
{  
    public:
        virtual void zboara(int km)=0; 
        virtual void getSunet()=0;
};

class Papagal : public Pasare
{
    list <string> cuvinte_stiute; 
    public:
        Papagal(string cuv){
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

        void zboara(int dist)
        {
            cout<<"Distanta parcursa de un papagal este: "<< dist<<endl;
            cout<<"\n";

        }

        void getSunet()
        {
            cout<<"Sunetul caracteristic al papagalului este cricri"<<endl;
            cout<<"\n";
        }

};

class Gaina : public Pasare
{
    public:
        static int numar;
        Gaina(){
            
            if (numar < 30)
            {
                numar++;
            }
            else cout << "Nu puteti avea mai mult de 30 de gaini"<<endl;
        }

         void zboara(int dist)
        {
            if(dist < 10)
            {
                cout<<"Distanta parcursa de o gaina este: "<< dist << endl;
            }
            else
            {
                cout<<"O gaina nu poate parcurge o distanta mai mare de 10 m"<<endl;
            }
            

        }

        void getSunet()
        {
            cout<<"Sunetul caracteristic al gainii este cocodac"<<endl;
            cout<<"\n";
        }

        void vanzareGaina()
        {
            if(numar==0)
            cout<<"Ne pare rau, nu mai avem gaini de vanzare"<<endl;
            else
            { 
                numar--;
                cout<<"Mai avem "<<numar<<" gaini de vanzare."<<endl;
                }
}

};

class Strut : public Pasare
{
    int contor_gaini;
 
   Strut(){}

   public:
    int contorGaini = 0;
    static Strut *strut;
    static Strut *getInstance() {  
        if (strut == 0)
        strut = new Strut();
        return strut;
   }

   Strut operator+(const Gaina &gaina)
   {
       contorGaini++;
       Gaina::numar--;
       return *this;
   }

   void zboara(int dist)
   {
       cout<<"Strutul nu zboara"<<endl;
   }

   void getSunet()
   {
       cout<<"Sunetul specific strutului e ii"<<endl;
   }

   int getContor()
   {
       return contorGaini;
   }
};

int Gaina::numar = 0;
Strut* Strut::strut=NULL;

int main(void)
{
    string s0("cuv1");
    string s1("cuv2");

    Papagal papagal1(s0);
    papagal1.adaugaCuvant(s1);
    papagal1.afiseazaCuvinteStiute();
    papagal1.getSunet();
    papagal1.zboara(20);

    Gaina* gaina1 = new Gaina();
    gaina1->getSunet();
    gaina1->zboara(12);
    // gaina1->vanzareGaina();
    // gaina1->vanzareGaina();

    Strut* str;
    str = Strut::getInstance();
    str->getSunet();

    (*str) + (*gaina1);

    cout << endl<<"Strutul are "<<str->getContor()<<" gaini"<< endl;
    cout<<endl<<"Nr de gaini este de "<<Gaina::numar<<" gaini!";

    return 0;
}
