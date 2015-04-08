#include "IntToStringConvertor.h"



std::vector<int> IntToStringConvertor :: convertString(std::string StringIndex){
	int Integer; char Comma;
	std::istringstream IndexLine(StringIndex);
	std::vector <int> IndexList;
	while(IndexLine!=""){
		IndexLine>>Integer;
		IndexList.push_back(Integer);
		IndexLine>> Comma;
	}
	return IndexList;
}

