#include "Task.h"
#include <iostream>
#include <algorithm>

using namespace std;

Task::Task(string Description, string Category)
{
	_Description= Description;
	_Category= Category;
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




