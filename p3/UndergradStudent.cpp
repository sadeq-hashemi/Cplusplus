#include "UndergradStudent.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>

using namespace std;

int UndergradStudent::numUndergradStudents = 0; 

UndergradStudent::UndergradStudent(std::string name,
                     int yearOfBirth,
                     const std::vector<double> &assignmentsScore,
                     double projectScore,
                     std::string residenceHall,
                     std::string yearInCollege) : Student(name, yearOfBirth, assignmentsScore, projectScore) 
 {
  UndergradStudent::residenceHall = residenceHall;
  UndergradStudent::yearInCollege = yearInCollege;
  UndergradStudent::numUndergradStudents++; 
 }

std::string UndergradStudent::getResidenceHall() {
  return UndergradStudent::residenceHall;
}

std::string UndergradStudent::getYearInCollege() {
  return UndergradStudent::yearInCollege;
}

int UndergradStudent::getNumStudents() {
  return UndergradStudent::numUndergradStudents;
}

void UndergradStudent::printDetails() {
  Student::printDetails();
  cout << "Type = Undergraduate Student" <<endl;
  cout << "Residence Hall = " << getResidenceHall() << endl;
  cout << "Year in College = " << getYearInCollege() << endl;
}

double UndergradStudent::getTotal() {
  vector<double> scores = Student::getAssignmentsScore();
  double avg = 0.0; 
  for (double s : scores)
    avg += s;
  avg = avg/scores.size();
  return avg*0.7 + Student::getProjectScore()*0.3; 
}

std::string UndergradStudent::getGrade() {
  if (getTotal() >= 70)
    return "CR";
  else return "N";
}
