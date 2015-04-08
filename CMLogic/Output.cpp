#include "Output.h"

Output::Output(void){

<<<<<<< HEAD
	_Feedback = "";
}

Output::Output(std :: string feedback, std :: vector<Task*> TaskList,int ActionIndex){
	_Feedback = feedback;
	_TaskList = TaskList;
	_LastAction = ActionIndex;
}

std :: string Output :: getFeedback() const{
	return _Feedback;
}

std :: vector < Task*> Output :: getDisplay() const {
	return _TaskList;
}

int Output :: getLastAction() const{
	return _LastAction;
=======
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
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
}