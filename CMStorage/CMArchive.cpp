//@author A0115990B

#include "CMArchive.h"

const std::string CMArchive:: ARCHIVE_FILENAME = "ArchivedCheckmate.txt";


void CMArchive:: addArchivedDeadline (Deadline* NewDeadline) {
	
	updateArchiveHistory();
	_completedTasks.push_back(NewDeadline);
	writeArchivedFile();
	
}

void CMArchive:: addArchivedTimedTask (TimedTask* NewTimedTask) {
	
	updateArchiveHistory();
	_completedTasks.push_back(NewTimedTask);
	writeArchivedFile();
	
}

void CMArchive:: addArchivedFloatingTask (FloatingTask* NewFloatingTask) {
	
	updateArchiveHistory();
	_completedTasks.push_back(NewFloatingTask);
	writeArchivedFile();
	
}

std::string CMArchive:: deleteCompletedTask (int realIndex){
	
	//lack of updateArchivehistory() in the case of multiple delete
	std::string deletedTask= _completedTasks[realIndex]->getInfo();
	eraseTask(realIndex);
	writeArchivedFile();
	return deletedTask;
	
}

void CMArchive:: eraseTask(int realIndex){
	
	_completedTasks [realIndex] =  NULL;
	delete _completedTasks[realIndex]; //deleting the pointer
	_completedTasks.erase(_completedTasks.begin()+realIndex); //erasing the vector item containing the pointer
	
}

void CMArchive:: clearCompletedTasks(){
	
	updateArchiveHistory();
	_completedTasks.clear();
	writeArchivedFile();
	
}

void CMArchive:: undoArchivedTaskAction() {
	
	std::vector<Task*> _newCompletedTasks;
	_newCompletedTasks = _completedTasksHistory.swapCopy(_completedTasks);
	_completedTasks = _newCompletedTasks;
	writeArchivedFile();
	
}

std::vector<Task*> CMArchive:: getArchivedDisplay (void) {
	
	std::vector<Task*> _displayCompletedTasks;
	
	for (unsigned int i = 0; i < _completedTasks.size(); i++){
		
		_displayCompletedTasks.push_back(_completedTasks[i]);
	
	}
	
	return _displayCompletedTasks;
	
}

std::vector<Task*> CMArchive:: getCompletedTasks(){
	
	return _completedTasks;

}


void CMArchive:: writeArchivedFile() {
	
	_archiveTextFile.writeFile(_completedTasks, ARCHIVE_FILENAME);
	
}

std::vector<std::string> CMArchive:: readArchivedFile() {
	
	return _archiveTextFile.readFile(ARCHIVE_FILENAME);
	
}

void CMArchive:: checkInArchive(Task* task){
	
	//lack of updateArchivehistory() in the case of multiple check
	_completedTasks.push_back(task);
	writeArchivedFile();
	
}

std::string CMArchive:: uncheckInArchive (int realIndex){ 
	
	//lack of updateArchivehistory() in the case of multiple uncheck
	std::string uncheckedTask= _completedTasks[realIndex]->getInfo();
	eraseTask(realIndex);
	writeArchivedFile();
	return uncheckedTask;
	
}

void CMArchive:: updateArchiveHistory(){
	
	_completedTasksHistory.updateCopy(_completedTasks);
	
}





