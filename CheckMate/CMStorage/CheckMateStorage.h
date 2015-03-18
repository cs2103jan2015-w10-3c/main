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
#include <windows.h>

class CMStorage {

	private:

		std::vector<Task*> _allTasks; //all tasks as Task pointers
		std::vector<std::string> _subTasks; //tasks being searched for in strings
		std::vector<int> _subIndexes;

	public:

		void addDeadline (Deadline*);
		void addTimedTask (TimedTask*);
		void addFloatingTask (FloatingTask*);
		std::string deleteTask (int);
		std::vector<std::string> getDisplay();
		/* void editStartDate (int, string);
		void editStartTime (int, string);
		void editEndDate (int, string);
		void editEndTime (int, string);
		void editDescription (int, string);
		void editCategory (int, string); */
		std::vector<std::string> searchTask (std::string);
		void writeFile(std::string);   
		void changeStorageLocation(const char*);

};

#endif