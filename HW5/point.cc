/* Copyright 2019 by Victoria Condos */
#include <point.h>

double Point::kMax_diff = 0.000001;

void Point::CalcBoundingBox(const Point* points,
  size_t size, Point* lower_left, Point* upper_right) {
  for (size_t i = 0; i < points[0].dimensions_; ++i) {
    upper_right->coordinates_[i] = points[0].coordinates_[i];
    lower_left->coordinates_[i] = points[0].coordinates_[i];
  }

  for (size_t i = 1; i < size; ++i) {
    for (size_t j = 0; j < points[0].dimensions_; ++j) {
      //  check upper right
      //  if points[i].coordinates_[j] is bigger, set as new biggest for u.r.
      if (points[i].coordinates_[j] > upper_right->coordinates_[j]) {
        upper_right->coordinates_[j] = points[i].coordinates_[j];
      }
      // check lower left
      // if points[i].coordinates_[j] is smaller, set as new smallest for l.l.
      if (points[i].coordinates_[j] < lower_left->coordinates_[j]) {
        lower_left->coordinates_[j] = points[i].coordinates_[j];
      }
    }
  }
}

// initialization constructors: create a point with provided coordinates
Point::Point() {  // default is a 0-D point
  coordinates_ = nullptr;
  dimensions_ = 0;
}

Point::Point(double x, double y) {  // two dimensions
  dimensions_ = 2;
  coordinates_ = new double[dimensions_];
  coordinates_[0] = x, coordinates_[1] = y;  // set correct values
}

Point::Point(double x, double y, double z) {  // three dimensions
  dimensions_ = 3;
  coordinates_ = new double[dimensions_];
  coordinates_[0] = x, coordinates_[1] = y, coordinates_[2] = z;  // set values
}

Point::Point(const double coordinates[], size_t dimensions) {
  // any amount of dimensions
  dimensions_ = dimensions;
  if (dimensions == 0) {
    coordinates_ = nullptr;
    return;
  }
  // if makes it here, not 0-D
  coordinates_ = new double[dimensions_];
  for (size_t i = 0; i < dimensions_; ++i) {
    // assign value from array to corresponding dimension.
    coordinates_[i] = coordinates[i];
  }
}

// copy constructor
Point::Point(const Point& that)
    : coordinates_(nullptr), dimensions_(that.dimensions_) {
  if (dimensions_ == 0)
    return;
  coordinates_ = new double[dimensions_];  // should this be size_t??
  for (size_t i = 0; i < dimensions_; ++i)
    *(coordinates_ + i) = *(that.coordinates_ + i);
}

// destructor: deletes any allocated memory
Point::~Point() {
  if (coordinates_) {
    delete [] coordinates_;
    coordinates_ = nullptr;
  }
}

// assignment operator: implements a deep copy
Point & Point::operator=(const Point& rhs) {
  if (this == &rhs) {  // same address
    return *this;
  }
  // delete existing if memory is already allocated
  // ~Point();
  if (coordinates_) {
    delete [] coordinates_;
    coordinates_ = nullptr;
  }
  dimensions_ = rhs.dimensions_;
  coordinates_ = new double[dimensions_];
  for (size_t i = 0; i < dimensions_; ++i) {
    *(coordinates_ + i) = *(rhs.coordinates_ + i);
  }
  return *this;
}

double &Point::operator[](size_t dimension) {
  return coordinates_[dimension];
}

bool Point::operator==(const Point& rhs) const {
  double difference;
  for (size_t i = 0; i < dimensions_; ++i) {
    difference = fabs(coordinates_[i] - rhs.coordinates_[i]);
    if (difference > Point::kMax_diff) {
      return false;
    }
  }
  return true;
}






