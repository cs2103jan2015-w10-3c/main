#include "LogicCommand.h"


Output*  LogicCommand :: addTask(std::string CommandInput){
	
	
	std::string TaskType = _Parser.determineType(CommandInput);
	_Parser.parseData(CommandInput,TaskType);
	

	if(TaskType==TIMEDTYPE){
		Output* output= addTimeTask();}
	else{
		if(TaskType==FLOATINGTYPE){
			Output*  output= addFloatTask();}
		else{
			if(TaskType==DEADLINE){
				Output*  output= addDeadlines();}
			else{ 
				std::string feedback = INVALIDTYPE;
				std::vector <Task*> TaskList =_Storage.getDisplay();
				Output*  output= new Output(feedback,Tasklist);}
		}}

	return output;


}

Output* LogicCommand :: addFloatTask(){
	std::string Description =_Parser.getDescription();

	FloatingTask* NewFloatingTask = new FloatingTask(Description);

	_Storage.addFloatingTask(NewFloatingTask);

	std::string feedback = Description + " " + " " + ADDED;
	std::vector <Task*> TaskList =_Storage.getDisplay();

	Output* output= new Output(feedback,TaskList);

	return output;
}


Output* LogicCommand :: addDeadlines(){
	std::string Description =_Parser.getDescription();
	ptime Start = _Parser.getStart();

	Deadline* NewDeadline = new Deadline(Description,Start);

	_Storage.addDeadline(NewDeadline);

	std::string feedback = Description +  " " + to_simple_string(Start) +" " +  " " + ADDED;
	std::vector <Task*> TaskList =_Storage.getDisplay();

	Output* output= new Output(feedback,TaskList);

	return output;
}

Output* LogicCommand :: addTimeTask(){

	std::string Description =_Parser.getDescription();

	ptime Start = _Parser.getStart(); // To identify a deadline and TimedTask
	ptime End = _Parser.getEnd();

	TimedTask* NewTimedTask = new TimedTask(Description,Start,End);

	_Storage.addTimedTask(NewTimedTask);

	std::string feedback = Description +  " " + to_simple_string(Start) + " " + to_simple_string(End) +  " " + ADDED;
	std :: vector <Task*> TaskList =_Storage.getDisplay();

	Output* output= new Output(feedback,TaskList);

	return output;
}

Output* LogicCommand :: searchTask (std::string CommandInput){

	std::vector <Task*> TaskList = _Storage.searchTask(CommandInput);
	std::string feedback = SEARCHFOUND + " " + TASKS;

	Output* output= new Output(feedback,TaskList);

	return output;
}

Output* LogicCommand :: deleteTask(std::string CommandInput){

	int index =atoi(CommandInput.c_str());

	std::string feedback = _Storage.deleteTask(index);
	std::vector <Task*> TaskList =_Storage.getDisplay();

	Output* output= new Output(feedback,TaskList);

	return output;
}

Output* LogicCommand :: EditTask(std::string CommandInput){
	std::string feedback;
	Editor.interpretCommand(CommandInput);
	int TaskIndex =Editor.getTaskindex();
	Task* SelectedTask= _Storage.getTask(TaskIndex);

	int EditCommandIndex = Editor.getSelectedCategory();

	switch(EditCommandIndex){
	case DESCRIPTIONINDEX:{
		SelectedTask->editDescription(Editor.getNewInput());
		feedback=EDITED;}
						  break;
	case STARTTIMEINDEX:{
		ptime PreviousTime = SelectedTask->getStart();
		ptime NewStart = _Parser.changeTime(PreviousTime,Editor.getNewInput());
		SelectedTask->editStartTime(NewStart);
		feedback=EDITED;}
						break;
	case STARTDATEINDEX:{
		ptime PreviousDate = SelectedTask->getStart();
		ptime NewStart = _Parser.changeDate(PreviousDate,Editor.getNewInput());
		SelectedTask->editStartDate(NewStart);
		feedback=EDITED;}
						break;
	case ENDTIMEINDEX:{
		ptime PreviousTime = SelectedTask->getEnd();
		ptime NewEnd = _Parser.changeTime(PreviousTime,Editor.getNewInput());
		SelectedTask->editEndTime(NewEnd);
		feedback=EDITED;}
					  break;

	case ENDDATEINDEX:{
		ptime PreviousDate = SelectedTask->getEnd();
		ptime NewEnd = _Parser.changeDate(PreviousDate,Editor.getNewInput());
		SelectedTask->editEndDate(NewEnd);
		feedback=EDITED;}
					  break;
	default:{
		feedback= INVALIDTYPE;}
			break;
	}


	std::vector <Task*> TaskList =_Storage.getDisplay();

	Output* output= new Output(feedback,TaskList);

	return output;


}

Output* LogicCommand :: DisplayToday(){


	std::string today = _Parser.getToday();
	Output* output= searchTask(today);

	return output;
}

Output* LogicCommand ::  DisplayTomorrow(){

	std::string tomorrow = _Parser.getTomorrow();
	Output* output= searchTask(tomorrow);

	return output;
}


Output* LogicCommand :: UndoAction(){
	_Storage.undoAction();

	std::vector <Task*> TaskList =_Storage.getDisplay();
	std::string feedback= UNDID;
	Output* output= new Output(feedback,TaskList);

	return output;

}
Output* LogicCommand :: RedoAction(){
	_Storage.redoAction();

	std::vector <Task*> TaskList =_Storage.getDisplay();
	std::string feedback= REDID;
	Output* output= new Output(feedback,TaskList);

	return output;
}