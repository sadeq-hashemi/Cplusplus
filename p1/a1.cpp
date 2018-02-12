#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <list> 
#include <algorithm>
using namespace std;


/*
Reads from a file stream and adds each line as input into
a list. 
inputs: reference to filestream, reference to list
*/
void get_students(ifstream& file, list<string>& list) {

  string name; 

  if(file.is_open()) {
    while(getline(file, name)) {
      list.push_front(name);
    }
  }
}

/*
Takes both lists, and compares values. All_students will
be every student that exists in both, and shared_students
is the students that are common to both courses.
*/
void compare_lists(list<string>& l1, list<string>& l2,
   list<string>& all, list<string>& shared) {

  string name;
  list<string>::iterator it;
  while(!l1.empty()) {
    name = l1.front();
    l1.pop_front(); //removes first name
    list<string>::iterator it = find(l2.begin(), l2.end(), name); //search in second list
    if(it != l2.end() ) {  //exists in both lists
      all.push_front(name);
      shared.push_front(name);
      l2.erase(it); //WHAT IF IT FOUND BUT ITS AT THE END?
    } else { //only in first list 
      all.push_front(name);
    }
  }

  //At this point, l1 should be empty, and
  //all shared names have been entered
  while(!l2.empty()) {
    name = l2.front();
    l2.pop_front();
    all.push_front(name);
  }
}

int main(){

string filename1, filename2; 
ifstream file1, file2;
list<string>  list1, list2, either, both;
//prompt for 2 input files
// Enter the name of the first file: ....
// Enter the name of the second file: ....
// Input: if valid, you will use those files
// 	if invalid, display error and prompt agin
//	error: Input file <name> is not NOT found. Please try again. 
  bool valid = 0;

  do {
    cout << "Enter the name of the first file: ";
    getline(cin, filename1); //store name

    file1.open(filename1.c_str()); //start stream to read
    valid = file1.good(); //hold validity of filename
    if(!valid) 
      cout << "Input file " << filename1 << " is NOT found. Please try again" << endl;  

  } while (!valid);

  valid = 0; 
  do {
    cout << "Enter the name of the second file: ";
    getline(cin, filename2); //store name
    file2.open(filename1.c_str()); //start stream to read
    valid = file2.good(); //validity of name
    if(!valid) 
      cout << "Input file " << filename2 << " is NOT found. Please try again" << endl;  

  } while (!valid);

//Data: LastName,Firstname (no space), names may contain space dash, they are case sensitive
//	no two names are equal
  get_students(file1, list1);
  get_students(file2, list2);
  
//output # of students in each: "Number of students in <file1> = <n1>"
  cout << "Number of students in "<< filename1 << " = " << list1.size() << endl; 
  cout << "Number of students in "<< filename2 << " = " << list2.size() << endl; 
//output: # of students that are present in both/either <file1> and <file2> = <n2>
  compare_lists(list1, list2, either, both);
  cout << "Number of students that are present in both  "<< filename1 << " and "
       << filename2 << " = " << both.size() << endl; 
  cout << "Number of students in either "<< filename1 << " or " 
       << filename2 << " = " << either.size() << endl; 
// also store in 2 output files named intersection.txt and union.txt

  file1.close();
  file2.close();
  return 0;
}

