#include <iostream>

class SomeClass{

public:

  // this is the same constructor of the previous example, not a copy constructor
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
  // this will call the constructor we wrote

  SomeClass s2(s1);
  // this will call the copy constructor
  // so the value of s.id will be copied into s2.id

  std::cout << "s1: " << s1.get_id() << std::endl;
  std::cout << "s2: " << s2.get_id() << std::endl;
}