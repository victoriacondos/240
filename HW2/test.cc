/* Copyright 2019 CSCE 240 */
#include <cmath>
// using fabs
// using fmin
#include <iostream>
using std::cout;
using std::endl;
#include <limits>
using std::numeric_limits;

#include "comp_geo.h"  // NOLINT
#include "comp_geo.h"  // NOLINT

bool TestCalcCircumference();
bool TestCalcCircleArea();
bool TestCalcPerimeter();
bool TestCalcRectangleArea();
bool TestCalcDistanceSquared();
bool TestCalcDistance();

int main(int argc, char* argv[]) {
  const int k_idx = 1;  // test number parameter index
  int test = argc == 2 ? atoi(argv[k_idx]) : -1;

  switch (test) {
  case 0:
    cout << "TestCalcCircumference" << endl;
    if (TestCalcCircumference()) {
      cout << "  PASSED" << endl;
      break;
    } else {
      cout << "  FAILED" << endl;
      return 1;
    }

  case 1:
    cout << "TestCalcCircleArea" << endl;
    if (TestCalcCircleArea()) {
      cout << "  PASSED" << endl;
      break;
    } else {
      cout << "  FAILED" << endl;
      return 1;
    }

  case 2:
    cout << "TestCalcPerimeter" << endl;
    if (TestCalcPerimeter()) {
      cout << "  PASSED" << endl;
      break;
    } else {
      cout << "  FAILED" << endl;
      return 1;
    }

  case 3:
    cout << "TestRectangleArea" << endl;
    if (TestCalcRectangleArea()) {
      cout << "  PASSED" << endl;
      break;
    } else {
      cout << "  FAILED" << endl;
      return 1;
    }

  case 4:
    cout << "TestCalcDistanceSquared" << endl;
    if (TestCalcDistanceSquared()) {
      cout << "  PASSED" << endl;
      break;
    } else {
      cout << "  FAILED" << endl;
      return 1;
    }

  case 5:
    cout << "TestCalcDistance" << endl;
    if (TestCalcDistance()) {
      cout << "  PASSED" << endl;
      break;
    } else {
      cout << "  FAILED" << endl;
      return 1;
    }

  default:
    cout << "Compiled and executed" << endl;
  }

  return 0;
}

bool fpeq(double a, double b, double epsilon = 0.000001);

bool TestCalcCircumference() {
  const double expected = 62.831853072;
  double actual = CalcCircumference(0.0, 0.0, 10.0, 0.0);

  if (!fpeq(expected, actual)) {
    cout << "Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}

bool TestCalcCircleArea() {
  const double expected = 314.159265359;
  double actual = CalcCircleArea(0.0, 0.0, 10.0, 0.0);

  if (!fpeq(expected, actual)) {
    cout << "Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}

bool TestCalcPerimeter() {
  const double expected = 30.0;
  double actual = CalcPerimeter(-5.0, -2.5, 5.0, 2.5);

  if (!fpeq(expected, actual)) {
    cout << "Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}

bool TestCalcRectangleArea() {
  const double expected = 50.0;
  double actual = CalcRectangleArea(-5.0, -2.5, 5.0, 2.5);

  if (!fpeq(expected, actual)) {
    cout << "Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}

bool TestCalcDistanceSquared() {
  const double expected = 2500.0;
  double actual = CalcDistanceSquared(-15.0, -20, 15.0, 20.0);

  if (!fpeq(expected, actual)) {
    cout << "Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}

bool TestCalcDistance() {
  const double expected = 50.0;
  double actual = CalcDistance(-15.0, -20, 15.0, 20.0);

  if (!fpeq(expected, actual)) {
    cout << "Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}

bool fpeq(double a, double b, double epsilon) {
  if (a == b)  // trivially true
    return true;

  double abs_a = fabs(a);
  double abs_b = fabs(b);
  double diff = fabs(a - b);

  if (a == 0 || b == 0 || (abs_a + abs_b < numeric_limits<double>::min())) {
    // when a or b is zero or both are extremely close to zero
    // relative error is less meaningful
    return diff < (epsilon * numeric_limits<double>::min());
  } else {  // use relative error
    return diff / fmin((abs_a + abs_b), numeric_limits<double>::max())
        < epsilon;
  }
}

