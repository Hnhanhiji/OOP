// EX2_GiaiPTBac1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


// giải phương trình bậc 1 ax + b = 0

int main()
{
	int a, b;
	cout << "Nhap a: "; cin >> a;
	cout << "Nhap b: "; cin >> b;
	if (a == 0) {
		if (b == 0) {
			cout << "Phuong trinh co vo so nghiem" << endl;
		}
		else {
			cout << "Phuong trinh vo nghiem" << endl;
		}
	}
	else {
		float x = -b / (float)a;
		cout << "Nghiem cua phuong trinh la: x = " << x << endl;
	}
	return 0;
}

		
