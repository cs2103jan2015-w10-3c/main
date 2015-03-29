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

using namespace std;

class CMStorage {

	private:

		vector<Task*> v_tasks; //all tasks as Task pointers
		vector<string> display_tasks; //all tasks in strings
		vector<string> subtasks; //tasks being searched for in strings
		vector<int> subindexes; //indexes for the tasks being searched for 

	public:

		void addDeadline (string, string, string, string);
		void addTimedTask (string, string, string, string, string, string);
		void addFloatingTask (string, string);
		string deleteTask (int);
		vector<string> getDisplay();
		void editStartDate (int, string);
		void editStartTime (int, string);
		void editEndDate (int, string);
		void editEndTime (int, string);
		void editDescription(int, string);
		void editCategory(int, string);
		vector<string> searchTask (string);
		void writeFile(string);   
		void changeStorageLocation(const char*);

};

#endif