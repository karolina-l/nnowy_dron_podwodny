#include <iostream>
#include <cstdlib>
#include "dron.hh"
#include "vector.hh"
#include "dno.hh"
#include "tafla.hh"
#include "templates.cpp"
#include "m_obrotu.hh"
#include "interfejs_drona.hh"
#include "p_prost.hh"
#include <fstream>
using namespace std;

void wait4key() {
  do {
    cout << "\n Press a key to continue..." << endl;
  } while(cin.get() != 'a');
}

void obrot(double k, const shared_ptr <Dron> &I, vector <shared_ptr<Przeszkoda> >t_p )
{
  double dzielnik=400;
  double dod=k/dzielnik;
  for(int i=1; i<=dzielnik; i++)
  {
    I->zmien_kat(dod);

    for (int j=0; j<t_p.size(); j++)
    {
      if(t_p[j]->czy_kolizja(*I))
        {
          dod=-dod;
          I->zmien_kat(dod);
          j=t_p.size();
          i=401;
        }
    }

  }
}

void plyn(TWektor<double,3> w, shared_ptr <Dron> I, vector <shared_ptr<Przeszkoda> >t_p)
{
  int dzielnik=600;
  TWektor<double,3> dod;
  dod=w/dzielnik;
  for(int i=0; i<dzielnik; i++)
  {
      I->zmien_polozenie(dod);

      for( int j=0; j<t_p.size(); j++)
      {
        if(t_p[j]->czy_kolizja(*I))
        {
          dod[0]=-dod[0];
          dod[1]=-dod[1];
          dod[2]=-dod[2];
          I->zmien_polozenie(dod);
          i=601;
        }
      }

  }
}

/*void wczytaj(int w_tab, string nazwa, TWektor<double,3> *tab, TMacierzKw<double,3> *x, TWektor<double,3> *sdk)
{
  fstream plik;
  TWektor<double,3> d[w_tab];
  TWektor<double,3> temp[3];

  /////wczytanie danych z pliku/////
  plik.open("nazwa.txt");
  for(int i=0; i<w_tab; i++)
  {
    plik>>d[i];
  }
  cout<<endl;
  for(int i=0; i<w_tab; i++)
  {
    if(i<w_tab-4)
      tab[i]=d[i];
    else if(i>w_tab-3 && i<w_tab-1)
      temp[i-(w_tab-4)]=d[i];
    else if(i>w_tab-2 && i<w_tab)
        sdk=d[i];
  }
  x->TMacierzKw(temp);
}
*/

int main()
{
  drawNS::APIGnuPlot3D *wsk=new drawNS::APIGnuPlot3D(-5,5,-5,5,-5,5,-1);//-1 na reczne odswiezanie
  TWektor<double,3> tab[12], tab1[12], tab2[8], tca1[8], tca2[8];
  TMacierzKw<double,3> x, x1, x2, mac1, mac2;
  TWektor<double,3> sdk, sdk1, sdk2, srw, srw1, sp1, sp2;
  TWektor<double,3> d[17];
  fstream wirnik, wirnik1, plik, p1, p2;

  wirnik.open("wirnik.txt");
  for(int i=0; i<17; i++)
  {
    wirnik>>d[i];
  }
  for(int i=0; i<16; i++)
  {
    if(i<12)
      tab[i]=d[i];
    else if(i>11 && i<15)
      x[i-12]=d[i];
    else if(i>14 && i<16)
        sdk=d[i];
    else if(i>15 && i<17)
        srw=d[i];
  }

  M_obr y(x);

  wirnik1.open("wirnik1.txt");
  for(int i=0; i<17; i++)
  {
    wirnik1>>d[i];
  }
  for(int i=0; i<17; i++)
  {
    if(i<12)
      tab1[i]=d[i];
    else if(i>11 && i<15)
      x1[i-12]=d[i];
    else if(i>14 && i<16)
        sdk1=d[i];
    else if(i>15 && i<17)
        srw1=d[i];
  }

  M_obr y1(x1);

  plik.open("dane.txt");
  for(int i=0; i<12; i++)
  {
    plik>>d[i];
  }
  for(int i=0; i<12; i++)
  {
    if(i<8)
      tab2[i]=d[i];
    else if(i>7 && i<11)
      x2[i-8]=d[i];
    else if(i>10 && i<12)
        sdk2=d[i];
  }
  M_obr y2(x);

  p1.open("p1.txt");
    for(int i=0; i<12; i++)
    {
      p1>>d[i];
    }
    for(int i=0; i<12; i++)
    {
      if(i<8)
        tca1[i]=d[i];
      else if(i>7 && i<11)
        mac1[i-8]=d[i];
      else if(i>10 && i<12)
          sp1=d[i];
    }

    p2.open("p2.txt");
    for(int i=0; i<12; i++)
    {
      p2>>d[i];
    }
    for(int i=0; i<12; i++)
    {
      if(i<8)
        tca2[i]=d[i];
      else if(i>7 && i<11)
        mac2[i-8]=d[i];
      else if(i>10 && i<12)
          sp2=d[i];
    }
    wirnik.close();
    wirnik1.close();
    plik.close();
    p1.close();
    p2.close();
///////koniec przygotowania danych////////

std::vector<std::shared_ptr<Dron>> t_dronow
    {
        std::make_shared<Dron>(wsk, sdk, sdk1, sdk2, tab, tab1, tab2, y),
        std::make_shared<Dron>(wsk, sdk, sdk1, sdk2, tab, tab1, tab2, y),
        std::make_shared<Dron>(wsk, sdk, sdk1, sdk2, tab, tab1, tab2, y)
    };

std::vector<std::shared_ptr<Pprost>> t_przeszkod
    {
        std::make_shared<Pprost>(wsk,sp1,mac1,tca1),
        std::make_shared<Pprost>(wsk,sp2,mac2,tca2)
    };

std::vector<std::shared_ptr<Przeszkoda>> t_p;

std::shared_ptr<Dno> dn = std::make_shared<Dno>(wsk);
std::shared_ptr<Tafla> tf=std::make_shared<Tafla>(wsk);

t_p.push_back(dn);
t_p.push_back(tf);
    for(int i=0; i<3; i++)
    {
      t_p.push_back(t_dronow[i]);
    }
    for (int i=0; i<2; i++)
    {
      t_p.push_back(t_przeszkod[i]);
    }

  char wybor='v';

  t_dronow[0]->zmien_kolor("blue");
  t_dronow[1]->zmien_kolor("black");
  t_dronow[2]->zmien_kolor("green");
  dn->rysuj_ksztalt();
  tf->rysuj_ksztalt();
  t_przeszkod[0]->rysuj_ksztalt();
  t_przeszkod[1]->rysuj_ksztalt();
  t_dronow[0]->rysuj_ksztalt();
  t_dronow[1]->rysuj_ksztalt();
  t_dronow[2]->rysuj_ksztalt();
  TWektor<double,3> i1, i2;
  double ti1[3]={-3.0, -3.0, -3.0};
  double ti2[3]={3.0,3.0,3.0};
  i1=ti1;
  i2=ti2;


  t_dronow[1]->zmien_polozenie(i1);
  t_dronow[2]->zmien_polozenie(i2);

  wsk->redraw();

////////\menu/\\\\\\\\\

  int wyb_drona=0;
  while(wybor!='q')
  {

      cout<<"Aktualna ilosc wektorow: "<<TWektor<double,3>::wez_ile_aktualnie()<<endl;
      cout<<"Calkowita ilosc wektorow: "<<TWektor<double,3>::wez_ile_wszystkich()<<endl;
      cout<<"Aktualna ilosc elementow: "<<Bryla::wez_ob_aktualnie()<<endl;
      cout<<"Calkowita ilosc elementow: "<<Bryla::wez_ob_wszystkie()<<endl;

      cout<<"wybierz opcję:"<<endl<<endl;
      cout<<"o - obroc dron"<<endl;
      cout<<"p - przesun dron"<<endl;
      cout<<"z - zmien dron"<<endl;
      cout<<"q - wyjscie z programu"<<endl;



    cout<<"Twoj wybor to ";
    cin>>wybor;
    switch(wybor)
    {
      case 'o':
      {
        double k;
        cout<<"Podaj kat obrotu: ";
        cin>>k;

        obrot(k,t_dronow[wyb_drona],t_p);
        break;
      }

      case 'p':
      {
        TWektor<double,3> w;
        cout<<"Podaj wektor przesuniecia: ";
        cin>>w;
        plyn(w,t_dronow[wyb_drona],t_p);
        break;
      }

      case 'q':
        cout<<"Dziekuje za skorzystanie z programu,\nmilego dnia!"<<endl;
        exit(0);
        break;

      case 'z':
      {
        string kolorek;
        cout<<"Podaj kolor drona, ktorym chcesz sterowac: (green, blue, black)"<<endl;
        cin>>kolorek;
        if(kolorek=="blue")
        wyb_drona=0;
        if(kolorek=="green")
        wyb_drona=2;
        if(kolorek=="black")
        wyb_drona=1;
        break;
      }




      default:
        cerr<<"Niepoprawna opcja wyboru z menu"<<endl;

    }
  }

return 0;
}
