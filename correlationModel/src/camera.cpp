#include "camera.h"
#include "util.h"
#include <iostream>
#include <cmath>

/* @brief   To calculate the correlation with another camera 
 * @param   CameraPos another camera
 *          Position interest area 
 * @retval  the correlation coefficient 
 */

#define PI 3.14159265


using namespace std;

double CameraPos::corrCoeff( CameraPos neighbor, Position area ){

  /*  To calculate the neighbor camera parameter */
  Position nPos = neighbor.get_position();
  double L_prime;      //straightDistance
  double theta_prime;   //argumentAngle
  double r_prime;       //shift
  double D_prime;             //Direction distance
  L_prime = sqrt(pow(nPos.x-area.x,2)+pow(nPos.y-area.y,2));
  theta_prime = atan((nPos.y-area.y)/(nPos.x-area.x));
  D_prime = abs(L_prime*cos(abs(theta_prime-neighbor.get_direction())));
  r_prime = abs(L_prime*sin(abs(theta_prime-neighbor.get_direction())));

  /* To calculate self camera parameter */
  Position sPos = this->get_position();
  double L;
  double theta;
  double r;
  double D;
  L = sqrt(pow(sPos.x-area.x,2)+pow(sPos.y-area.y,2));
  theta = atan((sPos.y-area.y)/(sPos.x-area.x));
  D = abs(L*cos(abs(theta_prime-neighbor.get_direction())));
  r = abs(L*sin(abs(theta_prime-neighbor.get_direction())));


  double rho, delta;
  double nDir = neighbor.get_direction();
  double sDir = this->get_direction();
  /*
  delta = (

      abs((-1*D*sin(sDir) - r*cos(sDir)) / (D + cos( sDir ))-
        (-1*D_prime*sin(nDir)-r_prime*cos(nDir)) / (D_prime+cos(nDir)))
      +
      abs((   D*sin(sDir) + r*cos(sDir)) / ( D - cos(sDir) )-
        (   D_prime*sin(nDir)+r_prime*cos(nDir)) / (D_prime-cos(nDir)))
      +
      abs((   D*cos(sDir) - r*sin(sDir)) / ( D + sin(sDir) )-
        (   D_prime*cos(nDir)-r_prime*sin(nDir)) / (D_prime+sin(nDir)))
      +
      abs((-1*D*cos(sDir) + r*sin(sDir)) / ( D - sin(sDir) )-
        (-1*D_prime*cos(nDir)+r_prime*sin(nDir)) / (D_prime-sin(nDir)))

      )/4;

  rho = 1-delta;
  */
  
  delta = disparity(D, sDir+PI, r, D_prime, nDir+PI, r_prime);
  
  if ( D_prime/D >= 1.0 ) {
    rho = (2/(1+pow(D_prime/D,2.0)))*(1-delta);
  } else {
    rho = (2/(1+pow(D/D_prime,2.0)))*(1-delta);
  }
  

  return rho;
}
