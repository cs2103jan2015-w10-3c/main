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
		std::string _filename;
		LPCWSTR _location;
		CMHistory history;
		 
	public:

		void addDeadline (Deadline*);
		void addTimedTask (TimedTask*);
		void addFloatingTask (FloatingTask*);
		std::string deleteTask (int);
		std::vector<std::string> getDisplay();
		Task* getTask(int);
<<<<<<< HEAD
		std::vector<std::string> searchTask (std::string);
		void writeFile(std::string);   
		void changeStorageLocation(const char*);
=======
		std::vector<Task*> searchTask (std::string);
		void setFileName (std::string);
		void writeFile();   
		std::vector<std::string> readFile();
		void changeStorageLocation(LPCWSTR);
>>>>>>> 92d2ce6a480266df894bd2ceee7de2a48730e5d2
		void undoAction();
		void redoAction();

};

#endif