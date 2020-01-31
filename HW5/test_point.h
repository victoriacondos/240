/* Copyright 2019 FALL CSCE240 002 */
#ifndef _CSCE240_HW5_INC_TEST_POINT_H_  //NOLINT
#define _CSCE240_HW5_INC_TEST_POINT_H_  //NOLINT


#include <point.h>

#include <cstddef>
// using size_t
#include <iostream>
using std::cout;
using std::endl;
#include <ostream>
using std::ostream;


/* Class to perform white-box testing of Point library/class.
 * 
 * A correct destructor is assumed for any of the tests.
 */
class PointInspector {
 public:
  /* CONSTRUCTOR TESTS
   * 
   * These methods are implemented in src/test_constructor.cc file. They allow
   * tests of only those methods.
   */
  bool TestPoint2DConstructor();
  bool TestPoint3DConstructor();
  bool TestPointNDConstructor();
  bool TestCopyConstructor();

  /* ASSIGNMENT OPERATOR TEST
   *
   * This method is implemented in src/test_assignment.cc file. This will test
   * the assignment operator alone.
   */
  bool TestAssignmentOp();

  /* BRACKET OPERATOR TEST
   *
   * This method is implemented in src/test_bracket.cc file. This will test the
   * bracket operator alone.
   */
  bool TestBracketOp();

  /* EQUALITY OPERATOR TEST
   *
   * This method is implemented in src/test_equals.cc file. This method tests
   * the equality operator alone.
   */
  bool TestEqualsOp();

  /* CALC BOUNDING BOX TEST
   *
   * This method is implemented in src/test_calc_bounding_box.cc file. This
   * method tests the method alone.
   */
  bool TestCalcBoundingBox();

  /* Used to print a Point instance using the friend-relationship. Can be used
   * for debugging purposes.
   */
  inline void PrintPoint(ostream& out, const Point& point) {
    out << "(";
    out << point.coordinates_[0];
    for (size_t i = 1; i < point.dimensions_; ++i)
      out << ", " << point.coordinates_[i];
    out << ")";
  }
};

#endif  //NOLINT
