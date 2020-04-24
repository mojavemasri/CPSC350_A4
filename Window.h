#include "Student.h"
using namespace std;

class Window{
public:
Window();//default constructor
~Window();//destructor
Student *currStud;//student being assisted
int timeWindow;//time window has been occupeid with current student
int idleTime;//time window has been idle
int studentTime;//how long the student needs
bool occ;//bool of whether student is there
bool hasStudent();//returns whether student is there
void incWindow();//increment time window has been occupied
void incIdle();//increments idle time
bool timeDone();//checks if student's time is done
void kick();//kicks student out
};
