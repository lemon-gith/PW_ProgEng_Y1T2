#include <iostream>

class Base{

public:
  void b(){
    b_pro = 1;
    b_pri = 2;
    std::cout << "b (in Base): " << b_pro << " " << b_pri << std::endl;
  }

protected:
  int b_pro;

private:
  int b_pri;
};

class Derived : public Base {

public:

  // redefinition of function b() in class Derived
  void b(){
    b_pro = 3;

    // b_pri = 4;
    // won't work (b_pri private in Base)

    std::cout << "b (in Derived): " << b_pro << std::endl;
  }

  void d(){
    b_pro = 3;
    std::cout << "d: " << b_pro << std::endl;
  }
};

int main(){

  Base ba;
  ba.b();

  Derived de;
  de.d();

  de.b();

}