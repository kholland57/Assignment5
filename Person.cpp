


/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 5
*/
#include "Person.h"

//Default Constructor
Person::Person()
{
  id = 0;
  name = "";
  level = "";

  return;
}

//Overloaded Constructor
Person::Person(int newID, string newName, string newLevel)
{
  id = newID;
  name = newName;
  level = newLevel;

}


//Destructor
Person::~Person()
{
    //cout <<"DELETING PERSON" << endl;

}

//Accessors and Mutators
void Person::setID(int newID)
{
  id = newID;
}

void Person::setName(string newName)
{
  name = newName;
}

void Person::setLevel(string newLevel)
{
  level = newLevel;
}


int Person::getID(){
  return id;
}

string Person::getName()
{
  return name;
}


string Person::getLevel()
{
  return level;
}
