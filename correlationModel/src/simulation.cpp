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

  /* construct the camera */

  vector<CameraPos> cameras;
  for ( int i = 0; i < D_xPositions.size(); i++) {
    Position p(D_xPositions[i],D_yPositions[i]);
    CameraPos c(p,D_directions[i],f_value);
    cameras.push_back(c);
  } 

  Position originPoint(0,0);
  /* Testing the correlation coefficient */
  for ( int i = 0; i < 99; i++) {
    cout << cameras[i].corrCoeff(cameras[i+1],originPoint) << endl;
  }

  /*
  Position posTest_1;
  posTest_1.x=2.5;
  posTest_1.y=0;
  CameraPos cameraTest_1(posTest_1,PI,f_value);

  Position posTest_2;
  posTest_2.x=2.5;
  posTest_2.y=0;
  CameraPos cameraTest_2(posTest_2,PI,f_value);

  Position targetPos;
  targetPos.x=0;
  targetPos.y=0;


  
  for (double i = -90; i < 90; i++) {
    double length = 2.5;
    posTest_2.x = length*cos(i*PI/180);
    posTest_2.y = length*sin(i*PI/180);
    cameraTest_2.set_position(posTest_2);
    cameraTest_2.set_direction(i*PI/180+PI); //To inverse the direction
    cout << cameraTest_2.corrCoeff(cameraTest_1,targetPos) << endl;
  }*/

  return 0;
}
