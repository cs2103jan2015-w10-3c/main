//@author A0115990B

#ifndef CMACTIVE_H
#define CMACTIVE_H

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

//CMActive is responsible for all the active tasks. basic functions such as add,delete,etc are performed here.
//typically, have to make sure that everything is sorted according to the time and date;
//a CMHistory object is called to store the history of previous vector for undo/redo function,
//a CMTextFile object is called to write the information into a textfile
//a CMStorageSort object is called to sort the tasks chronologically

class CMActive {

private:

	std::vector<Task*> _allActiveTasks;
	int _addedIndex;
	
	CMHistory _history;
	CMTextFile _textFile;
	CMStorageSort _storageSort;
	
	static const std::string FILENAME;
	
public:
	
	void addActiveDeadline (Deadline*);
	void addActiveTimedTask (TimedTask*);
	void addActiveFloatingTask (FloatingTask*);
	
	std:: string  deleteActiveTask (int );
	void eraseTask(int); //not returning anything
	Task* getTask(int); //linked to main storage to logic's edit function
	void clearActiveTasks();
	std::string checkActive(int);
	void sortAllActiveTasks(); 
	void undoActiveTaskAction();
	
	int getAddedActiveTaskIndex ();
	int getActiveIndexFirstFloat ();
	int getEditedIndex(std::string,boost::posix_time::ptime,boost::posix_time::ptime);
	std::vector<Task*> getActiveTasks();
	
	void updateActiveHistory();
		
	void writeActiveFile();
	std::vector<std::string> readActiveFile();
	void changeStorageLocation(std::string);
	std::string getStorageLocation();

};

#endif
