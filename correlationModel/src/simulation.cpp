#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include "camera.h"
#include "correlation.h"

#define PI 3.14159265

using namespace std;

int main(int argc, char *argv[]) {

  /* camera deployment configuration */
  /* read the map file */
  fstream inputFile;
  inputFile.open("map.out");
  
  string line;
  stringstream ss;
  double tmp;
  vector<double> D_xPositions;
  vector<double> D_yPositions;
  vector<double> D_directions;
  
  while(!inputFile.eof()) {
    getline(inputFile,line);
    if(line.size() == 0) break;
    ss << line;
    ss >> tmp;
    D_xPositions.push_back(tmp);

    ss >> tmp;
    D_yPositions.push_back(tmp);

    ss >> tmp;
    D_directions.push_back(tmp);
    ss.clear();
  }

  /* f number calculation */
  double f_value = 50/0.1;;

  Position posTest_1;
  posTest_1.x=50;
  posTest_1.y=0;
  CameraPos cameraTest_1(posTest_1,PI,f_value);

  Position posTest_2;
  posTest_2.x=2.5;
  posTest_2.y=0;
  CameraPos cameraTest_2(posTest_2,PI,f_value);

  Position targetPos;
  targetPos.x=0;
  targetPos.y=0;
  cout << cameraTest_2.corrCoeff(cameraTest_1,targetPos) << endl;



  



  /* construct the camera */
//  camera a(2.5, 0*PI/180, f_value, 0);
//  camera b(2.5, 1*PI/180, f_value, 0);
    
  /*  
  for (double i = -100; i < 100; i++) {
    b.set_theta(i*PI/180);
    cout << spatialCorrelation(a,b) << endl;
  }
  */
  return 0;
}
