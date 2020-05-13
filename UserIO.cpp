/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 5
*/

#include "UserIO.h"

//Constructor
UserIO::UserIO()
{


}

//Destructor
UserIO::~UserIO()
{
    cout <<"DELETING USERIO" << endl;
}
//------------------------------------------------------------------------------
//Methods


//This Method promps the user which command off of the menu they want to select.
//An int is returned.
int UserIO::promptUser()
{

  int numChoice = 0;
  cout << "\nDataBase Menu : \n" << endl;
  cout << "1 : Print Students" << endl;
  cout << "2 : Print Faculty" << endl;
  cout << "3 : Display a Student's Information" << endl;
  cout << "4 : Display a Faculty's Information" << endl;
  cout << "5 : Display a Student's Faculty Advisor " << endl;
  cout << "6 : Print Faculty Advisees" << endl;
  cout << "7 : Add new Student" << endl;
  cout << "8 : Delete Student" << endl;
  cout << "9 : Add new Faculty Member" << endl;
  cout << "10 : Delete Faculty Member" << endl;
  cout << "11: Change Student Advisor" << endl;
  cout << "12: Remove Student from Faculty Member" << endl;
  cout << "13: Rollback" << endl;
  cout << "14: Exit" << endl;

  cout << "\n Enter a number off the list above : " << endl;
  cin >> numChoice;
  if (cin.fail())
  {
    cin.clear();
    cin.ignore(256, '\n');
    cout <<"ERROR : Invalid Entry. System will exit." << endl;
    return 14;
  }


  cout << numChoice << endl;

  return numChoice;

}
//---------------


//This checks to see if facultyTable.txt exists. If not, the user has to
//enter in new faculty and students. It reads in the file if it is there
//into a string
bool UserIO::readInFacultyFile()
{
  ifstream inFS;

  string fileName = "facultyTable.txt";

  cout << "Opening " << fileName << endl;
  inFS.open(fileName);

  if (!inFS.is_open())
  {
    inFS.close();
    cout << "ERROR, could not find file." << fileName  << endl;
    cout << "User Must Enter Student and Faculty Data." << endl;
    return false;
  }

  string userString;
  string userTotalString;
  while (!inFS.eof()) {
    inFS >> userString;
    if (!inFS.fail()) {
      userTotalString = userTotalString + userString + "\n";
    }
  }

  inFS.close();
  cout << userTotalString << endl;
  this->facultyFile = userTotalString;
  return true;
}
//---------------


//This reads in a student table if there is a studentTabel.txt
bool UserIO::readInStudentFile()
{
  ifstream inFS;
  string fileName = "studentTable.txt";

  cout << "Opening " << fileName << endl;
  inFS.open(fileName);

  if (!inFS.is_open())
  {
    inFS.close();
    cout << "ERROR, could not find file." << fileName  << endl;
    cout << "User Must Enter Student and Faculty Data." << endl;
    return false;
  }

  string userString;
  string userTotalString;
  while (!inFS.eof()) {
    inFS >> userString;
    if (!inFS.fail()) {
      userTotalString = userTotalString + userString + "\n";
    }
  }

  inFS.close();
  cout << userTotalString << endl;
  this->studentFile = userTotalString;
  return true;
}
//---------------

//This asks the user to enter an int for the student id. If not an int,
//it will return -1 to menu to show there is an error
int UserIO::enterStudentID()
{
  int studentID;
  cout <<"Enter Student ID : " << endl;
  cin >> studentID;
  if (cin.fail())
  {
    cin.clear();
    cin.ignore(256, '\n');
    cout <<"ERROR : Invalid Entry. Returning to Menu." << endl;
    return -1;
  }
  return studentID;
}
//---------------

//This asks the user to enter an int for the faculty id. If not an int,
//it will return -1 to menu to show there is an error
int UserIO::enterFacultyID()
{
  int facultyID;
  cout <<"Enter Faculty ID : " << endl;
  cin >> facultyID;
  if (cin.fail())
  {
    cin.clear();
    cin.ignore(256, '\n');
    cout <<"ERROR : Invalid Entry. Returning to Menu." << endl;
    return -1;
  }
  return facultyID;
}
//---------------

//This returns the string read in from the textfile.
string UserIO::getFacultyFile()
{
  return this->facultyFile;
}
//---------------

//This returns the string read in from the textfile.
string UserIO::getStudentFile()
{
  return this->studentFile;
}
