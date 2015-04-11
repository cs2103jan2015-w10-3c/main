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
		std::vector<Task*> _searchedTasks; //all searched tasks as Task pointers
		std::vector<int> _subIndexes;
<<<<<<< HEAD
		std::vector<int> _subAIndexes; //storing sub-indexes for the completed tasks tab
=======
		std::string _filename;
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
		LPCSTR _location;
		CMHistory history;
		std::vector<Task*> _completedTasks; //all completed tasks as Task pointers
		int addedIndex;
		std::string _marker;

	public:

		void addDeadline (Deadline*);
		void addTimedTask (TimedTask*);
		void addFloatingTask (FloatingTask*);
<<<<<<< HEAD
		int getAddedIndex ();
		void addArchivedDeadline (Deadline*);
		void addArchivedTimedTask (TimedTask*);
		void addArchivedFloatingTask (FloatingTask*);
		std:: string  deleteTask (int );
=======
		std::string deleteTask (int);
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
		std::vector<Task*> getDisplay();
		std::vector<Task*> getArchivedDisplay();
		Task* getTask(int);
		std::vector<Task*> searchTask (std::string);
		void setFileName (std::string);
		void writeFile();   
		void writeArchivedFile();   
		std::vector<std::string> readFile();
		std::vector<std::string> readArchivedFile();
		void changeStorageLocation(std::string);
		void undoAction();
		void redoAction();
<<<<<<< HEAD
		void sortAllTasks();
		std::string getStorageLocation();
		std::string check(int);
		std::string uncheck(int);
		int getIndexFirstFloat ();
		void clearTasks();
=======
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e

};

#endif