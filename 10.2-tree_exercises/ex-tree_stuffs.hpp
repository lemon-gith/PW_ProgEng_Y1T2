#include <iostream>
#include <fstream>

typedef int tree_t;

struct TreeNode{
  tree_t val;
  TreeNode* left;
  TreeNode* right;
};

TreeNode* cons_tree(tree_t data, TreeNode* trn_l, TreeNode* trn_r){
  TreeNode* tmp;
  tmp = new TreeNode;

  (*tmp).val = data;
  (*tmp).left = trn_l;
  (*tmp).right = trn_r;

  return tmp;
}

TreeNode* ordered_ins(tree_t data, TreeNode* tr_ptr){
  if(tr_ptr == nullptr){
    return cons_tree(data, nullptr, nullptr);
  }
  else if(data < (*tr_ptr).val){
    (*tr_ptr).left = ordered_ins(data, (*tr_ptr).left);
    return tr_ptr;
  }
  else{
    (*tr_ptr).right = ordered_ins(data, (*tr_ptr).right);
    return tr_ptr;
  }
}

void print_tree(TreeNode* tr_ptr){
  if(tr_ptr != nullptr){
    print_tree((*tr_ptr).left);
    std::cout << (*tr_ptr).val << std::endl;
    print_tree((*tr_ptr).right);
  }
}

void deall_tree(TreeNode* tr_ptr){
  if(tr_ptr != nullptr){
    deall_tree((*tr_ptr).left);
    deall_tree((*tr_ptr).right);
    delete tr_ptr;
  }
}

TreeNode* txt_to_tree(TreeNode* tr_ptr, const std::string &fname){
  std::ifstream infile;
  infile.open(fname);

  if(!infile.is_open()){
    std::cout << "error opening file" << std::endl;
    return nullptr;
  }

  tree_t in_val;

  while(infile >> in_val){
    tr_ptr = ordered_ins(in_val, tr_ptr);
  }

  infile.close();

  return tr_ptr;
}

bool search_ordered_tree(tree_t data, TreeNode* tr_ptr){
  if (tr_ptr == nullptr){
    return false;
  }
  else if ((*tr_ptr).val == data){
    return true;
  }
  else if (data < (*tr_ptr).val){
    return search_ordered_tree(data, (*tr_ptr).left);
  }
  else{
    return search_ordered_tree(data, (*tr_ptr).right);
  }
}

int count_occurrences_tree(tree_t data, TreeNode* tr_ptr){
  if (tr_ptr == nullptr){
    return 0;
  }
  else if ((*tr_ptr).val == data){
    return 1 + count_occurrences_tree(data, (*tr_ptr).right);
  }
  else if (data < (*tr_ptr).val){
    return count_occurrences_tree(data, (*tr_ptr).left);
  }
  else{
    return count_occurrences_tree(data, (*tr_ptr).right);
  }
}

TreeNode* min_element_tree(TreeNode* tr_ptr){
  TreeNode* tmp{};

  while (tr_ptr != nullptr){
    tmp = tr_ptr;
    tr_ptr = (*tr_ptr).left;
  }

  return tmp;
}

/*void count_nodes_tree(TreeNode* tr_ptr, int &counter){
  if (tr_ptr != nullptr){
    count_nodes_tree((*tr_ptr).left, counter);
    counter++;
    count_nodes_tree((*tr_ptr).right, counter);
  }
}*/ //v1 of node counting function

int alt_count_nodes_tree(TreeNode* tr_ptr){
  if (tr_ptr == nullptr){
    return 0;
  }
  else{
    return 1 + alt_count_nodes_tree((*tr_ptr).left) + alt_count_nodes_tree((*tr_ptr).right);
  }
}

int count_leaves_tree(TreeNode* tr_ptr){
  if (tr_ptr == nullptr){
    return 0;
  }
  else if (((*tr_ptr).left == nullptr)&&((*tr_ptr).right == nullptr)){
    return 1;
  }
  else{
    return count_leaves_tree((*tr_ptr).left) + count_leaves_tree((*tr_ptr).right);
  }
}

int main(){
  TreeNode* tree;
  tree = nullptr;

  tree = txt_to_tree(tree, "10.2-tree_exercises/many_more_int.txt");
  if(tree == nullptr){
    std::cout << "Sorry, there was either an issue opening the file, or the file was empty" << std::endl;
    return EXIT_FAILURE;
  }

  /*int given_val = 25;
  if (search_ordered_tree(given_val, tree)){
    std::cout << given_val << " is in the list :)" << std::endl;
  }
  else{
    std::cout << given_val << " isn't in the list :(" << std::endl;
  }*/ //ex: search in an ordered tree

  //std::cout << count_occurrences_tree(9, tree) << std::endl; //ex: count all the occurrences of an element

  /*TreeNode* min_ptr = min_element_tree(tree);
  std::cout << "The smallest value in the tree is: " << (*min_ptr).val << std::endl;*/ //ex: find pointer to min element

  //std::cout << "This tree has " << alt_count_nodes_tree(tree) << " nodes :)" << std::endl; //ex: count nodes

  std::cout << "This tree has " << count_leaves_tree(tree) << " leaves :0" << std::endl; //ex: count leaves

  deall_tree(tree);
}
