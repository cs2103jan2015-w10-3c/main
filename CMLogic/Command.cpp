#include "Command.h"


Command::Command(int index,std::string input){
<<<<<<< HEAD
	_CommandIndex = index;
	_CommandDescription= input;
}


Command::~Command(void)
{
}

int Command:: getCommandIndex() const{
	return _CommandIndex;
}

std :: string Command:: getCommandDescription() const{
	return _CommandDescription;
=======
	_commandIndex = index;
	_commandDescription= input;
}

int Command::getCommandIndex() const{
	return _commandIndex;
}

std::string Command::getCommandDescription() const{
	return _commandDescription;
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
}
