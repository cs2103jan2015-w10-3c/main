#include "LogicCommand.h"

Output*  LogicCommand :: retrieveData(){
	Output* output;
	//_toDisplay= _TextFile.readFile();

	for(unsigned int index=0; index < _toDisplay.size(); index++){
		output= addTask(_toDisplay[index]);
	}
	int ActionIndex = NOINDEX;
	std::string feedback = WELCOMEBACK + USERNAME;
	std::vector <Task*> TaskList =_Storage.getDisplay();
	output= new Output(feedback,TaskList,ActionIndex);

	return output;


}


Output*  LogicCommand :: addTask(std::string CommandInput){


	std::string TaskType = _Parser.determineType(CommandInput);
	_Parser.parseData(CommandInput,TaskType);


	if(TaskType==TIMEDTYPE){
		Output* output= addTimeTask();
		return output;	}
	else{
		if(TaskType==FLOATINGTYPE){
			Output*  output= addFloatTask();
			return output;}
		else{
			if(TaskType==DEADLINE){
				Output*  output= addDeadlines();
				return output;}
			else{ 
				std::string feedback = INVALIDTYPE;
				std::vector <Task*> TaskList =_Storage.getDisplay();
				int ActionIndex = NOINDEX;
				Output*  output= new Output(feedback,TaskList,ActionIndex);
				return output;}
		}}

}

Output* LogicCommand :: addFloatTask(){
	std::string Description =_Parser.getDescription();

	FloatingTask* NewFloatingTask = new FloatingTask(Description);

	_Storage.addFloatingTask(NewFloatingTask);
	int ActionIndex=1;//= _Storage.getTaskIndex(TaskIndex);
	std::string feedback = Description + " " + " " + ADDED;
	std::vector <Task*> TaskList =_Storage.getDisplay();

	Output* output= new Output(feedback,TaskList,ActionIndex);

	return output;
}


Output* LogicCommand :: addDeadlines(){
	std::string Description =_Parser.getDescription();
	ptime Start = _Parser.getStart();

	Deadline* NewDeadline = new Deadline(Description,Start);

	_Storage.addDeadline(NewDeadline);
	int ActionIndex=1;//= _Storage.getTaskIndex(TaskIndex);
	std::string feedback = Description +  " " + to_simple_string(Start) +" " +  " " + ADDED;
	std::vector <Task*> TaskList =_Storage.getDisplay();

	Output* output= new Output(feedback,TaskList,ActionIndex);

	return output;
}

Output* LogicCommand :: addTimeTask(){

	std::string Description =_Parser.getDescription();

	ptime Start = _Parser.getStart(); // To identify a deadline and TimedTask
	ptime End = _Parser.getEnd();

	TimedTask* NewTimedTask = new TimedTask(Description,Start,End);

	_Storage.addTimedTask(NewTimedTask);
	int ActionIndex=1;//= _Storage.getTaskIndex(TaskIndex);
	std::string feedback = Description +  " " + to_simple_string(Start) + " " + to_simple_string(End) +  " " + ADDED;
	std :: vector <Task*> TaskList =_Storage.getDisplay();

	Output* output= new Output(feedback,TaskList,ActionIndex);

	return output;
}

Output* LogicCommand :: searchTask (std::string CommandInput){

	std::vector <Task*> TaskList = _Storage.searchTask(CommandInput);
	std::string feedback = SEARCHFOUND + " " + TASKS;
	int ActionIndex = NOINDEX;
	Output* output= new Output(feedback,TaskList,ActionIndex);

	return output;
}

Output* LogicCommand :: deleteTask(std::string SelectedIndexes){
	std::string feedback="";
	std::vector<int> IndexVector =_IntConvertor.convertString(SelectedIndexes);

	for(unsigned startindex=0;startindex<IndexVector.size();startindex++){

		int TaskIndex = IndexVector[startindex];
		feedback = feedback + _Storage.deleteTask(TaskIndex);
	}
	 
	std::vector <Task*> TaskList =_Storage.getDisplay();
	int ActionIndex = NOINDEX;
	Output* output= new Output(feedback,TaskList,ActionIndex);

	return output;
}

Output* LogicCommand :: EditTask(std::string CommandInput){
	std::string feedback;
	Editor.interpretCommand(CommandInput);
	int TaskIndex =Editor.getTaskindex();
	Task* SelectedTask= _Storage.getTask(TaskIndex);
	int ActionIndex=1; //= _Storage.getTaskIndex(TaskIndex);

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

	//_TextFile.writeFile();
	std::vector <Task*> TaskList =_Storage.getDisplay();

	Output* output= new Output(feedback,TaskList,ActionIndex);

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
	int ActionIndex=1;//= _Storage.getTaskIndex(TaskIndex);
	std::vector <Task*> TaskList =_Storage.getDisplay();
	std::string feedback= UNDID;
	Output* output= new Output(feedback,TaskList,ActionIndex);

	return output;

}
Output* LogicCommand :: RedoAction(){
	_Storage.redoAction();
	int ActionIndex=1; //= _Storage.getTaskIndex(TaskIndex);
	std::vector <Task*> TaskList =_Storage.getDisplay();
	std::string feedback= REDID;
	Output* output= new Output(feedback,TaskList,ActionIndex);

	return output;
}

Output* LogicCommand :: CheckTask(std::string SelectedIndexes){

	std::vector<int> IndexVector =_IntConvertor.convertString(SelectedIndexes);

	for(unsigned startindex=0;startindex<IndexVector.size();startindex++){

		int TaskIndex = IndexVector[startindex];
		Task* SelectedTask= _Storage.getTask(TaskIndex);
		SelectedTask->checkTask();
	}

	std:: string feedback=CHECKED;
	std::vector <Task*> TaskList =_Storage.getDisplay();
	int ActionIndex = NOINDEX;
	Output* output= new Output(feedback,TaskList,ActionIndex);

	return output;
}


Output* LogicCommand :: changeStorageDirectory(std::string DirectoryInput){

std::string NewDirectory =_Parser.interpretDirectoryString(DirectoryInput);
//_TextFile.changeStorageLocation(NewDirectory);
std::vector <Task*> TaskList =_Storage.getDisplay();
std::string feedback= NEWDIRECTORY + NewDirectory;
int ActionIndex = NOINDEX;
Output* output= new Output(feedback,TaskList,ActionIndex);

return output;

}