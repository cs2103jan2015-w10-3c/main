//
//  CMActive.cpp
//  testmypart
//
//  Created by Elaine Cai on 12/4/15.
//
//

#include "CMActive.h"

void CMActive :: sortAllTasks () {
	
	_allActiveTasks=_storageSort.sortAllTasks(_allActiveTasks, getDefaultIndexFirstFloat());
	
}

void CMActive:: writeFile() {
	
	_textFile.writeFile(_allActiveTasks);
	
}

std::vector<std::string> CMActive:: readFile() {
	
	return _textFile.readFile();

}

void CMActive :: changeStorageLocation(std::string NewLocation) {
	
	_textFile.changeStorageLocation(NewLocation);
	writeFile();
	
}

std::string CMActive :: getStorageLocation(){
	
	return _textFile.getStorageLocation();
}


void CMActive :: addDeadline (Deadline* NewDeadline) {
	
    bool isFound=false;
    
	updateHistory();
	if (_allActiveTasks.size()==0) { //empty vector
        
		_allActiveTasks.push_back(NewDeadline);
		_addedIndex=0;
        
	} else {
		
		int i=0;
		
		while ((i<getDefaultIndexFirstFloat())&&(!isFound)){
			
			//end of deadline compared with start of timedtask
			if (_allActiveTasks[i]->isTimed()) {
				
				if (NewDeadline->getEnd()<_allActiveTasks[i]->getStart()){
					isFound=true;
					break;
				}
                
			} else if (_allActiveTasks[i]->isDeadline()){
				//end of deadline compared with end of deadline
				
				if (NewDeadline->getEnd()<_allActiveTasks[i]->getEnd()){
					isFound=true;
					break;
				}
			}
			i++;
		}
		
		_allActiveTasks.insert(_allActiveTasks.begin()+i, NewDeadline);
		_addedIndex=i;
	}
	
	writeFile();
	
}

void CMActive :: addTimedTask (TimedTask* NewTimedTask){
	
    bool isFound=false;
    
	updateHistory();
	if (_allActiveTasks.size()==0) { //empty vector
        
		_allActiveTasks.push_back(NewTimedTask);
		_addedIndex=0;
        
	} else {
		
		int i=0;
		
		while ((i<getDefaultIndexFirstFloat())&&(!isFound)){
            
            //start of timedtask compared with start of timedtask
			if (_allActiveTasks[i]->isTimed()) {
                
                if (NewTimedTask->getStart()<_allActiveTasks[i]->getStart()){
                    isFound=true;
					break;
                }
                
            } else if (_allActiveTasks[i]->isDeadline()) {  //start of timedtask compared with end of deadline
                
                if (NewTimedTask->getStart()<_allActiveTasks[i]->getEnd()){
                    isFound=true;
					break;
                }
            }
			i++;
        }
		
		_allActiveTasks.insert(_allActiveTasks.begin()+i, NewTimedTask);
		_addedIndex=i;
	}
	
	writeFile();
}

void CMActive :: addFloatingTask (FloatingTask* NewFloatingTask) {
	
	updateHistory();
	_allActiveTasks.push_back(NewFloatingTask);
	writeFile();
	int index = _allActiveTasks.size()-1;
	_addedIndex= index;
	
}

int CMActive:: getAddedIndex () {
	return _addedIndex;
}


std:: string CMActive :: deleteActiveTask (int realIndex) {

	//lack of update history for multiple delete
	std::string deletedTask= _allActiveTasks[realIndex]->getInfo();
		eraseTask(realIndex);
		writeFile();
		return deletedTask;
}

void CMActive:: eraseTask(int realIndex){
	
	_allActiveTasks [realIndex] =  NULL;
	delete _allActiveTasks[realIndex]; //deleting the pointer
	_allActiveTasks.erase(_allActiveTasks.begin()+realIndex); //erasing the vector item containing the pointer
}

Task* CMActive :: getTask(int realIndex){ //linked to logic's edit function
	
	updateHistory();
	Task* taskPointer= _allActiveTasks[realIndex];
	return taskPointer;
	
}

void CMActive:: undoActiveTaskAction(){
	
	std::vector<Task*> _newAllTasks;
	_newAllTasks = _history.swapCopy(_allActiveTasks);
	_allActiveTasks = _newAllTasks;
	writeFile();
}

std::string CMActive:: check(int realIndex){
	
	//lack of update history for multiple check
	std::string checkedTask= _allActiveTasks[realIndex]->getInfo();
	eraseTask(realIndex);
	writeFile();
	return checkedTask;
	
}

int CMActive:: getDefaultIndexFirstFloat () { //the whole _allActiveTasks vector
	
	for (unsigned int i=0;i<_allActiveTasks.size();i++){
		if (_allActiveTasks[i]->isFloat()) {
			return i;
		}
	}
	
	int index=_allActiveTasks.size();
	return index;
	
}

void CMActive:: clearTasks(){
	
	updateHistory();
	_allActiveTasks.clear();
	writeFile();
		
}

int CMActive :: getEditedIndex(std::string desc,boost::posix_time::ptime start,boost::posix_time::ptime end){
	for (unsigned int i=0; i< _allActiveTasks.size() ; i++){
		if (_allActiveTasks[i]->isEditedTask(desc,start,end)){
			return i;
		}
	}
	return 0;
}

void CMActive::updateHistory(){
	_history.updateCopy(_allActiveTasks);
}

std::vector<Task*> CMActive::getActiveTasks(){
	
	return _allActiveTasks;

}
