#include <iostream>

int mfact(int n){
  if (n == 0){
    return 1;
  }
  else{
    return n * mfact(n - 1);
  }
}

int main(){
  std::cout << mfact(7) << std::endl;
}