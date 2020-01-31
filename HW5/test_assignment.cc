/* Copyright 2019 Jeremy S Lewis CSCE240 */

#include <test_point.h>

int main(int argc, char *argv[]) {
  PointInspector pi;

  if (!pi.TestAssignmentOp())
    return 1;
  return 0;
}

bool PointInspector::TestAssignmentOp() {
  cout << "Testing Point::operator=(const Point&): ";
  const size_t kSize = 4;
  Point to[2], from; // see note in tips-- array of size 2
  from.coordinates_ = new double[kSize];
  from.coordinates_[0] = 2.0;
  from.coordinates_[1] = 3.0;
  from.coordinates_[2] = 1.0;
  from.coordinates_[3] = 4.0;
  from.dimensions_ = kSize;

  to[0] = to[1] = from;
  from.coordinates_[0] = 2.1;
  from.coordinates_[1] = 3.1;
  from.coordinates_[2] = 1.1;
  from.coordinates_[3] = 4.1;

  if (to[1].coordinates_[0] != 2.0 || to[1].coordinates_[1] != 3.0
      || to[1].coordinates_[2] != 1.0 || to[1].coordinates_[3] != 4.0
      || to[1].dimensions_ != kSize) {
    cout << "FAILED" << endl;
    return false;
  }
  delete [] to[1].coordinates_;
  to[1].coordinates_ = nullptr;
  to[1].dimensions_ = 0;

  if (to[0].coordinates_[0] != 2.0 || to[0].coordinates_[1] != 3.0
      || to[0].coordinates_[2] != 1.0 || to[0].coordinates_[3] != 4.0
      || to[0].dimensions_ != kSize) {
    cout << "FAILED" << endl;
    return false;
  }

  cout << "PASSED" << endl;
  return true;
}
