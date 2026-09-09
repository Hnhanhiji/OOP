// cau5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//  Đảo ngược số


int main()
{   
    int n, soDaoNguoc = 0;

    cout << "Nhập vào một số nguyên: ";
    cin >> n;

    while (n > 0) {
        soDaoNguoc = soDaoNguoc * 10 + n % 10;
        n /= 10;
    }

    cout << "Số đảo ngược là: " << soDaoNguoc << endl;
    return 0;
}





