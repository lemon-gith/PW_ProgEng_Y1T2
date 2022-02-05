#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Contact{
  std::string f_name, s_name, e_add, p_num;
};

int search_contact(const std::vector<Contact>& contacts, const std::string& first_name, const std::string& surname){
  for (int i = 0; i < contacts.size(); i++){
    if (contacts[i].f_name == first_name){
      if (contacts[i].s_name == surname){
        return i;
      }
    }
  }

  return -1;
}

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

  /*for (int i = 0; i < contacts.size(); i++){
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
  }*/

  std::string fnm, snm;
  std::cout << "Please enter the first and last name of the person whose details you wish to know: " << std::endl;
  std::cin >> fnm >> snm;

  int contact_index = search_contact(contacts, fnm, snm);
  if (contact_index == -1){
    std::cout << "Apologies, but I couldn't find the person requested in the database." << std::endl;
  }
  else{
    std::cout << fnm << " " << snm << " の email address and phone number are: " << std::endl
    << contacts[contact_index].e_add << " & " << contacts[contact_index].p_num << std::endl;
  }
}