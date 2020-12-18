#include<iostream>
#include <math.h>
#include <list> 
using namespace std;
 class Punct{
     int x,y;

     public:
        Punct(int x, int y){this->x=x;this->y=y;}
        int getX(){return this->x;}
        int getY(){return this->y;}
        
 };
 class Cerc{
     int raza;
     int x,y;
     Cerc(int raza, int x,int y){
         this->raza=raza;
         this->x=x;
         this->y=y;
     }
      public:
        static Cerc* instanta;
        static Cerc& getInstance(int raza, int x, int y)
        {
            static Cerc instanta(raza, x, y);
            return instanta;
        }
        int getRaza(){return this->raza;}
        int getCentruX(){return this->x;}
        int getCentruY(){return this->y;}
        void afisareCerc()
        {
            cout<<"Cercul de raza "<<raza<<" si centru "<<x<<","<<y;
            cout<<endl;
        }
 };
class Figura
 {
     protected:
        int nr_puncte;
        //int contor=0;
        //Punct* p[];
        public:
        
            Figura(int nr_puncte){this->nr_puncte=nr_puncte;}
            int getNrPuncte(){return this->nr_puncte;}
            // void adaugaFig(Punct *p){
            //      p[contor++]=p;
            // }
            //Punct getPunct(int i){if(i>contor){return new Punct(0,0);}else{return puncte[i];}}
            virtual double perimetru() =0;
 };

template<class Punct>
void afisare(Punct &a, char c)
{
  cout<<"Punctul "<<c<<" este: ";
    cout<<a->getX()<<','<<a->getY();
  cout<<endl;
}
 
template<class Punct>
double distantaDintrDouaPuncte(Punct &a,Punct &b)
{
  return sqrt((a->getX()-b->getX())*(a->getX()-b->getX()) + (a->getY()-b->getY())*(a->getY()-b->getY()));
}

template<class Punct>
double pantaDreptei(Punct &a,Punct &b)
{
  return (b->getY() - a->getY()) / (b->getX() - a->getX());
}

template<class Punct>
void seAflaPeCerc(Punct &x,Cerc c)
{
    if(((x->getX()-c.getCentruX())*(x->getX()-c.getCentruX()) + (x->getY()-c.getCentruY())*(x->getY()-c.getCentruY()) ) == c.getRaza()^2)
    {
        cout<<"se afla pe cerc\n";
    }else{cout<<"nu se alfa\n";}      
}

class Patrat : public Figura{
      Punct* tab[4];
      int contor=0;
    public:
        Patrat(int nr_puncte):Figura(4){}
        void adauga(Punct *p){
           if(contor>4){
               cout<<"Patratul are 4 puncte\n";
           }else{
               tab[contor++]=p;
           }
        }
        double perimetru(){
            Punct *a=tab[0];
            Punct *b=tab[1];
            double latura=distantaDintrDouaPuncte(a,b);
            return 4*latura;
        }
};

class Dreptunghi : public Figura
{
     Punct* tab[4];
      int contor=0;
    public:
        Dreptunghi(int nr_puncte):Figura(4){}
        void adaugaDreptunghi(Punct *p){
           int i;
           if(contor>4){
               cout<<"sunt 4 puncte\n";
           }else{
               tab[contor++]=p;
           }
        }
        void schimbaPunct(Punct *ve,Punct *n){
            for(int i =0;i<contor;i++){
                if(tab[i] == ve)
                {
                    ve=n;
                }
            }
        }
        double perimetru(){
            Punct *a=tab[0];
            Punct *b=tab[1];
            Punct *c=tab[2];
            double lungime=distantaDintrDouaPuncte(a,b);
            double latime=distantaDintrDouaPuncte(a,c);
            return 2*(lungime+latime);
        }
};

class Triungi : public Figura
{
    Punct* tab[3];
      int contor=0;
    public:
        Triungi(int nr_puncte):Figura(3){}
        void adaugaTriunghi(Punct *p){
           int i;
           if(contor>3){
               cout<<"sunt 3 puncte\n";
           }else{
               tab[contor++]=p;
           }
        }
        double perimetru(){
            Punct *a=tab[0];
            Punct *b=tab[1];
            Punct *c=tab[2];
            double ab=distantaDintrDouaPuncte(a,b);
            double ac=distantaDintrDouaPuncte(a,c);
            double bc=distantaDintrDouaPuncte(a,c);
            return (ab+ac+bc);
        }
};

int main()
{
    Punct *a=new Punct(4,3);
    afisare(a,'A');
    Punct *b=new Punct(0,0);
    afisare(b,'B');
    cout<<"\n Distanta este:"<<distantaDintrDouaPuncte(a,b);
   cout<<endl;
   cout<<"panta este "<<pantaDreptei(a,b);
   cout<<endl;
   Patrat p(4);
   p.adauga(new Punct(3,4));
   p.adauga(new Punct(0,0));
    cout<<"\nperimetrul patratului este: "<<p.perimetru();
    Dreptunghi d(4);
    d.adaugaDreptunghi(new Punct(0,0));
    d.adaugaDreptunghi(new Punct(0,1));
    d.adaugaDreptunghi(new Punct(3,0));
    Punct *cv=new Punct(0,0);
    Punct *cn=new Punct(1,1);
    cout<<"\nperimetrul dreptungiului este: "<<d.perimetru();
    d.schimbaPunct(cv,cn);
    cout<<"\nperimetrul dreptungiului este: "<<d.perimetru();
    cout<<"\n-------------";
    Triungi t(3);
    t.adaugaTriunghi(new Punct(0,0));
    t.adaugaTriunghi(new Punct(3,0));
    t.adaugaTriunghi(new Punct(0,4));
    cout<<"\nperimetrul triunghilui este: "<<t.perimetru();
    cout<<endl;
    Cerc c = c.getInstance(1,0,0);
    c.afisareCerc();
    Punct *pp=new Punct(1,1);
    seAflaPeCerc(pp,c);
 return 0;
}
