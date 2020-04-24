#include <iostream>
//#include "Median.h"
#include "DoublyLinkedList.cpp"
template<class T>
class GenQueue{
public:
DoublyLinkedList<T> *myQueue;

//default
GenQueue(){
  myQueue = new DoublyLinkedList<T>();
}

void insert(T d){//queue up
  myQueue->insertBack(d);
}
void insertNode(ListNode<T> node){//queue up but it's a node being inserted
  T d = node->data;
  myQueue->insertBack(d);
}
T remove(){//pop
  return myQueue->removeFront();
}
T peek(){//pop but without removing
  ListNode<T> *frontNode = myQueue->front;
  return frontNode->data;
}

bool isEmpty(){
  return myQueue->isEmpty();
}

int getSize(){
  return myQueue->size;
}

ListNode<T>* getFront(){
  return myQueue->front;
}
ListNode<T>* getBack(){
  return myQueue->back;
}

void printList(){
  myQueue->printList();
}
};
