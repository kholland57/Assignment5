

/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 5
*/

#include "Run.h"


//Default Constructor
Run::Run()
{
  userIO = new UserIO();
  dataBase = new DataBase();
  dataBase->startUp();
}


//Destructor
Run::~Run()
{
  delete userIO;
  delete dataBase;
}
//------------------------------------------------------------------------
//Other Methods

//This calls the userIO class to promp the user, and based on the number
//the user chooses, manipulates the database's students and faculty BSTs.
void Run::runMenu()
{
  int choice = userIO->promptUser();

  if (choice == 1)
  {
    //Print Students
    dataBase->printStudents();
    runMenu();
  }
  else if (choice == 2)
  {
    //Print Faculty
    dataBase->printFaculty();
    runMenu();
  }
  else if (choice == 3)
  {
    //Print Student Info
    int studentID = userIO->enterStudentID();
    if (studentID == -1)
    {
      runMenu();
    }
    else
    {
      dataBase->findStudent(studentID);
      runMenu();
    }
  }
  else if (choice == 4)
  {
    //Print Faculty Info
    int facultyID = userIO->enterFacultyID();
    if (facultyID == -1)
    {
      runMenu();
    }
    else
    {
      dataBase->findFaculty(facultyID);
      runMenu();
    }
  }
  else if (choice == 5)
  {
    //Prints a student's advisor info
    int studentID = userIO->enterStudentID();
    if (studentID == -1)
    {
      runMenu();
    }
    else
    {
      dataBase->printAdvisorInfo(studentID);
      runMenu();
    }
  }
  else if (choice == 6)
  {
    //Prints a Faculty's student list
    int facultyID = userIO->enterFacultyID();
    if (facultyID == -1)
    {
      runMenu();
    }
    else
    {
      dataBase->printStudentList(facultyID);
      runMenu();
    }
  }
  else if (choice == 7)
  {
    //Adds a student
    dataBase->addStudent();
    runMenu();
  }
  else if (choice == 8)
  {
    //Deletes a Student
    int studentID = userIO->enterStudentID();
    if (studentID == -1)
    {
      runMenu();
    }
    else
    {
      dataBase->deleteStudent(studentID);
      runMenu();
    }
  }
  else if (choice == 9)
  {
    //Adds Faculty Member
    dataBase->addFaculty();
    runMenu();
  }

  else if (choice == 10)
  {
    //Deletes a Faculty Member
    int facultyID = userIO->enterFacultyID();
    if (facultyID == -1)
    {
      runMenu();
    }
    else
    {
      dataBase->deleteFaculty(facultyID);
      runMenu();
    }
  }
  else if (choice == 11)
  {
    //Changes a Student's Advisor
    int studentID = userIO->enterStudentID();
    int facultyID = userIO->enterFacultyID();
    if ((facultyID == -1 )|| (studentID == -1))
    {
      runMenu();
    }
    else
    {
      dataBase->changeStudentAdvisor(studentID,facultyID);

      runMenu();
    }
  }
  else if (choice == 12)
  {
    //Removes a student from the Faculty list
    int studentID = userIO->enterStudentID();
    int facultyID = userIO->enterFacultyID();
    if ((facultyID == -1 )|| (studentID == -1))
    {
      runMenu();
    }
    else
    {
      dataBase->removeStudentFromList(studentID,facultyID);
      runMenu();
    }
  }
  else if (choice == 13)
  {
    //Rollback
    dataBase->rollBackRemove();
    runMenu();
  }
  else if (choice == 14)
  {
    //Exits and writes out to file.
    cout <<"Exiting." << endl;
    dataBase->writeOutFaculty();
    dataBase->writeOutStudents();
    exit(1);

  }
  else
  {
    cout <<"Invalid choice, please choose a number off the list." << endl;
    runMenu();
  }

}
