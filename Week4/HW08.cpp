// cau8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//  Bội chung nhỏ nhất của n số nguyên
void bcnn(int n)
{
	int a[100];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap so thu " << i + 1 << ": ";
		cin >> a[i];
	}
	int bcnn = a[0];
	for (int i = 1; i < n; i++)
	{
		int temp = bcnn;
		while (temp % a[i] != 0)
		{
			temp += bcnn;
		}
		bcnn = temp;
	}
	cout << "Boi chung nho nhat cua " << n << " so nguyen la: " << bcnn << endl;
}

int main()
{	
    int n;
    cout << "Nhap so luong so nguyen: ";
    cin >> n;
    bcnn(n);
    return 0;
}


