// Function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
// void showelcome
void  showWelcome()
{
	cout << "==============================\n";
	cout << "Welcome to Student Manager\n";
	cout << "==============================\n";
}
// void showMenu include display Students, Show statistics, exit
void showMenu()
{
	cout << "1. Display Students\n";
	cout << "2. Show Statistics\n";
	cout << "3. Exit\n";
}
// void showStudentsName(string name)
void showStudentsName(string name){ 
	
	cout << "hello, " << name << "!" << endl;
	cout << "Student Name: " << name << endl;
}

int main()
{	// call the fucntion showWelcome
	showWelcome();
    showMenu();
	cout << "Let's get started!\n";
	string studentName;
	cout << "enter your name:";
	getline(cin, studentName);
	showStudentsName(studentName);

	return 0;
}






