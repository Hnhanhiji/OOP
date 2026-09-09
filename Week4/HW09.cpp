// cau9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//  Tính lũy thừa x^n 
void luythua(int x, int n)
{
	int result = 1;
	for (int i = 0; i < n; i++)
	{
		result *= x;
	}
	cout << "Luy thua cua " << x << "^" << n << " = " << result << endl;
}



int main()
{
    luythua(2, 3);
    return 0;
}


