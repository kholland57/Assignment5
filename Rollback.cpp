


/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 5
*/



#include "Rollback.h"

//Default Constructor
Rollback::Rollback()
{
  tempStudent = new BST<Student>();

  tempFaculty = new BST<Faculty>();

  numStudents = 0;
  numFaculty = 0;

  facultyIDStack = new GenStack<int>();
  studentIDStack = new GenStack<int>();

}


//Copy Constructor
Rollback::Rollback(Rollback* &origRollback)
{

  TreeNode<Student>* newRoot = origRollback->getStudent();
  this->tempStudent->setRoot(newRoot);

  TreeNode<Faculty>* newRootFaculty = origRollback->getFaculty();
  this->tempFaculty->setRoot(newRootFaculty);
}


//Operator = for overloading
Rollback& Rollback::operator=(Rollback* &origRollback)
{
  TreeNode<Student>* newRoot = origRollback->getStudent();
  this->tempStudent->setRoot(newRoot);

  TreeNode<Faculty>* newRootFaculty = origRollback->getFaculty();
  this->tempFaculty->setRoot(newRootFaculty);

  return *this;
}

//Destructor
Rollback::~Rollback()
{
  delete tempStudent;
  delete tempFaculty;

  delete facultyIDStack;
  delete studentIDStack;

}
//------------------------------------------------------------------------------

//Returns student BST root
TreeNode<Student>* Rollback::getStudent()
{
  return tempStudent->getRoot();
}
//------------

//Returns Faculty BST
TreeNode<Faculty>* Rollback::getFaculty()
{
  return tempFaculty->getRoot();
}
//------------

//sets the student ID stack
void Rollback::setStudentStack(GenStack<int> *newStack)
{

  studentIDStack = newStack;

}
void Rollback::setFacultyStack(GenStack<int> *newStack)
{

  facultyIDStack = newStack;
}


//Returns the ID stacks
GenStack<int> * Rollback::getStudentStack()
{
  return studentIDStack;
}
GenStack<int> * Rollback::getFacultyStack()
{
  return facultyIDStack;
}


//Sets the student BST starting with the node
void Rollback::setStudent(TreeNode<Student> *root)
{
  TreeNode<Student>* newRoot = tempStudent->copyTree(root);
  tempStudent->setRoot(newRoot);
}


//Sets the faculty BST starting with the node
void Rollback::setFaculty(TreeNode<Faculty> *root)
{
  TreeNode<Faculty>* newRoot = tempFaculty->copyTree(root);
  tempFaculty->setRoot(newRoot);
}

//Prints the BSTS
void Rollback::printStudents()
{
  tempStudent->print();
}

void Rollback::printFaculty()
{
  tempFaculty->print();
}




//Sets the number of students
void Rollback::setNumStudents(int num)
{
  numStudents = num;
}

//sets the number of faculty
void Rollback::setNumFaculty(int num)
{
  numFaculty = num;
}


//Returns number in BSTs
int Rollback::getNumStudents()
{
  return numStudents;
}


int Rollback::getNumFaculty()
{
  return numFaculty;
}
