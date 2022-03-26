#include <iostream>

class Base{

public:
  void b(){
    b_pro = 1;
    b_pri = 2;
    std::cout << "b: " << b_pro << " " << b_pri << std::endl;
  }

// access modifier protected:
// like private from outside the class
// but allows access from derived classes
// (see also below)

protected:
  int b_pro;

private:
  int b_pri;
};

// class Derived inherits from class Base
// using "public inheritance"
// (in C++ there are also other forms of inheritance that we will not consider)

class Derived : public Base {
//            ^ syntax for inheritance
public:

  void d(){
    b_pro = 3;
    // ok: not declared in Derived but inherited from Base
    // (b_pro protected in Base)

    // b_pri = 4;
    // won't work (b_pri private in Base)

    // std::cout << "d: " << b_pro + bpri << std::endl;
    // won't work (b_pri private in Base)

    std::cout << "d: " << b_pro << std::endl;
  }
};

int main(){

  Base ba;
  ba.b();

  Derived de;
  de.d();

  de.b();
  // ok: not defined in Derived but inherited from Base
  // (public in Base)

}