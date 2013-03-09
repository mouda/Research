#include "util.h"
#include <cmath>
using namespace std;
double disparity( double aD, double aTheta, double aR, double bD, double bTheta, double bR) {
  double delta = (
      abs((-1* aD *sin( aTheta )- aR *cos( aTheta ))/( aD +cos( aTheta ))-
        (-1* bD *sin( bTheta )- bR *cos( bTheta ))/( bD +cos( bTheta )))
      +abs(( aD *sin( aTheta )+ aR *cos( aTheta ))/( aD -cos( aTheta ))-
        ( bD *sin( bTheta )+ bR *cos( bTheta ))/( bD -cos( bTheta )))
      +abs(( aD *cos( aTheta )- aR *sin( aTheta ))/( aD +sin( aTheta ))-
        ( bD *cos( bTheta )- bR *sin( bTheta ))/( bD +sin( bTheta )))
      +abs((-1* aD *cos( aTheta )+ aR *sin( aTheta ))/( aD -sin( aTheta ))-
        (-1* bD *cos( bTheta )+ bR *sin( bTheta ))/( bD -sin( bTheta )))
      )/4;
  return delta;
}
