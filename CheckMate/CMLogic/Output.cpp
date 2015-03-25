#include "Output.h"

Output::Output(void){

	_Feedback = "";
}

Output::Output(std :: string feedback, std :: vector<std ::string> TaskList){
	_Feedback = feedback;
	_TaskList = TaskList;
}


std :: string Output :: getFeedback() const{
	return _Feedback;
}

std :: vector <std :: string> Output :: getDisplay() const {
	return _TaskList;
}