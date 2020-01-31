/* Copyright 2019 Jeremy S Lewis CSCE240 */

#include <test_point.h>

int main(int argc, char *argv[]) {
  PointInspector pi;

  if (!pi.TestEqualsOp())
    return 1;
  return 0;
}

bool PointInspector::TestEqualsOp() {
  cout << "Testing Point::operator==(const Point&): ";
  Point lhs, rhs;
  lhs.coordinates_ = new double[2];
  rhs.coordinates_ = new double[2];

  lhs.dimensions_ = 2;
  lhs.coordinates_[0] = 1.0/3.0;
  lhs.coordinates_[1] = 1.0/2.0;
  rhs.dimensions_ = 2;
  rhs.coordinates_[0] = 0.333333333;
  rhs.coordinates_[1] = 0.499999999;
  if (!(lhs == rhs)) {
    cout << "FAILED" << endl;
    return false;
  }

  lhs.dimensions_ = 2;
  lhs.coordinates_[0] = 1.0/3.0;
  lhs.coordinates_[1] = 1.0/2.0;
  rhs.dimensions_ = 2;
  rhs.coordinates_[0] = 0.33;
  rhs.coordinates_[1] = 0.49;
  if (lhs == rhs) {
    cout << "FAILED" << endl;
    return false;
  }

  cout << "PASSED" << endl;
  return true;
}
