#include "Student.h"

  Student::Student(){//default constructor
    waitTime = 0;
    timeNeeded = 0;
    timeEntered = 0;
  }
  Student::~Student(){//destructor
  }
  Student::Student(int timeN, int timeEnt){//overloaded constructor
    timeNeeded = timeN;
    waitTime = 0;
    timeEntered = timeEnt;
  }
  void Student::incWaitTime(){//increment wait time
    waitTime++;
  }
