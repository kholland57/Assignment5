

/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 5
*/

//Libraries included Here
#include <iostream>
#include <fstream>
#include <string>

#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "UserIO.h"
#include "GenStack.h"
#include "DataBase.h"
#ifndef   RUN_H
#define  RUN_H
using namespace std;

//Class that runs and chooses the user menu options
class Run{
  public:
    //Constructors
    Run();
    //Destructor
    ~Run();
    //Public Methods
//-----------------------------------------
    void runMenu();
    void rollBack(int num);

  //Private Variables
  private:
    UserIO* userIO;
    DataBase* dataBase;
};
#endif
