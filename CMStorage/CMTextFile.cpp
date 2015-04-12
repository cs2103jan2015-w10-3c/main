//
//  CMTextFile.cpp
//  testmypart
//
//  Created by Elaine Cai on 9/4/15.
//
//

#include "CMTextFile.h"

void CMTextFile:: writeFile(std::vector<Task*> _allTasks) {
	
	std::ofstream file;
	file.open(getStorageLocation()+"Checkmate.txt");
	int size=_allTasks.size();
	for(int i = 0; i < size; i++){
        file<<_allTasks[i]->getInfo()<<std::endl;
	}
	file.close();
}

std::vector<std::string> CMTextFile:: readFile() {
		
	std::ifstream read (getStorageLocation()+"Checkmate.txt");
	for (std::string line; getline(read,line);){
		_textFileStrings.push_back(line);
	}
	
	return _textFileStrings;
}

void CMTextFile :: changeStorageLocation(std::string NewLocation) {
	
	std::ofstream file;
	file.open("StorageLocation.txt");
	file << NewLocation;
	file.close();
	
}

std::string CMTextFile :: getStorageLocation(){
	
	std::ifstream read ("StorageLocation.txt");
	std::string line;
	getline(read,line);
	return line;
}