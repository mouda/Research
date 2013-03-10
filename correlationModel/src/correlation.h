#include "camera.h"
#include <vector>
double spatialCorrelation(Camera a, Camera b);
double jointEntropy(double hA, double hB, double rho);
double etaOfTwoViews(double hA, double hB, double rho); // calculate coding efficiency of two views
