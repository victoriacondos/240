/*
 * Copyright 2019 by Victoria Condos
 */
#include "comp_geo.h"  //NOLINT

// const double k_pi = 3.141592653589793;

double CalcCircumference(double centerX, double centerY,
double boundaryX, double boundaryY) {
  // assert(CalcDistance(centerX, centerY, boundaryX, boundaryY) > 0);
  // use CalcDistance to find radius & double for diameter
  double diameter = 2 * CalcDistance(centerX, centerY, boundaryX, boundaryY);
  double circumference = k_pi * diameter;  //  c=pi*d
  return circumference;
}

double CalcCircleArea(double centerX, double centerY, double boundaryX,
 double boundaryY) {
  //  assert(CalcDistance(centerX, centerY, boundaryX, boundaryY) > 0);
  double radius, area;  // initialize variables
  radius = CalcDistance(centerX, centerY, boundaryX, boundaryY);
  area = k_pi * pow(radius, 2);
  return area;
}

double CalcPerimeter(double lowLeftX, double lowLeftY, double topRightX,
 double topRightY) {
  //  assert(CalcDistance(lowLeftX, lowLeftY, topRightX, topRightY) > 0);
  double side1, side2, perimeter;  // initialize variables
  side1 = CalcDistance(lowLeftX, lowLeftY, lowLeftX, topRightY);
  side2 = CalcDistance(lowLeftX, lowLeftY, topRightX, lowLeftY);
  perimeter = 2 * (side1 + side2);
  return perimeter;
}

double CalcRectangleArea(double lowLeftX, double lowLeftY, double topRightX,
double topRightY) {
  double side1, side2, area;  // initialize variables
  side1 = CalcDistance(lowLeftX, lowLeftY, lowLeftX, topRightY);  //  Vertical
  side2 = CalcDistance(lowLeftX, lowLeftY, topRightX, lowLeftY);  //  Horizontal
  area = side1 * side2;
  return area;
}

double CalcDistanceSquared(double firstX, double firstY, double secondX,
 double secondY) {
  double distSquared;
  distSquared = pow(CalcDistance(firstX, firstY, secondX, secondY), 2);
  return distSquared;
}

double CalcDistance(double firstX, double firstY, double secondX,
 double secondY) {
  double distance, xDistance, yDistance;
  xDistance = secondX-firstX;
  yDistance = secondY-firstY;
  distance = sqrt(pow(xDistance, 2) + pow(yDistance, 2));
  return distance;
}
