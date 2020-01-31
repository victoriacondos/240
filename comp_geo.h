/* Copyright 2019 by Victoria Condos
 */
#ifndef _ACCT_VCONDOS_CSCE240_hw2_geo_comp_h_ // NOLINT
#define _ACCT_VCONDOS_CSCE240_hw2_geo_comp_h_ // NOLINT

#include <math.h>
#include <iostream>

// using std::cout;
// using std::endl;

const double k_pi = 3.141592653589793;  // used for circle calculations

// Do NOT change names of functions

/* CalcCircumference
 * Function: Calculates and returns the circumference of a circle described by a
 *   point at the circle's center and a point on the circle's boundary.
 *
 * Precondition(s): The distance between center point and boundary point is
 *   greater than 0.
 *   Both points are finite and defined.
 */
double CalcCircumference(double centerX, double centerY, double boundaryX,
double boundaryY);

/* CalcCircleArea
 * Function: Calculates and returns the area of a circle described by a
 * point at the circle's center and a point on the circle's boundary.
 *
 * Precondition(s): The distance between center point and boundary point is
 *   greater than 0.
 *   Both points are finite and defined.
 */
double CalcCircleArea(double centerX, double centerY, double boundaryX,
double boundaryY);

/* CalcPerimeter
 * Function: Calculates and returns the perimenter of a rectangle described by a
 *   point at the lower left vertex of the rectangle and a point at the upper
 *   right.
 *
 * Precondition(s): The distance between the lower left point and upper right is
 *   greater than 0.
 *   Both points are finite and defined.
 */
double CalcPerimeter(double lowLeftX, double lowLeftY, double topRightX,
double topRightY);


/* CalcRectangleArea
 * Function: Calculates and returns the area of a rectangle described by a point
 *   at the lower left vertex of the rectangle and a point at the upper
 *   right.
 *
 * Precondition(s): The distance between the lower left point and upper right is
 *   greater than 0.
 *   Both points are finite and defined.
 */
double CalcRectangleArea(double lowLeftX, double lowLeftY, double topRightX,
double topRightY);

/* CalcDistanceSquared
 * Function: Calculates the squared distance between two points, using the
 *   Euclidean distance equation but without the final square root calculation.
 *
 * Precondition: Both points are finite and defined.
 */
double CalcDistanceSquared(double firstX, double firstY, double secondX,
double secondY);

/* CalcDistance
 * Function: Calculates the squared distance between two points,
 * using the Euclidean distance calculation.
 *
 * Precondition: Both points are finite and defined.
 */
double CalcDistance(double firstX, double firstY, double secondX,
double secondY);

#endif //  NOLINT
