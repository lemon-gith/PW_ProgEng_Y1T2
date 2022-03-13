#include <iostream>

int main() {

  int* p;

  p = new int[5];
  // we allocate 5 contiguous memory cells of type int
  // p points to the first cells

  p[0] = 10;
  // we dereference the first cell and assign 10
  // *p = 10; would also work (but less readable in this case)

  p[1] = 20;
  p[2] = 30;
  // we dereference the second and third cell
  // and assign some values
  p[4] = 5;
  //p[5] = 12;  //causes an error, as the program attempts to write into memory that hasn't been assigned to it

  // note that in the condition 
  // of the loop below we write 3 and not 5
  // 5 in this case is the capacity 
  // 3 is the size (how many elements are actually stored)
  for(int i = 0; i < 6; i++){
    std::cout << p[i] << std::endl;
  }

  delete[] p; //array delete
  // deallocation of the memory pointed by p
  // note that we use delete[]
  // and not delete
}