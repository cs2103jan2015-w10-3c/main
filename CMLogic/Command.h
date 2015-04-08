#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>

class Command{

private:
	int _commandIndex;
	std::string _commandDescription;

public:
	Command(int,std::string);
	int getCommandIndex() const;
	std::string getCommandDescription() const ;
};

#endif
