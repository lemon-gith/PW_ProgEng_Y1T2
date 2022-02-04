#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Contact{
  std::string f_name, s_name, e_add, p_num;
};

int main(){
  std::ifstream infile;
  infile.open("8.2-struct_ex/contacts.txt");

  if(!infile.is_open()){
    std::cout << "error opening file" << std::endl;
    return EXIT_FAILURE;
  }

  std::vector <Contact> contacts;
  Contact tmp{};

  while (infile >> tmp.f_name >> tmp.s_name >> tmp.e_add >> tmp.p_num){
   contacts.push_back(tmp);
  }

  infile.close();

  for (int i = 0; i < contacts.size(); i++){
    if (contacts[i].s_name == "Wells"){
      std::cout << contacts[i].f_name << " " << contacts[i].s_name
      << "' email address and phone number are: " << std::endl;
      std::cout << contacts[i].e_add << " & " << contacts[i].p_num << std::endl;
    }
    else {
      std::cout << contacts[i].f_name << " " << contacts[i].s_name
                << "'s email address and phone number are: " << std::endl;
      std::cout << contacts[i].e_add << " & " << contacts[i].p_num << std::endl;
    }
  }
}