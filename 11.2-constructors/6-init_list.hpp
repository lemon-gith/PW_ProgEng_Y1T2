#include <iostream>
#include <cmath>
#include <string>

struct Point{
  double x;
  double y;

  // constructor with initializer list
  Point() : x(0), y(0) {
    // the body of the constructor is empty, this is normal
  }

  // constructor with initializer list
  Point(double ix, double iy) : x(ix), y(iy) {
    // the body of the constructor is empty, this is normal
  }

  Point (double val) : x(val), y(0) {}

  std::string to_s() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
  }

  double distance(Point p) const {
    return std::sqrt(std::pow((x - p.x), 2) + std::pow((y - p.y), 2));
  }
};

int main(){
  Point p1(2, -0.5);
  Point p2;
  Point p3(3);
  std::cout << p1.to_s() << std::endl;
  std::cout << p2.to_s() << std::endl;
  std::cout << p3.to_s() << std::endl;
}