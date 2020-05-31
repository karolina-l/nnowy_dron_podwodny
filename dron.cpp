#include "dron.hh"
#include "sruba.hh"

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
  double dzielnik=400;
  double dod=kat/dzielnik;
  for(int wycinek=1; wycinek<=dzielnik; wycinek++)
  {
    M_obr obr;
    obr=obr.utworz_mRz(dod);
    //srodek=obr*srodek;
    s1.Sruba::pamietaj_kat(dod*wycinek);
    s2.Sruba::pamietaj_kat(dod*wycinek);
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
    s1.Sruba::zmien_kat(dod);
    //s1.Sruba::obrot_sruby();
    s2.Sruba::zmien_kat(dod);
  //  s2.Sruba::obrot_sruby();
    this->rysuj_ksztalt();
    gnuplot->redraw();

  }
}

void Dron::zmien_polozenie(const TWektor<double,3> &w)
{

  double dzielnik=600;
  TWektor<double,3> dod;
  dod=w/dzielnik;
  for(int j=1; j<=dzielnik; j++)
  {
    s1.Sruba::zmien_polozenie(dod);
    s2.Sruba::zmien_polozenie(dod);
  //  s1.Sruba::obrot_sruby();
    //s2.Sruba::obrot_sruby();

    srodek=srodek+dod;

    for(int i=0; i<8; i++)
    {
      t[i]=t[i]+dod;
    }

    gnuplot->erase_shape(nazwa);
    this->rysuj_ksztalt();
    gnuplot->redraw();
  }
}
