//@author A0115990B

#ifndef CMTEXTFILE_H
#define CMTEXTFILE_H

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include "Task.h"
#include "FloatingTask.h"
#include "TimedTask.h"
#include "Deadline.h"

class CMTextFile {

private:
	
	std::vector<std::string> _textFileStrings;
	static const std::string PARTITION_LINE;
	static const std::string DESCRIPTION;
	static const std::string START_DATE_AND_TIME;
	static const std::string END_DATE_AND_TIME;
	static const std::string STORAGE_FILE;

public:
	
	void writeFile(std::vector<Task*>, std::string);
	std::vector<std::string> readFile(std::string);
	std::string headings();
	void changeStorageLocation(std::string);
	std::string getStorageLocation();

};

#endif
