// HW2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// Cấu trúc dữ liệu Flower theo yêu cầu của đề bài
struct Flower {
    string name;
    double price;
    int quantity;
    string type;
};

// Hàm bổ trợ: Chuyển chuỗi thành chữ thường để so sánh không phân biệt hoa thường
string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// Hàm bổ trợ: In tiêu đề bảng
void printHeader() {
    cout << left << setw(15) << "Ten hoa"
        << setw(10) << "Gia"
        << setw(10) << "So luong"
        << setw(15) << "Loai" << endl;
    cout << string(50, '-') << endl;
}

// Hàm bổ trợ: In thông tin của một bông hoa
void printFlower(const Flower& f) {
    cout << left << setw(15) << f.name
        << setw(10) << f.price
        << setw(10) << f.quantity
        << setw(15) << f.type << endl;
}

// Nhập dữ liệu và kiểm tra ràng buộc (Input & Constraints)
void inputFlowers(Flower flowers[], int& N) {
    do {
        cout << "Nhap so luong loai hoa (1 <= N <= 20): ";
        cin >> N;
    } while (N < 1 || N > 20);

    for (int i = 0; i < N; i++) {
        cout << "\nNhap thong tin hoa thu " << i + 1 << ":\n";
        cin.ignore();
        cout << "- Ten hoa: ";
        getline(cin, flowers[i].name);

        do {
            cout << "- Gia (price > 0): ";
            cin >> flowers[i].price;
        } while (flowers[i].price <= 0);

        do {
            cout << "- So luong (quantity >= 0): ";
            cin >> flowers[i].quantity;
        } while (flowers[i].quantity < 0);

        cin.ignore();
        cout << "- Loai hoa: ";
        getline(cin, flowers[i].type);
    }
}
// Task 1: Hien thi tat ca cac bong hoa
void task1_displayAll(Flower flowers[], int N) {
    cout << "\n--- Task 1: Danh sach tat ca hoa ---\n";
    printHeader();
    for (int i = 0; i < N; i++) {
        printFlower(flowers[i]);
    }
}
// Task 2: Tim bong hoa dat nhat
void task2_findMostExpensive(Flower flowers[], int N) {
    cout << "\n--- Task 2: Hoa dat nhat ---\n";
    if (N == 0) return;
    int maxIdx = 0;
    for (int i = 1; i < N; i++) {
        if (flowers[i].price > flowers[maxIdx].price) {
            maxIdx = i;
        }
    }
    printHeader();
    printFlower(flowers[maxIdx]);
}
