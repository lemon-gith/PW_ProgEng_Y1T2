#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

struct Point{
  double x;
  double y;

  std::string to_s(){
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
  }

  double distance(Point p){
    return std::sqrt(std::pow((x - p.x), 2) + std::pow((y - p.y), 2));
  }
};

int main(){
  std::ifstream infile;
  infile.open("11.1-member_func/points.txt");

  if(!infile.is_open()){
    std::cout << "error opening file" << std::endl;
    return EXIT_FAILURE;
  }

  std::vector<Point> points;
  Point tmp;

  while(infile >> tmp.x >> tmp.y){
    points.push_back(tmp);
  }

  infile.close();

  for (int i = 0; i < points.size(); i++){
    std::cout << points[i].to_s() << std::endl;
  }
}