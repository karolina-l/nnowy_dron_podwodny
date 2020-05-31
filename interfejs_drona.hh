#ifndef INTERFEJS_DRONA
#define INTERFEJS_DRONA

#include "vector.hh"
#include "m_obrotu.hh"
//#include "prostopadloscian.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

/*!
* \brief Klasa Interfejs 
*/
class Interfejs{

public:
  /*!
  * \brief wirtualny destruktor klasy Interfejs
  */
virtual ~Interfejs(){};
/*!
* \brief Wirtualna metoda wykrywajaca kolizje drona z przeszkoda
* \param1 Interfejs i - obiekt klasy Interfejs
*/
virtual TWektor<double,3> zwroc_interfejs() const =0;

};

#endif
