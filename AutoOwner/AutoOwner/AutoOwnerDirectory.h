#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class autoOwnerDirectory {
	multimap<string, string>auto_owner;
	multimap<string, string>::iterator pos;
public:
	void add_new_auto_owner(string, string);
	void delete_auto_owner(int);
	void edit_auto_owner();
	void sort_auto_owner();
	void search_owner(string);
	void print_directory();
};


class findNum {
	string num;
public:
	findNum(string num_auto) {
		num = num_auto;
	}
	void operator()(pair<string, string> obj)
	{
		if (obj.second == num)
			cout << obj.first << " " << obj.second << endl;

	}
};


