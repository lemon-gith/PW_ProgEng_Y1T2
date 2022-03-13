#include <iostream>
#include <vector>


int main(){

  std::vector<int> v;

  for(int i = 0; i < 10; i++){
    v.push_back(i);
    std::cout << i << " was added"<< std::endl;
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << std::endl;
  }
}