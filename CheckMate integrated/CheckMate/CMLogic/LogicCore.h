#include "LogicCommand.h"
#include "LogicRead.h"
#include <vector>

const string GOODBYE = "Goodbye!!";

class LogicCore
{	private:
		LogicCommand _CommandAction; //To execute actions
		LogicRead _CommandInput; //Commandindex and input
		string _Feedback; //Acknowledgement of Action
		bool _IsActive;  //Status of system

public:
	LogicCore(void);
	~LogicCore(void);
	void ExecuteCommand(string);
	string displayFeedback();
	vector <string> displayTask();
	bool getIsActive();

};

