#include "stdafx.h"
#include "checkmatestorage.h"

void CMStorage :: addDeadline (Deadline* NewDeadline) {
	
	history.updateCopy(_allTasks);
	_allTasks.push_back(NewDeadline); 
	writeFile();
}

void CMStorage :: addTimedTask (TimedTask* NewTimedTask){
	
	history.updateCopy(_allTasks);
	_allTasks.push_back(NewTimedTask);
	writeFile();

}

void CMStorage :: addFloatingTask (FloatingTask* NewFloatingTask) {

	history.updateCopy(_allTasks);
	_allTasks.push_back(NewFloatingTask);
	writeFile();

}

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
	std::vector<Task*>_subTasks;

	for (int i = 0; i < size; i++ ) {
		if (_allTasks[i]->isFound(Keyword)){
			_subTasks.push_back(_allTasks[i]);
			_subIndexes.push_back(i);
		}
	}

	return _subTasks;
}

void CMStorage:: setFileName (std::string Filename) {

	_filename=Filename;
}

void CMStorage:: writeFile() {   

	std::ofstream file;
	file.open(_filename);
	int size=_allTasks.size();
	for(int i = 0; i < size; i++){
        file<<_allTasks[i]->getInfo()<<std::endl;
	}
	file.close();
} 

std::vector<std::string> CMStorage:: readFile() {

	std::vector<std::string> textFileStrings;
	std::string line;

	std::ifstream read;
	read.open(_filename);
	while (!read.eof()){
		std::getline(read,line);
		textFileStrings.push_back(line);
	}

	return textFileStrings;
}

void CMStorage :: changeStorageLocation(LPCWSTR NewLocation) {
	
	const int bufferSize = MAX_PATH;
    char oldDir[bufferSize]; // store the current directory
    
    // get the current directory, and store it
    std::cout << "Current directory: " << oldDir << '\n';

    // new directory
    _location = NewLocation; //eg. C:\\Users\\Lai ling Yi\\Desktop
    if (!SetCurrentDirectory(_location)) {
        std::cerr << "Error setting current directory: #" << GetLastError() <<std::endl;
		system("pause"); // quit if we couldn't set the current directory
    }
    std::cout << "Set current directory to " << _location << '\n';
	
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
}