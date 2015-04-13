//@author A0115990B

#include "CMStorageSort.h"

std::vector<Task*> CMStorageSort:: sortTasks (std::vector<Task*> _allTasks, int firstFloatIndex) {
	
	for (int i=0; i<firstFloatIndex;i++) {
		
		for (int j=0; j<firstFloatIndex;j++){
			
			Task* a= _allTasks[i];
			Task* b= _allTasks[j];
			
			if (a->isTimed()){
				if (b->isTimed()){
					if (a->getStart()<b->getStart()){
						swap(_allTasks[i],_allTasks[j]);
					}
				} else if (b->isDeadline()){
					if (a->getStart()<b->getEnd()){
						swap(_allTasks[i],_allTasks[j]);
					}
				}
			} else if (a->isDeadline()){
				if (b->isTimed()) {
					if (a->getEnd()<b->getStart()){
						swap(_allTasks[i],_allTasks[j]);
					}
				} else if (b->isDeadline()){ 
					if (a->getEnd()<b->getEnd()){
						swap(_allTasks[i],_allTasks[j]);
					}
				}
			}
		}
	}
	
	return _allTasks;
}

void CMStorageSort:: swap (Task* &a, Task* &b){
	
	Task* temp = a;
	a=b;
	b=temp;
	
}
