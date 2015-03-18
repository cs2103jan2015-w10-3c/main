#include "checkmatestorage.h"

void CMStorage :: addDeadline (Deadline* NewDeadline) {
	
	_allTasks.push_back(NewDeadline); 
	
}

void CMStorage :: addTimedTask (TimedTask* NewTimedTask){
	_allTasks.push_back(NewTimedTask);

}

void CMStorage :: addFloatingTask (FloatingTask* NewFloatingTask) {

	_allTasks.push_back(NewFloatingTask);

}

std:: string CMStorage :: deleteTask (int index) {

	int realindex= _subIndexes[index-1];
	std::string deletedTask= _allTasks[realindex]->getInfo();
	_allTasks [realindex] =  NULL; 
	delete _allTasks[realindex]; //deleting the pointer
	_allTasks.erase(_allTasks.begin()+realindex); //erasing the vector item containing the pointer
	_subIndexes.clear();

	return deletedTask;

}

std::vector<std::string> CMStorage :: getDisplay (void) {

	std::vector<std::string> _displayTasks; 


	for (size_t i = 0; i < _allTasks.size(); i++){
		_displayTasks.push_back(_allTasks[i] -> getInfo());
	}

	return _displayTasks;

}

/* void CMStorage :: editStartDate (int index, string NewStartDate) {

	_allTasks[index] -> editStartDate (NewStartDate);

}

void CMStorage :: editStartTime (int index, string NewStartTime) {

	_allTasks[index] -> editStartTime (NewStartTime);

}

void CMStorage :: editEndDate (int index, string NewEndDate) {

	_allTasks[index] -> editEndDate (NewEndDate);

}

void CMStorage :: editEndTime (int index, string NewEndTime) {

	_allTasks[index] -> editEndTime (NewEndTime);

}

void CMStorage :: editDescription(int index, string NewDescription) {

	_allTasks[index] -> editDescription (NewDescription);
}

void CMStorage :: editCategory(int index, string NewCategory) {

	_allTasks[index] -> editCategory (NewCategory);
} */

std::vector<std::string> CMStorage :: searchTask (std::string Keyword) {

	int size = _allTasks.size();

	for (int i = 0; i < size; i++ ) {
		if (_allTasks[i]->isFound(Keyword)){
			_subTasks.push_back(_allTasks[i]->getInfo());
			_subIndexes.push_back(i);
		}
	}

	return _subTasks;
}

void CMStorage:: writeFile(std::string Filename) {   

	std::ofstream file;
	file.open(Filename);
	int size=_allTasks.size();
	for(int i = 0; i < size; i++){
        file<<_allTasks[i]->getInfo()<<std::endl;
	}
	file.close();
} 
void CMStorage :: changeStorageLocation(const char* NewLocation) {
	
	const int bufferSize = MAX_PATH;
    char oldDir[bufferSize]; // store the current directory
    
    // get the current directory, and store it
    if (!GetCurrentDirectory(bufferSize, oldDir)) {
        std::cerr << "Error getting current directory: #" << GetLastError();
        system ("pause"); // quit if it failed
    }
    std::cout << "Current directory: " << oldDir << '\n';

    // new directory
    const char* newDir = NewLocation; //eg. C:\\Users\\Lai ling Yi\\Desktop
    if (!SetCurrentDirectory(newDir)) {
        std::cerr << "Error setting current directory: #" << GetLastError() <<std::endl;
		system("pause"); // quit if we couldn't set the current directory
    }
    std::cout << "Set current directory to " << newDir << '\n';
}