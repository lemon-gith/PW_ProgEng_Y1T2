#include <iostream>

class SomeClass{

public:

  SomeClass(int idinput) : id(idinput) {
    std::cout << "object with id " << id << " instantiated" << std::endl;
  }

  // assignment operator, notice the return type
  SomeClass& operator=(const SomeClass& s){

    std::cout << "assignment operator" << std::endl;

    id = s.id;

    return *this; //this represents the pointer to the object itself, similar to "self" in python
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
  SomeClass s3(3);

  std::cout << "s1: " << s1.get_id() << std::endl;
  std::cout << "s2: " << s2.get_id() << std::endl;
  std::cout << "s3: " << s3.get_id() << std::endl;

  s3 = s2 = s1;
  // chained assignments      //in order to facilitate chained assignments like these, "=" operation must return *this
  // that can be used instead of writing:
  // s2 = s1;
  // s3 = s2;


  std::cout << "s1: " << s1.get_id() << std::endl;
  std::cout << "s2: " << s2.get_id() << std::endl;
  std::cout << "s3: " << s3.get_id() << std::endl;
}