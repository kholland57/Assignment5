


/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 5
*/

//Libraries included Here
#ifndef  USERIO_H
#define  USERIO_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class UserIO{
  public:
    //Constructors
    UserIO();

    //Destructor
    ~UserIO();

    //Public Methods
    int promptUser();
    bool readInFacultyFile();
    bool readInStudentFile();
    string getFacultyFile();
    string getStudentFile();

    int enterStudentID();
    int enterFacultyID();



  //Private Variables
  private:
    string facultyFile;
    string studentFile;

};
#endif
