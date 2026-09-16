#include <iostream>
#include <string>

using namespace std;

// Struct 1: Lưu tài khoản (username và password)
struct Account {
    string username;
    string password;
};

// Struct 2: Lưu thông tin máy tính
struct Computer {
    string id;
    string name;      // Tên máy
    string os;        // Hệ điều hành
    Account acc;      // Lồng Struct 1 (Account) vào để chứa username, password
    string model;
    int year;
};

// Struct 3: Lưu thông tin phòng Lab
struct Lab {
    string name;              // Tên phòng lab (VD: A5-104)
    int totalComputers;       // Số lượng máy
    Computer computers[100];  // Mảng chứa danh sách các máy tính
};


// 1. Hàm in thông tin của 1 máy tính (trả về void)
void showComputerInfo(Computer c) {
    if (c.id == "") {
        cout << "Khong tim thay thong tin may tinh!" << endl;
        return;
    }
    cout << "\n--- THONG TIN MAY TINH ---" << endl;
    cout << "ID: " << c.id << endl;
    cout << "Ten may: " << c.name << endl;
    cout << "He dieu hanh: " << c.os << endl;
    cout << "Model: " << c.model << endl;
    cout << "Nam san xuat: " << c.year << endl;
    cout << "Username: " << c.acc.username << endl;
    cout << "Password: " << c.acc.password << endl;
}

// Hàm hiển thị thông tin chung của Phòng Lab
void showLabInfo(Lab lab) {
    cout << "PHONG LAB: " << lab.name << endl;
    cout << "Tong so may tinh: " << lab.totalComputers << endl;
    cout << "===================================" << endl;
}

// 2. Hàm tìm máy theo ID và trả về đối tượng Computer
Computer getComputerInfo(Lab lab, string searchId) {
    for (int i = 0; i < lab.totalComputers; i++) {
        if (lab.computers[i].id == searchId) {
            return lab.computers[i]; // Trả về đúng struct Computer tìm thấy
        }
    }
    // Trả về máy rỗng nếu không tìm thấy
    Computer emptyComp = { "", "", "", {"", ""}, "", 0 };
    return emptyComp;
}

// 3. Hàm trả về nguyên mảng danh sách máy tính
Computer* getComputerList(Lab& lab) {
    return lab.computers; // Trả về con trỏ trỏ đến đầu mảng máy tính
}

// 4. Hàm tìm theo ID nhưng chỉ trả về struct Account (username, password)
Account getUserAndPassword(Lab lab, string searchId) {
    for (int i = 0; i < lab.totalComputers; i++) {
        if (lab.computers[i].id == searchId) {
            return lab.computers[i].acc; // Trả về struct Account của máy đó
        }
    }
    Account emptyAcc = { "", "" };
    return emptyAcc;
}

int main() {
    Lab myLab;

    // Nhập thông tin phòng Lab
    cout << "Nhap ten phong Lab (vi du: A5-104): ";
    cin >> myLab.name;
    cout << "Nhap so luong may tinh trong phong: ";
    cin >> myLab.totalComputers;

    // Nhập thông tin chi tiết từng máy
    for (int i = 0; i < myLab.totalComputers; i++) {
        cout << "\n--- Nhap may thu " << i + 1 << " ---" << endl;
        cout << "ID: "; cin >> myLab.computers[i].id;
        cout << "Ten may: "; cin >> myLab.computers[i].name;
        cout << "He dieu hanh: "; cin >> myLab.computers[i].os;
        cout << "Model: "; cin >> myLab.computers[i].model;
        cout << "Nam san xuat: "; cin >> myLab.computers[i].year;
        cout << "Username: "; cin >> myLab.computers[i].acc.username;
        cout << "Password: "; cin >> myLab.computers[i].acc.password;
    }

    // Hiển thị thông tin tổng quan phòng lab
    showLabInfo(myLab);

    //  CÂU 1: In thông tin máy đầu tiên ---
    cout << " YEU CAU 1: In thong tin 1 may tinh bang ham void";
    showComputerInfo(myLab.computers[0]);  // kh

    // CÂU 2: Tìm và trả về 1 struct Computer theo ID ---
    string findId;
    cout << "\n>>> YEU CAU 2: Nhap ID may tinh can tim: ";
    cin >> findId;
    Computer foundComp = getComputerInfo(myLab, findId);
    showComputerInfo(foundComp);

    // CÂU 3: Lấy toàn bộ mảng máy tính và duyệt in ---
    cout << "\n>>> YEU CAU 3: Lay nguyen mang mays tinh va in danh sach ID:";
    Computer* list = getComputerList(myLab);
    for (int i = 0; i < myLab.totalComputers; i++) {
        cout << "\nMay " << i + 1 << " ID: " << list[i].id << " - Ten: " << list[i].name;
    }
    cout << endl;

    //  CÂU 4: Chỉ lấy struct Account (username, password) theo ID ---
    cout << "\n>>> YEU CAU 4: Nhap ID may can lay User/Pass: ";
    cin >> findId;
    Account userPass = getUserAndPassword(myLab, findId);
    if (userPass.username != "") {
        cout << "-> User: " << userPass.username << " | Pass: " << userPass.password << endl;
    }
    else {
        cout << "-> Khong tim thấy ID nay!" << endl;
    }

    return 0;
}
