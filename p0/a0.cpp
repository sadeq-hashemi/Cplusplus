#include <iostream>
#include <string> 

using namespace std;
//prints Hello World on console
int main(){
  std::string name;
  string first = "* Hello ";
  string last = "! Welcome to CS 368 (C++)! :) *";

  std::cout << "Enter your name: " << std::endl;
  getline(std::cin,name);

  if (name.compare("") == 0)
    first = "* Hello";

  //outputs correct format
  int total_size = first.length() + name.length() + last.length();
  //first line
  for(int i=0; i< total_size; i++) {
  std::cout << "*";
  }
  std::endl(std::cout);
  //second line
  for(int i=0; i< total_size; i++){
    if(i==0 || i==total_size-1 )
      std::cout << "*";
    else
      std::cout << " ";
  }
  std::endl(std::cout);

  //third line
  std::cout << first << name << last << std::endl;

  //fourth line
  for(int i=0; i< total_size; i++){
    if(i==0 || i==total_size-1 )
      std::cout << "*";
    else
      std::cout << " ";
  }
  std::endl(std::cout);
  //fifth line
  for(int i=0; i< total_size; i++) {
  std::cout << "*";
  }
  std::endl(std::cout);

  return 0; 
}
