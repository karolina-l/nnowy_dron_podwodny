#include "dno.hh"

using namespace std;

void Dno::rysuj_ksztalt()
{
  nazwa= gnuplot->draw_surface(vector<vector<Point3D>>{{
  	drawNS::Point3D(-5,-5,-5), drawNS::Point3D(-5,-4,-5), drawNS::Point3D(-5,-2,-5), drawNS::Point3D(-5,0,-5), drawNS::Point3D(-5,2,-5), drawNS::Point3D(-5,4,-5), drawNS::Point3D(-5,5,-5)
  	  },{
  	drawNS::Point3D(-4,-5,-5), drawNS::Point3D(-4,-4,-5), drawNS::Point3D(-4,-2,-5),  drawNS::Point3D(-4,0,-5), drawNS::Point3D(-4,2,-5), drawNS::Point3D(-4,4,-5), drawNS::Point3D(-4,5,-5)
      },{
  	drawNS::Point3D(-2,-5,-5), drawNS::Point3D(-2,-4,-5), drawNS::Point3D(-2,-2,-5), drawNS::Point3D(-2,0,-5), drawNS::Point3D(-2,2,-5), drawNS::Point3D(-2,4,-5), drawNS::Point3D(-2,5,-5)
  	  },{
  	drawNS::Point3D(-0,-5,-5), drawNS::Point3D(-0,-4,-5), drawNS::Point3D(-0,-2,-5), drawNS::Point3D(-0,0,-5), drawNS::Point3D(-0,2,-5), drawNS::Point3D(-0,4,-5), drawNS::Point3D(-0,5,-5)
  	  },{
  	drawNS::Point3D(2,-5,-5), drawNS::Point3D(2,-4,-5), drawNS::Point3D(2,-2,-5), drawNS::Point3D(2,0,-5), drawNS::Point3D(2,2,-5), drawNS::Point3D(2,4,-5), drawNS::Point3D(2,5,-5)
  	  },{
  	drawNS::Point3D(4,-5,-5), 	drawNS::Point3D(4,-4,-5), drawNS::Point3D(4,-2,-5), drawNS::Point3D(4,0,-5), 	drawNS::Point3D(4,2,-5), drawNS::Point3D(4,4,-5), drawNS::Point3D(4,5,-5)
      },{
  	drawNS::Point3D(5,-5,-5), drawNS::Point3D(5,-4,-5), drawNS::Point3D(5,-2,-5), drawNS::Point3D(5,0,-5), drawNS::Point3D(5,2,-5), drawNS::Point3D(5,4,-5), drawNS::Point3D(5,5,-5)
  	  }},"grey");//rysuje szarą powierzchnie

}

bool Dno::czy_kolizja(const Interfejs &i) const
{
  TWektor<double,3> sr_drona;
  sr_drona=i.zwroc_interfejs();
  if(sr_drona[2]<-4.45)
  {
    cout<<"dron doleciał do dna"<<endl;
    return true;
  }
  else
  {
    return false;
  }

}
