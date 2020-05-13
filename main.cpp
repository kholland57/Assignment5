




/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 5
*/

//Libraries included here

#include "BST.h"
#include "Student.h"
#include "UserIO.h"
#include "DataBase.h"
#include "Run.h"

using namespace std;

//Main method for the program
int main(int argc, char **argv){

  Run* run = new Run();
  run->runMenu();


  delete run;

}
