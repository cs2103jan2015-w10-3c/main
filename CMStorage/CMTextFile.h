//
//  CMTextFile.h
//  testmypart
//
//  Created by Elaine Cai on 9/4/15.
//
//

#ifndef CMTextFile_H
#define CMTextFile_H

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include "Task.h"
#include "FloatingTask.h"
#include "TimedTask.h"
#include "Deadline.h"

//purely for active tasks

class CMTextFile {

private:
	std::vector<std::string> _textFileStrings;
	
public:
	void writeFile(std::vector<Task*>);
	std::vector<std::string> readFile();
	void changeStorageLocation(std::string);
	std::string getStorageLocation();

};

#endif
