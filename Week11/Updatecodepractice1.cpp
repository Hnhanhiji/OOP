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

    // ===== Getter để đọc dữ liệu private ra ngoài =====
    int getBirthYear() {
        return birthdate.year;
    }

    string getAddress() {
        return address;
    }

    // ===== Methods =====
    void setStudentInfo(string n) {
        name = n;
    }

    void setStudentInfo(string n, string addr) {
        name = n;
        address = addr;
    }

    void setStudentInfo(string n, string addr, Date d) {
        name = n;
        address = addr;
        birthdate = d;
    }

    void setStudentInfo(string n, string addr, Date d, string id) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = id;
    }

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

// ===== CÁC HÀM THỐNG KÊ =====
vector<Student> getStudentByYear(Student students[], int size, int year) {
    vector<Student> result;
    for (int i = 0; i < size; i++) {
        if (students[i].getBirthYear() == year) {
            result.push_back(students[i]);
        }
    }
    return result;
}

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
    Student student1;
    Student student2("Huong");
    Student student3("An", "Vo Van Ngan");

    Date d(1989, 9, 12);
    Student student4("DoMIXI", "Ha Noi", d, "0007777056");

    Date d2(1996, 10, 26);
    Student student5("DungSenpai", "Da Nang", d2, "999993884");

    student2.getStudentInfo();
    student3.getStudentInfo();
    student4.getStudentInfo();
    student5.getStudentInfo();

    Student students[5];
    students[0] = student1;
    students[1] = student2;
    students[2] = student3;
    students[3] = student4;
    students[4] = student5;

    // Thống kê sinh viên sinh năm 1996
    cout << "\n--- KET QUA THONG KE THEO NAM 1996 ---" << endl;
    vector<Student> yearList = getStudentByYear(students, 5, 1996);
    for (int i = 0; i < yearList.size(); i++) {
        yearList[i].getStudentInfo();
    }

    // Nhập địa chỉ và thống kê
    cout << "\nNhap dia chi muon tim: ";
    string address;
    
    // Đã thay thế cin >> address thành getline để đọc được cả khoảng trắng
    getline(cin, address);

    cout << "\n--- KET QUA THONG KE THEO DIA CHI ---" << endl;
    vector<Student> filteredStudents = getStudentByAddress(students, 5, address);
    for (int i = 0; i < filteredStudents.size(); i++) {
        filteredStudents[i].getStudentInfo();
    }

    return 0;
}
