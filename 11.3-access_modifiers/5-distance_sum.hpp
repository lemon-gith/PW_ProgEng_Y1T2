#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

class Point{

private:
  double x;
  double y;

public:

  Point(double ix, double iy) : x(ix), y(iy) {}

  std::string to_s(){
  return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
  }

  double displacement(Point p) const {
  return std::sqrt(std::pow((x - p.x), 2) + std::pow((y - p.y), 2));
  }
// note that we can access
// the private member data x and y of p
// even if it's a different object
// because it's an instance of the same class
};

double sum_distances_points(const std::vector<Point>& pv){
  double dist_sum{};
  for (int i = 0; i < pv.size() - 1; i++){
    int j = i + 1;
    dist_sum += pv[i].displacement(pv[j]);
  }
  return dist_sum;
}

int main(){
  std::ifstream infile;
  infile.open("11.3-access_modifiers/points.txt");

  if(!infile.is_open()){
    std::cout << "error opening file" << std::endl;
    return EXIT_FAILURE;
  }

  std::vector<Point> points;

  double inx, iny;

  while(infile >> inx >> iny){
    Point tmp(inx, iny);
    points.push_back(tmp);
  }

  infile.close();

  std::cout << sum_distances_points(points) << std::endl;

}