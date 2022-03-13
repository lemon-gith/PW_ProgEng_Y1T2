#include <iostream>
#include <vector>

int main(){
  int *p;
  p = new int[3];

  std::vector<int> v;

  p[0] = 10;
  p[2] = 30;
  v.push_back(10); // not v[0] = 10;

  std::cout << "p[0]: " << p[0] << std::endl;
  std::cout << "p[1]: " << p[1] << std::endl;
  std::cout << "v[0]: " << v[0] << std::endl;

  std::cout << "*p: " << *(p+2) << std::endl;
  // this will work: p is a pointer to the first memory cell

  //std::cout << "*v: " << *v << std::endl;
  // this will not work: v is not a pointer

  delete[] p;
}