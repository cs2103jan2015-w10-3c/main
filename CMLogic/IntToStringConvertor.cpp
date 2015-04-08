#include "IntToStringConvertor.h"



std::vector<int> IntToStringConvertor :: convertString(std::string StringIndex){
	int Integer; char Comma;
	std::string IndexString = StringIndex + ",";
	std::istringstream IndexLine(StringIndex);
	std::vector <int> IndexList;
	while(IndexLine>>Integer){
		IndexList.push_back(Integer);
		IndexLine>> Comma;
	}
	std::sort(IndexList.begin(),IndexList.end());
	return IndexList;
}

