#include <iostream>
#include <cmath>
#include <4-closest_pnt.hpp>

struct Triangle{
  Point p1, p2, p3;
};

double triangle_perimeter(Triangle tri){
  return (distance_points(tri.p1, tri.p2) + distance_points(tri.p2, tri.p3)
  + distance_points(tri.p3, tri.p1));
}

double triangle_area(Triangle tri){
  double a = distance_points(tri.p1, tri.p2);
  double b = distance_points(tri.p2, tri.p3);
  double c = distance_points(tri.p3, tri.p1);
  double C = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b));
  return (0.5 * a * b * sin(C));
}

int main(){
  Triangle t1{};
  std::cout << "Please enter coordinates for t1 below: " << std::endl;
  std::cin >> t1.p1.x >> t1.p1.y >> t1.p2.x >> t1.p2.y >> t1.p3.x >> t1.p3.y;

  std::cout << "The perimeter of that triangle is: " << triangle_perimeter(t1) << std::endl;
  std::cout << "The area of that triangle is: " << triangle_area(t1) << std::endl;
}

