#include <iostream>
#include <cmath>

struct Complex{
  double x, y;
};

Complex sol;

double disc(double a, double b, double c){
  return (pow(b, 2) - 4 * a * c);
}

double r_sol_comp(double a, double b){
  return ((-b) / (2 * a));
}

double i_sol_comp(double disc, double a){
  return (disc / (2 * a));
}

int main(){
  double a, b, c;
  double rep_sol, x, y;
  std::cout << "Please enter the x-coefficients here: " << std::endl;
  std::cin >> a >> b >> c;

  double d = disc(a, b, c);
  bool complx = false, repeat = false;

  if (d < 0){
    complx = true;
    sol.x = r_sol_comp(a, b);
    sol.y = abs(i_sol_comp(d, a)); //as complex conjugate is implied, too
  }
  else if (d == 0){
    repeat = true;
    rep_sol = r_sol_comp(a, b);
  }
  else{
    x = r_sol_comp(a, b);
    y = i_sol_comp(d, a);
  }

  if (complx){
    std::cout << "The solutions are: " << std::endl <<
    sol.x << " + " << sol.y << "j, " << std::endl <<
    sol.x << " - " << sol.y << "j, " << std::endl;
  }
  else if (repeat){
    std::cout << "The solution is: " << std::endl <<
    rep_sol << std::endl;
  }
  else{
    std::cout << "The solutions are: " << std::endl <<
    x + y << " and " << x - y << std::endl;
  }
}
