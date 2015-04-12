//@author A0115990B

#ifndef CHECKMATESTORAGE_H
#define CHECKMATESTORAGE_H

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

class CMStorage {

private: 
	
	std::vector<Task*> _searchedTasks; //all searched tasks as Task pointers
	
	std::vector<int> _subIndexes;
	
	std::string _displayMarker;
	std::string _checkUncheckMarker;

	CMArchive _completed;
	CMActive _active;
	CMStorageSort _storageSort;
	
	static const std::string DISPLAYS_HOME_PAGE;
	static const std::string DISPLAYS_SEARCHED_PAGE;
	static const std::string DISPLAYS_ARCHIVED_PAGE;
	static const std::string CHECKED_OR_UNCHECKED;
	
public:

	void addDeadline (Deadline*);
	void addTimedTask (TimedTask*);
	void addFloatingTask (FloatingTask*);
	
	void addArchivedDeadline (Deadline*); //Ar
	void addArchivedTimedTask (TimedTask*); //Ar
	void addArchivedFloatingTask (FloatingTask*); //Ar
	
	std:: string  deleteTask (int );
	Task* getTask(int); //for edit
	void writeEditedFile();
	void clearTasks();
	
	std::vector<Task*> getActiveDisplay();
	std::vector<Task*> getArchivedDisplay(); //Ar
	std::vector<Task*> getSearchedTasks(std::string);

	std::vector<std::string> readFile(); //TF
	void changeStorageLocation(std::string); //TF
	std::string getStorageLocation(); //TF
	std::vector<std::string> readArchivedFile(); //Ar
	
	std::string check(int);
	std::string uncheck(int);
	
	int getIndexFirstFloat ();
	int getDefaultIndexFirstFloat ();
	int getSearchedIndexFirstFloat ();
	
	int getEditedIndex(std::string,boost::posix_time::ptime,boost::posix_time::ptime);
	int getAddedIndex ();

	void sortAllTasks(); //Sort
	void sortSearchedTasks();

	void updateHistory();
	void updateArchivedHistory();//Ar
	
	void undoAction();

};

#endif