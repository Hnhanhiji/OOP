// FLowerShop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// Định nghĩa cấu trúc Flower theo yêu cầu đề bài
struct Flower {
    string name;
    double price;
    int quantity;
    string type;
};
Flower flowers[20]; // Mảng lưu trữ các loại hoa
int N; // Số lượng loại hoa
// Hàm bổ trợ: Chuyển chuỗi thành chữ thường để so sánh không phân biệt hoa thường (Case-insensitive)
string toLower(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

// Hàm bổ trợ: In tiêu đề bảng dữ liệu
void printHeader() {
    cout << left << setw(5) << "No"
        << setw(15) << "Name"
        << setw(10) << "Price"
        << setw(8) << "Qty"
        << setw(15) << "Type" << endl;
    cout << "--------------------------------------------------\n";
}

// Hàm bổ trợ: In thông tin của một bông hoa
void printFlower(int index, Flower f) {
    cout << left << setw(5) << index
        << setw(15) << f.name
        << setw(10) << fixed << setprecision(1) << f.price
        << setw(8) << f.quantity
        << setw(15) << f.type << endl;
}

// ============================================================================
// CHỨC NĂNG TỪ CÂU 1 ĐẾN CÂU 20
// ============================================================================
// Câu 1: Hiển thị tất cả các loài hoa có trong danh sách
void cau1_DisplayAllFlowers(Flower flowers[], int N) {
    cout << "--- Cau 1: All Flowers ---\n";
    printHeader();
    for (int i = 0; i < N; i++) {
        printFlower(i + 1, flowers[i]);
    }
}
// Câu 2: Tìm và hiển thị (các) loài hoa có giá đắt nhất
void cau2_FindMostExpensiveFlower(Flower flowers[], int N) {
    cout << "--- Cau 2: Most Expensive Flower(s) ---\n";
    double maxPrice = flowers[0].price;
    // Tìm giá trị lớn nhất
    for (int i = 1; i < N; i++) {
        if (flowers[i].price > maxPrice) maxPrice = flowers[i].price;
    }
    // In ra tất cả các hoa có cùng mức giá đắt nhất đó
    printHeader();
    for (int i = 0; i < N; i++) {
        if (flowers[i].price == maxPrice) printFlower(i + 1, flowers[i]);
    }
}
