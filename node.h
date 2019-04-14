#ifndef _NODE_H
#define _NODE_H
#include <stddef.h>

template <class M>
class Node
{
private:
  M item;
  Node<M>* nextPtr;
public:
  //constructors
  Node(M arg_item, Node* arg2_nextPtr);
  Node(M arg_item);

  //getters and setters
  M getItem();
  Node<M>* getNextPtr();
  void setItem(M arg_item);
  void setNextPtr(Node<M>* arg_nodePtr);
};

template <class M>
Node<M>::Node(M arg_item, Node<M>* arg_nextPtr)
{
  item = arg_item;
  nextPtr = arg_nextPtr;
}

template <class M>
Node<M>::Node(M arg_item)
{
  item = arg_item;
  nextPtr = NULL;
}

template <class M>
M Node<M>::getItem()
{ return item; }

template <class M>
Node<M>* Node<M>::getNextPtr()
{ return nextPtr; }

template <class M>
void Node<M>::setItem(M arg_item)
{ item = arg_item; }

template <class M>
void Node<M>::setNextPtr(Node* arg_nextPtr)
{ nextPtr = arg_nextPtr; }

#endif
