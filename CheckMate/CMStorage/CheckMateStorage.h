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

	private:

		std::vector<Task*> _allTasks; //all tasks as Task pointers
		std::vector<int> _subIndexes;
		CMHistory history;
		 
	public:

		void addDeadline (Deadline*);
		void addTimedTask (TimedTask*);
		void addFloatingTask (FloatingTask*);
		std::string deleteTask (int);
		std::vector<std::string> getDisplay();
		Task* getTask(int);
		std::vector<std::string> searchTask (std::string);
		void writeFile(std::string);   
		void changeStorageLocation(const char*);
		void undoAction();
		void redoAction();

};

#endif