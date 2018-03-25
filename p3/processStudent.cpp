///////////////////////////////////////////////////////////////////////////////
// File Name:      processStudent.cpp
//
// Author:         <your name>
// CS email:       <your CS email>
//
// Description:    Methods to perform some processing on student objects.
///////////////////////////////////////////////////////////////////////////////

#include "processStudent.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>

using namespace std; 
//checks if a string is a digit
bool is_number(const std::string& s)
{
    try
    {
        std::stod(s);
    }
    catch(...)
    {
        return false;
    }
    return true;
}


void fillStudents(std::ifstream &inFile,
                  std::vector<GradStudent> &gstudents,
                  std::vector<UndergradStudent> &ugstudents) {

    // TODO: Implement this method.
    string  name, res, year_adv;
    vector<double> assignmentScore; 
    double projectScore;
    int yearOfBirth;
    string type, line, word;
    int i; 
    istringstream iss; 
    char delim = ',';


    while(getline(inFile, line)) {
      iss.str(line);
      vector<string> words; //vector of words seperated by commas
      i = 0;
      while(getline(iss, word, delim))
        //checks i, if we are checking for assignment scortes, must make sure that we read all
        words.push_back(word);
        type = words[0]; 
        name = words[1]; 
        yearOfBirth = stoi(words[2].c_str());

        while (i <= max_assignments) {
          if (is_number(words[3+i])) {
            assignmentScore.push_back(stod(words[3+i].c_str())); //pushes values 
            i++;
          }
        }
        //last value added was project score
        if(!assignmentScore.empty()) {
        projectScore = assignmentScore.back();
        assignmentScore.pop_back();
        }
        res = words[3 + i];
        year_adv = words[4 + i];

  //Create student with correct type
     if(type.compare("U") == 0) {
       UndergradStudent Utmp(name, yearOfBirth, assignmentScore, projectScore, res, year_adv);
       ugstudents.push_back(Utmp);
     }
     else if(type.compare("G") == 0) {
       GradStudent Gtmp(name, yearOfBirth, assignmentScore, projectScore, res, year_adv); 
       gstudents.push_back(Gtmp);
     } else 
       cerr << "unknown student type";

     words.erase(words.begin(), words.end()); //removes vector elements
     assignmentScore.erase(assignmentScore.begin(), assignmentScore.end());
     iss.clear();  //clears stream
 
    }
}

void printStudents(const std::vector<std::reference_wrapper<Student>> &students) {

    // TODO: Implement this method.
    for(auto it = students.begin(); it != students.end(); ++it) {
      it->get().printDetails();
      cout << endl;
    }    

}

void computeStatistics(std::vector<std::reference_wrapper<Student>> &students) {

    // TODO: Implement this method.
    //Student st;
    string type;
    int numStudent = 0;
    bool ugrad = false;
    // compute the # of students based on the type of students.
    for(auto it = students.begin(); it != students.end(); ++it) {
      //Student st = it->get();

      if(it == students.begin()) { //first iteration
        if (typeid(it->get()) == typeid(UndergradStudent)) //checks for type
          ugrad = true;
        else 
          ugrad = false;
      }

      //check for type
      if(ugrad && (typeid(it->get()) != typeid(UndergradStudent)))
        cerr << "type mismatch in computerStatistics";
      else if (!ugrad && (typeid(it->get()) != typeid(GradStudent)))
        cerr << "type mismatch in computeStatistics"; 
     } 
      //gets number of student according to type
      if(ugrad) numStudent = UndergradStudent::getNumStudents();
      else numStudent = GradStudent::getNumStudents();
 
      cout << "Number of students = " << numStudent << endl;
      
   // compute the mean of the total score.
   double avg = 0; 
   for(auto it = students.begin(); it != students.end(); ++it)
     avg += it->get().getTotal();
   avg = avg/numStudent;
   cout << "The mean of the total score = " << avg << endl; 
    // sort and print the students based on their total.
   cout << "The sorted list of students (id, name, total, grade) in descending order of total:" << endl;
   sort(students.begin(), students.end(),
              [](const std::reference_wrapper<Student>& a,
               const std::reference_wrapper<Student>& b)
               {return a.get().getTotal() > b.get().getTotal(); }); 

   for (auto it = students.begin(); it != students.end(); ++it) {
//     if(ugrad) UndergradStudent st = it->get();
//     else GradStudent st = it->get();
     Student &st = it->get();
     cout << st.getId() << ", " << st.getName() << ", " << st.getTotal() << ", " << st.getGrade() << endl; 
   }
    
     cout << endl;
}
