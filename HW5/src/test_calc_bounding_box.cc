/* Copyright 2019 Jeremy S Lewis CSCE240 */

#include <test_point.h>

int main(int argc, char **argv) {
  PointInspector pi;
  if (pi.TestCalcBoundingBox())
    return 0;
  return 1;
}


bool PointInspector::TestCalcBoundingBox() {
  cout << "Testing Point::CalcBoundingBox: ";
  const double kPoint_array[][2] = { {2.0, 0.1}, {3.0, 0.5}, {1.0, 0.0} };

  Point *points = new Point[3];
  for (size_t i = 0; i < 3; ++i) {
    points[i].coordinates_ = new double[2];
    points[i].dimensions_ = 2;
    points[i][0] = kPoint_array[i][0];
    points[i][1] = kPoint_array[i][1];
  }

  Point ll, ur;
  ll.coordinates_ = new double[2];
  ll.dimensions_ = 2;
  ur.coordinates_ = new double[2];
  ur.dimensions_ = 2;

  Point::CalcBoundingBox(points, 3, &ll, &ur);
  if (ll.coordinates_[0] != 1.0 || ll.coordinates_[1] != 0.0
      || ur.coordinates_[0] != 3.0 || ur.coordinates_[1] != 0.5) {
    cout << "FAILED" << endl;
    return false;
  }

  cout << "PASSED" << endl;
  return true;
}
