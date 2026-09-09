// cau10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath> 
using namespace std;


void demSoLuongUoc(int n)
{
    // 1. Xử lý trường hợp đặc biệt n = 0
    if (n == 0)
    {
        cout << "So 0 co vo so uoc!" << endl;
        return;
    }

    // 2. Chuyển số âm thành số dương để tìm ước dương
    n = abs(n);

    int count = 0;
    cout << "Divisors: ";

    // Vòng lặp 1: In các ước nhỏ hơn hoặc bằng căn bậc hai của n
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            count++;
        }
    }

    // Vòng lặp 2: In các ước lớn hơn căn bậc hai của n (chạy ngược lại để đảm bảo thứ tự tăng dần)
    for (int i = sqrt(n); i >= 1; i--)
    {
        if (n % i == 0)
        {
            // Nếu i * i == n (ví dụ 6 * 6 = 36) thì ước n / i đã được đếm ở vòng lặp 1, bỏ qua để tránh trùng
            if (i * i != n)
            {
                cout << n / i << " ";
                count++;
            }
        }
    }

    cout << "\nNumber of divisors: " << count << endl;
}

int main()
{
    demSoLuongUoc(12); // Chạy thử với số 12
    return 0;
}




