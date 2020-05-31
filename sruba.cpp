#include "sruba.hh"
#include "m_obrotu.hh"
#include "dron.hh"
#include <math.h>

using namespace std;

void Sruba::pamietaj_kat(const double &kat)
{
  this->kat_ox=kat;
}

void Sruba::obrot_sruby() //problemy z dzialaniem
{
  M_obr obr, p_minus, p_plus;
  double oz;
  obr=obr.utworz_mRx(45);
  oz=this->kat_ox;
  //cout<<"oz: "<<oz<<endl<<endl;
  p_minus=p_minus.utworz_mRz(-oz);
  p_plus=p_plus.utworz_mRz(oz);

    for(int i=0; i<12; i++)
    {
      t[i]=t[i]-srodek; //przesuniecie do (0, 0, 0)
      t[i]=p_minus*t[i]; //obrot wokol OZ
      t[i]=obr*t[i]; //obrot sruby
      t[i]=p_plus*t[i]; //obrot wokol OZ
      t[i]=t[i]+srodek; //powrot do (0, 0, 0)
    }

  this->usun();
  //this->Graniastoslup::rysuj_ksztalt();
  //gnuplot->redraw();

}

  void Sruba::zmien_kat(double kat)
  {
      M_obr obr;

      obr=obr.utworz_mRz(kat);

      for(int i=0; i<12; i++)
      {
        t[i]=t[i]-sr_drona;
        t[i]=obr*t[i];
        t[i]=t[i]+sr_drona;
      }
      this->usun();
  }

void Sruba::zmien_polozenie(const TWektor<double,3> &w)
{

  sr_drona=sr_drona+w;
  srodek=srodek+w;
  for(int i=0; i<12; i++)
  {
    t[i]=t[i]+w;
  }
  gnuplot->erase_shape(nazwa);
}
