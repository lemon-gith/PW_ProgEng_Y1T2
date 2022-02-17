#include <iostream>

int main(){
  int* p;
  int* t;
  int a;

  p = new int;
  t = p;

  delete p;

  *t = 2;
  a = 1;
  p = &a;


  std::cout << *p << std::endl;
  std::cout << *t << std::endl;
}
