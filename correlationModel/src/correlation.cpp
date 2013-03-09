#include "correlation.h"
#include "util.h"
#include <iostream>
#include <cmath>

/* @brief    calculation of correlation
 * @param    
 * @retval   
 */
using namespace std;


double spatialCorrelation(Camera a, Camera b)
{
  double rho, delta;

  
  /*  
  delta = (
      abs((-1*a.get_d()*sin(a.get_theta())-a.get_r()*cos(a.get_theta()))/(a.get_d()+cos(a.get_theta()))-
        (-1*b.get_d()*sin(b.get_theta())-b.get_r()*cos(b.get_theta()))/(b.get_d()+cos(b.get_theta())))
      +abs((a.get_d()*sin(a.get_theta())+a.get_r()*cos(a.get_theta()))/(a.get_d()-cos(a.get_theta()))-
        (b.get_d()*sin(b.get_theta())+b.get_r()*cos(b.get_theta()))/(b.get_d()-cos(b.get_theta())))
      +abs((a.get_d()*cos(a.get_theta())-a.get_r()*sin(a.get_theta()))/(a.get_d()+sin(a.get_theta()))-
        (b.get_d()*cos(b.get_theta())-b.get_r()*sin(b.get_theta()))/(b.get_d()+sin(b.get_theta())))
      +abs((-1*a.get_d()*cos(a.get_theta())+a.get_r()*sin(a.get_theta()))/(a.get_d()-sin(a.get_theta()))-
        (-1*b.get_d()*cos(b.get_theta())+b.get_r()*sin(b.get_theta()))/(b.get_d()-sin(b.get_theta())))
      )/4;
  */
  //cout << "D: " << a.get_d() << " Theta: " << a.get_theta() << " r: " << a.get_r() << endl;
  cout << "D: " << b.get_d() << " Theta: " << b.get_theta() << " r: " << b.get_r() << endl;
  /*
  delta = (
      abs((-1*a.get_d()*sin(a.get_theta())-a.get_r()*cos(a.get_theta()))/(a.get_d()+cos(a.get_theta()))-
        (-1*b.get_d()*sin(b.get_theta())-b.get_r()*cos(b.get_theta()))/(b.get_d()+cos(b.get_theta())))
      +abs((a.get_d()*sin(a.get_theta())+a.get_r()*cos(a.get_theta()))/(a.get_d()-cos(a.get_theta()))-
        (b.get_d()*sin(b.get_theta())+b.get_r()*cos(b.get_theta()))/(b.get_d()-cos(b.get_theta())))
      +abs((a.get_d()*cos(a.get_theta())-a.get_r()*sin(a.get_theta()))/(a.get_d()+sin(a.get_theta()))-
        (b.get_d()*cos(b.get_theta())-b.get_r()*sin(b.get_theta()))/(b.get_d()+sin(b.get_theta())))
      +abs((-1*a.get_d()*cos(a.get_theta())+a.get_r()*sin(a.get_theta()))/(a.get_d()-sin(a.get_theta()))-
        (-1*b.get_d()*cos(b.get_theta())+b.get_r()*sin(b.get_theta()))/(b.get_d()-sin(b.get_theta())))
      )/4;
  */
  double aD, aTheta, aR, bD, bTheta, bR;
  aD = a.get_d();
  aTheta = a.get_theta();
  aR = a.get_r();

  bD = b.get_d();
  bTheta = b.get_theta();
  bR = b.get_r();
  delta =  disparity( aD, aTheta, aR, bD, bTheta, bR);

  rho = (2/(1+pow(b.get_d()/a.get_d(),2.0)))*(1-delta);
  return rho;
}



