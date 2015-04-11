#include "IntToStringConvertor.h"



std::vector<int> IntToStringConvertor :: convertString(std::string StringIndex){
	int Integer; char Comma;
<<<<<<< HEAD
	std::istringstream IndexLine(StringIndex);
	std::vector <int> IndexList;
	while(IndexLine!=""){
		IndexLine>>Integer;
		IndexList.push_back(Integer);
		IndexLine>> Comma;
	}
=======
	std::string IndexString = StringIndex + ",";
	std::istringstream IndexLine(StringIndex);
	std::vector <int> IndexList;
	while(IndexLine>>Integer){
		IndexList.push_back(Integer);
		IndexLine>> Comma;
	}
	std::sort(IndexList.begin(),IndexList.end());
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
	return IndexList;
}

