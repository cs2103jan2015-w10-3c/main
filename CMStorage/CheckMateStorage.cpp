#include "checkmatestorage.h"

void CMStorage :: addDeadline (Deadline* NewDeadline) {
	
	history.updateCopy(_allTasks);
<<<<<<< HEAD
	if (_allTasks.size()==0) {
		_allTasks.push_back(NewDeadline);
		addedIndex=0;
	}
	else {
		unsigned int i=0;
		while( i<_allTasks.size() && ((_allTasks[i]->getStart())!=ptime()) && (NewDeadline->getStart()>_allTasks[i]->getStart())){
			i++;						
		} 
		_allTasks.insert(_allTasks.begin()+i, NewDeadline);
		addedIndex=i;
	}
	
=======
	_allTasks.push_back(NewDeadline); 
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
	writeFile();
}

void CMStorage :: addTimedTask (TimedTask* NewTimedTask){
	
	history.updateCopy(_allTasks);
<<<<<<< HEAD
	if (_allTasks.size()==0) {
		_allTasks.push_back(NewTimedTask);
		addedIndex=0;

	}
	else {
		unsigned int i=0;
		while( i<_allTasks.size() && ((_allTasks[i]->getStart())!=ptime()) && (NewTimedTask->getStart()>_allTasks[i]->getStart())){
			i++;						

		} 
		_allTasks.insert(_allTasks.begin()+i, NewTimedTask);
		addedIndex=i;

	}
=======
	_allTasks.push_back(NewTimedTask);
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
	writeFile();

}

void CMStorage :: addFloatingTask (FloatingTask* NewFloatingTask) {

	history.updateCopy(_allTasks);
	_allTasks.push_back(NewFloatingTask);
	writeFile();
	int size = _allTasks.size()-1;
	addedIndex=size;

}

int CMStorage:: getAddedIndex () {
	return addedIndex;
}

void CMStorage :: addArchivedDeadline (Deadline* NewDeadline) {

	_completedTasks.push_back(NewDeadline);
	writeArchivedFile();
}

<<<<<<< HEAD
void CMStorage :: addArchivedTimedTask (TimedTask* NewTimedTask) {

	_completedTasks.push_back(NewTimedTask);
	writeArchivedFile();
}

void CMStorage :: addArchivedFloatingTask (FloatingTask* NewFloatingTask) {

	_completedTasks.push_back(NewFloatingTask);
	writeArchivedFile();
}

=======
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
std:: string CMStorage :: deleteTask (int index) {

	history.updateCopy(_allTasks);
	int realIndex= _subIndexes[index-1];
	std::string deletedTask= _allTasks[realIndex]->getInfo();
	_allTasks [realIndex] =  NULL; 
	delete _allTasks[realIndex]; //deleting the pointer
	_allTasks.erase(_allTasks.begin()+realIndex); //erasing the vector item containing the pointer
	_subIndexes.clear();
	writeFile();

	return deletedTask;
}

std::vector<Task*> CMStorage :: getDisplay (void) {

	_subIndexes.clear();
	std::vector<Task*> _displayTasks; 

	for (unsigned int i = 0; i < _allTasks.size(); i++){
		_displayTasks.push_back(_allTasks[i]);
		_subIndexes.push_back(i);
	}

	_marker="home";
	return _displayTasks;

}


Task* CMStorage :: getTask(int index){ //linked to logic's edit function
 
	history.updateCopy(_allTasks);
	int realIndex= _subIndexes[index-1];
	Task* taskPointer= _allTasks[realIndex];
	_subIndexes.clear();
	return taskPointer;

}


std::vector<Task*> CMStorage :: searchTask (std::string Keyword) {

	_subIndexes.clear();
	int size = _allTasks.size();
	_searchedTasks.clear();

	for (int i = 0; i < size; i++ ) {
		if (_allTasks[i]->isFound(Keyword)){
			_searchedTasks.push_back(_allTasks[i]);
			_subIndexes.push_back(i);
		}
	}
	_marker="searched";
	return _searchedTasks;
}

void CMStorage:: setFileName (std::string Filename) {

	_filename=Filename;
}

void CMStorage:: writeFile() {   

	std::ofstream file;
<<<<<<< HEAD
	file.open(getStorageLocation()+"checkmate.txt");
=======
	file.open(_filename);
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
	int size=_allTasks.size();
	for(int i = 0; i < size; i++){
        file<<_allTasks[i]->getInfo()<<std::endl;
	}
	file.close();
} 

std::vector<std::string> CMStorage:: readFile() {

	std::vector<std::string> textFileStrings;

<<<<<<< HEAD
	std::ifstream read (getStorageLocation()+"checkmate.txt");
	for (std::string line; getline(read,line);){
=======
	std::ifstream read;
	read.open(_filename);
	while (!read.eof()){
		std::getline(read,line);
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
		textFileStrings.push_back(line);
	}

	return textFileStrings;
}


void CMStorage :: changeStorageLocation(std::string NewLocation) {

	std::ofstream file;
	file.open("StorageLocation.txt");
	file<<NewLocation;
	file.close();
	writeFile();
	
}

void CMStorage:: undoAction() {
	
	std::vector<Task*> _newAllTasks;
	_newAllTasks = history.swapCopy(_allTasks);
	_allTasks = _newAllTasks;
}

void CMStorage:: redoAction() {
	 
	std::vector<Task*> _newAllTasks;
	_newAllTasks = history.swapCopy(_allTasks);
	_allTasks = _newAllTasks;
<<<<<<< HEAD
}


std::string CMStorage :: getStorageLocation(){

	std::ifstream read ("StorageLocation.txt");
	std::string line;
	getline(read,line);
	return line;
}

std::string CMStorage:: check(int index){

	history.updateCopy(_allTasks);
	int realIndex= _subIndexes[index-1];
	_completedTasks.push_back(_allTasks[realIndex]);
	std::string checkedTask= _allTasks[realIndex]->getInfo();
	_allTasks [realIndex] =  NULL; 
	delete _allTasks[realIndex]; //deleting the pointer
	_allTasks.erase(_allTasks.begin()+realIndex); //erasing the vector item containing the pointer
	_subIndexes.clear();
	writeArchivedFile();
	return checkedTask;

}

std::string CMStorage:: uncheck (int index){ //if the task has been checked as completed, now uncheck it and it becomes active again

	history.updateCopy(_allTasks);
	int realIndex= _subAIndexes[index-1];
	_allTasks.push_back(_completedTasks[realIndex]);
	std::string uncheckedTask= _completedTasks[realIndex]->getInfo();
	_completedTasks [realIndex] =  NULL; 
	delete _completedTasks[realIndex]; //deleting the pointer
	_completedTasks.erase(_completedTasks.begin()+realIndex); //erasing the vector item containing the pointer
	_subAIndexes.clear();
	writeArchivedFile();
	return uncheckedTask;

}

std::vector<Task*> CMStorage :: getArchivedDisplay (void) {

	_subAIndexes.clear();
	std::vector<Task*> _displayCompletedTasks; 

	for (unsigned int i = 0; i < _completedTasks.size(); i++){
		_displayCompletedTasks.push_back(_completedTasks[i]);
		_subAIndexes.push_back(i);
	}

	return _displayCompletedTasks;

}

void CMStorage:: writeArchivedFile() {   

	std::ofstream file;
	file.open("ArchivedCheckmate.txt");
	int size=_completedTasks.size();
	for(int i = 0; i < size; i++){
        file<<_completedTasks[i]->getInfo()<<std::endl;
	}
	file.close();
} 

std::vector<std::string> CMStorage:: readArchivedFile() {

	std::vector<std::string> textFileStrings;

	std::ifstream read ("ArchivedCheckmate.txt");
	for (std::string line; getline(read,line);){
		textFileStrings.push_back(line);
	}

	return textFileStrings;
}

int CMStorage:: getIndexFirstFloat () {
	
	if (_marker=="home"){
	for (unsigned int i=0;i<_allTasks.size();i++){
		if (_allTasks[i]->isFloat()) {
			return i;
		}
	
	}

	int index=_allTasks.size();
	return index; 

	} else if (_marker=="string"){
	
	for (unsigned int i=0;i<_searchedTasks.size();i++){
		if (_searchedTasks[i]->isFloat()) {
			return i;
		}
	
	}

	int index=_searchedTasks.size();
	return index; 
	
	} else return 0;

}

void CMStorage:: clearTasks(){

	history.updateCopy(_allTasks);
	_allTasks.clear();
	writeFile();
}

=======
}
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
