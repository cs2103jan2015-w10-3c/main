//@author A0111448M
#include "Output.h"

Output::Output(void){

	_feedback = "";
}

Output::Output(std::string feedback, std::vector<Task*> taskList,int actionIndex,int floatindex,bool listType){
	_feedback = feedback;
	_taskList = taskList;
	_lastActionIndex = actionIndex;
	_firstFloatIndex = floatindex;
	_listType= listType;
}

void Output::editFeedback(std::string newFeedback){
	_feedback = newFeedback;
}

std::string Output :: getFeedback() const{
	return _feedback;
}

std::vector < Task*> Output::getDisplay() const {
	return _taskList;
}

int Output::getLastAction() const{
	return _lastActionIndex;
}

int Output::getFirstFloat() const{
	return _firstFloatIndex;
}
bool Output::getListType() const{
	return _listType;
}