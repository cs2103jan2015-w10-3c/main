//@author A0111448M
#include "LogicCommand.h"

Output*  LogicCommand :: retrieveData(){
	Output* output;
	//Add Task from textfiles back
	std::vector<std::string> _toDisplay=_storage.readFile();		
	for(unsigned int index=0; index < _toDisplay.size(); index++){
		output = addTask(_toDisplay[index],FROMFILE,ACTIVETASK);
	} 
	//Add Completed Files from textfiles back
	std::vector<std::string> archivedFileList = _storage.readArchivedFile();
	for(unsigned int index=0; index < archivedFileList.size(); index++){
		output = addTask(archivedFileList[index],FROMFILE,COMPLETEDTASK);
	} 
	_taskList =_storage.getActiveDisplay();
	_firstFloatIndex=_storage.getIndexFirstFloat();
	_lastActionIndex= NONOBSERVABLE;
	_feedback = WELCOMEBACK;
	_listType= ACTIVETASK;

	output= new Output(_feedback,_taskList,_lastActionIndex,_firstFloatIndex,_listType);
	return output;

}


Output*  LogicCommand :: addTask(std::string commandInput,int InputSource=FROMUSER,bool isCompleted=ACTIVETASK){


	if(InputSource==FROMFILE){                          
		_parser.parseDataFromFile(commandInput);
	}else{												
		_parser.parseData(commandInput);
	}

	std::string taskType = _parser.getType();

	if(taskType==TIMEDTYPE){
		Output* output= addTimeTask(isCompleted);
		return output;	
	}else if
		(taskType==FLOATINGTYPE){
			Output*  output= addFloatTask(isCompleted);
			return output;
	}else if
		(taskType==DEADLINE){
			Output*  output= addDeadlines(isCompleted);
			return output;
	}else{ 
		std::string feedback = INVALIDTYPE;
		_taskList =_storage.getActiveDisplay();
		
		Output*  output= new Output(feedback,_taskList,_lastActionIndex,_firstFloatIndex,_listType);
		return output;}
}

Output* LogicCommand :: addFloatTask(bool isCompleted){
	std::string description =_parser.getDescription();

	FloatingTask* newFloatingTask = new FloatingTask(description);
	if(isCompleted){
		_storage.addArchivedFloatingTask(newFloatingTask);
		_lastActionIndex=NONOBSERVABLE;
	}else if
		(!isCompleted){
			_storage.addFloatingTask(newFloatingTask);
			_lastActionIndex=_storage.getAddedIndex();}

	_taskList =_storage.getActiveDisplay();
	_firstFloatIndex=_storage.getIndexFirstFloat();
	_feedback = description + ADDED;

	Output* output= new Output(_feedback,_taskList,_lastActionIndex,_firstFloatIndex,_listType);
	return output;
}


Output* LogicCommand :: addDeadlines(bool isCompleted){
	std::string description =_parser.getDescription();
	boost::posix_time::ptime end = _parser.getEnd();

	Deadline* NewDeadline = new Deadline(description,end);

	if(isCompleted){
		_storage.addArchivedDeadline(NewDeadline);
		_lastActionIndex=NONOBSERVABLE;
	}else if
		(!isCompleted){
			_storage.addDeadline(NewDeadline);
			_lastActionIndex=_storage.getAddedIndex();}

	_taskList =_storage.getActiveDisplay();
	_firstFloatIndex=_storage.getIndexFirstFloat();
	_feedback = description + ADDED;

	Output* output= new Output(_feedback,_taskList,_lastActionIndex,_firstFloatIndex,_listType);
	return output;
}

Output* LogicCommand :: addTimeTask(bool isCompleted){

	std::string description =_parser.getDescription();

	boost::posix_time::ptime Start = _parser.getStart(); // To identify a deadline and TimedTask
	boost::posix_time::ptime End = _parser.getEnd();

	_taskList =_storage.getActiveDisplay();


	bool hasClash = _checker.checkClash(_taskList,Start,End);

	if(hasClash){
		_feedback =  CLASHED ; 
	} else if
		(!hasClash){
			_feedback = description + ADDED;
	}
	TimedTask* newTimedTask = new TimedTask(description,Start,End);

	if(isCompleted){
		_storage.addArchivedTimedTask(newTimedTask);
		_lastActionIndex=NONOBSERVABLE;}
	else if
		(!isCompleted){
			_storage.addTimedTask(newTimedTask);
			_lastActionIndex=_storage.getAddedIndex();}
	_taskList =_storage.getActiveDisplay();
	_firstFloatIndex=_storage.getIndexFirstFloat();

	Output* output= new Output(_feedback,_taskList,_lastActionIndex,_firstFloatIndex,_listType);
	return output;
}

Output* LogicCommand :: searchTask (std::string commandInput){
	if(commandInput==""){
		_taskList =_storage.getActiveDisplay();
		_feedback = NOTFOUND;
	} else {
		_taskList = _storage.getSearchedTasks(commandInput);
		if(_taskList.empty()){
			_feedback = NOTFOUND;
			_firstFloatIndex = _taskList.size();
		}else {
			_feedback = SEARCHFOUND + TASKS;
			_firstFloatIndex = _taskList.size();
		}
	}
	_lastActionIndex = NONOBSERVABLE;
	

	Output* output= new Output(_feedback,_taskList,_lastActionIndex,_firstFloatIndex,_listType);
	return output;
}

Output* LogicCommand :: deleteTask(std::string selectedIndexes){
	_storage.updateHistory();
	_feedback="";
	std::vector<int> indexVector =_stringConvertor.toInt(selectedIndexes);
	
	for(unsigned int index=0;index<indexVector.size();index++){
		int taskIndex = indexVector[index];
		_feedback = _feedback + _storage.deleteTask(taskIndex);
	}

	_taskList =_storage.getActiveDisplay();
	_lastActionIndex= NONOBSERVABLE;
	_firstFloatIndex=_storage.getIndexFirstFloat();

	Output* output= new Output(_feedback,_taskList,_lastActionIndex,_firstFloatIndex,_listType);
	return output;
}

Output* LogicCommand :: editTask(std::string commandInput){
	std::string _feedback;
	bool isValidInput=true;
	isValidInput=_editor.interpretCommand(commandInput);
	Task* selectedTask;
	_taskList =_storage.getActiveDisplay();
	if(isValidInput&&(_editor.getTaskIndex()<=_taskList.size())){
		int taskIndex =_editor.getTaskIndex();
		selectedTask= _storage.getTask(taskIndex);


		int editCommandIndex = _editor.getSelectedCategory();
		std::string editedInput = _editor.getNewInput();

		switch(editCommandIndex){
		case DESCRIPTIONINDEX:{
			selectedTask->editDescription(editedInput);
			_feedback=EDITED;}
							  break;
		case STARTTIMEINDEX:{
			boost::posix_time::ptime previousTime = selectedTask->getStart();
			boost::posix_time::ptime newStart = _parser.changeTime(previousTime,editedInput);
			selectedTask->editStartTime(newStart);
			_feedback=EDITED;}
							break;
		case STARTDATEINDEX:{
			boost::posix_time::ptime previousDate = selectedTask->getStart();
			boost::posix_time::ptime newStart = _parser.changeDate(previousDate,editedInput);
			selectedTask->editStartDate(newStart);
			_feedback=EDITED;}
							break;
		case ENDTIMEINDEX:{
			boost::posix_time::ptime previousTime = selectedTask->getEnd();
			boost::posix_time::ptime newEnd = _parser.changeTime(previousTime,editedInput);
			selectedTask->editEndTime(newEnd);
			_feedback=EDITED;}
						  break;

		case ENDDATEINDEX:{
			boost::posix_time::ptime previousDate = selectedTask->getEnd();
			boost::posix_time::ptime newEnd = _parser.changeDate(previousDate,editedInput);
			selectedTask->editEndDate(newEnd);
			_feedback=EDITED;}
						  break;
		default:{
			_feedback= INVALIDTYPE;}
				break;
		}
	}else {_feedback= INVALIDTYPE;}

	_storage.writeEditedFile();
	_taskList =_storage.getActiveDisplay();
	if(_feedback!= INVALIDTYPE){
		_lastActionIndex = _storage.getEditedIndex(selectedTask->getDescription(),selectedTask->getStart(),selectedTask->getEnd());
	} 

	Output* output= new Output(_feedback,_taskList,_lastActionIndex,_firstFloatIndex,_listType);
	return output;


}

Output* LogicCommand :: displayToday(){

	std::string today = _parser.getToday();
	Output* output= searchTask(today);
	_listType= ACTIVETASK;
	return output;
}

Output* LogicCommand ::  displayTomorrow(){

	std::string tomorrow = _parser.getTomorrow();
	Output* output= searchTask(tomorrow);
	_listType= ACTIVETASK;
	return output;
}


Output* LogicCommand :: undoAction(){
	_storage.undoAction();

	_taskList =_storage.getActiveDisplay();
	_lastActionIndex = NONOBSERVABLE;
	_firstFloatIndex= _storage.getIndexFirstFloat();

	_feedback= UNDID;


	Output* output= new Output(_feedback,_taskList,_lastActionIndex,_firstFloatIndex,_listType);
	return output;

}


Output* LogicCommand :: checkTask(std::string selectedIndexes){

	_storage.updateHistory();
	_storage.updateArchivedHistory();

	std::vector<int> indexVector =_stringConvertor.toInt(selectedIndexes);
	_feedback="";

	for(unsigned index=0;index<indexVector.size();index++){
		_feedback = _storage.check(indexVector[index]) + '\n' +_feedback;
	}
	_taskList =_storage.getActiveDisplay();
	_feedback= _feedback + CHECKED;

	_firstFloatIndex = _storage.getIndexFirstFloat();
	_lastActionIndex =NONOBSERVABLE;

	Output* output= new Output(_feedback,_taskList,_lastActionIndex,_firstFloatIndex,_listType);
	return output;
}

Output* LogicCommand :: uncheckTask(std::string selectedIndexes){
	
	_storage.updateHistory();
	_storage.updateArchivedHistory();

	std::vector<int> indexVector =_stringConvertor.toInt(selectedIndexes);
	_feedback="";

	Output* output;
	for(unsigned startindex=0;startindex<indexVector.size();startindex++){
		std::string uncheckTask = _storage.uncheck(indexVector[startindex]);
		output = addTask(uncheckTask,FROMFILE,ACTIVETASK);
		_feedback = uncheckTask + '\n' +_feedback;
	}
	_feedback= _feedback + CHECKED;

	output= checkCompletedTask();

	return output;
}

Output* LogicCommand :: clearTask(){
	_storage.clearTasks();

	_feedback=CLEARED;
	_taskList =_storage.getActiveDisplay();
	_lastActionIndex=NONOBSERVABLE;
	_firstFloatIndex=NONE;

	Output* output= new Output(_feedback,_taskList,_lastActionIndex,_firstFloatIndex,_listType);

	return output;

}

Output* LogicCommand :: changeStorageDirectory(std::string DirectoryInput){

	std::string NewDirectory =_parser.interpretDirectoryString(DirectoryInput);

	_storage.changeStorageLocation(NewDirectory);

	_taskList =_storage.getActiveDisplay();
	_feedback= NEWDIRECTORY + NewDirectory;

	Output* output= new Output(_feedback,_taskList,_lastActionIndex,_firstFloatIndex,_listType);
	return output;
}

Output* LogicCommand :: checkCompletedTask() {

	_taskList =_storage.getArchivedDisplay();
	_feedback = ARCHIVED;
	_lastActionIndex=NONOBSERVABLE;
	_firstFloatIndex=_taskList.size();
	_listType= COMPLETEDTASK;
	Output* output= new Output(_feedback,_taskList,_lastActionIndex,_firstFloatIndex,_listType);
	return output;
}

Output* LogicCommand :: returnToHomePage(){

	_taskList =_storage.getActiveDisplay();
	_feedback = "";
	_lastActionIndex=NONOBSERVABLE;
	_firstFloatIndex=_storage.getIndexFirstFloat();
	_listType= ACTIVETASK;
	Output* output= new Output(_feedback,_taskList,_lastActionIndex,_firstFloatIndex,_listType);
	return output;
}