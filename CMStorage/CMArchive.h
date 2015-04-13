//@author A0115990B

#ifndef CMARCHIVE_H
#define CMARCHIVE_H

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
#include "CMTextFile.h"

class CMArchive {
	
private:
	
	std::vector<Task*> _completedTasks; //all completed tasks as Task pointers
	CMHistory _completedTasksHistory; //object in Archive
	CMTextFile _archiveTextFile;
	static const std::string ARCHIVE_FILENAME;

public:
	
	void addArchivedDeadline (Deadline*);
	void addArchivedTimedTask (TimedTask*);
	void addArchivedFloatingTask (FloatingTask*);
	std::string deleteCompletedTask (int);
	void eraseTask(int);
	void clearCompletedTasks();
	void undoArchivedTaskAction();
	
	std::vector<Task*> getArchivedDisplay();
	std::vector<Task*> getCompletedTasks();

	void writeArchivedFile();
	std::vector<std::string> readArchivedFile();
	
	void checkInArchive(Task*);
	std::string uncheckInArchive(int);
	
	void updateArchiveHistory();
	
};

#endif