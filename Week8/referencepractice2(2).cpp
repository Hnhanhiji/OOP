// referencepractice2(2).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// Hàm hoán đổi giá trị sử dụng tham chiếu (reference)
void swapValues(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 5, b = 10;

    cout << "Before: a = " << a << ", b = " << b << endl;

    // Gọi hàm hoán đổi
    swapValues(a, b);

    cout << "After: a = " << a << ", b = " << b << endl;
    // khi có dấu & Hàm dùng trực tiếp vùng nhớ của biến gốc a và b.
    // giá trị a và  b bị hoán đổi 

    // khi không có dấu & Hàm tự tạo ra 2 bản sao x và y riêng biệt tại vùng nhớ khác.
    // giá trị của a  và b giữ nguyên ko thay đổi 


    return 0;
}

