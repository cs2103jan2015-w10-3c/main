#include "checkmatestorage.h"


const std::string CMStorage:: DISPLAYS_HOME_PAGE = "home";
const std::string CMStorage:: DISPLAYS_SEARCHED_PAGE = "searched";
const std::string CMStorage:: DISPLAYS_ARCHIVED_PAGE = "archive";
const std::string CMStorage:: CHECKED_OR_UNCHECKED = "checkedOrUnchecked";

//---------------------------------------------------------------//

void CMStorage :: addDeadline (Deadline* newDeadline) {
	
	_active.addActiveDeadline(newDeadline);
    std::cout<<"STORAGE:"<<"Added "<<newDeadline->Task::getInfo();
	
}

void CMStorage :: addTimedTask (TimedTask* newTimedTask){
	
    _active.addActiveTimedTask(newTimedTask);
}

void CMStorage :: addFloatingTask (FloatingTask* newFloatingTask) {

	_active.addActiveFloatingTask(newFloatingTask);

}

//---------------------------------------------------------------//

void CMStorage :: addArchivedDeadline (Deadline* newDeadline) {

	_completed.addArchivedDeadline(newDeadline);
	
}

void CMStorage :: addArchivedTimedTask (TimedTask* newTimedTask) {
	
	_completed.addArchivedTimedTask(newTimedTask);
	
}

void CMStorage :: addArchivedFloatingTask (FloatingTask* newFloatingTask) {
	
	_completed.addArchivedFloatingTask(newFloatingTask);
	
}

//---------------------------------------------------------------//


std:: string CMStorage :: deleteTask (int index) {

	if (_displayMarker!=DISPLAYS_ARCHIVED_PAGE){
		int realIndex= _subIndexes[index-1];
		return _active.deleteActiveTask(realIndex);
	} else {
		int realIndex= index - 1;
		return _completed.deleteCompletedTask(realIndex);
	}
}

Task* CMStorage :: getTask(int index){ //linked to logic's edit function
	
	int realIndex= _subIndexes[index-1];
	return _active.getTask(realIndex);
	
}

void CMStorage:: writeEditedFile () { //linked to logic's edit function
	
	_active.writeFile();
	
}

void CMStorage:: clearTasks(){
	
	_active.clearTasks();
	_completed.clearCompletedTasks();
	
}

//---------------------------------------------------------------//


std::vector<Task*> CMStorage :: getActiveDisplay (void) {

	_subIndexes.clear();
	std::vector<Task*> _displayTasks; 
	sortAllTasks();
		
	for (unsigned int i = 0; i <_active.getActiveTasks().size(); i++){
		_displayTasks.push_back(_active.getActiveTasks()[i]);
		_subIndexes.push_back(i);
	}

	_displayMarker=DISPLAYS_HOME_PAGE;
	return _displayTasks;

}

std::vector<Task*> CMStorage :: getArchivedDisplay (void) {
	
	_displayMarker=DISPLAYS_ARCHIVED_PAGE;
	return _completed.getArchivedDisplay();
	
}

std::vector<Task*> CMStorage :: getSearchedTasks(std::string keyword) {

	_subIndexes.clear();
	_searchedTasks.clear();
	
	for (unsigned int i = 0; i < _active.getActiveTasks().size(); i++ ) {
		if (_active.getActiveTasks()[i]->isFound(keyword)){
			_searchedTasks.push_back(_active.getActiveTasks()[i]);
			_subIndexes.push_back(i);
		}
	}
    
    sortSearchedTasks();
	_displayMarker=DISPLAYS_SEARCHED_PAGE;
	return _searchedTasks; //will be sorted

}

//---------------------------------------------------------------//


std::vector<std::string> CMStorage:: readFile() {

	return _active.readFile();
}


void CMStorage :: changeStorageLocation(std::string newLocation) {

	_active.changeStorageLocation(newLocation);
	
}

std::string CMStorage :: getStorageLocation(){
	
	return _active.getStorageLocation();
	
}

std::vector<std::string> CMStorage:: readArchivedFile() {
	
	return _completed.readArchivedFile();
	
}

//---------------------------------------------------------------//

std::string CMStorage:: check(int index){

	_checkUncheckMarker=CHECKED_OR_UNCHECKED;
	int realIndex= _subIndexes[index-1];
	_completed.checkInArchive(_active.getActiveTasks()[realIndex]);
	return _active.check(realIndex);
}

std::string CMStorage:: uncheck (int index){ //if the task has been checked as completed, now uncheck it and it becomes active again

	_checkUncheckMarker=CHECKED_OR_UNCHECKED;
	int realIndex=index - 1;
	return _completed.uncheckInArchive(realIndex); //return unchecked task

}

//---------------------------------------------------------------//


int CMStorage:: getIndexFirstFloat () {
	
	if (_displayMarker==DISPLAYS_HOME_PAGE){
		
		return getDefaultIndexFirstFloat();

	} else if (_displayMarker==DISPLAYS_SEARCHED_PAGE){
	
		return getSearchedIndexFirstFloat();
	
	} else {
		
		return 0;
	}
}

int CMStorage:: getDefaultIndexFirstFloat () { //the whole _allActiveTasks vector
	
	return _active.getDefaultIndexFirstFloat();
		
}

int CMStorage:: getSearchedIndexFirstFloat() {
	
	for (unsigned int i=0;i<_searchedTasks.size();i++){
		
		if (_searchedTasks[i]->isFloat()) {
			return i;
		}
	}
	
	int index=_searchedTasks.size();
	return index;

}

//---------------------------------------------------------------//


int CMStorage :: getEditedIndex(std::string desc,boost::posix_time::ptime start,boost::posix_time::ptime end){
	
	return _active.getEditedIndex (desc, start, end);
	
}

int CMStorage:: getAddedIndex () {
	
	return _active.getAddedActiveIndex();
    
}

//---------------------------------------------------------------//

void CMStorage :: sortAllTasks () { //no need to sort archived/completed tasks
	
	_active.sortAllTasks();
	
}

void CMStorage :: sortSearchedTasks () {
	
	_searchedTasks= _storageSort.sortAllTasks(_searchedTasks, getSearchedIndexFirstFloat());
	
}

//---------------------------------------------------------------//

void CMStorage:: updateHistory(){
	_active.updateHistory();
}

void CMStorage:: updateArchivedHistory(){
	_completed.updateArchiveHistory();
}

//---------------------------------------------------------------//

void CMStorage:: undoAction() {
	
	if (_checkUncheckMarker==CHECKED_OR_UNCHECKED){
		_active.undoActiveTaskAction();
		_completed.undoArchivedTaskAction();
	} else if (_displayMarker!=DISPLAYS_ARCHIVED_PAGE){
		_active.undoActiveTaskAction();
	} else {
		_completed.undoArchivedTaskAction();
	}
}