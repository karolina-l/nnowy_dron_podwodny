#include "tafla.hh"

using namespace std;

void Tafla::rysuj_ksztalt()
{
  nazwa=gnuplot->draw_surface(vector<vector<Point3D>>{{
    drawNS::Point3D(-5,-5,5), drawNS::Point3D(-5,5,5)
      },{
    drawNS::Point3D(-4.5,-5,4.5), drawNS::Point3D(-4.5,5,4.5)
      },{
    drawNS::Point3D(-4,-5,5), drawNS::Point3D(-4,5,5)
      },{
    drawNS::Point3D(-3.5,-5,4.5), drawNS::Point3D(-3.5,5,4.5)
      },{
    drawNS::Point3D(-3,-5,5), drawNS::Point3D(-3,5,5)
      },{
    drawNS::Point3D(-2.5,-5,4.5), drawNS::Point3D(-2.5,5,4.5)
      },{
    drawNS::Point3D(-2,-5,5), drawNS::Point3D(-2,5,5)
      },{
    drawNS::Point3D(-1.5,-5,4.5), drawNS::Point3D(-1.5,5,4.5)
      },{
    drawNS::Point3D(-1,-5,5), drawNS::Point3D(-1,5,5)
      },{
    drawNS::Point3D(-0.5,-5,4.5), drawNS::Point3D(-0.5,5,4.5)
      },{
    drawNS::Point3D(-0,-5,5), drawNS::Point3D(-0,5,5)
      },{
    drawNS::Point3D(0.5,-5,4.5), drawNS::Point3D(0.5,5,4.5)
      },{
    drawNS::Point3D(1,-5,5), drawNS::Point3D(1,5,5)
      },{
    drawNS::Point3D(1.5,-5,4.5), drawNS::Point3D(1.5,5,4.5)
      },{
    drawNS::Point3D(2,-5,5), drawNS::Point3D(2,5,5)
      },{
    drawNS::Point3D(2.5,-5,4.5), drawNS::Point3D(2.5,5,4.5)
      },{
    drawNS::Point3D(3,-5,5), drawNS::Point3D(3,5,5)
      },{
    drawNS::Point3D(3.5,-5,4.5), drawNS::Point3D(3.5,5,4.5)
      },{
    drawNS::Point3D(4,-5,5), drawNS::Point3D(4,5,5)
      },{
    drawNS::Point3D(4.5,-5,4.5), drawNS::Point3D(4.5,5,4.5)
      },{
    drawNS::Point3D(5,-5,5), drawNS::Point3D(5,5,5)
      }},"grey");

      gnuplot->redraw();
}

bool Tafla::czy_kolizja(const Interfejs &i) const
{
  TWektor<double,3> sr_drona;
  sr_drona=i.zwroc_interfejs();
  if(sr_drona[2]>4.5)
  {
    cout<<"dron się wynużył"<<endl;
    return true;
  }
  else
  {
    return false;
  }

}
