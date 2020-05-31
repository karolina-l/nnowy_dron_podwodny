#ifndef PRZESZKODA
#define PRZESZKODA

#include "vector.hh"
#include "m_obrotu.hh"
#include "interfejs_drona.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

/*!
* \brief Klasa Przeszkoda
*/
class Przeszkoda{

public:
  /*!
  * \brief Konstruktor obiektu klasy Przeszkoda
  */
  Przeszkoda(){}
  /*!
  * \brief wirtualny destruktor klasy Przeszkoda
  */
  virtual ~Przeszkoda(){}
  /*!
  * \brief Metoda wykrywajaca kolizje drona z dronem
  * \param1 Interfejs i - obiekt klasy Interfejs
  */
  virtual bool czy_kolizja(const Interfejs &i) const=0;

};

#endif
