/* Copyright 2019 Jeremy S Lewis CSCE240 */

#include <test_point.h>

int main(int argc, char *argv[]) {
  PointInspector pi;

  if (!pi.TestBracketOp())
    return 1;
  return 0;
}

bool PointInspector::TestBracketOp() {
  cout << "Testing Point::operator[](size_t): ";
  Point to(2.0, 3.0, 1.0);

  to[0] = 1.7;

  if (to.coordinates_[0] != 1.7 || to[1] != 3.0
      || to[2] != 1.0 || to.dimensions_ != 3) {
    cout << "FAILED" << endl;
    return false;
  }

  delete [] to.coordinates_;
  to.coordinates_ = nullptr;
  to.dimensions_ = 0;

  cout << "PASSED" << endl;
  return true;
}
