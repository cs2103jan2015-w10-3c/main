#ifndef CHECKMATEHISTORY_H
#define CHECKMATEHISTORY_H

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include "Task.h"
#include "FloatingTask.h"
#include "TimedTask.h"
#include "Deadline.h" 

class CMHistory {

private:
	std::vector<Task*> _allTasksCopy;

public:
	CMHistory();
	void updateCopy(std::vector<Task*>); //if no undo or redo action
	std::vector<Task*> swapCopy(std::vector<Task*>); //if undo or redo action is being called 
}





#endif