#include "prostopadloscian.hh"
#include "m_obrotu.hh"
#include <math.h>

using namespace std;
  Prostopadloscian::Prostopadloscian(drawNS::APIGnuPlot3D*plot, const TWektor<double,3> &sr, const TMacierzKw<double,3> &mat, TWektor<double,3>*w): Bryla(plot, sr, mat)
  {
    for(int i=0; i<8; i++)
    {
      t[i]=w[i];
    }
  }

  void Prostopadloscian::rysuj_ksztalt()
  {
    nazwa=gnuplot->draw_polyhedron (vector<vector<drawNS::Point3D>>
    {
      {t[0],t[1],t[2],t[3]},
      {t[4],t[5],t[6],t[7]}
    },"red");
  }

  void Prostopadloscian::zmien_kat(double kat)
  {
    M_obr obr;
    double dzielnik=420;
    double dod=kat/dzielnik;
    for(int wycinek=1; wycinek<=dzielnik; wycinek++)
    {
      obr=obr.utworz_mRz(dod);
      srodek=obr*srodek;
      for(int i=0; i<8; i++)
      {
        t[i]=t[i]-srodek;
      }

      for(int i=0; i<8; i++)
      {
        t[i]=obr*t[i];
      }

      for(int i=0; i<8; i++)
      {
        t[i]=t[i]+srodek;
      }

      usleep(0.000001);

      gnuplot->erase_shape(nazwa);
      this->rysuj_ksztalt();
    }


  }

void Prostopadloscian::zmien_polozenie(const TWektor<double,3> &w)
{
  double dzielnik=1000;
  TWektor<double,3> dod;
  dod=w/dzielnik;
  for(int j=1; j<=dzielnik; j++)
  {
    srodek=srodek+dod;
    for(int i=0; i<8; i++)
    {
      t[i]=t[i]+dod;
    }
    usleep(0.0000001);
    gnuplot->erase_shape(nazwa);
    this->rysuj_ksztalt();
  }
}
