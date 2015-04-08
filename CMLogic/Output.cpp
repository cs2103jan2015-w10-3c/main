#include "Output.h"

Output::Output(void){

	_feedback = "";
}

Output::Output(std::string feedback, std::vector<Task*> taskList,int actionIndex,int floatindex){
	_feedback = feedback;
	_taskList = taskList;
	_lastActionIndex = actionIndex;
	_firstFloatIndex = floatindex;
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