/*Copyright 2019 by Victoria Condos */
#ifndef _CSCE240_HW5_INC_POINT_H_ // NOLINT
#define _CSCE240_HW5_INC_POINT_H_ // NOLINT

#include <algorithm>
#include <cassert>
// using assert
#include <cmath>
// using fabs
#include <cstddef>
// using size_t


class Point {
  /* Used for white-box testing.
   */
  friend class PointInspector;

 public:
  /* Calculates a bounding box for the stored points and stores in the two
   * output paramters.
   *  - PRECONDITION:
   *    - all elements in the points array have the same number of dimensions
   *    - lower_left and upper_right output params have same number of
   *        dimentions as an element of points array
   *  - PARAMETERS
   *    - points: array of Point elements around which a bounding box is
   *        calculated
   *    - lower_left: output parameter to store the lower left point of a
   *        bounding-box containing all the points in the array
   *    - upper_right: output parameter to store the upper right point of a
   *        bounding-box containing all the points in the array
   *  - POSTCONDITION: the lower_left and upper_right store the lower left and
   *      upper right points of a bounding box containing all elements of the
   *      input array points.
   */
  static void CalcBoundingBox(
    const Point* points,
    size_t size,
    Point* lower_left,
    Point* upper_right);

  /* Initialization Constructors: create a point from the provided coordinates
   */
  Point();
  Point(double x, double y);
  Point(double x, double y, double z);
  Point(const double coordinates[], size_t dimensions);
  /* Copy Constructor: implements a deep copy */
  Point(const Point& that);

  /* Destructor: deletes any allocated memory
   */
  ~Point();


  /* Assignment Operator: implements a deep copy
   */
  Point & operator=(const Point& rhs);

  /*
  Point p1 = p2; // copy constructor
  p1 = p2; // assignment operator
  */

  /* Accessor/Mutator Operator: provides access to private member
   * - PRECONDITIONS: parameter dimension is a valid axis of the point
   * - RETURNS: reference to one of the coordinates of the point
   */
  double &operator[](size_t dimension);

  /* Equality Operator: defines points equal when the difference between
   * axes is no more than kMax_point_diff.
   * - PRECONDITIONS: points' dimensions are equal
   */
  bool operator==(const Point& rhs) const;

 private:
  static double kMax_diff;  // floating point equality

  double *coordinates_;
  size_t dimensions_;
};
#endif //NOLINT
