
/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 5
*/

#include <iostream>
#include <string>
#include "Person.h"


#ifndef  STUDENT_H
#define  STUDENT_H
class Student : public Person
{
  public:
    //Constructors
    Student();
    Student(int newID, string newName, string newLevel, string newMajor, double newGPA, int newAdvisorField);
    ~Student();
    Student(const Student& origStudent);



    //Overloaded Operators
    Student& operator=(const Student& origStudent);
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
    //OtherMethods :


    void printInfo();
    //getters and setters
    void setMajor(string newMajor);
    void setGPA(double newGPA);
    void setAdvisorField(int newAdvisorField);

    string getMajor();
    double getGPA();
    int getAdvisorField();

//private variables
  private:

    string major;
    double GPA;
    int advisorField;

};


#endif
