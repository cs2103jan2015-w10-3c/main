#include "LogicCommand.h"



LogicCommand::LogicCommand(void)
{}


LogicCommand::~LogicCommand(void)
{}


Output LogicCommand :: addFloatTask(std::string CommandInput){
	std::string Description =_Parser.getDescription(CommandInput,FLOATINGTYPE);
	std::string Category = _Parser.getCategory(CommandInput);

	FloatingTask* NewFloatingTask = new FloatingTask(Description,Category);
	
	_Storage.addFloatingTask(NewFloatingTask);

	std::string feedback = Description + " " + Category + " " + ADDED;
	std::vector <std::string> TaskList =_Storage.getDisplay();

	Output output(feedback,TaskList);

	return output;
}


Output LogicCommand :: addDeadlines(std::string CommandInput){
	std::string Description =_Parser.getDescription(CommandInput,DEADLINE);
	std::string Category = _Parser.getCategory(CommandInput);
	ptime Start = _Parser.getStart(CommandInput,DEADLINE);

	Deadline* NewDeadline = new Deadline(Description,Category,Start);
	_Storage.addDeadline(NewDeadline);

	std::string feedback = Description +  " " + to_simple_string(Start) +" " + Category + " " + ADDED;
	std::vector <std::string> TaskList =_Storage.getDisplay();

	Output output(feedback,TaskList);

	return output;
}

Output LogicCommand :: addTimeTask(std::string CommandInput){

	std::string Description =_Parser.getDescription(CommandInput,TIMEDTYPE);
	std::string Category = _Parser.getCategory(CommandInput);
	ptime Start = _Parser.getStart(CommandInput,TIMEDTYPE); // To identify a deadline and TimedTask
	ptime End = _Parser.getEnd(CommandInput);

	TimedTask* NewTimedTask = new TimedTask(Description,Category,Start,End);

	_Storage.addTimedTask(NewTimedTask);

	std::string feedback = Description +  " " + to_simple_string(Start) + " " + to_simple_string(End) +  " " + Category + ADDED;
	std :: vector <std :: string> TaskList =_Storage.getDisplay();

	Output output(feedback,TaskList);

	return output;
}

Output LogicCommand :: searchTask (std::string CommandInput){
	
	std::vector <std::string> TaskList = _Storage.searchTask(CommandInput);
	std::string feedback = SEARCHFOUND + " " + TASKS;
	
	Output output(feedback,TaskList);

	return output;
}

Output LogicCommand :: deleteTask(std::string CommandInput){
	
	int index =atoi(CommandInput.c_str());
	
	std::string feedback = _Storage.deleteTask(index);
	std::vector <std::string> TaskList =_Storage.getDisplay();
	Output output(feedback,TaskList);

	return output;
}
/*
Output LogicCommand :: EditTask(std::string CommandInput){


}

OutputLogicCommand :: DisplayToday(){

}

Output LogicCommand ::  DisplayTommorrow(){

}

*/
