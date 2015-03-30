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
#include <windows.h>


class CMStorage {

	public: //changed for testing purpose

		std::vector<Task*> _allTasks; //all tasks as Task pointers
		std::vector<int> _subIndexes;
		std::string _filename;
		LPCSTR _location;
		CMHistory history;
		 
	public:

		void addDeadline (Deadline*);
		void addTimedTask (TimedTask*);
		void addFloatingTask (FloatingTask*);
		std::string deleteTask (int);
		std::vector<Task*> getDisplay();
		Task* getTask(int);
		std::vector<Task*> searchTask (std::string);
		void setFileName (std::string);
		void writeFile();   
		std::vector<std::string> readFile();
		void changeStorageLocation(LPCSTR);
		void undoAction();
		void redoAction();

};

#endif