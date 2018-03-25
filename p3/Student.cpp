#include "Student.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>

using namespace std;

int Student::numStudents = 0; //initialize static

Student::Student(std::string name, int yearOfBirth,
            const std::vector<double> &assignmentsScore, double projectScore){

  Student::numStudents++;
  Student::id = Student::numStudents;
  Student::name = name;
  Student::yearOfBirth = yearOfBirth;
  for(int i = 0; i < assignmentsScore.size(); i++)
    Student::assignmentsScore.push_back(assignmentsScore[i]); 
  Student::projectScore = projectScore;
}

int Student::getId() {
  return Student::id;
}

std::string Student::getName() {
  return Student::name;
}

int Student::getYearOfBirth() {
  return Student::yearOfBirth;
}

int Student::getAge() {
  return current_year - getYearOfBirth();
}

const std::vector<double> &Student::getAssignmentsScore() {
  /*vector<double> temp;
   for(int i = 0; i < Student::assignmentsScore.size(); i++)
    temp.push_back(Student::assignmentsScore[i]);  
  return temp;*/
  return Student::assignmentsScore;
}

double Student::getProjectScore() {
  return Student::projectScore;
}

int Student::getNumStudents() {
  return Student::numStudents;
}

void Student::printDetails() {
  cout << "STUDENT DETAILS:" << endl;
  cout << "Id = " << getId() << endl;
  cout << "Name = " << getName() << endl;
  cout << "Age = " << getAge() << endl;
  cout << "Assignments = [";
   for ( int i = 0; i < Student::assignmentsScore.size(); i++) {
     cout << Student::assignmentsScore[i];
     if(i == Student::assignmentsScore.size() - 1)
       cout << "]" << endl;
     else 
       cout << ", ";
   }
  cout << "Project = " << getProjectScore() << endl;
  cout << "Total = " << getTotal()  << endl;
  cout << "Grade = " << getGrade() << endl;
}

