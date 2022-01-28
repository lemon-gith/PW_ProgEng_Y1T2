#include <iostream>
#include <cmath>
#include <string>

struct Complex{
  double x, y;
};

double disc(int a, int b, int c){
  return (pow(b, 2) - 4 * a * c);
}

double r_sol_comp(int a, int b){
  return ((-b) / (2 * a));
}

double i_sol_comp(int disc, int a){
  return (disc / (2 * a));
}

int main(){
  double a, b, c;
  std::cout << "Please enter the x-coefficients here: " << std::endl;
  std::cin >> a >> b >> c;

  double d = disc(a, b, c);
  bool complex = false, repeat = false;

  if (d < 0){
    complex = true;
    Complex sol;
    sol.x = r_sol_comp(a, b);
    sol.y = i_sol_comp(d, a);
  }
  else if (d == 0){
    repeat = true;
    double sol = r_sol_comp(a, b);
  }
  else{
    double x = r_sol_comp(a, b);
    double y = i_sol_comp(d, a); 
  }

  if (complex){
    
  }
}
