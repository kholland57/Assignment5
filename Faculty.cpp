


/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 5
*/
#include "Faculty.h"
#include "GenStack.h"

//Default Constructor
Faculty::Faculty()
{
  department = "";
  studentIDList = new GenStack<int>(0);
  numStudents = 0;
}

//Overloaded Constructor
Faculty::Faculty(int newID, string newName, string newLevel, string newDepartment )
{
  id = newID;
  name = newName;
  level = newLevel;
  department = newDepartment;
  numStudents = 0;

  studentIDList = new GenStack<int>(0);
}

//Copy Constuctor
Faculty::Faculty(const Faculty &origFaculty)
{
    this->id = origFaculty.id;
    this->name = origFaculty.name;
    this->level = origFaculty.level;
    this->department = origFaculty.department;
    if (origFaculty.numStudents > 0)
    {
        this->studentIDList = origFaculty.studentIDList;
    }

    this->numStudents = origFaculty.numStudents;


}





//Destructor
Faculty::~Faculty()
{

}





//Operator = overloading
Faculty& Faculty::operator=(const Faculty &origFaculty)
{
//  cout <<"GOT TO OPERATOR = " << endl;
    this->id = origFaculty.id;
    this->name = origFaculty.name;
    this->level = origFaculty.level;
    this->department = origFaculty.department;
    this->studentIDList = origFaculty.studentIDList;
    this->numStudents = origFaculty.numStudents;

  return *this;
}

//Operator << overloading for printing
std::ostream& operator<<(std::ostream& os, const Faculty &faculty)
{
  os << "Faculty ID: " << faculty.id << endl;
  os << "Name: " << faculty.name << endl;
  os << "Level: " << faculty.level << endl;
  os << "Department: " << faculty.department << endl;

  return os;
}



//Accessors and Mutators

string Faculty::getDepartment()
{
  return department;
}


void Faculty::setDepartment(string newDep)
{
  department = newDep;
}


//Adds a Student ID to the student list
void Faculty::addStudentID(int newID)
{
  if (numStudents == 0)
  {
    studentIDList = new GenStack<int>(1);
    studentIDList->push(newID);
    cout << studentIDList->peek() << endl;
    numStudents += 1;
  }
  else
  {
    studentIDList->push(newID);
    numStudents += 1;
  }
}



int Faculty::getFrontOfList()
{
    int temp = studentIDList->pop();
    numStudents -= 1;

    return temp;

}

int Faculty::removeStudentID(int id)
{
  for (int i = 0; i < numStudents; ++i)
  {
    int temp = studentIDList->pop();
    //cout <<"Temp : " << temp << endl;
    if (id == temp)
    {
      cout <<"Student Removed." << endl;
      numStudents -= 1;
      return temp;
    }
    else
    {
      studentIDList->push(temp);
    }
  }
  cout <<"Could not find student." << endl;
  return -1;

}


int Faculty::getNumStudents()
{
  return numStudents;
}
