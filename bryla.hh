#ifndef BRYLA
#define BRYLA

#include <cstdlib>
#include <unistd.h>
#include "rysowanie_int.hh"
#include "vector.hh"
#include "m_obrotu.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

/*!
* \brief Klasa wirtualna reprezentujaca bryle,
* dziedziczy publicznie po klasie Rysuj
*/
class Bryla:public Rysuj{

    static int ob_aktualnie;
    static int ob_wszystkie;
protected:
  /*!
  * \brief srodek bryly
  */
  TWektor<double,3> srodek;
  /*!
  * \brief macierz obrotu bryly
  */
  M_obr mobr;
  /*!
  * \brief nazwa bryly nadawana podczas rysowania
  */
  int nazwa;

  string kolor;

public:
  /*!
  * \brief Konstruktor obiektu klasy Bryla
  * \param1 drawNS::APIGnuPlot3D *plot - wskaznik na dany obszar rysowania
  * \param2 TWektor<double,3> sr - wspolrzedne srodka
  * \param3 TMacierzKw<double,3> mat - macierz m_obrotu
  * Metoda domyslnie przypisuje polu "nazwa" wartosc 0
  */
  Bryla(drawNS::APIGnuPlot3D*plot, const TWektor<double,3> &sr, const TMacierzKw<double,3> &mat): Rysuj(plot), mobr(mat), srodek(sr), nazwa(0), kolor("red"){++ob_aktualnie; ++ob_wszystkie;}
  Bryla(const Bryla &nowa);
  /*!
  * \brief Wirtualny destruktor obiiektów klasy Bryla
  */
  virtual ~Bryla(){--ob_aktualnie;}
  /*!
  * \brief Naglowek wirtualnej metody odpowiadajacej za rysowanie bryl
  */
  virtual void rysuj_ksztalt()=0;
  /*!
  * \brief Naglowek wirtualnej metody odpowiadajacej za zmiane kata prostopadloscianu wzgledem osi OZ
  * \param1 double kat - kat obrotu
  */
  virtual void zmien_kat(double kat)=0;
  /*!
  * \brief Naglowek wirtualnej metody odpowiadajacej za zmiane polozenia prostopadloscianu
  * \param1 TWektor<double,3> w - wektor zmiany polozenia
  */
  virtual void zmien_polozenie(const TWektor<double,3> &w) =0;
  /*!
  * \brief metoda usuwa dany obiekt klasy Bryla
  */
  virtual void zmien_kolor(string klr)=0;
  void usun()
  {
    gnuplot->erase_shape(this->nazwa);
  }
  static int wez_ob_aktualnie() {return ob_aktualnie;}
  static int wez_ob_wszystkie() {return ob_wszystkie;}
};



#endif
