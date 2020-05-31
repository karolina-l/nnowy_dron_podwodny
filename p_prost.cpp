#include "p_prost.hh"
#include <cmath>

bool Pprost::czy_kolizja(Interfejs i)
{
  TWektor<double,3> dronsr, przesr;
  przesr=this->srodek;
  dronsr=i.zwroc_interfejs();
  double dx, dy, dz, odl,Ri,Rp;
  Ri=1.47;
  Rp=0.71;
  dx=abs(przesr[0]-dronsr[0]);
  dy=abs(przesr[1]-dronsr[1]);
  dz=abs(przesr[2]-przesr[2]);
  odl=dx*dx+dy*dy+dz*dz;
  odl=sqrt(odl);
  if(odl<(Ri+Rp))
    return true;
  else
    return false;
}
