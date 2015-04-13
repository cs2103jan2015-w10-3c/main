//@author A0111448M
#include "Command.h"


Command::Command(int index,std::string input){
	_commandIndex = index;
	_commandDescription= input;
}

int Command::getCommandIndex() const{
	return _commandIndex;
}

std::string Command::getCommandDescription() const{
	return _commandDescription;
}
