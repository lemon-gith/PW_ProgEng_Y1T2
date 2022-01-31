#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
 
struct Point{
    double x;
    double y;
};
 
double distance_points(Point p1, Point p2){
    return std::sqrt(std::pow((p1.x - p2.x), 2) + std::pow((p1.y - p2.y), 2));
}
 
std::string point_to_s(Point p){
    return "(" + std::to_string(p.x) + ", " + std::to_string(p.y) + ")";
}
 
void closest_points(const std::vector<Point>& vp, int& idxp1, int& idxp2){
  double min_dist = distance_points(vp[0], vp[1]), cur_dist;
  int match_count = false;
  for (int i = 0; i < vp.size(); i++){
    for (int j = i + 1; j < vp.size(); j++){
      cur_dist = distance_points(vp[i], vp[j]);
      if (cur_dist == 0){
        continue;
      }
      else if (cur_dist < min_dist){
        min_dist = cur_dist;
        idxp1 = i;
        idxp2 = j;
      }
      else if (cur_dist == min_dist){
        if (!match_count){
          match_count = true;
        }
        else{
          std::cout << "we may have a tie from: " << "\t" << "i =  " << i << ", j = " << j << std::endl;
        }
      }
    }
  }
}
/*
int main(){
  std::ifstream infile;
  infile.open("8.1-struct/points.txt");

  if (!infile.is_open()){
    std::cout << "ERROR OPENING FILE, GRRRR :p" << std::endl;
    return EXIT_FAILURE;
  }

  std::vector<Point> points;
  Point tmp;

  while (infile >> tmp.x >> tmp.y){
    points.push_back(tmp);
  }

  infile.close();


  if(points.size() == 0){
    std::cout << "there are no points in the file" << std::endl;
  }
  else if(points.size() == 1){
    std::cout << "there is only one point in the file" << std::endl;
  }
  else{
    int idxp1, idxp2;
    closest_points(points, idxp1, idxp2);
    
    std::cout << "The two closest points are: " << std::endl;
    std::cout << point_to_s(points[idxp1]) << " & " << point_to_s(points[idxp2]) << " :)" << std::endl;
  }
}*/