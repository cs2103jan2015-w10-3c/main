//@author A0115990B

#include "CMTextFile.h"

const std::string CMTextFile:: PARTITION_LINE = "===========================================================================================================================";
const std::string CMTextFile:: DESCRIPTION = "DESCRIPTION" ;
const std::string CMTextFile:: START_DATE_AND_TIME = "START";
const std::string CMTextFile:: END_DATE_AND_TIME = "END";
const std::string CMTextFile:: STORAGE_FILE = "StorageLocation.txt";

void CMTextFile:: writeFile(std::vector<Task*> _allTasks, std::string fileName) {
	
	std::ofstream file;
	file.open(getStorageLocation()+ fileName);
	
	file<<headings();
	
	int size=_allTasks.size();
	for(int i = 0; i < size; i++){
		
        file<<_allTasks[i]->getInfo()<<std::endl;
	
	}
	file.close();
	
}

std::vector<std::string> CMTextFile:: readFile(std::string fileName) {
		
	std::ifstream read (getStorageLocation()+fileName);
	
	std::string buffer; //buffer to get rid of the first three lines for headings
	getline(read,buffer);
	getline(read,buffer);
	getline(read,buffer);

	for (std::string line; getline(read,line);){
		
		_textFileStrings.push_back(line);
	
	}
	
	return _textFileStrings;
	
}

std::string CMTextFile:: headings () {
	
	std::ostringstream oss;
	oss << PARTITION_LINE << std::endl << std::left << std::setw(60) <<
	DESCRIPTION << std::setw(36) << START_DATE_AND_TIME << std::setw(38) <<
	END_DATE_AND_TIME << std::endl << PARTITION_LINE << std::endl;
	
	return oss.str();

}

void CMTextFile:: changeStorageLocation(std::string NewLocation) {
	
	std::ofstream file;
	file.open(STORAGE_FILE);
	file << NewLocation;
	file.close();
	
}

std::string CMTextFile:: getStorageLocation(){
	
	std::ifstream read (STORAGE_FILE);
	std::string line;
	getline(read,line);
	return line;
	
}