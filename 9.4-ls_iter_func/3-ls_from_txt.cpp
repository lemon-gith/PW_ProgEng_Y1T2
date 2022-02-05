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

ListNode* ls_from_txt(ListNode* ptr, const std::string& txt_name){
  std::ifstream infile;
  infile.open(txt_name);

  if (!infile.is_open()){
    std::cout << "error opening file" << std::endl;
    return nullptr;
  }

  list_t in_val;

  while (infile >> in_val){
    ptr = cons_list(in_val, ptr);
  }

  infile.close();

  return ptr;
}

int main(){
  ListNode* l = nullptr;
  l = ls_from_txt(l, "9.4-ls_iter_func/int_list.txt");

  if (l == nullptr){
    std::cout << "Sorry, either the file was empty, or there was an issue opening it";
    return EXIT_FAILURE;
  }

  print_list(l);

  deallocate_list(l);
}