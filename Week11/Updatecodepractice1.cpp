#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_STUDENTS 100

class Date {
public:
    int year, month, day;
    Date() { year = 0; month = 0; day = 0; }
    Date(int y, int m, int d) { year = y; month = m; day = d; }
};

class Student {
private:
    string name;
    string address;
    Date birthdate; // yyyy/mm/dd
    string cccd;

public:
    // ===== Constructors =====
    Student() {
        name = "";
        address = "";
        birthdate = Date();
        cccd = "";
    }

    Student(string n) {
        name = n;
        address = "";
        birthdate = Date();
        cccd = "";
    }

    Student(string n, string addr) {
        name = n;
        address = addr;
        birthdate = Date();
        cccd = "";
    }

    Student(string n, string addr, Date d) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = "";
    }

    Student(string n, string addr, Date d, string id) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = id;
    }

    // ===== Getters (Lấy dữ liệu private để dùng cho các hàm thống kê) =====
    int getBirthYear() {
        return birthdate.year;
    }

    string getAddress() {
        return address;
    }

    // ===== Methods =====
    void setStudentInfo(string n) { name = n; }
    void setStudentInfo(string n, string addr) { name = n; address = addr; }
    void setStudentInfo(string n, string addr, Date d) { name = n; address = addr; birthdate = d; }
    void setStudentInfo(string n, string addr, Date d, string id) { name = n; address = addr; birthdate = d; cccd = id; }

    void getStudentInfo() {
        cout << "====================" << endl;
        cout << "=== Student Info ===" << endl;
        cout << "====================" << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Birthdate: " << birthdate.year << "/" << birthdate.month << "/" << birthdate.day << endl;
        cout << "CCCD: " << cccd << endl;
    }
};

// ===== HÀM THỐNG KÊ THEO NĂM SINH =====
vector<Student> getStudentByYear(Student students[], int size, int year) {
    vector<Student> result;
    for (int i = 0; i < size; i++) {
        if (students[i].getBirthYear() == year) {
            result.push_back(students[i]);
        }
    }
    return result;
}

// ===== HÀM THỐNG KÊ THEO ĐỊA CHỈ/TỈNH =====
vector<Student> getStudentByAddress(Student students[], int size, string address) {
    vector<Student> result;
    for (int i = 0; i < size; i++) {
        if (students[i].getAddress() == address) {
            result.push_back(students[i]);
        }
    }
    return result;
}

int main() {
    // Khởi tạo các sinh viên thử nghiệm (có đầy đủ năm sinh 2000, 2001, 1996)
    Student student1;
    Student student2("Huong", "Ha Noi", Date(2000, 5, 10), "012345");
    Student student3("An", "Vo Van Ngan", Date(2001, 8, 20), "012346");

    Date d1(2000, 9, 12);
    Student student4("DoMIXI", "Ha Noi", d1, "0007777056");

    Date d2(1996, 10, 26);
    Student student5("DungSenpai", "Da Nang", d2, "999993884");

    Date d3(2001, 1, 15);
    Student student6("PewPew", "Da Nang", d3, "0011223344");

    // Đưa sinh viên vào mảng tĩnh
    int totalStudents = 6;
    Student students[6];
    students[0] = student1;
    students[1] = student2;
    students[2] = student3;
    students[3] = student4;
    students[4] = student5;
    students[5] = student6;

    // ==========================================================
    // 1. THỐNG KÊ THEO NĂM SINH (Nhập từ bàn phím: 2000, 2001, ...)
    // ==========================================================
    int searchYear;
    cout << "Nhap nam sinh muon thong ke (VD: 2000, 2001): ";
    cin >> searchYear;

    vector<Student> filteredByYear = getStudentByYear(students, totalStudents, searchYear);

    cout << "\n--- KET QUA THONG KE SINH VIEN SINH NAM " << searchYear << " ---" << endl;
    cout << "Tong so luong: " << filteredByYear.size() << " sinh vien" << endl;
    for (int i = 0; i < filteredByYear.size(); i++) {
        filteredByYear[i].getStudentInfo();
    }

    // ==========================================================
    // 2. THỐNG KÊ THEO ĐỊA CHỈ / TỈNH (Nhập từ bàn phím: Ha Noi, Da Nang, ...)
    // ==========================================================
    string address;
    cout << "\nNhap dia chi muon thong ke: ";
    cin.ignore(); // Xóa bộ nhớ đệm trước khi nhập chuỗi bằng getline
    getline(cin, address);

    vector<Student> filteredByAddress = getStudentByAddress(students, totalStudents, address);

    cout << "\n--- KET QUA THONG KE SINH VIEN TAI: " << address << " ---" << endl;
    cout << "Tong so luong: " << filteredByAddress.size() << " sinh vien" << endl;
    for (int i = 0; i < filteredByAddress.size(); i++) {
        filteredByAddress[i].getStudentInfo();
    }

    return 0;
}
