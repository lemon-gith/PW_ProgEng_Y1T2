#include <iostream>

class Counter{

private:
  int c;

public:
  Counter(){
    c = 0;
  }

  void inc(){
    c++;
  }

  int get_count() const {
    return c;
  }
};


int main(){
  Counter c1;
  std::cout << c1.get_count() << std::endl;
  c1.inc();
  std::cout << c1.get_count() << std::endl;
  c1.c = -2;
}