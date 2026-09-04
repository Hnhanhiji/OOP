// EX3_KtraNGguyenTo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// kiểm tra số nguyên tố 
bool ktNguyenTo(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main()
{   
	int n;
	cout << "Nhap mot so nguyen: ";
	cin >> n;

	if (ktNguyenTo(n)) {
		cout << n << " la so nguyen to." << endl;
	} else {
		cout << n << " khong phai la so nguyen to." << endl;
	}

	return 0;
}


