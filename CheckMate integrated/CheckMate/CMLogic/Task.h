#pragma once
#include <iostream>
#include <string>

using namespace std;
//Base class
class Task
{
protected:
	string _Description;		//Describes what the task is about
	string _Category;			//Categorises task as personal/school/work



public:
	Task(string,string);
	~Task();
	void editDescription(string);
	void editCategory(string);

	string getDescription() const;
	string getCategory() const;

	bool Isfound(string);
};

