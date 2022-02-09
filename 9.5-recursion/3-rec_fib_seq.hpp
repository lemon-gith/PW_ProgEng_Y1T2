#include <iostream>

double fib(double n){
  if (n == 0){
    return 0;
  }
  else if (n == 1){
    return 1;
  }
  else{
    return (fib(n - 1) + fib(n - 2));
  }
}

int main(){
  std::cout << fib(8) << std::endl;
}