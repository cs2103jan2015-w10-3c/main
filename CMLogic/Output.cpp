#include "Output.h"

Output::Output(void){

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
}