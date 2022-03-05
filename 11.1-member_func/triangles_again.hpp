#include "closest_pnt.hpp"
//all other includes included in closest_pnt.hpp

struct Triangle {
  Point p1, p2, p3;

  double triangle_perimeter() const {
    return (p1.distance(p2) + p2.distance(p3)
            + p3.distance(p1));
  }

  double triangle_area() const {
    double a = p1.distance(p2);
    double b = p2.distance(p3);
    double c = p3.distance(p1);
    double C = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b));
    return (0.5 * a * b * sin(C));
  }
};

int main(){

  std::ifstream infile;
  infile.open("11.1-member_func/points.txt");

  if(!infile.is_open()){
    std::cout << "error opening file" << std::endl;
    return EXIT_FAILURE;
  }

  std::vector <Point> points;
  Point tmp_pnt;

  while (infile >> tmp_pnt.x >> tmp_pnt.y){
    points.push_back(tmp_pnt);
  }

  infile.close();

  if(points.size() == 0){
    std::cout << "there are no points in the file" << std::endl;
  }
  else if(points.size() < 3){
    std::cout << "there are insufficient points to make a triangle" << std::endl;
  }
  else{
    int rem = points.size() % 3;
    std::vector <Triangle> triangles;
    Triangle tmp_tri;
    for (int i = 0; i < points.size() - rem; i += 3){
      tmp_tri.p1 = points[i];
      tmp_tri.p2 = points[i + 1];
      tmp_tri.p3 = points[i + 2];
      triangles.push_back(tmp_tri);
    }
    for (int c = 0; c < triangles.size(); c++) {
      std::cout << "Triangle " << c + 1 << ": " << std::endl;
      std::cout << "perimeter = " << triangles[c].triangle_perimeter() << std::endl;
      std::cout << "area = " << triangles[c].triangle_area() << std::endl;
    }
  }
}