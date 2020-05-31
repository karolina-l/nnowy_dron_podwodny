#ifndef DRON
#define DRON

#include <iostream>
#include "interfejs_drona.hh"
#include "prostopadloscian.hh"
#include "rysowanie_int.hh"
#include "sruba.hh"
#include "vector.hh"
#include "m_obrotu.hh"
#include "przeszkoda.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

/*!
* \brief Klasa Dron dziedziczaca publicznie po klasie Interfejs
*/
class Dron: public Interfejs, public Prostopadloscian, public Przeszkoda{

  /*!
  * \brief pole reprezentujace wirnik drona
  */
  Sruba s1;
  /*!
  * \brief pole reprezentujace wirnik drona
  */
  Sruba s2;

public:
  /*!
  * \brief Konstruktor obiektu klasy Dron
  * \param1 drawNS::APIGnuPlot3D *plot - wskaznik na dany obszar rysowania
  * \param2 TWektor<double,3> sr1 - wspolrzedne srodka pierwszego wirnika
  * \param3 TWektor<double,3> sr2 - wspolrzedne srodka drugiego wirnika
  * \param4 TWektor<double,3> srdr - wspolrzedne srodka drona
  * \param5 TWektor<double,3> *ws1 - tablica wektorow zawieracjacych wspolrzedne wierzcholkow pierwszego wirnika
  * \param6 TWektor<double,3> *ws2 - tablica wektorow zawieracjacych wspolrzedne wierzcholkow drugiego wirnika
  * \param7 TWektor<double,3> *wd - tablica wektorow zawieracjacych wspolrzedne wierzcholkow drona
  * \param8 TMacierzKw<double,3> mat - macierz m_obrotu
  * Metoda korzysta z konstruktora klasy Interfejs
  */
  Dron(drawNS::APIGnuPlot3D*plot, const TWektor<double,3> &sr1, const TWektor<double,3> &sr2, const TWektor<double,3> &srdr, TWektor<double,3> *ws1, TWektor<double,3> *ws2, TWektor<double,3> *wd, const TMacierzKw<double,3> &mat):Prostopadloscian(plot,srdr,mat,wd), s1(plot, sr1, mat, ws1, srdr), s2(plot, sr2, mat, ws2, srdr){}
  /*!
  * \brief wirtualny destruktor klasy DRON*/
  virtual ~Dron(){}
  /*!
  * \brief metoda sluzaca do rysowania obiektow
  */
  void rysuj_ksztalt() override;
  /*!
  * \brief Metoda pozwalajaca na zmiane kata drona wzgledem osi OZ
  * \param1 double kat - kat obrotu
  */
  void zmien_kat(double kat) override;
  /*!
  * \brief Metoda pozwalajaca na zmiane polozenia drona
  * \param1 TWektor<double,3> w - wektor zmiany polozenia
  */
  void zmien_polozenie(const TWektor<double,3> &w) override;
  /*!
  * \brief Metoda wykrywajaca kolizje drona z dronem
  * \param1 Interfejs i - obiekt klasy Interfejs
  */
  bool czy_kolizja(const Interfejs &i) const;
  /*!
  * \brief Metoda zwracajaca srodek drona
  */
  TWektor<double,3> zwroc_interfejs() const override
  {
    return srodek;
  }
};


#endif
