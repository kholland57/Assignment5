
/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 5
*/

#include "Student.h"

//Constructors
//Student is a derived class of Person.
Student::Student()
{
  Person();
  major = "";
  GPA = 0.00;
  advisorField = 0;
}


//Overloaded Constructor
Student::Student(int newID, string newName, string newLevel, string newMajor, double newGPA, int newAdvisorField)
{
  id = newID;
  name = newName;
  level = newLevel;
  major = newMajor;
  GPA = newGPA;
  advisorField = newAdvisorField;

}
//Copy Constructor
Student::Student(const Student &origStudent)
{

    this->id = origStudent.id;
    this->name = origStudent.name;
    this->level = origStudent.level;

    this->major = origStudent.major;
    this->GPA = origStudent.GPA;
    this->advisorField = origStudent.advisorField;
}


//Destructor
Student::~Student()
{
//  cout <<"DELETING STUDENT" << endl;
}


//Overloading operator= for assignments
Student& Student::operator=(const Student &origStudent)
{
    this->id = origStudent.id;
    this->name = origStudent.name;
    this->level = origStudent.level;

    this->major = origStudent.major;
    this->GPA = origStudent.GPA;
    this->advisorField = origStudent.advisorField;

  return *this;
}

//Overloading operator << for printing out
std::ostream& operator<<(std::ostream& os, const Student& student)
{
  os << "Student ID: " << student.id << endl;
  os << "Name: " << student.name << endl;
  os << "Level: " << student.level << endl;
  os << "Major: " << student.major << endl;
  os << "GPA: " << student.GPA << endl;
  os << "Advisor: " << student.advisorField << endl;

  return os;
}



//-----------------------------------------------------------------------------
//Other methods
//Prints the information of the student without a return type
void Student::printInfo()
{
  cout <<"Student ID : " << id << endl;
  cout <<"Name : " << name << endl;
  cout <<"Level : " << level << endl;
  cout <<"Major : " << major << endl;
  cout <<"GPA : " << GPA << endl;
  cout <<"Advisor : " << advisorField << endl;


}

//Getters and Setters
void Student::setMajor(string newMajor)
{
  major = newMajor;
}

void Student::setGPA(double newGPA)
{
  GPA = newGPA;
}

void Student::setAdvisorField(int newAdvisorField)
{
  advisorField = newAdvisorField;
}

string Student::getMajor()
{
  return major;
}

double Student::getGPA()
{
  return GPA;
}

int Student::getAdvisorField()
{
  return advisorField;
}
