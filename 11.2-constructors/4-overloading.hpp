#include <iostream>
#include <string>
#include "2-test_param.hpp"

void f(){
  std::cout << "no parameters version" << std::endl;
}

void f(int n){
  std::cout << "int version" << std::endl;
}

void f(std::string s){
  std::cout << "std::string version" << std::endl;
}

void f(int n1, int n2){
  std::cout << "2 int version" << std::endl;
}

void f(Point pnt){
  Point origin(0, 0);
  std::cout << pnt.distance(origin) << std::endl;
}

int main(){
  int a{}, c{};
  std::string b;
  Point p(2, 3);
  f();
  f(a);
  f(b);
  f(a, c);
  f(p);
}