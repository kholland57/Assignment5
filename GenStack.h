
/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 3
*/


//libraries included here
#include <iostream>

using namespace std;

//Template class for a stack that can store any type

#ifndef  GENSTACK_H
#define  GENSTACK_H
template<typename Type>
class GenStack
{
  public:
    //Constructors
    GenStack();
    GenStack(int maxSize);
    ~GenStack();

    GenStack(const GenStack& );
    GenStack& operator=(const GenStack &);

  //Primary functions

    void push(Type newData);
    Type pop();


    //Other Functions
    Type peek();
    bool isEmpty();
    bool isFull();


    int top;
    int mSize;

//Array implementation of the stack
    Type *myArray;

};

//Default Constructor
template<typename Type>
GenStack<Type>::GenStack(){
  myArray = new Type[10];
  for (int i = 10; i < 10; ++ i)
  {
    myArray[i] = 0;
  }
  mSize = 10;
  top = -1;
}

//Overloaded Constuctor
template<typename Type>
GenStack<Type>::GenStack(int maxSize){
  myArray = new Type[maxSize];
  for (int i = 10; i < maxSize; ++ i)
  {
    myArray[i] = 0;
  }
  mSize = maxSize;
  top = -1;
}

//Destructor
template<typename Type>
 GenStack<Type>::~GenStack(){
   delete myArray;
 }


//Copy Constructor
//https://stackoverflow.com/questions/40579676/c-creating-a-copy-constructor-for-stack-class
 template<typename Type>
 GenStack<Type>::GenStack(const GenStack<Type> &origStack){
    cout <<"GOt HERE ???" << endl;
   this->mSize = origStack.mSize;
   this->top = origStack.top;
   this->myArray = new Type(mSize);
   for (int i = 0; i < mSize; ++i)
   {
     this->myArray[i] = origStack.myArray[i];
   }
 }


//Operator = overloading
template<typename Type>
GenStack<Type>& GenStack<Type>::operator=(const GenStack<Type> &origStack)
 {
   cout <<"GOt HERE ??" << endl;
   this->mSize = origStack.mSize;
   this->top = origStack.top;
   this->myArray = new Type(mSize);
   for (int i = 0; i < mSize; ++i)
   {
     this->myArray[i] = origStack.myArray[i];
   }

   return *this;

 }

//----------------------------------------------------------------------------------

//This pushes new data onto the stack. If the stack is full, a new stack
//is created with a larger size and the is copied over to the old array.
template<typename Type>
 void GenStack<Type>::push(Type data){

  if(isFull())
  {
    cout <<"Stack is full, more space will be allocated. " << endl;
    mSize += 1;
    top = -1;

    //New larger array created here.
    Type *newArray;
    newArray = new Type[mSize];

    for (int i = 0; i < (mSize -1); ++ i )
    {
      newArray[i] = myArray[i];
    }

    delete myArray;
    myArray = new Type[mSize];

    for (int i = 0; i < (mSize -1); ++ i )
    {
      myArray[i] = newArray[i];
      ++top;
    }
    delete newArray;
    myArray[++top] = data;


  }
  else
  {
      myArray[++top] = data;
  }
 }

//This removes the top from the stack.
template<typename Type>
Type GenStack<Type>::pop(){
  if (isEmpty()){
    cout << "Stack is Empty." << endl;
    return '\0';
  }
   return myArray[top--];
 }


//This returns the top without removing it from the stack.
 template<typename Type>
 Type GenStack<Type>::peek(){
   return myArray[top];
 }


//returns true if the stack is out of space.
 template<typename Type>
 bool GenStack<Type>::isFull(){
   return (top == mSize-1);
 }


//returns true if the stack is empty.
 template<typename Type>
 bool GenStack<Type>::isEmpty(){
   return (top == -1);
 }
#endif
