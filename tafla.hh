#ifndef TAFLA
#define TAFLA

#include "powierzchnia.hh"
#include "vector.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
/*!
* \brief Klasa Tafla dziedziczaca publicznie po klasie Powierzchnia
*/
class Tafla: public Powierzchnia{
/*!
* \brief indeks rysowanego dna
*/
int nazwa;

public:
  /*!
  * \brief Konstruktor klasy Tafla
  * \param1 drawNS::APIGnuPlot3D *plot - wskaznik na dany obszar rysowania
  * Konstruktor korzysta z konstruktora klasy Powierzchnia oraz przypisuje polu nazwa wartosc 0
  */
  Tafla(drawNS::APIGnuPlot3D*plot): Powierzchnia(plot), nazwa(0){}
  /*!
  * \brief wirtualny destruktor klasy Dno
  */
  virtual ~Tafla(){}
  /*!
  * \brief Dziedziczona metoda sluzaca do rysowania obiektow
  */
  void rysuj_ksztalt() override;

};

#endif
