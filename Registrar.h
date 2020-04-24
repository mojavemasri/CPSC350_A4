#include "Window.h"
#include "GenQueue.cpp"

class Registrar{
public:
  DoublyLinkedList<int> *studList;//list of student wait times
  DoublyLinkedList<Window> *windowArr;//array of windows
  ~Registrar();//destructor
  int timeOff;//simulation time
  int windows;//number of windows
  Registrar();//default constructor
  Registrar(int numWindows);//overloaded constructor
  GenQueue<Student*> *myQueue;//queue of students, ie the line
  bool cycle();//one cycle of a click
  bool windowsFull();//all windows have a studnet
  bool windowsEmpty();//all windows are empty
  float getMedian();//returns the median of student wait times 
};
