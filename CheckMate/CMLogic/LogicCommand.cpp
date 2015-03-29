#include "LogicCommand.h"




Output* LogicCommand :: addFloatTask(std::string CommandInput){
	std::string Description =_Parser.getDescription(CommandInput,FLOATINGTYPE);
	std::string Category = _Parser.getCategory(CommandInput);

	FloatingTask* NewFloatingTask = new FloatingTask(Description,Category);

	_Storage.addFloatingTask(NewFloatingTask);

	std::string feedback = Description + " " + Category + " " + ADDED;
	std::vector <std::string> TaskList =_Storage.getDisplay();

	Output* output= new Output(feedback,TaskList);

	return output;
}


Output* LogicCommand :: addDeadlines(std::string CommandInput){
	std::string Description =_Parser.getDescription(CommandInput,DEADLINE);
	std::string Category = _Parser.getCategory(CommandInput);
	ptime Start = _Parser.getStart(CommandInput,DEADLINE);

	Deadline* NewDeadline = new Deadline(Description,Category,Start);

	_Storage.addDeadline(NewDeadline);

	std::string feedback = Description +  " " + to_simple_string(Start) +" " + Category + " " + ADDED;
	std::vector <std::string> TaskList =_Storage.getDisplay();

	Output* output= new Output(feedback,TaskList);

	return output;
}

Output* LogicCommand :: addTimeTask(std::string CommandInput){

	std::string Description =_Parser.getDescription(CommandInput,TIMEDTYPE);
	std::string Category = _Parser.getCategory(CommandInput);
	ptime Start = _Parser.getStart(CommandInput,TIMEDTYPE); // To identify a deadline and TimedTask
	ptime End = _Parser.getEnd(CommandInput);

	TimedTask* NewTimedTask = new TimedTask(Description,Category,Start,End);

	_Storage.addTimedTask(NewTimedTask);

	std::string feedback = Description +  " " + to_simple_string(Start) + " " + to_simple_string(End) +  " " + Category + ADDED;
	std :: vector <std :: string> TaskList =_Storage.getDisplay();

	Output* output= new Output(feedback,TaskList);

	return output;
}

Output* LogicCommand :: searchTask (std::string CommandInput){

	std::vector <std::string> TaskList = _Storage.searchTask(CommandInput);
	std::string feedback = SEARCHFOUND + " " + TASKS;

	Output* output= new Output(feedback,TaskList);

	return output;
}

Output* LogicCommand :: deleteTask(std::string CommandInput){

	int index =atoi(CommandInput.c_str());

	std::string feedback = _Storage.deleteTask(index);
	std::vector <std::string> TaskList =_Storage.getDisplay();

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
	case CATEGORYINDEX:{
		SelectedTask->editCategory(Editor.getNewInput());
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


	std::vector <std::string> TaskList =_Storage.getDisplay();

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

	std::vector <std::string> TaskList =_Storage.getDisplay();
	std::string feedback= UNDID;
	Output* output= new Output(feedback,TaskList);

	return output;

}
Output* LogicCommand :: RedoAction(){
	_Storage.redoAction();

	std::vector <std::string> TaskList =_Storage.getDisplay();
	std::string feedback= REDID;
	Output* output= new Output(feedback,TaskList);

	return output;
}