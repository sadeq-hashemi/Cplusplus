#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
using namespace std;

list get_students(ifstream file) {

}
int main(){

string filename1, filename2; 
ifstream file1, file2;

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
    file1.open(filename1.c_str()); //start stream to read
    valid = file1.good(); //validity of name
    if(!valid) 
      cout << "Input file " << filename1 << " is NOT found. Please try again" << endl;  

  } while (!valid);

//Data: LastName,Firstname (no space), names may contain space dash, they are case sensitive
//	no two names are equal
  

//output # of students in each: "Number of students in <file1> = <n1>"
//output: # of students that are present in both/either <file1> and <file2> = <n2>
// also store in 2 output files named intersection.txt and union.txt

  file1.close();
  file2.close();
  return 0;
}

