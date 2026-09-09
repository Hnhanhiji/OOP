// cau7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
// tìm ước chung lớn nhất của n số nguyên 
void UCLN(int n)
{
	int a[100];
	cout << "Nhap n so nguyen: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ucln = a[0];
	for (int i = 1; i < n; i++)
	{
		while (a[i] != 0)
		{
			int temp = a[i];
			a[i] = ucln % a[i];
			ucln = temp;
		}
	}
	cout << "Uoc chung lon nhat cua " << n << " so nguyen la: " << ucln << endl;
}

int main()
{
	int n;
	cout << "Nhap so luong so nguyen: ";
	cin >> n;
	UCLN(n);
	return 0;
}



