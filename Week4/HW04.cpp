// cau4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//  Kiểm tra n có phải là số đối xứng hay không?
bool isSymmetric(int n) {
	int original = n;
	int reversed = 0;
	while (n > 0) {
		int digit = n % 10;
		reversed = reversed * 10 + digit;
		n /= 10;
	}
	return original == reversed;
}
int main()
{   
	int n;

	cout << "Nhap so n: ";
	cin >> n;

	if (isSymmetric(n)) {
		cout << n << " la so doi xung." << endl;
	}
	else {
		cout << n << " khong phai la so doi xung." << endl;
	}

 
}



