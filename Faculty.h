

/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 5
*/

//Libraries Included Here
#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"

#include "GenStack.h"

#ifndef  FACULTY_H
#define  FACULTY_H
//Faculty is a Derived class of Person
class Faculty : public Person
{
public:
  //Constuctors
  Faculty();
  Faculty(int newID, string newName, string newLevel, string newDepartment);
  ~Faculty();
  //Copy Constructor
  Faculty(const Faculty &origFaculty);

  //Operator = overloading
  Faculty& operator=(const Faculty &origFaculty);
  friend std::ostream& operator<<(std::ostream& os, const Faculty &faculty);

  //Ohter Functions, Accessors and Mutators
  string getDepartment();


  void setDepartment(string newDep);
  void addStudentID(int newID);
  int getFrontOfList();
  int removeStudentID(int id);
  int getNumStudents();

//Private Variables
private:
  string department;
  GenStack<int> *studentIDList;
  int numStudents;



};

#endif
