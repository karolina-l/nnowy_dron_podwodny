#include "p_prost.hh"
#include <cmath>

bool Pprost::czy_kolizja(const Interfejs &i) const
{
  TWektor<double,3> dronsr, przesr;
  przesr=this->srodek;
  dronsr=i.zwroc_interfejs();
  //cout<<"srdr: "<<dronsr[0]<<","<<dronsr[1]<<","<<dronsr[2]<<endl;
  //cout<<"przesr: "<<przesr[0]<<","<<przesr[1]<<","<<przesr[2]<<endl;

  //cout<<"KOLIZJA Z PUDELKIEM "<<endl;
  double dx, dy, dz, odl,Ri,Rp;
  Ri=1.47;
  Rp=0.71;
  dx=abs(przesr[0]-dronsr[0]);
  dy=abs(przesr[1]-dronsr[1]);
  dz=abs(przesr[2]-dronsr[2]);
  odl=dx*dx+dy*dy+dz*dz;
  odl=sqrt(odl);
  if(odl<(Ri+Rp+0.6))
  {
    cout<<"kolizja z pudelkiem"<<endl;
    return true;
  }

  else
    return false;
}
