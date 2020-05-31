#ifndef PPROST
#define PPROST

#include "vector.hh"
#include "m_obrotu.hh"
#include "prostopadloscian.hh"
#include "interfejs_drona.hh"
#include "przeszkoda.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

/*!
* \brief Klasa Pprost dziedziczaca publicznie po klasie Prostopadloscian i klasie Przeszkoda
*/
class Pprost:  public Prostopadloscian, public Przeszkoda{

public:
  /*!
  * \brief Konstruktor obiektu klasy Pprost
  * \param1 drawNS::APIGnuPlot3D *plot - wskaznik na dany obszar rysowania
  * \param2 TWektor<double,3> sr - wspolrzedne srodka
  * \param3 TMacierzKw<double,3> mat - macierz m_obrotu
  * \param4 TWektor<double,3> *w - tablica wektorow zawieracjacych wspolrzedne wierzcholkow prostopadloscianu
  * Metoda korzysta z konstruktora klasy Prostopadloscian
  */
  Pprost(drawNS::APIGnuPlot3D*plot, const TWektor<double,3> &sr, const TMacierzKw<double,3> &mat, TWektor<double,3>*w): Prostopadloscian(plot,sr,mat,w){}
  /*!
  * \brief wirtualny destruktor klasy Pprost
  */
  virtual ~Pprost(){};
  /*!
  * \brief Metoda wykrywajaca kolizje drona z przeszkoda prostopadloscienna
  * \param1 Interfejs i - obiekt klasy Interfejs
  */
  bool czy_kolizja(const Interfejs &i) const;

};

#endif
