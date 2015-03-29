#include "LogicRead.h"
#include <string>
#include <iostream>


using namespace std;

LogicRead::LogicRead(void){}


LogicRead:: ~LogicRead(void)
{}

void LogicRead :: readCommand(string input){
	//Finding the first word
	size_t  FirstLetter = input.find_first_not_of(" "), LastLetter = input.find_first_of(" ",FirstLetter);
	string FirstWord = input.substr(FirstLetter,FirstLetter-LastLetter);
	_commandIndex= indexCommand(FirstWord);
	_input = input.substr(LastLetter);
}


int LogicRead :: indexCommand(string command){
	if(command==ADDF)
	{return 1;}
	else{
		if(command==ADDD)
		{return 2;}
		else{
			if(command==ADDT)
			{return 3;}
			else {
				if(command==SEARCH)
				{return  4;}
				else{
					if(command==EDIT)
					{return 5;}
					else
					{if(command=="delete")
					{return 6;}
					else
					{return 7;}
					}}}}}}
int LogicRead :: getCommandIndex() const{
	return _commandIndex;
}
string LogicRead :: getInput() const {
	return _input;
}
