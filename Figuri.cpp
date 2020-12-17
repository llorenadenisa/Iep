#include<iostream>
#include<list>

using namespace std;
 class Punct
{
    string nume;
    int x;
    int y;
    public:
        Punct() {}
        Punct(string nume, int x, int y)
        {
            this->nume = nume;
            this->x = x;
            this->y = y;
        }
        std::string get_nume()
        {
            return this->nume;
        }
        int get_x()
        {
            return this->x;
        }
        int get_y()
        {
            return this->y;
        }
        void set_x(int x)
        {
            this->x = x;
        }
        void set_y(int y)
        {
            this->y = y;
        }
        static void afisare_punct(Punct* p)
        {
            cout << p->get_nume() << "(" << p->get_x() << "," << p->get_y() << ")" << endl;
        }
};
class Figura
{ 
 public:
    virtual void adaugare_punct_coordonate(string nume_punct, int x, int y)=0;
    virtual void modificare_coordonate_punct(string nume_punct, int x_nou, int y_nou)=0;
    virtual void afisare_lista_puncte()=0;
    template <class myType> float panta_dreptei(myType figura)
    {
        float panta_dreptei = 0;
        int index = 0;
        int x1, x2, y1, y2;
        list<Punct*> lista = figura->get_lista_puncte();
        list<Punct*>::iterator i;
        if (lista.size() < 2)
        {
            std::cout << "Insuficiente puncte in lista pentru a calcula panta dintre 2 puncte";
            return 0;
        }
        else
        {
            for (i = lista.begin(); i != lista.end(); i++)
            {
                if (index == 0)
                {
                    x1 = (*i)->get_x();
                    y1 = (*i)->get_y();
                }
                else if (index == 1)
                {
                    x2 = (*i)->get_x();
                    y2 = (*i)->get_y();
                }
                index++;
            }
            int y = y2 - y1;;
            int x = x2-x1;
            panta_dreptei = (float)y / x;
            cout << "Panta dreptei primelor 2 puncte din lista este=" << panta_dreptei << endl;
        }
        return panta_dreptei;
    }
};

class Patrat: public Figura
{   
    int latura;
    list<Punct*> lista_puncte_patrat;
    public:
        Patrat(int latura)
        {
            this->latura = latura;
        }
        void afisare_figura()
        {
            cout << "Patrat: L=" << latura << endl;
        }
        list<Punct*> get_lista_puncte()
        {
            return lista_puncte_patrat;
        }
        
        int perimetru_patrat()
        {
            return 4 * latura;
        }
        
        void adaugare_punct_coordonate(string nume_punct, int x, int y)
        {
            lista_puncte_patrat.push_back(new Punct(nume_punct, x, y));
        }
    
        void afisare_lista_puncte()
        {
            list<Punct*>::iterator i;
            if (lista_puncte_patrat.size() == 0)
            {
                cout << "Lista puncte patrat goala!"<<endl;
            }
            else
            {
                for (i = lista_puncte_patrat.begin(); i != lista_puncte_patrat.end(); i++)
                {
                    cout << (*i)->get_nume() << "(" << (*i)->get_x() << "," << (*i)->get_y() << ")" << endl;
                }
            }
        } 
};

class Triunghi: public Figura
{
  public:
    void perimetru()
    {
        cout<<"cv";
    }
 
};

class Hexagon: public Figura

{
  public:
    void perimetru(){
        cout<<"cv";
    }

};
// class Cerc: public Figura
// {

// };

int main()
{
    cout<<"Compilabil";
    return 0;
}