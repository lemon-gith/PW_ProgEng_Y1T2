#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

ListNode* ls_from_txt(ListNode* ptr, const std::string& txt_name){ //shifted reading of values to a func
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

int len_list(ListNode* ptr){ //ex: Length of a list, works irrelevant of datatype
  int ls_len = 0;
  ListNode* tmp;
  tmp = ptr;

  while (tmp != nullptr){
    tmp = (*tmp).next;
    ls_len++;
  }

  return ls_len;
  //also, remember to deallocate the list, separately after using this function
}

bool search_list(list_t given_val, ListNode* ptr){ //ex: Search in a list
  ListNode* tmp;
  tmp = ptr;
  bool val_match = false;

  while (tmp != nullptr && !val_match){
    if ((*tmp).val == given_val){
      val_match = true;
    }
    else{
      tmp = (*tmp).next;
    }
  }

  return val_match;
}

ListNode* reversed_copy_list(ListNode* ptr){ //ex: Reversed copy of a list
  ListNode* n_ls;
  ListNode* rd_ls; //read list
  n_ls = nullptr;
  rd_ls = ptr;

  while (rd_ls != nullptr){
    n_ls = cons_list((*rd_ls).val, n_ls);
    rd_ls = (*rd_ls).next;
  }

  return n_ls;
}

bool search_ordered_list(list_t e, ListNode* ptr){//ex: Search in an ordered list
  bool val_match = false;

  ListNode* rd_ls;
  rd_ls = ptr;

  while (rd_ls != nullptr && !val_match && (((*rd_ls).val) <= e + 1)){
    if ((*rd_ls).val == e){
      val_match = true;
    }
    else{
      rd_ls = (*rd_ls).next;
    }
  }

  return val_match;
}

bool replace_list(const list_t e, const list_t n, ListNode* ptr, bool all = true){ //ex: Replace elements in a list
  bool comp_replace = false; //completed replacement
  int counter = 0; // to count num of replacements
  ListNode* rd_ls;
  rd_ls = ptr;

  while (rd_ls != nullptr){
    if ((*rd_ls).val == e){
      (*rd_ls).val = n;
      comp_replace = true;
      if (!all){
        rd_ls = nullptr;
        counter++;
      }
      else{
        rd_ls = (*rd_ls).next;
        counter++;
      }
    }
    else{
      rd_ls = (*rd_ls).next;
    }
  }

  if (counter == 1){
    std::cout << "1 instance was replaced" << std::endl;
  }
  else {
    std::cout << counter << " instances were replaced" << std::endl;
  }

  return comp_replace;
}


//maybe also try a list order-er code
int main(){
  ListNode* ls_ptr = nullptr;

  //reading list from the txt file
  ls_ptr = ls_from_txt(ls_ptr, "9.4-ls_iter_func/int_list.txt");
  if (ls_ptr == nullptr){
    std::cout << "Sorry, either the file was empty, or there was an issue opening it";
    return EXIT_FAILURE;
  }

  //std::cout << "That list has a length of " << len_list(ls_ptr) << std::endl; //ex: Length of a list

  /*int give_val = 7;
  ls_ptr = reversed_copy_list(ls_ptr);
  if (search_ordered_list(give_val, ls_ptr)){
    std::cout << give_val << " is in the list" << std::endl;
  }
  else{
    std::cout << give_val << " is not in the list" << std::endl;
  }*/ //ex: Search in a list/ex: Search in an ordered list

  /*if (replace_list(2, 17, ls_ptr)){
    print_list(ls_ptr);
    std::cout << "all 2 --> 17" << std::endl;
  }
  else{
    print_list(ls_ptr);
    std::cout << "in the else condition" << std::endl;
  }*/ //ex: Replace elements in a list

  /*print_list(ls_ptr);
  print_list(reversed_copy_list(ls_ptr));*/ //ex: Reversed copy of a list

  deallocate_list(ls_ptr);
}