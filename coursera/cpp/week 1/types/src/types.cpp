//============================================================================
// Name        : types.cpp
// Author      : Andrey Kondratenko
// Version     :
// Copyright   : AK
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {

	int x = 5;
	double pi = 3.14;
	bool logicalValue = false;
	char synbol = 'Z';

	string hw = "Hello World";

	vector<int> nums = {1, 3, 5, 7};
	cout << nums.size() << endl;

	map<string, int> nameToValue;
	nameToValue["one"] = 1;
	nameToValue["two"] = 2;

	cout << "two is " << nameToValue["two"];

	return 0;
}
