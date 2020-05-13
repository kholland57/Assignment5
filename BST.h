


/*
Kelsey Holland
002298547
kholland@chapman.edu
CPSC-350-02
Assignment 5
*/



//Binary Search Tree Template Class :



#ifndef  TREENODE_H
#define  TREENODE_H
#include <iostream>
using namespace std;

//Treenode for BST
template<class Type>
class TreeNode{
  public:
    //Constructors
    TreeNode();
    TreeNode(int k, const Type &val);
    TreeNode(int k, const Type &val, TreeNode *leftNode, TreeNode *rightNode);

    ~TreeNode();


    int key;
    Type data;


//Left and right pointers
    TreeNode<Type> *left;
    TreeNode<Type> *right;
};


//Treenode implementation


//Default Constructor
template<class Type>
TreeNode<Type>::TreeNode(){
  key = 0;
  left = NULL;
  right = NULL;
}


//Overloaded Constructor
template<class Type>
TreeNode<Type>::TreeNode(int k, const Type &val){
  key = k;
  data = val;
  left = NULL;
  right = NULL;

}

//Overloaded constructor with left and right pointer parameters
template<class Type>
TreeNode<Type>::TreeNode(int k, const Type &val, TreeNode *leftNode, TreeNode *rightNode)
{

  this->key = k;
  this->data = val;
  this->left = leftNode;
  this->right = rightNode;

}
//
// template<class Type>
// TreeNode<Type> *TreeNode<Type>::copy()
// {
//   TreeNode<Type> *root = new TreeNode<Type>(this->key,this->data, this->left,this->right );
//   if (left!= NULL)
//   {
//     root->left = left->copy();
//   }
//   if (right!= NULL)
//   {
//     root->right = right->copy();
//   }

//
//   return root;
// }


//Destructor
template<class Type>
TreeNode<Type>::~TreeNode(){
  left = NULL;
  right = NULL;

  delete left;
  delete right;
}
#endif


//-----------------------------------------------------------------------------

//Binary Search Tree Template
#ifndef  BST_H
#define  BST_H
template<class Type>
class  BST{
public:

  //Constructors
  BST();
  ~BST();

  //Copy Method
  TreeNode<Type>* copyTree(TreeNode<Type>* origTree);



//Other Methods
  TreeNode<Type>* createNode(int data, const Type &val);

  void insertRoot(int value, const Type &val);
  void insert(int value, const Type &val);
  TreeNode<Type>* insert(TreeNode<Type> *node, int value, const Type &data);
  bool search (TreeNode<Type> *root, int value);


  TreeNode<Type>* find(TreeNode<Type> *root, int value);
  Type find(int value);

  bool deleteNode(int k);
  bool isEmpty();

  //accessors and Mutators
  TreeNode<Type>* getMin();
  TreeNode<Type>* getMax();

  TreeNode<Type>* getSuccessor(TreeNode<Type> *d);
  TreeNode<Type>* getRoot();
  void setRoot(TreeNode<Type> *d);




  void print();
  void printTree(TreeNode<Type> *node);

private:
  TreeNode<Type> *root;

};
//-------------


//References Primarily used:
//https://stackoverflow.com/questions/26964869/binary-search-tree-copying-a-tree
//https://gist.github.com/ktuazon/3984248



//Method to Copy over the tree
template<class Type>
TreeNode<Type>* BST<Type>::copyTree(TreeNode<Type>* origTree)
{
  if (origTree == NULL)
  {
    return NULL;
  }
  TreeNode<Type>* newTree = new TreeNode<Type>();
  newTree->key = origTree->key;
  newTree->data = origTree->data;

  newTree->left = copyTree(origTree->left);
  newTree->right = copyTree(origTree->right);


  return newTree;
}
//-------------




//Default constructor
template<class Type>
BST<Type>::BST(){
  this->root = NULL; //empty tree
}

//Destructor
template<class Type>
BST<Type>::~BST(){
//GET THIS SITUATED FOOOL


}

//Creates a new treenode and returns it
template<class Type>
TreeNode<Type>* BST<Type>::createNode(int newKey,const Type &val )
{
  cout <<"NODE CREATED" << endl;
  TreeNode<Type> *newNode = new TreeNode<Type>();

  newNode->key = newKey;
  newNode->data = val;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}


//Calls the other print function starting with the root of the tree
template<class Type>
void BST<Type>::print()
{
  printTree(this->root);
}


//Prints the tree by calling the funtion recursively and going all the way
//left then to the right
template<class Type>
void BST<Type>::printTree(TreeNode<Type> *node)
{
  //TreeNode* node = this->root;
  if (node == NULL)
  {
    //cout <<"NULL" << endl;
    return;
  }

  printTree(node->left);
  cout <<node->key << endl;
  cout << node->data << endl;
  printTree(node->right);
}



//Returns the max by traversing the tree all the way right.
template<class Type>
TreeNode<Type>* BST<Type>::getMax(){
  TreeNode<Type> *curr = root;

//empty tree
  if (root == NULL)
  {
    return NULL;
  }
  while(curr->right != NULL)
  {
    curr = curr->right;
  }
  return curr;

}
//get min is oposite, you go all the way to the left

template<class Type>
TreeNode<Type>* BST<Type>::getMin(){
  TreeNode<Type> *curr = root;

//empty tree
  if (root == NULL)
  {
    return NULL;
  }
  while(curr->left != NULL)
  {
    curr = curr->left;
  }
  return curr;

}


//Returns true if tree is empty
template<class Type>
bool BST<Type>::isEmpty(){
  return (root == NULL);
}


//Inserts the root into the Binary search tree. This must be inserted
//before any other node is.
template<class Type>
void BST<Type>::insertRoot(int value, const Type &val)
{
  this->root = new TreeNode<Type>(value, val);
}

//Inserts a node into a position, starting with the root.
//Referenced from : //https://gist.github.com/harish-r/a7df7ce576dda35c9660
template<class Type>
void BST<Type>::insert(int value, const Type &val)
{
  insert(this->root, value, val);
}


//Inserts a node into the right place by comparing the keys each time it
//traverses. It goes left if its smaller, and right if its larger, until
//a null spot is found.
template<class Type>
TreeNode<Type>* BST<Type>::insert(TreeNode<Type> *node, int value, const Type &data)
{

  if (search(node,value) == true){
    cout <<"value already exists." <<endl;
    return NULL;
  }


  if (node == NULL)
  {
    node = createNode(value, data);
  }
  else if (value < node->key)
  {
      node->left = insert(node->left, value, data);
  }
  else if (value > node->key)
  {
      node->right = insert(node->right, value, data);
  }

  return node;
}

//Searches for the key value, starting with the root and using comparison
//operators
//Reference used : https://gist.github.com/christophewang/a379d980019c2a1d93b4
template<class Type>
bool BST<Type>::search(TreeNode<Type> *root, int value)
{

  if (root == NULL)
  {
    return false;
  }
  else if (value == root->key)
  {
    return true;
  }
  else if (value < root->key)
  {
    return search(root->left, value);
  }
  else
  {
    return search(root->right, value);
  }

}


//Returns the data in the tree node, starting with the root.
template<class Type>
Type BST<Type>::find(int value)
{
  TreeNode<Type>* info = find(root,value);
  return info->data;
}


template<class Type>
TreeNode<Type>* BST<Type>::find(TreeNode<Type> *root, int value)
{
  if (root == NULL)
  {
    return NULL;
  }
  else if (value == root->key)
  {
    return root;
  }
  else if (value < root->key)
  {
    return find(root->left, value);
  }
  else
  {
    return find(root->right, value);
  }
}


//Searches for the node and Deletes it. Many considerations have to
//be taken into account based on the number of children the node has/
template<class Type>
bool BST<Type>::deleteNode(int k){

  if (isEmpty())
    return false;


  TreeNode<Type> *parent = root;
  TreeNode<Type> *current = root;
  bool isLeft = true;

  while(current->key != k){
    parent = current;
    if (k < current->key){
      isLeft = true;
      current = current->left;
    }
    else {
      isLeft = false;
      current = current->right;
    }

    if (current == NULL)
      return false;
  }
  //if we make it here, we found value

  if ((current->left == NULL) && (current->right == NULL))
  {
    //node is a leaf with no children
    //then we have a leaf node
    if(current == root){
      root = NULL;

    }
    else if (isLeft){
      parent->left = NULL;


    }
    else
      parent->right = NULL;
  }
  else if (current->right == NULL){
    //no right child
    //the node we are deleting has one child, must be left
    if (current == root)
      root = current->left;
    else if (isLeft)
      parent->left = current->left;
    else
      parent->right = current->left;

  }
  else if (current->left == NULL){
    //no leftchild
    //the node we are deleting has one child, must be right
    if (current == root)
      root = current->right;
    else if (isLeft)
      parent->left = current->right;
    else
      parent->right = current->right;

  }
  else {
    //node to be deleted has two children
    //at this point we begin to cry and bang our head on the keyboard

//we have to implement this function
    TreeNode<Type> *successor = getSuccessor(current);

    if (current == root)
      root = successor;
    else if (isLeft)
      parent->left = successor;
    else
      parent->right = successor;


    //connect/link successor to current's(d) left child
    successor->left = current->left;

    return true;
  }
  return false;

}


//This is used in the deleteMode method. It returns the child of a node
//that will take its place once deleted.
template<class Type>
TreeNode<Type>* BST<Type>::getSuccessor(TreeNode<Type> *d){
  //the parameter d represents the node to be deleted
  TreeNode<Type> *current = d->right;
  TreeNode<Type> *sp = d;
  TreeNode<Type> *successor = d;

  while(current != NULL){
    sp = successor;
    successor = current;
    current = current->left;
  }

  if(successor != d->right)
  {
    //if successor is not right child of node to be deleted
    sp->left = successor->right;
    successor->right = d->right;

  }
    return successor;


}//end of class


//Returns the root of the binary search tree.
template<class Type>
TreeNode<Type>* BST<Type>::getRoot()
{
  return root;
}

//sets the root of the binary search tree.
template<class Type>
void BST<Type>::setRoot(TreeNode<Type> *d)
{
  root = d;
}

#endif
