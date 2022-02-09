#include <iostream>

double mpow(double x, int n){
  if(n == 0){
    return 1; // base case
  }
  else{
    return x * mpow(x, n - 1); // recursive call
  }
}

int main(){
  std::cout << mpow(3, 4) << std::endl;
}