//
//  StorageSort.h
//  testmypart
//
//  Created by Elaine Cai on 10/4/15.
//
//

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
//	bool hasStart(Task*);
//	bool hasEnd(Task*);
	std::vector<Task*>  sortAllTasks(std::vector<Task*>, int);
	void swap(Task*&,Task*&);

};


#endif