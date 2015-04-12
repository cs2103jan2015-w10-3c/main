//
//  StorageSort.cpp
//  testmypart
//
//  Created by Elaine Cai on 10/4/15.
//
//

#include "CMStorageSort.h"

std::vector<Task*> CMStorageSort :: sortAllTasks (std::vector<Task*> _allTasks, int firstFloatIndex) {
	
	for (int i=0; i<firstFloatIndex;i++) {
		for (int j=0; j<firstFloatIndex;j++){
			Task* a= _allTasks[i];
			Task* b= _allTasks[j];
			
			if (a->isTimed()){ //a is timedtask
				if (b->isTimed()){ //b is timedtask
					if (a->getStart()<b->getStart()){
						swap(_allTasks[i],_allTasks[j]);
					}
				} else if (b->isDeadline()){ //b is deadline
					if (a->getStart()<b->getEnd()){
						swap(_allTasks[i],_allTasks[j]);
					}
					
				}
			} else if (a->isDeadline()){ //a is deadline
				if (b->isTimed()) { //b is timedtask
					if (a->getEnd()<b->getStart()){
						swap(_allTasks[i],_allTasks[j]);
					}
				} else if (b->isDeadline()){ //b is deadline
					if (a->getEnd()<b->getEnd()){
						swap(_allTasks[i],_allTasks[j]);
					}
				}
			}
		}
	}
	return _allTasks;
}

void CMStorageSort :: swap (Task* &a, Task* &b){
	Task* temp = a;
	a=b;
	b=temp;
}
/*
bool CMStorageSort:: hasStart(Task* task){
    
    if (task->getStart()!=boost::posix_time::ptime()){
        return true;
    } else {
        return false;
    }
    
}

bool CMStorageSort:: hasEnd(Task* task){
    
    if (task->getEnd()!=boost::posix_time::ptime()){
        return true;
    } else {
        return false;
    }
    
}
*/