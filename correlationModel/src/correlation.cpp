#include "correlation.h"
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
  rho = (2/(1+pow(b.get_d()/a.get_d(),2.0)))*(1-delta);
  return rho;
}
