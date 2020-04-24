#include "Registrar.h"
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char **argv){
string nfile = argv[1];
ifstream inFS;
int numOfWindows = 0;
inFS.open(nfile);//open file
inFS >> numOfWindows;//read number of windos
Registrar *reg = new Registrar(numOfWindows);
for(int i = 0; i < numOfWindows; ++i){
  reg->windowArr->get(i)->idleTime = 0;//sets init values to 0
}
GenQueue<Student*> *q = reg->myQueue;
int fileTime = 0;
int simTime = -1;
inFS >> fileTime;
int numStud = 0;
Student *temp = NULL;
int t = 0; //file input time for each student
int plz = -1;//checks time
do{
  plz++;
simTime++;
if(!inFS.eof()){
if(fileTime == simTime){//if the next line input has come
  inFS >> numStud;
  for(int i = 0; i < numStud; ++i){
    inFS >> t;
    temp = new Student(t, fileTime);
    q->insert(temp);//inserts appropriate amount of files
  }
  inFS >> fileTime;
}
}
}while((reg->cycle() || !inFS.eof()));//while the file hasnt run out and there are people in line/at the windwos
DoublyLinkedList<int> *studList = (reg->studList);
DoublyLinkedList<int> *windowList = new DoublyLinkedList<int>();
float sizeStudList = studList->size;
float mean = 0;
float median = reg->getMedian();//returns median
int over10 = 0;
int curr = 0;
int longestStud = 0;
ListNode<int> currStud;
while(!studList->isEmpty()){//pop values from student list and assesses them
  currStud = studList->removeBack();
  curr = currStud.data;
  if(curr > longestStud){
    longestStud = curr;
  }
  if(curr > 10){
    over10++;
  }
  mean += curr;
}
mean /= sizeStudList;
for(int i = 0; i < numOfWindows; ++i){//inserting idle time data into list
  windowList->insertFront(reg->windowArr->get(i)->idleTime);
}
int longestWindow = 0;
float meanWindow = 0;
int windowOver5 = 0;
int currWind = 0;
float sizeWindList = windowList->size;
while(!windowList->isEmpty()){//popping and assessing data
  currWind = windowList->removeBack();
  if(longestWindow < currWind){
    longestWindow = currWind;
  }
  if(currWind > 5){
    windowOver5++;
  }
  meanWindow += currWind;
}
meanWindow /= sizeWindList;
cout << "\f\n\n\n\n\n\n\n\n\n\n\nSTUDENT STATS:\n" <<  "Mean Student wait time: " << mean << endl;
cout <<  "Median student wait time: " << median << endl;
cout <<  "Longest Student wait time: " << longestStud << endl;
cout  <<  "Number of students waiting over 10 minutes: " << over10 << endl;
cout <<  "Mean Window Idle Time: " << meanWindow << endl;
cout  <<  "Longest Window Idle Time: " << longestWindow << endl;
cout  <<  "Number of Windows idle for over 5 minutes: "<< windowOver5 << endl;
//deletion
delete reg;
delete q;
delete windowList;
delete studList;
inFS.close();
return 0;
}
