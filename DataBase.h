


/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 5
*/

//Libraries Included Here
#include <iostream>
#include <fstream>
#include <string>

#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "UserIO.h"
#include "GenStack.h"
#include "Rollback.h"

//Primary Class to Run the Program
#ifndef  DATABASE_H
#define  DATABASE_H
using namespace std;


class DataBase{
  public:
    //Constructor
    DataBase();

    //Destructor
    ~DataBase();



    //Public Methods
//-----------------------------------------
//File and Startup Methods
    void startUp();
    void createFacultyTable();
    void createStudentTable();
    void exit();
    void writeOutFaculty();
    void writeOutStudents();



//Student Methods

    void addStudent();
    void deleteStudent(int idNum);
    void printStudents();
    void findStudent(int idNum);
    void printAdvisorInfo(int idNum);
    void changeStudentAdvisor(int studentID, int facultyID);


//------------------------------------------
//Faculty Methods

    void addFaculty();
    void deleteFaculty(int idNum);
    void printFaculty();
    void findFaculty(int idNum);
    void addStudentToList(int studentID, int newFacultyID);
    void removeStudentFromList(int studentID, int facultyID);
    void printStudentList(int idNum);

//Rollback/ undo methods

  void rollBack();
  void rollBackAdd();
  void rollBackRemove();

  //Student and Faculty ID stack methods

  bool searchThroughStackS(int idNum);
  bool searchThroughStackF(int idNum);
  bool deleteFromStackS(int idNum);
  bool deleteFromStackF(int idNum);


//------------------------------------
  //Private Variables

  private:
    UserIO* userInput;
//Main BSTS for program
    BST<Student>* masterStudent;
    BST<Faculty>* masterFaculty;


    int numFaculty;
    int numTotalStudents;

//----------------------------------
  //Rollback and id stacks
    GenStack<Rollback*>* history;

    GenStack<int>* facultyIDStack;
    GenStack<int>* studentIDStack;



};
#endif

//https://stackoverflow.com/questions/26964869/binary-search-tree-copying-a-tree
//https://gist.github.com/ktuazon/3984248
//https://gist.github.com/christophewang/a379d980019c2a1d93b4
//https://gist.github.com/harish-r/a7df7ce576dda35c9660
//https://stackoverflow.com/questions/10367544/visual-c-undo-and-redo-operations
//https://stackoverflow.com/questions/43766410/overwrite-an-existing-text-file-c
//https://www.cs.yale.edu/homes/aspnes/classes/223/examples/c++/stack/stack.h
//https://gist.github.com/christophewang/a379d980019c2a1d93b4
//https://stackoverflow.com/questions/33592002/need-help-implementing-binary-search-tree/33592115
