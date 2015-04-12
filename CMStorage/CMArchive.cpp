//
//  CMArchive.cpp
//  testmypart
//
//  Created by Elaine Cai on 9/4/15.
//
//

#include "CMArchive.h"

void CMArchive :: addArchivedDeadline (Deadline* NewDeadline) {
	
	updateArchiveHistory();
	_completedTasks.push_back(NewDeadline);
	writeArchivedFile();
}

void CMArchive :: addArchivedTimedTask (TimedTask* NewTimedTask) {
	
	updateArchiveHistory();
	_completedTasks.push_back(NewTimedTask);
	writeArchivedFile();
}

void CMArchive :: addArchivedFloatingTask (FloatingTask* NewFloatingTask) {
	
	updateArchiveHistory();
	_completedTasks.push_back(NewFloatingTask);
	writeArchivedFile();
}

std::vector<Task*> CMArchive :: getArchivedDisplay (void) {
	
	std::vector<Task*> _displayCompletedTasks;
	
	for (unsigned int i = 0; i < _completedTasks.size(); i++){
		_displayCompletedTasks.push_back(_completedTasks[i]);
	}
	
	return _displayCompletedTasks;
	
}

void CMArchive:: writeArchivedFile() {
	
	std::ofstream file;
	file.open("ArchivedCheckmate.txt");
	int size=_completedTasks.size();
	for(int i = 0; i < size; i++){
        file<<_completedTasks[i]->getInfo()<<std::endl;
	}
	file.close();
}

std::vector<std::string> CMArchive:: readArchivedFile() {
	
	std::vector<std::string> textFileStrings;
	
	std::ifstream read ("ArchivedCheckmate.txt");
	for (std::string line; getline(read,line);){
		textFileStrings.push_back(line);
	}
	
	return textFileStrings;
}

void CMArchive:: checkInArchive(Task* task){
	
	//lack of update history for multiple check
	_completedTasks.push_back(task);
	writeArchivedFile();
}

std::string CMArchive:: uncheckInArchive (int realIndex){ //if the task has been checked as completed, now uncheck it and it becomes active again
	
	//lack of update history for multiple uncheck
	std::string uncheckedTask= _completedTasks[realIndex]->getInfo();
	eraseTask(realIndex);
	//	_subAIndexes.clear();
	writeArchivedFile();
	return uncheckedTask;
	
}

void CMArchive:: eraseTask(int realIndex){
	
	_completedTasks [realIndex] =  NULL;
	delete _completedTasks[realIndex]; //deleting the pointer
	_completedTasks.erase(_completedTasks.begin()+realIndex); //erasing the vector item containing the pointer
	
}

std::string CMArchive:: deleteCompletedTask (int realIndex){
	
	std::string deletedTask= _completedTasks[realIndex]->getInfo();
	eraseTask(realIndex);
	writeArchivedFile();
	return deletedTask;
}


void CMArchive:: updateArchiveHistory(){
	_completedTasksHistory.updateCopy(_completedTasks);
}

std::vector<Task*> CMArchive:: getCompletedTasks(){
	return _completedTasks;
}

void CMArchive:: undoArchivedTaskAction() {
	
	std::vector<Task*> _newCompletedTasks;
	_newCompletedTasks = _completedTasksHistory.swapCopy(_completedTasks);
	_completedTasks = _newCompletedTasks;
	writeArchivedFile();
}


void CMArchive:: clearCompletedTasks(){
	
	updateArchiveHistory();
	_completedTasks.clear();
	writeArchivedFile();
}