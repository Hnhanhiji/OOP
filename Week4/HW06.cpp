// cau6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//đếm số chữ trong chuỗi nhập vào từ bàn phím
// vd input: 583
// output: 16
#include <iostream>
#include <vector>

using namespace std;

// Số chữ cái của các từ từ 0 đến 9 (không=5, một=3, hai=3, ba=2, bốn=3, năm=3, sáu=3, bảy=3, tám=3, chín=4)
const vector<int> C = { 5, 3, 3, 2, 3, 3, 3, 3, 3, 4 };

int main() {
    int n;
    cout << "Nhap n (0-999): ";
    cin >> n;

    if (n == 0) {
        cout << "Output: " << C[0] << endl; // chữ "không" có 5 chữ cái
        return 0;
    }

    int tram = n / 100;
    int chuc = (n % 100) / 10;
    int donvi = n % 10;
    int tong = 0;

    // 1. Tính hàng trăm (Ví dụ: "năm trăm" = năm + trăm = 3 + 4)
    if (tram > 0) {
        tong += C[tram] + 4; // "trăm" có 4 chữ cái
    }

    // 2. Tính hàng chục
    if (chuc > 1) {
        tong += C[chuc] + 4; // "mươi" có 4 chữ cái (Ví dụ: "tám mươi" = 3 + 4)
    }
    else if (chuc == 1) {
        tong += 4;           // "mười" có 4 chữ cái
    }
    else if (tram > 0 && donvi > 0) {
        tong += 4;           // "linh" hoặc "lẻ" đều có 4 chữ cái (Ví dụ: "linh ba")
    }

    // 3. Tính hàng đơn vị
    if (donvi > 0) {
        if (donvi == 1 && chuc > 1) {
            tong += 3; // "mốt" có 3 chữ cái
        }
        else if (donvi == 5 && chuc > 0) {
            tong += 3; // "lăm" có 3 chữ cái
        }
        else if (donvi == 4 && chuc > 1) {
            tong += 2; // "tư" có 2 chữ cái
        }
        else {
            tong += C[donvi]; // Các số còn lại giữ nguyên số chữ cái ban đầu
        }
    }

    cout << "Output: " << tong << endl;
    return 0;
}

