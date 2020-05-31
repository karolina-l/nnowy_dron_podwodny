#include "dron.hh"
#include "sruba.hh"
#include <cmath>

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;


void Dron::rysuj_ksztalt()
{
  s1.rysuj_ksztalt();
  s2.rysuj_ksztalt();
  nazwa=gnuplot->draw_polyhedron (vector<vector<drawNS::Point3D>>
  {
    {t[0],t[1],t[2],t[3]},
    {t[4],t[5],t[6],t[7]}
  },"red");
}

void Dron::zmien_kat(double kat)
{
    M_obr obr;
    obr=obr.utworz_mRz(kat);
    //srodek=obr*srodek;
    s1.Sruba::pamietaj_kat(kat);
    s2.Sruba::pamietaj_kat(kat);
    //cout<<"dod: "<<dod*wycinek<<endl;

    for(int i=0; i<8; i++)
    {
      t[i]=t[i]-srodek;
      t[i]=obr*t[i];
      t[i]=t[i]+srodek;
    }

    s1.usun();
    s2.usun();
    gnuplot->erase_shape(nazwa);
    s1.Sruba::zmien_kat(kat);
    //s1.Sruba::obrot_sruby();
    s2.Sruba::zmien_kat(kat);
  //  s2.Sruba::obrot_sruby();
    this->rysuj_ksztalt();
    gnuplot->redraw();

}

void Dron::zmien_polozenie(const TWektor<double,3> &w)
{

    s1.Sruba::zmien_polozenie(w);
    s2.Sruba::zmien_polozenie(w);
    // s1.Sruba::obrot_sruby();
    //s2.Sruba::obrot_sruby();

    srodek=srodek+w;

    for(int i=0; i<8; i++)
    {
      t[i]=t[i]+w;
    }

    gnuplot->erase_shape(nazwa);
    this->rysuj_ksztalt();
    gnuplot->redraw();
}

bool Dron::czy_kolizja(const Interfejs &i) const
{
  TWektor<double,3> dronsr, przesr;
  przesr=this->srodek;
  dronsr=i.zwroc_interfejs();
  double dx, dy, dz, odl,Ri;
  Ri=1.47;
  dx=abs(przesr[0]-dronsr[0]);
  dy=abs(przesr[1]-dronsr[1]);
  dz=abs(przesr[2]-przesr[2]);
  odl=dx*dx+dy*dy+dz*dz;
  odl=sqrt(odl);
  if(odl<(2*Ri+0.45))
  {
    cout<<"kolizja z dronem"<<endl;
    return true;
  }

  else
    return false;
}
