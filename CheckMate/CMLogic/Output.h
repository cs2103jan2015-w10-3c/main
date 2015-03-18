#ifndef OUTPUT_H
#define OUTPUT_H
#include <iostream>
#include <vector>

class Output{
	std::string _Feedback;
	std::vector <std::string> _TaskList;
public:
	Output(void);
	Output(std :: string, std :: vector<std ::string>);
	std::string getFeedback() const;
	std::vector <std::string> getDisplay() const;
};
#endif
