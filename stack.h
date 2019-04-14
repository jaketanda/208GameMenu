#ifndef _STACK_H
#define _STACK_H
#include "node.h"
using namespace std;

const int StackEmpty = 99;

template <class W>
class Stack
{
protected:
  Node<W>* topPtr;
  int length;
public:
  Stack(); // constructor
  ~Stack(); // destructor
  bool isEmpty();
  void push(W argW);
  W pop();
  W peek();
  int getLength();
};

//***************************************
// Function : Stack constructor
// Description: sets the top pointer to NULL
//              sets the length to 0
//*****************************************
template <class W>
Stack<W>::Stack()
{ topPtr = NULL;
  length = 0;   }

//***************************************
// Function : isEmpty
// Description: if top ptr is Null, it's empty
//*****************************************
template <class W>
bool Stack<W>::isEmpty()
{
  if (topPtr == NULL)
    return true;
  return false;
}

//***************************************
// Function : push
// Description: pushes argW into the stack and 
//              replaces the top ptr
//*****************************************
template <class W>
void Stack<W>::push(W argW)
{
  //create a new Node
  // this should point to old top
  Node<W>* newNode = new Node<W>(argW, topPtr);
  topPtr = newNode;
  length++;

  return;

  //top of stack shold point to new node
}

//***************************************
// Function : pop
// Description: pops a W out of the stack
//*****************************************
template <class W>
W Stack<W>::pop()
{
  if (isEmpty())
  { throw StackEmpty; }

  //Remove top Node
  Node<W>* popNodePtr = topPtr;
  topPtr = topPtr->getNextPtr();

  //save info to return
  W returnItem = popNodePtr->getItem();

  //delete old
  delete popNodePtr;
  popNodePtr = NULL;

  length--;

  return returnItem;
}

//***************************************
// Function : peek
// Description: peeks at the top of the stack
//*****************************************
template <class W>
W Stack<W>::peek()
{
  if (isEmpty())
  { throw StackEmpty; }

  return topPtr->getItem();
}

//***************************************
// Function : Stack deconstructor
// Description: deconstructs the stack
//*****************************************
template <class W>
Stack<W>::~Stack()
{
  while (!isEmpty())
  {
    pop();
  }
}

//***************************************
// Function : getLength
// Description: returns length of stack
//*****************************************
template <class W>
int Stack<W>::getLength()
{ return length; }

#endif
