#include <iostream>
#include <string>

struct LsNode{
  int val;
  LsNode* next;
};

int main(){
  int ls_len; //list_length

  std::cout << "How long a list would you like to create? " << std::endl;
  std::cin >> ls_len;

  LsNode* ptr = nullptr; //pointer set to NULL
  LsNode* tmp;
  tmp = new LsNode;
  (*tmp).next = ptr;
  ptr = tmp;

  std::cout << "Please enter integer values below" << std::endl;
  std::cout << "int, number " << ls_len << ": " << std::endl;
  std::cin >> (*ptr).val;
  for (int i = 1; i < ls_len; i++) {
    tmp = new LsNode;
    (*tmp).next = ptr;
    ptr = tmp;

    if (i == ls_len - 1) {
      std::cout << "last one now: " << std::endl;
    }
    else {
    std::cout << "int, number " << ls_len - i << ": " << std::endl;
    }
    std::cin >> (*ptr).val;
  }

  std::cout << "finished constructing list" << std::endl;

  LsNode* rd_ptr; //pointer for reading the list
  rd_ptr = ptr;
  while (rd_ptr != nullptr){
    std::cout << (*rd_ptr).val << std::endl;
    rd_ptr = (*rd_ptr).next;
  }

  //now the searching part
  int search_int, counter = 0; //counter to keep track of number of iterations of list tracing
  bool int_found = false; //flag for apology msg after the search loop

  std::cout << "ignoring the pointlessness of this code, please enter a integer "
               "you would like to search the list for: " << std::endl;
  std::cin >> search_int;

  rd_ptr = ptr;

  while (rd_ptr != nullptr){
    counter++;
    if ((*rd_ptr).val == search_int){
      std::cout << "value found, it's item number " << (ls_len - 1) - counter << " in the list :)" << std::endl;
      rd_ptr = nullptr;
      int_found = true;
    }
    else{
      rd_ptr = (*rd_ptr).next;
    }
  }

  if (!int_found){
    std::cout << "Apologies, I could not find the specified integer" << std::endl;
  }

  rd_ptr = ptr;

  while (rd_ptr != nullptr){
    tmp = (*rd_ptr).next;
    delete rd_ptr;
    rd_ptr = tmp;
  }

  std::cout << "list safely deallocated" << std::endl;
}