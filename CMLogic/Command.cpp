#include "Command.h"


Command::Command(int index,std::string input){
	_CommandIndex = index;
	_CommandDescription= input;
}

int Command::getCommandIndex() const{
	return _CommandIndex;
}

std::string Command::getCommandDescription() const{
	return _CommandDescription;
}
