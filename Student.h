#include <iostream>
using namespace std;

class Student{
public:
  int waitTime;//time waited
  int timeNeeded;//time needed at the window
  int timeEntered;//click they entered at
  Student();//default constructor
  Student(int timeN, int timeEnt);//overloaded constructor
  ~Student();//destructor
  void incWaitTime();//increment time waited
};
