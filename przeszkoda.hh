#ifndef PRZESZKODA
#define PRZESZKODA

#include "vector.hh"
#include "m_obrotu.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

/*!
* \brief Klasa Interfejs dziedziczaca publicznie po klasie Prostopadloscian
*/
class Przeszkoda{

public:
  /*!
  * \brief Konstruktor obiektu klasy Interfejs
  * \param1 drawNS::APIGnuPlot3D *plot - wskaznik na dany obszar rysowania
  * \param2 TWektor<double,3> sr - wspolrzedne srodka
  * \param3 TMacierzKw<double,3> mat - macierz m_obrotu
  * \param4 TWektor<double,3> *w - tablica wektorow zawieracjacych wspolrzedne wierzcholkow prostopadloscianu
  * Metoda korzysta z konstruktora klasy Prostopadloscian
  */
  Przeszkoda(){}
  /*!
  * \brief wirtualny destruktor klasy Interfejs
  */
  virtual ~Przeszkoda(){}

  virtual bool czy_kolizja(Interfejs i)=0;

};

#endif
