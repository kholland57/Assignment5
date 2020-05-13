# Assignment5


Name : Kelsey Holland
StudentID : 002298547
Email : kholland@chapman.edu
CPSC-350-02
Assignment 5

List of Source Files:
  1) BST.h
  2) DataBase.h
  3) DataBase.cpp
  4) Faculty.h
  5) Faculty.cpp
  6) GenStack.h
  7) main.cpp
  8) Person.h
  9) Person.cpp
  10) Rollback.h
  11) Rollback.cpp
  12) Run.h
  13) Run.cpp
  14) Student.h
  15) Student.cpp
  16) UserIO.h
  17) UserIO.cpp
  18) studentTable.txt
  19) facultyTable.txt
  20) README.md
  21) Makefile



---------------------
References:
- Zybooks
- The Queue in GenQueue.h was based on the example we did in class
- C++ 2nd Edition book by Goodrich.
- For the Binary Search Tree :
-https://stackoverflow.com/questions/26964869/binary-search-tree-copying-a-tree
-https://gist.github.com/ktuazon/3984248
-https://gist.github.com/harish-r/a7df7ce576dda35c9660
-https://gist.github.com/christophewang/a379d980019c2a1d93b4
-//https://stackoverflow.com/questions/33592002/need-help-implementing-binary-search-tree/33592115
- Rollback :
-https://stackoverflow.com/questions/10367544/visual-c-undo-and-redo-operations
-Other :
-https://www.cs.yale.edu/homes/aspnes/classes/223/examples/c++/stack/stack.h
-https://stackoverflow.com/questions/43766410/overwrite-an-existing-text-file-c

---------------------



Comments/Errors:
- You must make faculty members before you make any students, since a student needs an advisor ID.
- I could not find out a way to encrypt or decrypt the text file, so the information cannot be changed in between uses. The format has to stay the same in studentTable.txt and facultyTable.txt
- studentTable.txt and facultyTable.txt are sample input formats that the Program
can read in. Files being read in have to match this format exactly
- When a student or faculty is deleted, the id will not remove from their
advisor or advisee that has them listed, so you need to remove an advisee
from an advisor and assign them to a new one before you delete them.
-When files are read in and students and faculty are added to the lists,
calling rollback will delete the newly added students, then faculty, until
more user changes are added to the stack.


To run:
1 - make All
2 - ./assignment5.exe filename.txt
