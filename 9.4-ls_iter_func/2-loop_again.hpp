#include <iostream>

typedef int list_t; //remember to also alter the implementation on line 48
//typedef std::string list_t; //this can be uncommented to convert the whole operation into a string-based list

struct ListNode{
  list_t val{};
  ListNode* next{};
};

ListNode* cons_list(list_t e, ListNode* l){
  ListNode* tmp;

  tmp = new ListNode;

  tmp->val = e;
  tmp->next = l;

  return tmp;
}

void print_list(ListNode* l){
  while(l != nullptr){
    std::cout << l->val << std::endl;
    l = l->next;
  }
}

void deallocate_list(ListNode* l){
  ListNode* tmp;

  while(l != nullptr){
    tmp = l->next;
    delete l;
    l = tmp;
  }
}

int main(){
  ListNode* l = nullptr;
  int in_size;
  list_t in_val;

  std::cout << "Please input the size of your desired list: " << std::endl;
  std::cin >> in_size;

  for (int i = 0; i < in_size; i++){
    std::cout << "please enter a value of type int: " << std::endl;
    std::cin >> in_val;
    l = cons_list(in_val, l);
  }

  print_list(l);

  deallocate_list(l);
}