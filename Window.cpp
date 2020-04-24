#include "Window.h"

Window::Window(){//default constructor
  currStud = NULL;
  studentTime = -1;
  timeWindow = 0;
  idleTime = 0;
  occ = false;
}
Window::~Window(){//destructor
  delete currStud;
}
bool Window::hasStudent(){//returns occ
  return occ;
}

bool Window::timeDone(){
  if(studentTime == -1){//error checking
    return false;
  }
  else{
    return(studentTime <= timeWindow && studentTime != -1);
  }
}

void Window::incWindow(){//increments student time at window//increments idle time
  timeWindow++;
}

void Window::incIdle(){//increments idle time
  idleTime++;
}
void Window::kick(){
  Student *temp = currStud;//assigns student to NULL and deletes old student
  currStud = NULL;
  delete temp;
  timeWindow = 0;
  studentTime = -1;
  occ = false;
}
