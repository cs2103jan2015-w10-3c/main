//@author A0111448M
#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>

//An Object to store the Command Index 
//and command Description interpreted from
//LogicRead.
class Command{
private:
	int _commandIndex;					//Index for switch case
	std::string _commandDescription;	//Remainding details after command

public:
	Command(int,std::string);			//Creates a Command object for execution
	int getCommandIndex() const;		
	std::string getCommandDescription() const ;
};

#endif
