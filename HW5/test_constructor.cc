/* Copyright 2019 Jeremy S Lewis CSCE240 */

#include <test_point.h>

int main(int argc, char *argv[]) {
  PointInspector pi;

  if (!pi.TestPoint2DConstructor()
      || !pi.TestPoint3DConstructor()
      || !pi.TestPointNDConstructor()
      || !pi.TestCopyConstructor())
    return 1;
  return 0;
}

/* Two-Dimension constructor
 *
 * Basic test calls constructor and examines the private data store and
 * dimensions of the new class using the.
 */
bool PointInspector::TestPoint2DConstructor() {
  cout << "Testing Point::Point(double, double): ";
  Point p(2.0, 3.0);
  if (p.coordinates_[0] != 2.0 || p.coordinates_[1] != 3.0
      || p.dimensions_ != 2) {
    cout << "FAILED" << endl;
    return false;
  }
  cout << "PASSED" << endl;
  return true;
}

/* Three-Dimension constructor
 *
 * Basic test calls constructor and examines the private data store and
 * dimensions of the new class using the.
 */
bool PointInspector::TestPoint3DConstructor() {
  cout << "Testing Point::Point(double, double, double): ";
  Point p(2.0, 3.0, 1.0);
  if (p.coordinates_[0] != 2.0 || p.coordinates_[1] != 3.0
      || p.coordinates_[2] != 1.0 || p.dimensions_ != 3) {
    cout << "FAILED" << endl;
    return false;
  }
  cout << "PASSED" << endl;
  return true;
}

/* Any-Dimension constructor
 *
 * Basic test calls constructor to create a 4D point and examines the private
 * data store and dimensions of the new class using the.
 */
bool PointInspector::TestPointNDConstructor() {
  cout << "Testing Point::Point(const double[], size_t): ";
  const double array[] = { 2.0, 3.0, 1.0, 4.0 };
  size_t size = 4;
  Point p(array, size);
  if (p.coordinates_[0] != 2.0 || p.coordinates_[1] != 3.0
      || p.coordinates_[2] != 1.0 || p.coordinates_[3] != 4.0
      || p.dimensions_ != 4) {
    cout << "FAILED" << endl;
    return false;
  }
  cout << "PASSED" << endl;
  return true;
}

/* Copy constructor
 *
 * Basic test calls constructor to create a 4D point and examines the private
 * data store and dimensions of the new class using the.
 */
bool PointInspector::TestCopyConstructor() {
  cout << "Testing Point::Point(const Point&): ";
  Point from;
  const size_t kSize = 4;
  from.coordinates_ = new double[kSize];
  from.coordinates_[0] = 2.0;
  from.coordinates_[1] = 3.0;
  from.coordinates_[2] = 1.0;
  from.coordinates_[3] = 4.0;
  from.dimensions_ = kSize;

  Point to = from; // testing copy constructor, if shallow copy causes error
  delete [] from.coordinates_;
  from.coordinates_ = nullptr;
  from.dimensions_ = 0;

  if (to.coordinates_[0] != 2.0 || to.coordinates_[1] != 3.0
      || to.coordinates_[2] != 1.0 || to.coordinates_[3] != 4.0
      || to.dimensions_ != kSize) {
    cout << "FAILED" << endl;
    return false;
  }

  cout << "PASSED" << endl;
  return true;
} // from falls out of scope at this point and disappears
