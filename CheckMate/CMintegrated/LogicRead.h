#include <iostream>
#include <string>

using namespace std;

const string ADDF = "addf";
const string ADDT = "addt";
const string ADDD = "addd";
const string DELETE = "delete";
const string EDIT ="edit";
const string SEARCH = "search";

//Read the command and input and executes it
class LogicRead{

private:
	int _commandIndex;
	string _input;

public:
	LogicRead(void);
	~LogicRead(void);
	void readCommand(string);
	int indexCommand(string);
	int getCommandIndex() const;
	string getInput() const ;

};

