// stringpractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 = "Hello";
	string s2 = "C++";
	cout << s1 << endl;
	cout << s2 << endl;

	string name;
	cout << "Enter your name:  ";
	getline(cin, name);
	cout << "Hello,  " << name << "!" << endl;

	string first = "Hello";
	string second = "World";
	string message = first + " " + second + "!";
	cout << message << endl;

	
	string str1 = "Hello C++";
	cout << "length " << str1.length() << endl; 

	
	string str2 = "Hello";
	cout << " First character:  " << str2[0] << endl;
	cout << " Third character:  " << str2[2] << endl;

	string text1 = " I love C++";
	size_t pos = text1.find("C++");
	if (pos != string::npos) {
		cout << "found at position: " << pos << endl;
	}
	else {
		cout << "not found" << endl;
	}

	
	string text2 = "hello C++ World ";
	string part = text2.substr(6, 3);
	cout << part << endl;

	
	s1 = "apple";
	s2 = "apple";

	
	if (s1.compare(s2) == 0) {
		cout << " The strings are equal. " << endl;
	}
	else {
		cout << " The strings are different." << endl;
	}

	return 0;
}

