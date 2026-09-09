// cau3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
// Kiểm tra n có phải số hoan hảo hay không?

int main()
{
    int n;
    cout << "Nhap so n: ";
    cin >> n;

    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }

    if (sum == n)
    {
        cout << n << " la so hoan hao.\n";
    }
    else
    {
        cout << n << " khong phai la so hoan hao.\n";
    }

    return 0;
}

