// Week10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

// 1. Chuyển đổi từ struct sang class
class Food {
public:
    string id;
    string name;
    double price;
    int quantity;

    void input() {
        cout << "Nhap ten: ";
        getline(cin, name);
        cout << "Nhap gia: ";
        cin >> price;
        quantity = 0;
        cin.ignore(); 
    }

    void display() {
        cout << name << " - " << price << " (" << quantity << ")\n";
    }
};

int main() {
    // Tạo mảng gồm 3 món ăn
    Food menu[3];

    // Nhập thông tin cho 3 món ăn
    for (int i = 0; i < 3; i++) {
        menu[i].input();
    }

    // In thông tin các món ăn ra màn hình
    cout << "\n=== Danh sach mon an ===\n";
    for (int i = 0; i < 3; i++) {
        menu[i].display();
    }
    // 3. Tìm món ăn theo tên
    string searchName;
    cout << "\nNhap ten mon an can tim: ";
    getline(cin, searchName);
    cout << "\n=== Ket qua tim kiem ===\n";
    for (int i = 0; i < 3; i++) {
        if (menu[i].name == searchName) {
            menu[i].display();
            
        }
    }
	//4. cập nhật giá của một món ăn
	string updateName;
	cout << "\nNhap ten mon an can cap nhat gia: ";
	getline(cin, updateName);
    bool found = false;
	for (int i = 0; i < 3; i++) {
		if (menu[i].name == updateName) {
			cout << "Nhap gia moi: ";
			cin >> menu[i].price;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "Khong tim thay mon an!\n";
	}

    return 0;
}

