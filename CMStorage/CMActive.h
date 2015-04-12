//
//  CMActive.h
//  testmypart
//
//  Created by Elaine Cai on 12/4/15.
//
//

#ifndef CMActive_H
#define CMActive_H

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include "Task.h"
#include "FloatingTask.h"
#include "TimedTask.h"
#include "Deadline.h"
#include "CMHistory.h"
#include "CMArchive.h"
#include "CMTextFile.h"
#include "CMStorageSort.h"
#include "CMActive.h"

class CMActive {

private:

	//vectors of Task*:
	std::vector<Task*> _allActiveTasks; //all tasks as Task pointers
	//std::vector<Task*> _searchedTasks; //all searched tasks as Task pointers
	
	//std::vector<int> _subIndexes;
	int _addedIndex;
	
	std::string _displayMarker;
	std::string _checkUncheckMarker;
	
	CMHistory _history;
	CMTextFile _textFile;
	CMStorageSort _storageSort;
	
	static const std::string DISPLAYS_HOME_PAGE;
	static const std::string DISPLAYS_SEARCHED_PAGE;
	static const std::string DISPLAYS_ARCHIVED_PAGE;
	static const std::string CHECKED_OR_UNCHECKED;
	
	
public:
	void addActiveDeadline (Deadline*);
	void addActiveTimedTask (TimedTask*);
	void addActiveFloatingTask (FloatingTask*);
	int getAddedActiveIndex ();
	std:: string  deleteActiveTask (int );
	Task* getTask(int);
	std::string check(int);
	int getIndexFirstFloat ();
	int getDefaultIndexFirstFloat ();
	void clearTasks();
	void eraseTask(int);
	void sortAllTasks(); //Sort
	void sortSearchedTasks();
	int getEditedIndex(std::string,boost::posix_time::ptime,boost::posix_time::ptime);
	void updateHistory();
	void undoActiveTaskAction();
	void writeFile();
	std::vector<std::string> readFile();
	std::vector<Task*> getActiveTasks();
	std::vector<int> getSubIndexes ();
	void changeStorageLocation(std::string);
	std::string getStorageLocation();

};


#endif
