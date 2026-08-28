#include <iostream>
#include <string>

using namespace std;

int main() {
    const int N = 20;   // 1. Khai báo số lượng 20 sinh viên
    string names[N];
    string ids[N];
    string phones[N];

    // 2. Nhập thông tin của 20 học sinh bằng vòng lặp for
    for (int i = 0; i < N; i++) {
        cout << "Enter student " << (i + 1) << "\n";

        cout << "Name : ";
        getline(cin, names[i]);

        cout << "ID   : ";
        getline(cin, ids[i]);

        cout << "Phone: ";
        getline(cin, phones[i]);

        cout << "---------------------\n";
    }

    // 3. Hiển thị thông tin của 20 học sinh ra màn hình
    cout << "\n===== STUDENT LIST =====\n";
    for (int i = 0; i < N; i++) {
        cout << "Student " << (i + 1) << "\n";
        cout << "Name : " << names[i] << "\n";
        cout << "ID   : " << ids[i] << "\n";
        cout << "Phone: " << phones[i] << "\n";
        cout << "---------------------\n";
    }
    cout << "Total students: " << N << "\n";

    return 0;
}
