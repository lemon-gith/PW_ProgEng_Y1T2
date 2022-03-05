#include <iostream>
#include <cmath>
#include <string>

struct Point{
  double x;
  double y;

  Point(double ix, double iy){
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

/*int main(){
  Point p(1, -1);
  std::cout << p.to_s() << std::endl;
}*/