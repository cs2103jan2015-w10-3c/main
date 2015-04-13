//@author A0115990B

#ifndef CMSTORAGESORT_H
#define CMSTORAGESORT_H

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include "Task.h"
#include "FloatingTask.h"
#include "TimedTask.h"
#include "Deadline.h"

class CMStorageSort {
	
public:
	
	std::vector<Task*>  sortTasks(std::vector<Task*>, int);
	void swap(Task*&,Task*&);
	
};


#endif