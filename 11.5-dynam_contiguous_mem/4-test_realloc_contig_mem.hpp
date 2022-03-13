#include <iostream>
#include <fstream>
#include <cstdlib>

int main(){

  std::ifstream infile;
  infile.open("11.5-dynam_contiguous_mem/inputs.txt");

  if(!infile.is_open()){
    std::cout << "error opening file" << std::endl;
    return EXIT_FAILURE;
  }

  int* p;
  int size = 0;
  int capacity = 1;

  p = new int[capacity];

  int n;

  while(infile >> n){
    std::cout << "n = " << n << std::endl;
    std::cout << "current size = " << size << std::endl;
    std::cout << "current capacity = " << capacity << std::endl;

    if(capacity <= size){
      // reallocation needed

      capacity *= 2;

      int* tmp_p;
      tmp_p = new int[capacity];
      // a new memory area of the size
      // of the updated capacity value is allocated

      for(int i = 0; i < size; i++){
        tmp_p[i] = p[i];
      }
      // the content of the previous memory area is copied 
      // to the newly allocated memory area

      delete[] p;
      // the previous memory area is deallocated

      p = tmp_p;
      // the pointer is updated to point to the new memory area

    }

    p[size] = n;
    // the element is added 
    size++;
    // the size is updated
  }

  for(int i = 0; i < size; i++){
    std::cout << p[i] << std::endl;
  }

  delete[] p;
}