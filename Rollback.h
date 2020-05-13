

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
#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include "GenStack.h"
using namespace std;

//Rollback is a class that stores an iteration of the databases.
#ifndef  ROLLBACK_H
#define  ROLLBACK_H
class Rollback{
public:

  //Constructors
  Rollback();
  Rollback(Rollback* &origRollback);
  Rollback& operator=(Rollback*& origRollback);

  ~Rollback();

  //Other Methods
  //Gets the BSTS
  TreeNode<Student> * getStudent();
  TreeNode<Faculty> * getFaculty();
  //Sets the BSTS
  void setStudent(TreeNode<Student> *root);
  void setFaculty(TreeNode<Faculty> *root);


  //Prints each node in BSTS
  void printStudents();
  void printFaculty();


  //Accessors/Mutators for the ID stacks
  void setStudentStack(GenStack<int> *newStack);
  void setFacultyStack(GenStack<int> *newStack);
  GenStack<int> * getStudentStack();
  GenStack<int> * getFacultyStack();




  void setNumStudents(int num);
  void setNumFaculty(int num);
  int getNumStudents();
  int getNumFaculty();



//Private/Protected Variables
protected:

  BST<Student>* tempStudent;
  BST<Faculty>* tempFaculty;

  GenStack<int>* facultyIDStack;
  GenStack<int>* studentIDStack;

  int numStudents;
  int numFaculty;

};


#endif
