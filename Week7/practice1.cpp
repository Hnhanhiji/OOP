#include <iostream>
#include <string>

using namespace std;

// Struct luu tai khoan
struct User {
    string username;
    string pwd;
};

// Struct luu thong tin may tinh
struct Computer {
    string id;
    string name;
    string os;
    User user; 
    string model;
    int year;
};

// Struct luu thong tin phong lab
struct Lab {
    string roomCode;
    string function;
};

// Ham nhap thong tin lab va danh sach may tinh
void inputLabAndComputers(Lab &lab, Computer computers[], int &n) {
    cout << "=== NHAP THONG TIN PHONG LAB ===\n";
    cout << "Nhap ma phong: ";
    getline(cin, lab.roomCode);
    cout << "Nhap chuc nang phong: ";
    getline(cin, lab.function);

    cout << "\nNhap so luong may tinh (1 - 20): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin may tinh " << (i + 1) << " ---\n";
        cin.ignore(); // Xoa bo nho dem truoc khi nhap chuoi
        cout << "ID: ";
        getline(cin, computers[i].id);
        cout << "Ten may: ";
        getline(cin, computers[i].name);
        cout << "He dieu hanh (OS): ";
        getline(cin, computers[i].os);
        cout << "Username: ";
        getline(cin, computers[i].user.username);
        cout << "Password: ";
        getline(cin, computers[i].user.pwd);
        cout << "Model: ";
        getline(cin, computers[i].model);
        cout << "Nam san xuat: ";
        cin >> computers[i].year;
    }
}

// Ham in thong tin phong lab
void showLabInfo(Lab lab) {
    cout << "\n=== THONG TIN PHONG LAB ===\n";
    cout << "Ma phong : " << lab.roomCode << "\n";
    cout << "Chuc nang: " << lab.function << "\n";
}

// 1) Tim va in thong tin may tinh theo ID (kieu void)
void getComputerInfo(Computer computers[], int n, string targetId) {
    bool timThay = false;
    for (int i = 0; i < n; i++) {
        if (computers[i].id == targetId) {
            cout << "\n=== THONG TIN MAY (ID: " << targetId << ") ===\n";
            cout << "Ten may : " << computers[i].name << "\n";
            cout << "OS      : " << computers[i].os << "\n";
            cout << "Username: " << computers[i].user.username << "\n";
            cout << "Password: " << computers[i].user.pwd << "\n";
            cout << "Model   : " << computers[i].model << "\n";
            cout << "Nam     : " << computers[i].year << "\n";
            timThay = true;
            break;
        }
    }
    if (!timThay) {
        cout << "\nKhong tim thay may tinh co ID: " << targetId << "\n";
    }
}

// 2) Tim va tra ve doi tuong Computer theo ID
Computer getComputerById(Computer computers[], int n, string targetId) {
    for (int i = 0; i < n; i++) {
        if (computers[i].id == targetId) {
            return computers[i];
        }
    }
    // Tra ve may rong neu khong tim thay
    Computer rong;
    rong.id = "";
    rong.name = "N/A";
    rong.os = "N/A";
    rong.model = "N/A";
    rong.year = 0;
    return rong;
}

// 3) Tra ve con tro trỏ den mang cac may tinh
Computer* getComputers(Computer computers[]) {
    return computers;
}

// 4) Lay thong tin Username & Password thong qua ID may
User getUserAndPassword(Computer computers[], int n, string targetId) {
    for (int i = 0; i < n; i++) {
        if (computers[i].id == targetId) {
            return computers[i].user;
        }
    }
    User uRong;
    uRong.username = "N/A";
    uRong.pwd = "N/A";
    return uRong;
}

int main() {
    Lab lab;
    Computer computers[20];
    int n = 0;

    // Nhap thong tin
    inputLabAndComputers(lab, computers, n);
    
    // In thong tin lab
    showLabInfo(lab);

    string searchId;

    // 1) Test ham in thong tin theo ID
    cout << "\nNhap ID may can in thong tin: ";
    cin.ignore();
    getline(cin, searchId);
    getComputerInfo(computers, n, searchId);

    // 2) Test ham trả về doi tuong Computer
    cout << "\nNhap ID may can lay doi tuong: ";
    getline(cin, searchId);
    Computer comp = getComputerById(computers, n, searchId);
    cout << "-> Ket qua: Ten = " << comp.name << " | Model = " << comp.model << "\n";

    // 3) Test ham tra ve con tro mang
    cout << "\n=== DANH SACH MAY TINH (DUYET TUC CON TRO) ===\n";
    Computer* list = getComputers(computers);
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". ID: " << list[i].id 
             << " | Ten: " << list[i].name 
             << " | OS: " << list[i].os << "\n";
    }

    // 4) Test ham lay tai khoan User/Pass
    cout << "\nNhap ID may can lay tai khoan: ";
    getline(cin, searchId);
    User u = getUserAndPassword(computers, n, searchId);
    cout << "-> Credentials (User: " << u.username << " | Password: " << u.pwd << ")\n";

    return 0;
}
