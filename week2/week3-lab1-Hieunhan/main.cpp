#include <iostream>
#include <string>

using namespace std;

int main() {
    // 1. Khai báo 3 mảng lưu tối đa 20 sinh viên
    const int MAX = 20;
    string names[MAX];
    string ids[MAX];
    string phones[MAX];

    int n;
    // 2. Nhập số lượng sinh viên (từ 2 đến 20)
    cout << "Nhap so luong sinh vien (2-20): ";
    cin >> n;
    cin.ignore(); // Xóa bộ nhớ đệm để không bị lỗi trôi dòng khi nhập chữ

    // 3. Vòng lặp NHẬP thông tin sinh viên
    for (int i = 0; i < n; i++) {
        cout << "Nhap sinh vien " << (i + 1) << ":\n";
        cout << "Name: ";
        getline(cin, names[i]);
        cout << "ID: ";
        getline(cin, ids[i]);
        cout << "Phone: ";
        getline(cin, phones[i]);
    }

    // 4. Vòng lặp XUẤT thông tin sinh viên
    cout << "\n=========================================\n";
    cout << "               STUDENT LIST              \n";
    cout << "=========================================\n";
    
    for (int i = 0; i < n; i++) {
        cout << "Student " << (i + 1) << "\n";
        cout << "Name       : " << names[i] << "\n";
        cout << "Student ID : " << ids[i] << "\n";
        cout << "Phone      : " << phones[i] << "\n\n";
    }

    cout << "=========================================\n";
    cout << "Total students: " << n << "\n";
    cout << "=========================================\n";

    return 0;
}

