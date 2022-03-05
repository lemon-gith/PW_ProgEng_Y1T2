#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

struct Point{
  double x;
  double y;

  std::string to_s() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
  }

  double distance(Point p) const {
    return std::sqrt(std::pow((x - p.x), 2) + std::pow((y - p.y), 2));
  }
};

void closest_points(const std::vector<Point>& vp, int& idxp1, int& idxp2){
  double min_dist = vp[0].distance(vp[1]);
  idxp1 = 0;
  idxp2 = 1;

  for (int i = 0; i < vp.size(); i++){
    for (int j = i + 1; j < vp.size(); j++) {
      if ((i == 0) && (j == 1)){
        continue;
      }

      double cur_dist = vp[i].distance(vp[j]);

      if (cur_dist < min_dist) {
        min_dist = cur_dist;
        idxp1 = i;
        idxp2 = j;
      }
      else if (cur_dist == min_dist) {
        std::cout << "There are multiple points of equal distance, the foremost shall be maintained" << std::endl;
      }
    }
  }
}


/*int main(){

  std::ifstream infile;
  infile.open("11.1-member_func/points.txt");

  if(!infile.is_open()){
    std::cout << "error opening file" << std::endl;
    return EXIT_FAILURE;
  }

  std::vector <Point> points;
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

    tmp = points[idxp1];
    std::cout << tmp.to_s() << std::endl;
    tmp = points[idxp2];
    std::cout << tmp.to_s() << std::endl;
  }
}*/
