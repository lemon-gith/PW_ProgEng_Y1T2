#include <iostream>
#include <fstream>

typedef int list_t;

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

  std::ifstream infile;
  infile.open("9.4-ls_iter_func/list.txt");

  if (!infile.is_open()){
    std::cout << "error opening file" << std::endl;
    return EXIT_FAILURE;
  }

  list_t in_val;

  while (infile >> in_val){
    l = cons_list(in_val, l);
  }

  infile.close();

  print_list(l);

  deallocate_list(l);
}