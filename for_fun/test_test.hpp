#include <iostream>

/*int main(){
  int* p;
  int* t;
  int a;

  p = new int;
  t = p;

  delete p;

  *t = 2;
  a = 1;
  p = &a;


  std::cout << *p << std::endl;
  std::cout << *t << std::endl;
}*/

int f(int n){
  if (n == 0){
    return 1;
  }
  else if ((n % 2) == 0){
    return 1 - f(n - 1);
  }
  else{
    return n + f(n - 1);
  }
}

int main(){
  int n;
  std::cin >> n;
  std::cout << f(n) << std::endl;
}
