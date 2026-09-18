// referencepractice1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int main()
{
	int x = 10;
	int& rx = x;
	rx = 20;
	cout << " x= " << x << endl;
	cout << "rx =" << rx << endl;

	return 0;
}



