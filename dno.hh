#ifndef DNO
#define DNO

#include "powierzchnia.hh"
#include "vector.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

/*!
* \brief Klasa Dno dziedziczaca publicznie po klasie Powierzchnia
*/
class Dno: public Powierzchnia{
/*!
* \brief indeks rysowanego dna
*/
int nazwa;

public:
  /*!
  * \brief Konstruktor klasy Dno
  * \param1 drawNS::APIGnuPlot3D *plot - wskaznik na dany obszar rysowania
  * Konstruktor korzysta z konstruktora klasy Powierzchnia oraz przypisuje polu nazwa wartosc 0
  */
  Dno(drawNS::APIGnuPlot3D*plot): Powierzchnia(plot), nazwa(0){}
  /*!
  * \brief wirtualny destruktor klasy Dno
  */
  virtual ~Dno(){}
  /*!
  * \brief Dziedziczona metoda sluzaca do rysowania obiektow
  */
  void rysuj_ksztalt() override;

};

#endif
