

/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 5
*/
//Libraries included here
#include <iostream>
#include <string>
using namespace std;



//Base class for Student and Faculty
#ifndef  PERSON_H
#define  PERSON_H
class Person{
public:

  //Constructors
  Person();
  Person(int newID, string newName, string newLevel);
  ~Person();

  //Mutators And Accessors

  void setID(int newId);
  void setName(string newName);
  void setLevel(string newLevel);

  int getID();
  string getName();
  string getLevel();


//Protected Variables
protected:

  int id;
  string name;
  string level;

};


#endif
