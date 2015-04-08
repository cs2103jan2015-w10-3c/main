#include "LogicCommand.h"

Output*  LogicCommand :: retrieveData(){
	Output* output;
<<<<<<< HEAD
	//_toDisplay= _TextFile.readFile();

	for(unsigned int index=0; index < _toDisplay.size(); index++){
		output= addTask(_toDisplay[index]);
	}
	int ActionIndex = NOINDEX;
	std::string feedback = WELCOMEBACK + USERNAME;
	std::vector <Task*> TaskList =_Storage.getDisplay();
	output= new Output(feedback,TaskList,ActionIndex);

	return output;

=======
	//Add Task from textfiles back
	_toDisplay=_Storage.readFile();		
	for(unsigned int index=0; index < _toDisplay.size(); index++){
		output = addTask(_toDisplay[index],FROMFILE,UNCOMPLETEDTASK);
	} 
	//Add Completed Files from textfiles back
	std::vector<std::string> archivedFileList = _Storage.readArchivedFile();
	for(unsigned int index=0; index < archivedFileList.size(); index++){
		output = addTask(archivedFileList[index],FROMFILE,COMPLETEDTASK);
	} 

	_firstFloatIndex=_Storage.getIndexFirstFloat();
	_lastActionIndex= NONOBSERVABLE;
	std::string feedback = WELCOMEBACK;
	std::vector <Task*> TaskList =_Storage.getDisplay();

	output= new Output(feedback,TaskList,_lastActionIndex,_firstFloatIndex);

	return output;
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e

}


<<<<<<< HEAD
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
=======
Output*  LogicCommand :: addTask(std::string CommandInput,int InputSource=FROMUSER,bool isCompleted=UNCOMPLETEDTASK){


	if(InputSource==FROMFILE){                          
		_Parser.parseDataFromFile(CommandInput);
	}else{												
		_Parser.parseData(CommandInput);
	}

	std::string TaskType = _Parser.getType();

	if(TaskType==TIMEDTYPE){
		Output* output= addTimeTask(isCompleted);
		return output;	
	}else if
		(TaskType==FLOATINGTYPE){
			Output*  output= addFloatTask(isCompleted);
			return output;
	}else if
		(TaskType==DEADLINE){
			Output*  output= addDeadlines(isCompleted);
			return output;
	}else{ 
		std::string feedback = INVALIDTYPE;
		std::vector <Task*> TaskList =_Storage.getDisplay();
		Output*  output= new Output(feedback,TaskList,_lastActionIndex,_firstFloatIndex);
		return output;}
}

Output* LogicCommand :: addFloatTask(bool isCompleted){
	std::string Description =_Parser.getDescription();

	FloatingTask* NewFloatingTask = new FloatingTask(Description);
	if(isCompleted){
		_Storage.addArchivedFloatingTask(NewFloatingTask);
		_lastActionIndex=NONOBSERVABLE;
	}else if
		(!isCompleted){
			_Storage.addFloatingTask(NewFloatingTask);
			_lastActionIndex=_Storage.getAddedIndex();}

	_firstFloatIndex=_Storage.getIndexFirstFloat();
	std::string feedback = Description + " " + " " + ADDED;
	std::vector <Task*> TaskList =_Storage.getDisplay();

	_Storage.writeFile();
	Output* output= new Output(feedback,TaskList,_lastActionIndex,_firstFloatIndex);
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e

	return output;
}


<<<<<<< HEAD
Output* LogicCommand :: addDeadlines(){
=======
Output* LogicCommand :: addDeadlines(bool isCompleted){
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
	std::string Description =_Parser.getDescription();
	ptime Start = _Parser.getStart();

	Deadline* NewDeadline = new Deadline(Description,Start);

<<<<<<< HEAD
	_Storage.addDeadline(NewDeadline);
	int ActionIndex=1;//= _Storage.getTaskIndex(TaskIndex);
	std::string feedback = Description +  " " + to_simple_string(Start) +" " +  " " + ADDED;
	std::vector <Task*> TaskList =_Storage.getDisplay();

	Output* output= new Output(feedback,TaskList,ActionIndex);
=======
	if(isCompleted){
		_Storage.addArchivedDeadline(NewDeadline);
		_lastActionIndex=NONOBSERVABLE;
	}else if
		(!isCompleted){
			_Storage.addDeadline(NewDeadline);
			_lastActionIndex=_Storage.getAddedIndex();}

	_firstFloatIndex=_Storage.getIndexFirstFloat();
	std::string feedback = Description +  " " + to_simple_string(Start) +" " +  " " + ADDED;
	std::vector <Task*> TaskList =_Storage.getDisplay();

	_Storage.writeFile();
	Output* output= new Output(feedback,TaskList,_lastActionIndex,_firstFloatIndex);
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e

	return output;
}

<<<<<<< HEAD
Output* LogicCommand :: addTimeTask(){
=======
Output* LogicCommand :: addTimeTask(bool isCompleted){
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e

	std::string Description =_Parser.getDescription();

	ptime Start = _Parser.getStart(); // To identify a deadline and TimedTask
	ptime End = _Parser.getEnd();

	TimedTask* NewTimedTask = new TimedTask(Description,Start,End);
<<<<<<< HEAD

	_Storage.addTimedTask(NewTimedTask);
	int ActionIndex=1;//= _Storage.getTaskIndex(TaskIndex);
	std::string feedback = Description +  " " + to_simple_string(Start) + " " + to_simple_string(End) +  " " + ADDED;
	std :: vector <Task*> TaskList =_Storage.getDisplay();

	Output* output= new Output(feedback,TaskList,ActionIndex);
=======
	if(isCompleted){
		_Storage.addArchivedTimedTask(NewTimedTask);
		_lastActionIndex=NONOBSERVABLE;}
	else if
		(!isCompleted){
			_Storage.addTimedTask(NewTimedTask);
			_lastActionIndex=_Storage.getAddedIndex();}

	_firstFloatIndex=_Storage.getIndexFirstFloat();
	std::string feedback = Description +  " " + to_simple_string(Start) + " " + to_simple_string(End) +  " " + ADDED;
	std :: vector <Task*> TaskList =_Storage.getDisplay();

	_Storage.writeFile();
	Output* output= new Output(feedback,TaskList,_lastActionIndex,_firstFloatIndex);
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e

	return output;
}

Output* LogicCommand :: searchTask (std::string CommandInput){

	std::vector <Task*> TaskList = _Storage.searchTask(CommandInput);
	std::string feedback = SEARCHFOUND + " " + TASKS;
<<<<<<< HEAD
	int ActionIndex = NOINDEX;
	Output* output= new Output(feedback,TaskList,ActionIndex);
=======
	_lastActionIndex = NONOBSERVABLE;
	_firstFloatIndex = TaskList.size();
	Output* output= new Output(feedback,TaskList,_lastActionIndex,_firstFloatIndex);
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e

	return output;
}

Output* LogicCommand :: deleteTask(std::string SelectedIndexes){
	std::string feedback="";
<<<<<<< HEAD
	std::vector<int> IndexVector =_IntConvertor.convertString(SelectedIndexes);

	for(unsigned startindex=0;startindex<IndexVector.size();startindex++){

		int TaskIndex = IndexVector[startindex];
		feedback = feedback + _Storage.deleteTask(TaskIndex);
	}
	 
	std::vector <Task*> TaskList =_Storage.getDisplay();
	int ActionIndex = NOINDEX;
	Output* output= new Output(feedback,TaskList,ActionIndex);
=======
	std::vector<int> IndexVector =_stringConvertor.toInt(SelectedIndexes);

	for(unsigned int index=0;index<IndexVector.size();index++){
		int TaskIndex = IndexVector[index];
		feedback = feedback + _Storage.deleteTask(TaskIndex);
	}

	_Storage.writeFile();
	std::vector <Task*> TaskList =_Storage.getDisplay();
	_lastActionIndex= NONOBSERVABLE;
	_firstFloatIndex=_Storage.getIndexFirstFloat();
	Output* output= new Output(feedback,TaskList,_lastActionIndex,_firstFloatIndex);
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e

	return output;
}

<<<<<<< HEAD
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
=======
Output* LogicCommand :: editTask(std::string CommandInput){
	std::string feedback;
	bool IsValidInput=true;
	IsValidInput=Editor.interpretCommand(CommandInput);


	if(IsValidInput){
		int TaskIndex =Editor.getTaskindex();

		Task* SelectedTask= _Storage.getTask(TaskIndex);
		_lastActionIndex = TaskIndex;

		int EditCommandIndex = Editor.getSelectedCategory();
		std::string EditedInput = Editor.getNewInput();

		switch(EditCommandIndex){
		case DESCRIPTIONINDEX:{
			SelectedTask->editDescription(EditedInput);
			feedback=EDITED;}
							  break;
		case STARTTIMEINDEX:{
			ptime PreviousTime = SelectedTask->getStart();
			ptime NewStart = _Parser.changeTime(PreviousTime,EditedInput);
			SelectedTask->editStartTime(NewStart);
			feedback=EDITED;}
							break;
		case STARTDATEINDEX:{
			ptime PreviousDate = SelectedTask->getStart();
			ptime NewStart = _Parser.changeDate(PreviousDate,EditedInput);
			SelectedTask->editStartDate(NewStart);
			feedback=EDITED;}
							break;
		case ENDTIMEINDEX:{
			ptime PreviousTime = SelectedTask->getEnd();
			ptime NewEnd = _Parser.changeTime(PreviousTime,EditedInput);
			SelectedTask->editEndTime(NewEnd);
			feedback=EDITED;}
						  break;

		case ENDDATEINDEX:{
			ptime PreviousDate = SelectedTask->getEnd();
			ptime NewEnd = _Parser.changeDate(PreviousDate,EditedInput);
			SelectedTask->editEndDate(NewEnd);
			feedback=EDITED;}
						  break;
		default:{
			feedback= INVALIDTYPE;}
				break;
		}
	}else {feedback= INVALIDTYPE;}

	_Storage.writeFile();
	std::vector <Task*> TaskList =_Storage.getDisplay();

	Output* output= new Output(feedback,TaskList,_lastActionIndex,_firstFloatIndex);
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e

	return output;


}

<<<<<<< HEAD
Output* LogicCommand :: DisplayToday(){

=======
Output* LogicCommand :: displayToday(){
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e

	std::string today = _Parser.getToday();
	Output* output= searchTask(today);

	return output;
}

<<<<<<< HEAD
Output* LogicCommand ::  DisplayTomorrow(){
=======
Output* LogicCommand ::  displayTomorrow(){
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e

	std::string tomorrow = _Parser.getTomorrow();
	Output* output= searchTask(tomorrow);

	return output;
}


<<<<<<< HEAD
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
=======
Output* LogicCommand :: undoAction(){
	_Storage.undoAction();
	_lastActionIndex = NONOBSERVABLE;
	_firstFloatIndex= _Storage.getIndexFirstFloat();
	std::vector <Task*> TaskList =_Storage.getDisplay();
	std::string feedback= UNDID;
	Output* output= new Output(feedback,TaskList,_lastActionIndex,_firstFloatIndex);
	_Storage.writeFile();
	return output;

}
Output* LogicCommand :: redoAction(){
	_Storage.redoAction();
	_lastActionIndex = NONOBSERVABLE;
	_firstFloatIndex= _Storage.getIndexFirstFloat();
	std::vector <Task*> TaskList =_Storage.getDisplay();
	std::string feedback= REDID;
	Output* output= new Output(feedback,TaskList,_lastActionIndex,_firstFloatIndex);
	_Storage.writeFile();
	return output;
}

Output* LogicCommand :: checkTask(std::string SelectedIndexes){

	std::vector<int> IndexVector =_stringConvertor.toInt(SelectedIndexes);
	std:: string feedback="";
	for(unsigned startindex=0;startindex<IndexVector.size();startindex++){
		feedback = _Storage.check(IndexVector[startindex]) + '\n' +feedback;
	}
	feedback= feedback + CHECKED;
	std::vector <Task*> TaskList =_Storage.getDisplay();
	_firstFloatIndex = _Storage.getIndexFirstFloat();
	_lastActionIndex =NONOBSERVABLE;
	Output* output= new Output(feedback,TaskList,_lastActionIndex,_firstFloatIndex);

	_Storage.writeFile();
	_Storage.writeArchivedFile();
	return output;
}

Output* LogicCommand :: uncheckTask(std::string SelectedIndexes){

	std::vector<int> IndexVector =_stringConvertor.toInt(SelectedIndexes);
	std:: string feedback="";

	for(unsigned startindex=0;startindex<IndexVector.size();startindex++){
		feedback = _Storage.uncheck(IndexVector[startindex]) + '\n' +feedback;
	}
	feedback= feedback + CHECKED;

	Output* output= checkCompletedTask();

	_Storage.writeArchivedFile();
	_Storage.writeFile();
	return output;
}

Output* LogicCommand :: clearTask(){
	_Storage.clearTasks();
	std:: string feedback=CLEARED;
	std::vector <Task*> TaskList =_Storage.getDisplay();
	_lastActionIndex=NONOBSERVABLE;
	_firstFloatIndex=NONE;
	Output* output= new Output(feedback,TaskList,_lastActionIndex,_firstFloatIndex);
	_Storage.writeFile();
	return output;

>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
}


Output* LogicCommand :: changeStorageDirectory(std::string DirectoryInput){

<<<<<<< HEAD
std::string NewDirectory =_Parser.interpretDirectoryString(DirectoryInput);
//_TextFile.changeStorageLocation(NewDirectory);
std::vector <Task*> TaskList =_Storage.getDisplay();
std::string feedback= NEWDIRECTORY + NewDirectory;
int ActionIndex = NOINDEX;
Output* output= new Output(feedback,TaskList,ActionIndex);

return output;

}
=======
	std::string NewDirectory =_Parser.interpretDirectoryString(DirectoryInput);

	_Storage.changeStorageLocation(NewDirectory);

	std::vector <Task*> TaskList =_Storage.getDisplay();
	std::string feedback= NEWDIRECTORY + NewDirectory;
	Output* output= new Output(feedback,TaskList,_lastActionIndex,_firstFloatIndex);

	return output;

}

Output* LogicCommand :: checkCompletedTask() {

	std::vector <Task*> TaskList =_Storage.getArchivedDisplay();
	std::string feedback = ARCHIVED;

	_lastActionIndex=NONOBSERVABLE;
	_firstFloatIndex=TaskList.size();
	Output* output= new Output(feedback,TaskList,_lastActionIndex,_firstFloatIndex);
	return output;

}
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
