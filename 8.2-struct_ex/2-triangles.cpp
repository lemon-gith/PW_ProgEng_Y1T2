#include <iostream>
#include <cmath>
#include <string>
#include <4-closest_pnt.hpp>

struct Triangle{
  Point p1, p2, p3;
};

double triangle_perimeter(Triangle tri){
  return (distance_points(tri.p1, tri.p2) + distance_points(tri.p2, tri.p3)
  + distance_points(tri.p3, tri.p1));
}

int main(){
  
}

