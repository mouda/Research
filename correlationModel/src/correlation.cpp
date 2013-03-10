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

/* @brief    To calculate the joint entropy by given the correlation coeff
 * @param    hA, hB is the entropy of two cameras, rho is correlation coeff
 * @retval   Joint Entropy if the parms is legal, -1 if illegal
 */

double jointEntropy(double hA, double hB, double rho)
{
  if ( hA < 0 || hB < 0 ) return -1;
  return ( 1 - rho/2 ) * ( hA + hB );
}

/* @brief    To caluculate coding efficiency of two views
 * @param    hA, hB is the entropy of two cameras
 * @retval   Eta is the codign efficiency
 */

double etaOfTwoViews(double hA, double hB, double rho)
{
  if ( hA < 0 || hB < 0 ) return -1;
  return 1-jointEntropy( hA, hB, rho)/(hA+hB);
}



