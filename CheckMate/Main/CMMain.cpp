#include "CMLogic.h"

#include <iostream>
#include <vector>



int main (void) {
	std::string str;
std::	vector<std::string> vStr;
	CMLogic testSample;
	 
	getline(std::cin, str);
	
	while (str!="exit") {
		
		testSample.ExecuteCommand(str);
		Output testOutput=testSample.getOutput();
		vStr = testOutput.getDisplay();
		std::cout <<"Feedback: "<< testOutput.getFeedback()<<std::endl;
		for (size_t i=0; i<vStr.size(); ++i)
		{
			std::cout << vStr[i]<<std::endl;
		}
		getline(std::cin, str);
	}
	return 0;
}