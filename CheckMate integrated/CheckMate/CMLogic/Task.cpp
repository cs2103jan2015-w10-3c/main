#include "Task.h"
#include <iostream>
#include <algorithm>

using namespace std;

Task::Task(string Description, string category)
{
	_Description= Description;
	_Category= category;
} 
Task::~Task(void)
{}

void Task:: editDescription(string NewDescription){
	_Description = NewDescription;
}

void Task:: editCategory(string NewCategory){
	_Category = NewCategory;
}

string Task:: getDescription() const{
	return _Description;
}
string Task:: getCategory() const{
	return _Category;
}

bool Task :: Isfound(string keyword){
	bool found = false;
	size_t position;
	position = _Description.find(keyword);
	if(position!= string::npos)
		found = true;
	position = _Category.find(keyword);
	if(position!= string::npos)
		found = true;
	return found;
}



}



