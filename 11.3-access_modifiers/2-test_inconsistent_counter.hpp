#include "1-test_counter.hpp"

int main(){

  Counter c1;

  std::cout << c1.get_count() << std::endl;

  c1.inc();

  std::cout << c1.get_count() << std::endl;

  c1.c = c1.c - 1;

  std::cout << c1.get_count() << std::endl;

  c1.c = -3;

  std::cout << c1.get_count() << std::endl;

} 