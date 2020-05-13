


/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 5
*/



#include "DataBase.h"
#include <cmath>
#include <algorithm>


//Default Constructor
DataBase::DataBase()
{
  userInput = new UserIO();

  masterStudent = new BST<Student>();

  masterFaculty = new BST<Faculty>();
  numFaculty = 0;
  numTotalStudents = 0;

  history = new GenStack<Rollback*>();
  facultyIDStack = new GenStack<int>();
  studentIDStack = new GenStack<int>();
}


//Destructor
DataBase::~DataBase()
{
  cout <<"DELETING DATABASE" << endl;
  delete masterStudent;
  delete masterFaculty;
  delete userInput;
  delete history;
  delete facultyIDStack;
  delete studentIDStack;
}



//------------------------------------------------------------------------------------



//Function that reads in the files, and sets up the student and faculty
//BSTs if text file is found.
void DataBase::startUp()
{
  bool hasTable = userInput->readInFacultyFile();
  if (hasTable == true)
  {
    createFacultyTable();
  }
  else
  {
    cout <<"No Faculty Table found." << endl;
  }

  hasTable = userInput->readInStudentFile();
  if (hasTable == true)
  {
    createStudentTable();
  }
  else
  {
    cout <<"No Student Table found." << endl;
  }
}
//---------------



//Creating faculty table from the userString from reading in the faculty
//file. The for loop reads in each string into a variable, seperated by a
//newline.
void DataBase::createFacultyTable()
{
  string userString = userInput->getFacultyFile();

  int stringInt = 0;

  int id = 0;
  string idString = "";
  string name = "";
  string level = "";
  string department = "";

  for (int i = 0; i < userString.length(); ++i)
  {
    //'-' devides the people from each other
    if (userString[i] == '-')
    {
      id = stoi(idString);
      //id is pushed onto id stack
      facultyIDStack->push(id);
      Faculty newFaculty = Faculty(id, name, level, department);
      if (masterFaculty->isEmpty() == true)
      {
        //faculty is added to BSTs
        masterFaculty->insertRoot(id,newFaculty);
      }
      else
      {
        masterFaculty->insert(id,newFaculty);
      }
      id = 0;
      idString = "";
      name = "";
      level = "";
      department = "";
      stringInt = 0;
      numFaculty +=1;
      i ++;

    }
    else if (userString[i] != '\n')
    {
      if (stringInt == 0)
      {
        idString += userString[i];
      }
      else if (stringInt == 1)
      {
        name += userString[i];
      }
      else if (stringInt == 2)
      {
        level += userString[i];
      }
      else if (stringInt == 3)
      {
        department += userString[i];
      }
    }
    else if (userString[i] == '\n')
    {
      stringInt += 1;
    }
  }
}
//---------------


//Creating student table from the userString from reading in the student
//file. The for loop reads in each string into a variable, seperated by a
//newline.
void DataBase::createStudentTable()
{
  if (numFaculty == 0)
  {
    cout <<"Error: No Faculty Have been Created Yet." << endl;
    cout <<"Faculty must be created before Students are created." << endl;

    return;
  }
  string userString = userInput->getStudentFile();

  int stringInt = 0;

  int id = 0;
  string idString = "";
  string name = "";
  string level = "";
  string major = "";
  double gpa = 0.00;
  string gpaString = "";
  int advisorField = 0;
  string feildString = "";

  for (int i = 0; i < userString.length(); ++i)
  {
    if (userString[i] == '-')
    {
      id = stoi(idString);
      //student ID is pushed onto id stack
      studentIDStack->push(id);


      advisorField = stoi(feildString);
      gpa = stod(gpaString);

      //student is then made and added onto BST
      Student newStudent = Student(id, name, level, major, gpa, advisorField);
      if (masterStudent->isEmpty() == true)
      {

        masterStudent->insertRoot(id,newStudent);
        addStudentToList(id,advisorField);
      }
      else
      {
        masterStudent->insert(id,newStudent);
        addStudentToList(id,advisorField);
      }
      id = 0;
      idString = "";
      name = "";
      level = "";
      major = "";
      gpa = 0;
      gpaString = "";
      advisorField = 0;
      feildString = "";
      stringInt = 0;
      numTotalStudents += 1;
      i ++;
    }
    else if (userString[i] != '\n')
    {
      if (stringInt == 0)
      {
        idString += userString[i];
      }
      else if (stringInt == 1)
      {
        name += userString[i];
      }
      else if (stringInt == 2)
      {
        level += userString[i];
      }
      else if (stringInt == 3)
      {
        major += userString[i];
      }
      else if (stringInt == 4)
      {
        gpaString += userString[i];
      }
      else if (stringInt == 5)
      {
        feildString += userString[i];
      }
    }
    else if (userString[i] == '\n')
    {
      stringInt += 1;
    }
  }
}
//---------------

//writes out BST information to facultyTable.txt in same format it was read in
void DataBase::writeOutFaculty()
{
  cout <<"Writing out to facultyTable.txt" << endl;
  ofstream outFS;
  outFS.open("facultyTable.txt", ios::trunc);

  for (int i = 0; i < numFaculty; ++i)
  {
    if (!masterFaculty->isEmpty())
    {
      TreeNode<Faculty>* tempNode = masterFaculty->getMin();
      Faculty tempFaculty = tempNode->data;
      masterFaculty->deleteNode(tempFaculty.getID());


      outFS << tempFaculty.getID() << endl;
      outFS << tempFaculty.getName() << endl;
      outFS << tempFaculty.getLevel() << endl;
      outFS << tempFaculty.getDepartment() << endl;


      outFS << "-" << endl;
      delete tempNode;
    }
  }

  outFS.close();
  cout <<"End" << endl;
}


//writes out BST information to studentTable.txt in same format it was read in
void DataBase::writeOutStudents()
{
  cout <<"Writing out to studentTable.txt" << endl;
  ofstream outFS;
  outFS.open("studentTable.txt", ios::trunc);
  //cout <<"NUM FACULTY : " << numFaculty << endl;
  for (int i = 0; i < numTotalStudents; ++i)
  {
    if (!masterStudent->isEmpty())
    {
      TreeNode<Student>* tempNode = masterStudent->getMin();
      Student tempStudent = tempNode->data;
      masterStudent->deleteNode(tempStudent.getID());


      outFS << tempStudent.getID() << endl;
      outFS << tempStudent.getName() << endl;
      outFS << tempStudent.getLevel() << endl;
      outFS << tempStudent.getMajor() << endl;
      outFS << tempStudent.getGPA() << endl;
      outFS << tempStudent.getAdvisorField() << endl;

      outFS << "-" << endl;

      delete tempNode;

    }
  }

  outFS.close();
  cout <<"END OF WRITING" << endl;
}
//---------------




//Takes user input and creates a new student, but only if faculty have already
//been created
void DataBase::addStudent()
{

  if (numFaculty == 0)
  {
    cout <<"Error: No Faculty Have been Created Yet." << endl;
    cout <<"Faculty must be created before Students are created." << endl;

    return;
  }
  int id = 0 ;
  string name = "";
  string level = "";
  string major = "";
  double GPA = 0.00;
  int advisorField = 0;


  cout <<"\nCreating New Student:" << endl;

  cout <<"Enter the Student's Name : " << endl;
  cin >> name;
  if (cin.fail())
  {
    cin.clear();
    cin.ignore(256, '\n');
    cout <<"ERROR : Invalid Entry. Please try entering Student Data Again." << endl;
    return;
  }

  cout <<"Enter the Student's ID number : " << endl;
  cin >> id;
  if (cin.fail())
  {
    cin.clear();
    cin.ignore(256, '\n');
    cout <<"ERROR : Invalid Entry. Please try entering Student Data Again." << endl;
    return;
  }

  cout <<"Enter the Student's Level : " << endl;
  cin >> level;

  cout <<"Enter the Student's Major : " << endl;
  cin >> major;

  cout <<"Enter the Student's GPA : " << endl;
  cin >> GPA;
  if (cin.fail())
  {
    cin.clear();
    cin.ignore(256, '\n');
    cout <<"ERROR : Invalid Entry. Please try entering Student Data Again." << endl;
    return;
  }

  cout <<"Enter the Student's Advisor's ID : " << endl;
  cin >> advisorField;
  if (cin.fail())
  {
    cin.clear();
    cin.ignore(256, '\n');
    cout <<"ERROR : Invalid Entry. Please try entering Student Data Again." << endl;
    return;
  }
  else
  {
    if (searchThroughStackF(advisorField) == false)
    {
      cout <<"Error, Faculty does not exist. Please try entering Student Data Again." << endl;
      return;
    }
  }


  //Rollback is called to save previous version of BTS
  rollBackAdd();
  Student newStudent = Student(id, name, level, major, GPA, advisorField);
  cout <<"\nSTUDENT CREATED : " << endl;
  cout << newStudent << endl;

  if (masterStudent->isEmpty() == true)
  {
    cout <<"Root will be created. " << endl;
    masterStudent->insertRoot(id,newStudent);
    addStudentToList(id,advisorField);
  }
  else
  {
    cout <<"Adding Student." << endl;
    masterStudent->insert(id,newStudent);
    addStudentToList(id,advisorField);
  }
  numTotalStudents += 1;
  studentIDStack->push(id);
}
//---------------



//Prints all the students in the student BST
void DataBase::printStudents()
{
  cout <<"\n Printing Student List." << endl;
  masterStudent->print();
}
//---------------



//Deletes a student from the binary search tree.
void DataBase::deleteStudent(int idNum)
{
  //rollback add is called to save the previous version of the tree.
  rollBackAdd();
  bool isFound = true;


  isFound = masterStudent->deleteNode(idNum);

  if (isFound == false)
  {
    cout <<" " << endl;
  }
  else
  {
    deleteFromStackS(idNum);
  }
}
//---------------

//Finds a student given an ID number
void DataBase::findStudent(int idNum)
{
  if (searchThroughStackS(idNum) == false)
  {
    cout << "ERROR : Could not Find Student Given ID." << endl;
    return;
  }
  cout << masterStudent->find(idNum) << endl;
}
//---------------



//Finds the student in the BST, temporarily removes it and gets its advisor
//id number, and search for the faculy and print their information.
void DataBase::printAdvisorInfo(int idNum)
{

  int idAdvisor = 0;

  Student temp = masterStudent->find(idNum);
  cout <<"STUDENT FOUND : " << temp << endl;
  idAdvisor = temp.getAdvisorField();
  cout << "NUMBER FOUND : " << idAdvisor << endl;

  Faculty tempFaculty = masterFaculty->find(idAdvisor);
  cout <<tempFaculty << endl;

}
//---------------


//Finds the student and old advisor, removes the student from the advisor's list,
//and adds it to the new faculty ID
void DataBase::changeStudentAdvisor(int studentID, int newFacultyID)
{
  cout <<"CHANGE STUDENT ADVISOR " << endl;


  if ((searchThroughStackS(studentID) == false) || (searchThroughStackF(newFacultyID) == false))
  {
    cout << "Error : IDs are not in system. Returning to Menu." << endl;
    return;
  }
  //rollback is called to saved previous version of tree
  rollBackAdd();

  int idAdvisor = 0;

  Student temp = masterStudent->find(studentID);
  int oldId = temp.getAdvisorField();

  Faculty oldFaculty = masterFaculty->find(oldId);

  cout << oldFaculty.getNumStudents() << endl;
  oldFaculty.removeStudentID(studentID);

  masterFaculty->deleteNode(oldId);



  if (masterStudent->isEmpty() == true)
  {
    masterFaculty->insertRoot(oldId,oldFaculty);
  }
  else
  {
    masterFaculty->insert(oldId,oldFaculty);
  }


  //ADDING FACULTY TO STUDENT HERE
  temp.setAdvisorField(newFacultyID);

  masterStudent->deleteNode(studentID);
  if (masterStudent->isEmpty() == true)
  {
    masterStudent->insertRoot(studentID,temp);
  }
  else
  {
    masterStudent->insert(studentID,temp);
  }


//ADDING STUDENT TO NEW FACULTY
  Faculty tempFaculty = masterFaculty->find(newFacultyID);
  tempFaculty.addStudentID(studentID);
  masterFaculty->deleteNode(newFacultyID);
  if (masterFaculty->isEmpty() == true)
  {
    masterFaculty->insertRoot(newFacultyID,tempFaculty);
  }
  else
  {
    masterFaculty->insert(newFacultyID,tempFaculty);
  }
  cout << "END" << endl;
}

//------------------------------------------------------------------------------------
//FACULTY METHODS

//Takes in user input and adds it to Faculty list
void DataBase::addFaculty()
{
  //previous version of tree is saved with rollback add
  rollBackAdd();
  int id = 0 ;
  string name = "";
  string level = "";
  string department = "";

  cout <<"\nCreating New Faculty Member:" << endl;

  cout <<"Enter the Faculty Member's Name : " << endl;
  cin >> name;

  cout <<"Enter the Faculty ID number : " << endl;
  cin >> id;
  if (cin.fail())
  {
    cin.clear();
    cin.ignore(256, '\n');
    cout <<"ERROR : Invalid Entry. Please try entering all Faculty Data Again." << endl;
    return;
  }
  if (searchThroughStackF(id) == true)
  {
    cout <<"Error : ID already exists for Faculty. Please try entering all Faculty Data Again." << endl;
    return;
  }
  else
  {
    facultyIDStack->push(id);
  }

  cout <<"Enter the Faculty's Level : " << endl;
  cin >> level;

  cout <<"Enter the Faculty's Department : " << endl;
  cin >> department;


  Faculty newFaculty = Faculty(id, name, level, department);
  cout <<"\nFACULTY CREATED : " << endl;
  //cout << newFaculty << endl;

  if (masterFaculty->isEmpty() == true)
  {
    cout <<"Root will be created. " << endl;
    masterFaculty->insertRoot(id,newFaculty);

  }
  else
  {
    cout <<"Adding Faculty." << endl;
    masterFaculty->insert(id,newFaculty);
  }
  numFaculty += 1;
}
//---------------

//deletes a faculty member from the BST
void DataBase::deleteFaculty(int idNum)
{
  //rollbackAdd is called to save the previous version of the class
  rollBackAdd();
  bool isFound = true;


  isFound = masterFaculty->deleteNode(idNum);

  if (isFound == false)
  {
    cout <<"Could not Find Faculty Given ID." << endl;
  }
  else
  {
    deleteFromStackF(idNum);
  }
  masterFaculty->print();
}
//---------------

//This prints the faculty list
void DataBase::printFaculty()
{
  cout <<"\n Printing Faculty List." << endl;
  masterFaculty->print();
}
//---------------


//This searches and finds the faculty in the BST based on ID
void DataBase::findFaculty(int idNum)
{
  if (searchThroughStackF(idNum) == false)
  {
    cout << "Error : IDs are not in system. Returning to Menu." << endl;
    return;
  }
  cout << masterFaculty->find(idNum) << endl;
}

//Adds a new student to the faculty's list based on ID
void DataBase::addStudentToList(int studentID, int facultyID)
{
  cout <<"ADDING STUDENT TO LIST " << endl;


  if ((searchThroughStackS(studentID) == false) || (searchThroughStackF(facultyID) == false))
  {
    cout << "Error : IDs are not in system. Returning to Menu." << endl;
    return;
  }


  int idAdvisor = 0;
  rollBackAdd();

  Student temp = masterStudent->find(studentID);

  temp.setAdvisorField(facultyID);

  masterStudent->deleteNode(studentID);

  if (masterStudent->isEmpty() == true)
  {
    masterStudent->insertRoot(studentID,temp);
  }
  else
  {
    masterStudent->insert(studentID,temp);
  }

  Faculty tempFaculty = masterFaculty->find(facultyID);

  tempFaculty.addStudentID(studentID);
  masterFaculty->deleteNode(facultyID);


  if (masterFaculty->isEmpty() == true)
  {
    masterFaculty->insertRoot(facultyID,tempFaculty);
  }
  else
  {
    masterFaculty->insert(facultyID,tempFaculty);
  }
}
//---------------


//This removes a student from a Faculty's list. Student ID and Faculty ID
//are entered
void DataBase::removeStudentFromList(int studentID, int facultyID)
{
  cout <<"Removing Student From List " << endl;


  if ((searchThroughStackS(studentID) == false) || (searchThroughStackF(facultyID) == false))
  {
    cout << "Error : IDs are not in system. Returning to Menu." << endl;
    return;
  }



  int idAdvisor = 0;

  Student temp = masterStudent->find(studentID);

  cout <<"Enter a new advisor ID for the student: " << endl;
  int newAdvisor = userInput->enterFacultyID();
  if ( (searchThroughStackF(newAdvisor) == false))
  {
    cout << "Error : ID is not in system. Returning to Menu." << endl;
    return;
  }

  temp.setAdvisorField(newAdvisor);


  rollBackAdd();
  masterStudent->deleteNode(studentID);

  if (masterStudent->isEmpty() == true)
  {
    masterStudent->insertRoot(studentID,temp);
  }
  else
  {
    masterStudent->insert(studentID,temp);
  }
  addStudentToList(studentID, newAdvisor);



  Faculty tempFaculty = masterFaculty->find(facultyID);

  tempFaculty.removeStudentID(studentID);
  masterFaculty->deleteNode(facultyID);


  if (masterFaculty->isEmpty() == true)
  {
    masterFaculty->insertRoot(facultyID,tempFaculty);
  }
  else
  {
    masterFaculty->insert(facultyID,tempFaculty);
  }
}



//This prints the advisee list of a faculty member
void DataBase::printStudentList(int idNum)
{
  if (searchThroughStackF(idNum) == false)
  {
    cout <<"Error : ID could not be found." << endl;
    return;
  }


  Faculty tempFaculty = masterFaculty->find(idNum);
  cout << tempFaculty << endl;
  int iterations = 0;
  iterations = tempFaculty.getNumStudents();
  cout <<" NUM STUDENTS :" << iterations << endl;
  for (int i = 0; i < iterations; ++i)
  {
      int studentID = tempFaculty.getFrontOfList();
      cout << masterStudent->find(studentID) << endl;

  }
}


//-------------------------------------------------------------------------------
//RollBack Methods here


  //
  // void  DataBase::rollBack()
  // {
  //
  //   Rollback* newLists = new Rollback();
  //
  //   TreeNode<Student>* newRoot = masterStudent->getRoot();
  //   cout << newRoot->data << endl;
  //
  //   newLists->setStudent(newRoot);
  //   cout <<"PRINTING COPYS OF STUDENTS:" << endl;
  //   newLists->printStudents();
  //
  //   delete newLists;
  //
  // }


//This adds both the Student and Faculty BSTs to the rollback class as well
//as their information, so if the user wants to undo something the previous
//version of the trees were saved.
  void DataBase::rollBackAdd()
  {

    Rollback* newLists = new Rollback();

    TreeNode<Student>* newRoot = masterStudent->getRoot();


    newLists->setStudent(newRoot);
    newLists->setNumStudents(numTotalStudents);
    newLists->setStudentStack(studentIDStack);


    TreeNode<Faculty>* newRootFaculty = masterFaculty->getRoot();

    newLists->setFaculty(newRootFaculty);
    newLists->setNumFaculty(numFaculty);
    newLists->setFacultyStack(facultyIDStack);

    history->push(newLists);
  }
  //--------------------



//This is called when the user wants to undo a change to the BSTs
  //This removes a previous iteration of the BSTS from the rollback stack
  void DataBase::rollBackRemove()
  {
    if (history->isEmpty() == true )
    {
      cout <<"Error, nothing to undo. Stack is empty. " << endl;
      return;
    }
    cout <<"Undo" << endl;
    Rollback* newLists = new Rollback();

    newLists = history->pop();
    TreeNode<Student>* newRoot = newLists->getStudent();


    masterStudent->setRoot(newRoot);
    numTotalStudents = newLists->getNumStudents();
    studentIDStack = newLists->getStudentStack();



    TreeNode<Faculty>* newRootFaculty = newLists->getFaculty();

    masterFaculty->setRoot(newRootFaculty);
    numFaculty = newLists->getNumFaculty();
    facultyIDStack = newLists->getFacultyStack();
  }
//-------------------------------------------------------------------------------
//ID Stacks Here



//This searches through the ID stacks to see if an id exists. If it does,
//it returns true. A temp stack is needed to save each element being popped.
//For Students:
  bool DataBase::searchThroughStackS(int idNum)
  {
    bool isFound = false;
    GenStack<int>* tempStack = new GenStack<int>(numTotalStudents);
    for (int i = 0; i < numTotalStudents; ++i)
    {
      int temp = studentIDStack->pop();
      tempStack->push(temp);
      if (temp == idNum)
      {
        isFound = true;
      }
      cout <<"TEMP : " << temp << endl;
    }
    for (int i = 0; i < numTotalStudents; ++i)
    {
      int temp = tempStack->pop();
      studentIDStack->push(temp);
    }
    delete tempStack;
    return isFound;
  }
//For Faculty::
  bool DataBase::searchThroughStackF(int idNum)
  {
    bool isFound = false;
    GenStack<int>* tempStack = new GenStack<int>(numFaculty);
    for (int i = 0; i < numFaculty; ++i)
    {
      int temp = facultyIDStack->pop();
      tempStack->push(temp);
      if (temp == idNum)
      {
        isFound = true;
      }
      cout <<"TEMP : " << temp << endl;
    }
    for (int i = 0; i < numFaculty; ++i)
    {
      int temp = tempStack->pop();
      facultyIDStack->push(temp);
    }
    delete tempStack;
    return isFound;
  }


//This deletes an ID number off the stack by copying over all the stack elements
//except for the number being deleted.
bool DataBase::deleteFromStackF(int idNum)
  {
    bool isFound = false;
    GenStack<int>* tempStack = new GenStack<int>(numFaculty-1);
    for (int i = 0; i < numFaculty; ++i)
    {
      int temp = facultyIDStack->pop();
      if (temp == idNum)
      {
        isFound = true;
      }
      else
      {
        tempStack->push(temp);
      }
      cout <<"TEMP : " << temp << endl;
    }
    for (int i = 0; i < numFaculty - 1; ++i)
    {
      int temp = tempStack->pop();
      facultyIDStack->push(temp);
    }
    delete tempStack;
    return isFound;
  }

bool DataBase::deleteFromStackS(int idNum)
  {
    bool isFound = false;
    GenStack<int>* tempStack = new GenStack<int>(numTotalStudents);
    for (int i = 0; i < numTotalStudents; ++i)
    {
      int temp = studentIDStack->pop();
      tempStack->push(temp);
      if (temp == idNum)
      {
        isFound = true;
      }
      else
      {
        tempStack->push(temp);
      }
    }
    for (int i = 0; i < numTotalStudents; ++i)
    {
      int temp = tempStack->pop();
      studentIDStack->push(temp);
    }
    delete tempStack;
    return isFound;
  }
