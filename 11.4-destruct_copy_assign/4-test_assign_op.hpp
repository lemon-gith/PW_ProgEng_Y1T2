#include <iostream>

class SomeClass{

public:

  SomeClass(int idinput) : id(idinput) {
    std::cout << "object with id " << id << " instantiated" << std::endl;
  }

  int get_id() const {
    return id;
  }

private:

  int id;

};

int main(){

  SomeClass s1(1);
  SomeClass s2(2);

  std::cout << "s1: " << s1.get_id() << std::endl;
  std::cout << "s2: " << s2.get_id() << std::endl;

  std::cout << std::endl;

  s2 = s1;
  // the default assignment operator
  // will assign the value of s1.id to s2.id

  std::cout << "s1: " << s1.get_id() << std::endl;
  std::cout << "s2: " << s2.get_id() << std::endl;

}