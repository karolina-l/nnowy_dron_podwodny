#include "interfejs_drona.hh"




/*{

  s1(plot, sr1, mat, ws1, srdr);
  s2(plot, sr2, mat, ws2, srdr);
  dron(plot, srdr, mat, wd);
}

void Interfejs::rysuj_ksztalt()
{
  dron.Dron::rysuj_ksztalt();
  s1.Sruba::rysuj_ksztalt();
  s2.Sruba::rysuj_ksztalt();
  gnuplot->redraw();
}

void Interfejs::zmien_kat(double kat)
{
  M_obr obr;
  double dzielnik=420;
  double dod=kat/dzielnik;
  for(int wycinek=1; wycinek<=dzielnik; wycinek++)
  {
    s1.Sruba::zmien_kat(dod);
    s2.Sruba::zmien_kat(dod);
    s1.Sruba::obrot_sruby();
    s2.Sruba::obrot_sruby();
    dron.Prostopadloscian::zmien_kat(dod);

    usleep(0.000000001);
    gnuplot->redraw();
  }

}

void Interfejs::zmien_polozenie(const TWektor<double,3> &w)
{

  double dzielnik=1000;
  TWektor<double,3> dod;
  dod=w/dzielnik;
  for(int j=1; j<=dzielnik; j++)
  {
    s1.Sruba::zmien_polozenie(dod);
    s2.Sruba::zmien_polozenie(dod);
    s1.Sruba::obrot_sruby();
    s2.Sruba::obrot_sruby();
    dron.Prostopadloscian::zmien_polozenie(dod);
  }
}*/
