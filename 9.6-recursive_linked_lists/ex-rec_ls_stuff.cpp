#include <iostream>
#include <fstream>
#include "1-test_rec_print.hpp"

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

int length_list_rec(ListNode* l){ //ex: length of a list
  if(l == nullptr){
    return 0;
  }
  else{
    return 1 + length_list_rec((*l).next);
  }
}

bool search_list_rec(list_t e, ListNode* l){ //ex: search in a list
  if(l == nullptr){
    return false;
  }
  else if((*l).val == e){
    return true;
  }
  else{
    return search_list_rec(e, (*l).next);
  }
}

//s(e, l) = false if l = null
//s(e, l) = false if (*l).val > e
//s(e, l) = true if (*l).val = e
//s(e, l) = s(e, (*l).next) otherwise

bool search_ordered_list_rec(list_t e, ListNode* l){ //ex: search in an ordered list
  if (l == nullptr){
    return false;
  }
  else if((*l).val > e){
    return false;
  }
  else if((*l).val == e){
    return true;
  }
  else{
    return search_ordered_list_rec(e, (*l).next);
  }
}

ListNode* ordered_insertion_list(list_t e, ListNode* l, bool ascend = true){ //ex: ordered insertion in a list, requires ascending list
  if(l == NULL){
    return cons_list(e, l);
  }
  else if(e > l->val && ascend){
    return cons_list(e, l);
  }
  else if(e < l->val && not ascend){
    return cons_list(e, l);
  }
  else{
    l->next = ordered_insertion_list(e, l->next);
    return l;
  }
}

ListNode* simpler_order_ls(ListNode* ptr, bool ascend = true){
  ListNode* rd_ls = ptr;
  ListNode* n_ls = nullptr;

  while (rd_ls != nullptr) {
    n_ls = ordered_insertion_list((*rd_ls).val, n_ls, ascend);
    rd_ls = (*rd_ls).next;
  }

  delete ptr;
  return n_ls;
}


//functions defined for use in order_ls():

//returns the lowest/highest value in the list
list_t extreme_val(ListNode* ptr, bool minimum = true){
  ListNode* rd_ls = ptr;
  list_t ex_val = (*ptr).val; //current extremum value, either minimum or maximum

  while(rd_ls != nullptr) {
    if (minimum) {
      if ((*rd_ls).val < ex_val) {
        ex_val = (*rd_ls).val;
      }
      rd_ls = (*rd_ls).next;
    }
    else{
      if ((*rd_ls).val > ex_val){
        ex_val = (*rd_ls).val;
      }
      rd_ls = (*rd_ls).next;
    }
  }

  return ex_val;
}

//cuts the first instance of value, val, from the list referenced by ptr
void crispr(list_t value, ListNode* &ptr){
  ListNode* rd_ls = ptr;
  ListNode* tmp = rd_ls; // address of prev ListNode

  if(rd_ls->val == value){
    ptr = rd_ls->next;
    return;
  }

  while ((rd_ls) != nullptr){
    if(rd_ls->val == value){
      if(rd_ls->next == nullptr){
        tmp->next = nullptr;
        return;
      }
      tmp->next = rd_ls->next; // memory leak here
      return;
    }

    tmp = rd_ls;
    rd_ls = (*rd_ls).next;
  }
}

ListNode* order_ls(ListNode* ptr, bool ascend = true){ //ex: ordered copy of a list
  ListNode* rd_ls;
  ListNode* n_ls;
  n_ls = nullptr;
  rd_ls = ptr;
  list_t min_max;
  int ls_len = length_list_rec(ptr);

  if (ascend){
    for (int i = 0; i < ls_len; i++){
      min_max = extreme_val(rd_ls, false);
      crispr(min_max, rd_ls);
      n_ls = cons_list(min_max, n_ls);
    }
    return n_ls;
  }
  else{
    for (int i = 0; i < ls_len; i++){
      min_max = extreme_val(rd_ls);
      crispr(min_max, rd_ls);
      n_ls = cons_list(min_max, n_ls);
    }
    return n_ls;
  }
}


int main(){
  ListNode* ls_ptr = nullptr;

  ls_ptr = ls_from_txt(ls_ptr, "9.6-recursive_linked_lists/fib_mess.txt");
  if (ls_ptr == nullptr){
    std::cout << "Sorry, either the file was empty, or there was an issue opening it";
    return EXIT_FAILURE;
  }

  //std::cout << length_list_rec(ls_ptr) << std::endl; //ex: list length

  /*if(search_ordered_list_rec(55, ls_ptr)){
    std::cout << "yee" << std::endl;
  }
  else{
    std::cout << "nay" << std::endl;
  }*/ //ex: search in list/search in ordered list

  //ordered_insertion_list(44, ls_ptr); //ex: ordered insertion

  //ls_ptr = simpler_order_ls(ls_ptr);

  ls_ptr = order_ls(ls_ptr, true);

  print_list_rec(ls_ptr);

  deallocate_list_rec(ls_ptr);
}