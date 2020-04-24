#include "Registrar.h"

Registrar::Registrar(){//constructor
  myQueue = new GenQueue<Student*>();
  studList = new DoublyLinkedList<int>();
  windowArr = new DoublyLinkedList<Window>();
  windows = 0;
  timeOff = -1;
}
Registrar::Registrar(int numWindows){//default constructor
  myQueue = new GenQueue<Student*>();
  windowArr = new DoublyLinkedList<Window>();
  Window *w;
  for(int i = 0; i < numWindows; ++i){//initialize and declare all the windows
    w = new Window();
    windowArr->insertFront(*w);
  }
  windows = numWindows;
  timeOff = -1;
  studList = new DoublyLinkedList<int>();
}
Registrar::~Registrar(){//destructor
  delete myQueue;
  delete studList;
}
bool Registrar::cycle(){
  ++timeOff;
  Student *temp;
  Window *wi;
  Window del;
  if(windowsEmpty() && myQueue->isEmpty()){//check if windows and line are empty
    for(int i = 0; i < windows; ++i){
      windowArr->get(i)->incIdle();//increments idle time
    }
    return false;
  }
  for(int i = 0; i < windows; ++i){
    windowArr->get(i)->incWindow();//increment window time
  if(windowArr->get(i)->idleTime > timeOff){//error checking
    windowArr->removeAtPos(i);
    wi = new Window();
    windowArr->insertFront(*wi);
  }
    if(windowArr->get(i)->timeDone()){//check if the window's client is done
        windowArr->get(i)->kick();
      }
      if(!myQueue->isEmpty()){
        if(!windowArr->get(i)->occ){//insert new student and update stats and pointers
        temp = myQueue->remove();
        temp->waitTime = timeOff - temp->timeEntered;
        studList->insertFront(temp->waitTime);
        windowArr->get(i)->currStud = temp;
        windowArr->get(i)->studentTime = temp->timeNeeded;
        windowArr->get(i)->occ = true;
      }
    }
    else if(!windowArr->get(i)->hasStudent()){//if the queue is empty and the window is empty
         windowArr->get(i)->incIdle();
    }
  }
    if(windowsEmpty() && myQueue->isEmpty()){//checks if windows and line are empty
      return false;
    }
    else if(!(windowsEmpty() && myQueue->isEmpty())){//checks if windows and line have peoples
      return true;
    }
    delete temp;
    }
bool Registrar::windowsFull(){//checks if all windows have clients
  for(int i = 0; i < windows; ++i){
    if(!windowArr->get(i)->hasStudent())
      return false;
  }
  return true;
}

bool Registrar::windowsEmpty(){//checks if all windows don't have clients
  bool empt = true;
    for(int i = 0; i < windows; ++i){
      if(windowArr->get(i)->occ || windowArr->get(i)->studentTime != -1){
        empt = false;
      }
      else{
      }
    }
    return empt;
  }

  float Registrar::getMedian(){//finds median
    ListNode<int> *curr = studList->front;
    ListNode<int> *comp;
    int size = studList->size;
    int bigger = 0;
    int smaller = 0;
    int same = 0;
    float rightMed = 0;
    float leftMed = 0;
    do{
      bigger = 0;
      smaller = 0;
      same = 0;
      comp = studList->front;
      for(int i = 0; i < studList->size; ++i){
      if(comp->data > curr->data){//data point is bigger
        bigger++;
      }
      else if(comp->data < curr->data){//data point is smaller
        smaller++;
      }
      else if(comp->data == curr->data){//data point is the same
        same++;
      }
      comp = comp->next;
    }
    if(size%2 == 1){//odd size, has single median
      if(bigger <= size/2 && smaller <= size/2){//it's in the middle
        return curr->data;
      }
    }
    else{//has 2 medians
      if(bigger + smaller == size - 1){//no data points with the same val as curr
        if(bigger == smaller + 1){
          leftMed = curr->data;
        }
        else if(smaller == bigger + 1){
          rightMed = curr->data;
        }
      }
      else{//multiple with curr value
            if(smaller == size / 2){//curr is the upper median
              rightMed = curr->data;
            }
            if(same + bigger > smaller && same + smaller > bigger){//curr and it's similar values are both medians
              return curr->data;
            }
          }
      }

    if(leftMed != 0 && rightMed != 0){//checks if r and l medians have been found
      break;
    }
    curr = curr->next;
  }while(curr != studList->back);
  return ((leftMed + rightMed)/2);
}
