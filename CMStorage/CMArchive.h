//
//  CMArchive.h
//  testmypart
//
//  Created by Elaine Cai on 9/4/15.
//
//

#ifndef CMArchive_H
#define CMArchive_H

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


class CMArchive {
	
private:
	std::vector<Task*> _completedTasks; //all completed tasks as Task pointers
	CMHistory _completedTasksHistory; //object in Archive

public:
	void addArchivedDeadline (Deadline*);
	void addArchivedTimedTask (TimedTask*);
	void addArchivedFloatingTask (FloatingTask*);
	std::vector<Task*> getArchivedDisplay();
	void writeArchivedFile();
	std::vector<std::string> readArchivedFile();
	void checkInArchive(Task*);
	std::string uncheckInArchive(int);
	void eraseTask(int);
	std::string deleteCompletedTask (int);
	std::vector<Task*> getCompletedTasks();
	void undoArchivedTaskAction();
	void updateArchiveHistory();
	void clearCompletedTasks();
	
};

#endif