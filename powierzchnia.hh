#ifndef POWIERZCHNIA
#define POWIERZCHNIA

#include "rysowanie_int.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

/*!
* \brief Klasa Powierzchnia dziedziczaca publicznie po klasie Rysuj
*/
class Powierzchnia: public Rysuj{

public:
/*!
* \brief Konstrujtor klasy Powierzchnia
* \param1 drawNS::APIGnuPlot3D *plot - wskaznik na dany obszar rysowania
* Konstruktor korzysta z konstruktora klasy Rysuj
*/
  Powierzchnia(drawNS::APIGnuPlot3D*plot): Rysuj(plot){}
  /*!
  * \brief wirtualny destruktor klasy Powierzchnia
  */
  virtual ~Powierzchnia() {}
  /*!
  * \brief Naglowek wirtualnej metody odpowiadajacej za rysowanie bryl
  */
  virtual void rysuj_ksztalt()=0;

};


#endif
