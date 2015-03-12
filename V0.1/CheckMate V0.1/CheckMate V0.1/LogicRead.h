#include <iostream>
#include <string>

using namespace std;

const string ADDF = "addf";
const string ADDT = "addt";
const string ADDD = "addd";
const string DELETE = "delete";
const string EDIT ="edit";
const string SEARCH = "search";
const string TODAY ="today";
const string TOMMORROW ="tommorrow";
const string UNDO ="undo";
const string HELP ="help";

//Read the command and input and executes it
class LogicRead{

private:
	int _commandIndex; //Index associated with Action
	string _input;	//Task to be saved / keyword/ delete index

public:
	LogicRead(void);
	~LogicRead(void);
	void readCommand(string);
	int indexCommand(string);
	int getCommandIndex() const;
	string getInput() const ;

};

