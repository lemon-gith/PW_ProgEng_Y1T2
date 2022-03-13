#include <iostream>

class intvector{

public:

  // constructor
  intvector(){
    m_size = 0;
    // initially no elements, size is 0

    m_capacity = 1;
    p = new int[m_capacity];
    // we dynamically allocate
    // an initial memory area
    // of size 1 (there is space
    // to add 1 element before
    // a reallocation is needed)
  }

  // like push_back in std::vector
  // same algorithm as
  // "Reallocating dynamically allocated contiguous memory"
  // in section 11.5
  void push_back(int n){
    // TODO: implement this function
  }

  // like size() in std::vector
  int size() const {
    // TODO: implement this function
  }

  // like capacity() in std::vector
  int capacity() const {
    // TODO: implement this function
  }

  // return the element at index i
  // (consider how it is used in the main below)
  int at(int i) const {
    // TODO: implement this function
  }

  // destructor: we need to write our own destructor
  // with a delete[] instruction that deallocates
  // the dynamically allocated contiguous memory

  // we would have a memory leak otherwise because
  // the default destructor wouldn't do this

  ~intvector(){
    delete[] p;
  }

  // copy constructor
  // (see explanation in exercise below)

  intvector(const intvector& v){
    m_capacity = v.m_capacity;
    m_size = v.m_size;

    p = new int[m_capacity];

    for(int i = 0; i < m_size; i++){
      p[i] = v.p[i];
    }

  }

  // assignment operator
  // (see explanation in exercise below)

  intvector& operator=(const intvector& v){

    // first of all we check whether this is being called
    // during a reflexive assignment
    // that is something such as a = a;

    // if yes we don't do anything
    // otherwise we enter the if statement

    if(this != &v){

      delete[] p;

      m_capacity = v.m_capacity;
      m_size = v.m_size;

      p = new int[m_capacity];

      for(int i = 0; i < m_size; i++){
        p[i] = v.p[i];
      }
    }
    return *this;
  }

private:

  int* p;
  int m_size;
  int m_capacity;

};


int main(){
  intvector iv1;

  for(int i = 0; i < 9; i++){
    iv1.push_back(i);
    // TODO: add printing instructions showing how the size and the capacity are updated
  }

  std::cout << "printing iv1: " << std::endl;

  for(int i = 0; i < iv1.size(); i++){
    std::cout << iv1.at(i) << std::endl;
  }

  std::cout << std::endl;

  // calling the copy constructor
  intvector iv2(iv1);

  // calling the assignment operator
  intvector iv3 = iv1;

  iv1.push_back(9);

  std::cout << "printing iv1:" << std::endl;

  for(int i = 0; i < iv1.size(); i++){
    std::cout << iv1.at(i) << std::endl;
  }

  std::cout << std::endl;

  std::cout << "printing iv2:" << std::endl;

  for(int i = 0; i < iv2.size(); i++){
    std::cout << iv2.at(i) << std::endl;
  }

  std::cout << std::endl;

  std::cout << "printing iv3:" << std::endl;

  for(int i = 0; i < iv3.size(); i++){
    std::cout << iv3.at(i) << std::endl;
  }

  std::cout << std::endl;

}