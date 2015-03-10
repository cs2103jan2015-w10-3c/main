#ifndef CHECKMATESTORAGE_H
#define CHECKMATESTORAGE_H

#include<iostream>
#include<vector>
#include"Task.h"

using namespace std;

class CheckMateStorage {

	private:

		vector<Task> v_tasks;

	public:
		void addTask(Task);
		void deleteTask (int);
};

#endif