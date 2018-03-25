#include "GradStudent.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>


using namespace std;
int GradStudent::numGradStudents = 0;
   GradStudent::GradStudent(std::string name,
                int yearOfBirth,
                const std::vector<double> &assignmentsScore,
                double projectScore,
                std::string researchArea,
                std::string advisor) : 
Student(name, yearOfBirth, assignmentsScore, projectScore)
{
  GradStudent::numGradStudents++;
  GradStudent::researchArea = researchArea;
  GradStudent::advisor = advisor;
}

std::string GradStudent::getResearchArea() {
  return GradStudent::researchArea; 
  }

std::string GradStudent::getAdvisor() {
    return GradStudent::advisor;
    }
int GradStudent::getNumStudents() {
    return GradStudent::numGradStudents;
    }

void GradStudent::printDetails() {
    Student::printDetails();
    cout << "Type = Graduate Student" << endl;
    cout << "Research Area = " << getResearchArea() << endl;
    cout << "Advisor = " << getAdvisor() << endl; 
    }

double GradStudent::getTotal() {
      vector<double> scores = Student::getAssignmentsScore();
      double avg = 0.0;
      for (double s : scores)
      avg += s;
      avg = avg/scores.size();
      return avg*0.5 + Student::getProjectScore()*0.5;
    }

std::string GradStudent::getGrade() {
  if (getTotal() >= 80)
    return "CR";
  else return "N";
    }


