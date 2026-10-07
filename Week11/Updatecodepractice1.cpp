#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date {
public:
    int day;
    int month;
    int year;

    Date() {
        day = 0;
        month = 0;
        year = 0;
    }

    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
};

class Student {
//properties - những tính chất của đối tượng 
private:
    string name;
    string address;  
    Date birthdate; //yyyy/mm/dd hh:mm:ss
    string cccd; 

//methods
public: 
    //constructors: các hàm khởi tạo dữ lieu -> thông báo hđh cap phát vùng nhớ để lưu trữ 
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

    Student(Date d) {
        name = ""; 
        address = "";
        birthdate = d; 
        cccd = "";
    }

    Student(string n, string a) {
        name = n;
        address = a;
        birthdate = Date();
        cccd = "";
    }

    Student(string n, string a, Date d) {
        name = n;
        address = a;
        birthdate = d;
        cccd = "";
    }

    Student(string n, string a, Date d, string c) {
        name = n;
        address = a;
        birthdate = d;
        cccd = c;
    }

    // Lấy các giá trị ra để xử lý
    string getName() { return name; }
    string getAddress() { return address; }
    string getCccd() { return cccd; }
    int getBirthYear() { return birthdate.year; }

    void setStudentInfo() { //nhập thông tin sinh viên 
        cout << "Nhap ten: ";
        getline(cin, name);
        cout << "Nhap dia chi: ";
        getline(cin, address);
        cout << "Nhap ngay thang nam sinh (ngay thang nam): ";
        cin >> birthdate.day >> birthdate.month >> birthdate.year;
        cin.ignore(); // Tránh trôi lệnh getline
        cout << "Nhap CCCD: ";
        getline(cin, cccd);
    }
};

// ================ HÀM XỬ LÝ DANH SÁCH SINH VIÊN ================

// Lấy thông tin sinh viên theo CCCD
Student getStudentInfo(string cccd, vector<Student> ds) {
    for (int i = 0; i < ds.size(); i++) {
        if (ds[i].getCccd() == cccd) {
            return ds[i];
        }
    }
    return Student();
}

// Lấy danh sách sinh viên theo tên
vector<Student> getStudents(string name, vector<Student> ds) {
    vector<Student> kq;
    for (int i = 0; i < ds.size(); i++) {
        if (ds[i].getName() == name) {
            kq.push_back(ds[i]);
        }
    }
    return kq;
}

// Update:
// 1. Thống kê số lượng sinh viên theo năm sinh (2000, 2001,...)
int thongKeTheoNamSinh(int nam, vector<Student> ds) {
    int dem = 0;
    for (int i = 0; i < ds.size(); i++) {
        if (ds[i].getBirthYear() == nam) {
            dem++;
        }
    }
    return dem;
}

// 2. Thống kê theo tỉnh (kiểm tra xem tên tỉnh có trong địa chỉ không)
int thongKeTheoTinh(string tinh, vector<Student> ds) {
    int dem = 0;
    for (int i = 0; i < ds.size(); i++) {
        if (ds[i].getAddress().find(tinh) != string::npos) {
            dem++;
        }
    }
    return dem;
}

// private/public: OOP = Data hiding -> Encapsulation 

int main() {
    Student student1;
    Student student2("huong");
    Student student3("", "vo van ngan");

    // Tạo danh sách sinh viên để test các hàm thống kê
    vector<Student> dsSinhVien;
    dsSinhVien.push_back(Student("An", "TPHCM", Date(1, 1, 2001), "001"));
    dsSinhVien.push_back(Student("Binh", "Dong Nai", Date(5, 5, 2001), "002"));
    dsSinhVien.push_back(Student("Cuong", "TPHCM", Date(10, 10, 2000), "003"));

    // Gọi hàm thống kê
    int soLuong2001 = thongKeTheoNamSinh(2001, dsSinhVien);
    int soLuongTPHCM = thongKeTheoTinh("TPHCM", dsSinhVien);

    cout << "So sinh vien sinh nam 2001: " << soLuong2001 << endl;
    cout << "So sinh vien o TPHCM: " << soLuongTPHCM << endl;

    return 0;
}
