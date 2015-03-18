#include "Task.h"
#include <iostream>
#include <algorithm>

Task::Task(std::string Description, std::string Category)
{
	_Description= Description;
	_Category= Category;
} 
Task::~Task(void)
{}

void Task:: editDescription(std::string NewDescription){
	_Description = NewDescription;
}

void Task:: editCategory(std::string NewCategory){
	_Category = NewCategory;
}

std::string Task:: getDescription() const{
	return _Description;
}
std::string Task:: getCategory() const{
	return _Category;
}



