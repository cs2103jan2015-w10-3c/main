#ifndef CHECKMATESTORAGE_H
#define CHECKMATESTORAGE_H

#include<iostream>
#include<vector>
using namespace std;

class CheckMateStorage {

	private:
		struct item { //we should have this in the whole project 
			
			string desc;
			string stime;
			string etime;
			string cat;

		};
		vector<struct> v;

	public:
		void addItem(string, string, string, string);
};

#endif