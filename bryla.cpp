#include "bryla.hh"

int Bryla::ob_aktualnie=0;
int Bryla::ob_wszystkie=0;

Bryla::Bryla(const Bryla &nowa): Rysuj(nowa)
{
  *this=nowa;
  ++ob_aktualnie;
  ++ob_wszystkie;
}
