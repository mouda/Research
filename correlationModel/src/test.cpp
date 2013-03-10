#include <iostream>
#include <cmath>
#include "camera.h"
#include "correlation.h"

#define PI 3.14159265

using namespace std;

int main(int argc, char *argv[]) {

  /* Camera deployment configuration */

  /* f number calculation */
  double f_value = 50/0.1;

  /* construct the Camera */
  Camera a(2.5, 0*PI/180, f_value, 0);
  Camera b(10.0, 0*PI/180, f_value, 0);
  cout << "rho:         " << spatialCorrelation(a,b) << endl;
  cout << "Joint:       " << jointEntropy(3,3,spatialCorrelation(a,b)) << endl; 
  cout << "Independent: " << 3+3 << endl;
  cout << "Efficiency:  " << etaOfTwoViews(3,3,spatialCorrelation(a,b)) << endl;
  /*  
  cout << a.get_theta() << endl;
  cout << a.get_d() << endl;
  cout << a.get_f() << endl;
  cout << b.get_theta() << endl;
  cout << b.get_d() << endl;
  cout << b.get_f() << endl;
  */
    
  /*    
  for (double i = -90; i < 90; i++) {
    b.set_theta(i*PI/180);
    cout << spatialCorrelation(a,b) << endl;
  }
  */
  /*
  for (double i = 2.5; i < 50; i++) {
    b.set_d(i);
    cout << spatialCorrelation(a,b) << endl;
  }
  */
  return 0;
}
