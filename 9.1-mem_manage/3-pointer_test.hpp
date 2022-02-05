#include <iostream>

int main(){
  int a;
  int* pi;
  // this declares pi as a pointer to int
  // which means that pi can be used to store the address
  // of a memory location of type int

  pi = &a;

  std::cout << &a << std::endl;
  std::cout << pi << std::endl;

  //now for doubles
  double b;
  double* e;

  e = &b;

  std::cout << &b << std::endl;
  std::cout << e << std::endl;
}