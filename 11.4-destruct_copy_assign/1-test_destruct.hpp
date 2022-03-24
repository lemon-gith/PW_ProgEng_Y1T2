#include <iostream>

class SomeClass{

public:

  SomeClass(int idinput) : id(idinput) {
    std::cout << "object with id " << id << " instantiated" << std::endl;
  }

  // the destructor
  ~SomeClass(){
    std::cout << "object with id " << id << " going out of scope" << std::endl;
  }

private:

  int id;

};

void f(){
  SomeClass s(1);
}

int main(){
  SomeClass s(2);

  std::cout << "just s(2)'d" << std::endl;
  SomeClass* sp;
  sp = new SomeClass(3);
  std::cout << "just s(3)'d" << std::endl;
  // with dynamic memory allocation

  f();
  std::cout << "just f()'d" << std::endl;
  delete sp;
  //s(2) is automatically deleted by the main function, as it wasn't dynamically allocated
}