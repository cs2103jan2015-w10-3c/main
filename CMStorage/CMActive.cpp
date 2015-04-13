//@author A0115990B

#include "CMActive.h"

const std::string CMActive:: FILENAME = "Checkmate.txt";

void CMActive:: addActiveDeadline (Deadline* NewDeadline) {
	
    bool isFound=false;
    
	updateActiveHistory();
	if (_allActiveTasks.size()==0) { //empty vector
        
		_allActiveTasks.push_back(NewDeadline);
		_addedIndex=0;
        
	} else {
		
		int i=0;
		
		while ((i<getActiveIndexFirstFloat())&&(!isFound)){
			
			if (_allActiveTasks[i]->isTimed()) {
				
				if (NewDeadline->getEnd()<_allActiveTasks[i]->getStart()){	//end of deadline compared with start of timedtask

					
					isFound=true;
					break;
				
				}
                
			} else if (_allActiveTasks[i]->isDeadline()){

				
				if (NewDeadline->getEnd()<_allActiveTasks[i]->getEnd()){  //end of deadline compared with end of deadline
					
					isFound=true;
					break;
				
				}
			}
			i++;
		}
		
		_allActiveTasks.insert(_allActiveTasks.begin()+i, NewDeadline);
		_addedIndex=i;
		
	}
	
	writeActiveFile();
	
}

void CMActive:: addActiveTimedTask (TimedTask* NewTimedTask){
	
    bool isFound=false;
    
	updateActiveHistory();
	if (_allActiveTasks.size()==0) { //empty vector
        
		_allActiveTasks.push_back(NewTimedTask);
		_addedIndex=0;
        
	} else {
		
		int i=0;
		
		while ((i<getActiveIndexFirstFloat())&&(!isFound)){
            
			if (_allActiveTasks[i]->isTimed()) {
                
                if (NewTimedTask->getStart()<_allActiveTasks[i]->getStart()){  //start of timedtask compared with start of timedtask

                    isFound=true;
					break;
					
                }
                
            } else if (_allActiveTasks[i]->isDeadline()) {
                
                if (NewTimedTask->getStart()<_allActiveTasks[i]->getEnd()){  //start of timedtask compared with end of deadline
                    
					isFound=true;
					break;
					
                }
            }
			i++;
        }
		
		_allActiveTasks.insert(_allActiveTasks.begin()+i, NewTimedTask);
		_addedIndex=i;
		
	}
	
	writeActiveFile();
}

void CMActive:: addActiveFloatingTask (FloatingTask* NewFloatingTask) {
	
	updateActiveHistory();
	_allActiveTasks.push_back(NewFloatingTask);
	writeActiveFile();
	int index = _allActiveTasks.size()-1;
	_addedIndex= index;
	
}

//---------------------------------------------------------------//

std:: string CMActive:: deleteActiveTask (int realIndex) {

	//lack of updateActivehistory() in the case of multiple delete
	std::string deletedTask= _allActiveTasks[realIndex]->getInfo();
		eraseTask(realIndex);
		writeActiveFile();
		return deletedTask;
	
}

void CMActive:: eraseTask(int realIndex){
	
	_allActiveTasks [realIndex] =  NULL;
	delete _allActiveTasks[realIndex]; //deleting the pointer
	_allActiveTasks.erase(_allActiveTasks.begin()+realIndex); //erasing the vector item containing the pointer
	
}


Task* CMActive:: getTask(int realIndex){ //linked to logic's edit function
	
	updateActiveHistory();
	Task* taskPointer= _allActiveTasks[realIndex];
	return taskPointer;
	
}

void CMActive:: clearActiveTasks(){
	
	updateActiveHistory();
	_allActiveTasks.clear();
	writeActiveFile();
	
}

std::string CMActive:: checkActive(int realIndex){
	
	//lack of updateActivehistory() in the case of multiple check
	std::string checkedTask= _allActiveTasks[realIndex]->getInfo();
	eraseTask(realIndex);
	writeActiveFile();
	return checkedTask;
	
}

void CMActive:: sortAllActiveTasks () {
	
	_allActiveTasks=_storageSort.sortTasks(_allActiveTasks, getActiveIndexFirstFloat());
	
}

void CMActive:: undoActiveTaskAction(){
	
	std::vector<Task*> _newAllTasks;
	_newAllTasks = _history.swapCopy(_allActiveTasks);
	_allActiveTasks = _newAllTasks;
	writeActiveFile();
	
}

//---------------------------------------------------------------//

int CMActive:: getAddedActiveTaskIndex () {
	
	return _addedIndex;

}

int CMActive:: getActiveIndexFirstFloat () {
	
	for (unsigned int i=0;i<_allActiveTasks.size();i++){
		
		if (_allActiveTasks[i]->isFloat()) {
			return i;
		}
	}
	
	int index=_allActiveTasks.size();
	return index;
	
}

int CMActive:: getEditedIndex(std::string desc,boost::posix_time::ptime start,boost::posix_time::ptime end){
	
	for (unsigned int i=0; i< _allActiveTasks.size() ; i++){
		
		if (_allActiveTasks[i]->isEditedTask(desc,start,end)){
			return i;
		}
	}
	
	return 0;
}

std::vector<Task*> CMActive:: getActiveTasks(){
	
	return _allActiveTasks;
	
}

//---------------------------------------------------------------//

void CMActive:: updateActiveHistory(){
	
	_history.updateCopy(_allActiveTasks);
	
}

//---------------------------------------------------------------//

void CMActive:: writeActiveFile() {
	
	_textFile.writeFile(_allActiveTasks, FILENAME);
	
}

std::vector<std::string> CMActive:: readActiveFile() {
	
	return _textFile.readFile(FILENAME);
	
}

void CMActive:: changeStorageLocation(std::string NewLocation) {
	
	_textFile.changeStorageLocation(NewLocation);
	writeActiveFile();
	
}

std::string CMActive:: getStorageLocation(){
	
	return _textFile.getStorageLocation();
	
}

