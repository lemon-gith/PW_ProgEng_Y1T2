// this program will not compile
#include <iostream>
#include <cmath>
#include <string>

struct Point{
  double x;
  double y;

  Point(double ix, double iy) {
    x = ix;
    y = iy;
  }

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
  // compiler error because
  // the default constructor with no parameters
  // isn't available

  std::cout << p1.to_s() << std::endl;
  std::cout << p2.to_s() << std::endl;
}