#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1. Class Employee (lớp cha)
class Employee {
protected:
    string cccd;
    string sdt;
    string address;

public:
    Employee();
    Employee(string c, string s, string a);
    
    // Khai báo hàm ảo (virtual) để hỗ trợ tính đa hình cho bài tập mở rộng
    virtual ~Employee() {}
    virtual void displayInfo() const;
    virtual double tinhLuong() const { return 0.0; } 
    virtual string getType() const { return "Employee"; } // Phân loại nhân viên

    // Getters & Setters
    string getCCCD() const;
    string getSDT() const;
    string getAddress() const;
    void setCCCD(string c);
    void setSDT(string s);
    void setAddress(string a);
};

// 2. Class HourlyEmployee (kế thừa từ Employee)
class HourlyEmployee : public Employee {
private:
    int soGioLamViec;
    double donGia;

public:
    HourlyEmployee();
    HourlyEmployee(string c, string s, string a, int soGio, double donGia);

    // Mở rộng 1 & 2: Ghi đè hàm tinhLuong() và displayInfo()
    double tinhLuong() const override;
    void displayInfo() const override;
    string getType() const override { return "HourlyEmployee"; }

    // Getters & Setters
    int getSoGioLamViec() const;
    double getDonGia() const;
    void setSoGioLamViec(int g);
    void setDonGia(double dg);
};

// 3. Class MonthlyEmployee (kế thừa từ Employee)
class MonthlyEmployee : public Employee {
private:
    double luongCoBan;
    double phuCap;
    double heSoThuong;

public:
    MonthlyEmployee();
    MonthlyEmployee(string c, string s, string a, double lcb, double pc, double hs);

    // Mở rộng 1 & 2: Ghi đè hàm tinhLuong() và displayInfo()
    double tinhLuong() const override;
    void displayInfo() const override;
    string getType() const override { return "MonthlyEmployee"; }

    // Getters & Setters
    double getLuongCoBan() const;
    double getPhuCap() const;
    double getHeSoThuong() const;
    void setLuongCoBan(double lcb);
    void setPhuCap(double pc);
    void setHeSoThuong(double hs);
};

// ĐỊNH NGHĨA CÁC PHƯƠNG THỨC & CONSTRUCTOR

// --- Employee ---
Employee::Employee() { cccd = ""; sdt = ""; address = ""; }
Employee::Employee(string c, string s, string a) : cccd(c), sdt(s), address(a) {}

string Employee::getCCCD() const { return cccd; }
string Employee::getSDT() const { return sdt; }
string Employee::getAddress() const { return address; }
void Employee::setCCCD(string c) { cccd = c; }
void Employee::setSDT(string s) { sdt = s; }
void Employee::setAddress(string a) { address = a; }

void Employee::displayInfo() const {
    cout << "CCCD: " << cccd << endl;
    cout << "SDT: " << sdt << endl;
    cout << "Address: " << address << endl;
}

// --- HourlyEmployee ---
HourlyEmployee::HourlyEmployee() : Employee(), soGioLamViec(0), donGia(0.0) {}
HourlyEmployee::HourlyEmployee(string c, string s, string a, int soGio, double dg)
    : Employee(c, s, a), soGioLamViec(soGio), donGia(dg) {}

// Bài mở rộng 1: Công thức tính lương HourlyEmployee
double HourlyEmployee::tinhLuong() const {
    return soGioLamViec * donGia;
}

// Bài mở rộng 2: Ghi đè displayInfo
void HourlyEmployee::displayInfo() const {
    Employee::displayInfo();
    cout << "So gio lam viec: " << soGioLamViec << endl;
    cout << "Don gia: " << donGia << endl;
    cout << "Luong: " << tinhLuong() << endl;
}

int HourlyEmployee::getSoGioLamViec() const { return soGioLamViec; }
double HourlyEmployee::getDonGia() const { return donGia; }
void HourlyEmployee::setSoGioLamViec(int g) { soGioLamViec = g; }
void HourlyEmployee::setDonGia(double dg) { donGia = dg; }

// --- MonthlyEmployee ---
MonthlyEmployee::MonthlyEmployee() : Employee(), luongCoBan(0.0), phuCap(0.0), heSoThuong(0.0) {}
MonthlyEmployee::MonthlyEmployee(string c, string s, string a, double lcb, double pc, double hs)
    : Employee(c, s, a), luongCoBan(lcb), phuCap(pc), heSoThuong(hs) {}

// Bài mở rộng 1: Công thức tính lương MonthlyEmployee
double MonthlyEmployee::tinhLuong() const {
    return luongCoBan + phuCap + (luongCoBan * heSoThuong);
}

// Bài mở rộng 2: Ghi đè displayInfo
void MonthlyEmployee::displayInfo() const {
    Employee::displayInfo();
    cout << "Luong co ban: " << luongCoBan << endl;
    cout << "Phu cap: " << phuCap << endl;
    cout << "He so thuong: " << heSoThuong << endl;
    cout << "Luong: " << tinhLuong() << endl;
}

double MonthlyEmployee::getLuongCoBan() const { return luongCoBan; }
double MonthlyEmployee::getPhuCap() const { return phuCap; }
double MonthlyEmployee::getHeSoThuong() const { return heSoThuong; }
void MonthlyEmployee::setLuongCoBan(double lcb) { luongCoBan = lcb; }
void MonthlyEmployee::setPhuCap(double pc) { phuCap = pc; }
void MonthlyEmployee::setHeSoThuong(double hs) { heSoThuong = hs; }


// HÀM MAIN THỰC HIỆN CÁC BÀI TẬP MỞ RỘNG (MỤC 7)


int main() {
    // Bài mở rộng 3: Khởi tạo ít nhất 2 đối tượng mỗi loại
    // Bài mở rộng 4: Tạo mảng hoặc vector<Employee*>
    vector<Employee*> dsNhanVien;

    dsNhanVien.push_back(new HourlyEmployee("079876543210", "0901002003", "Ha Noi", 160, 50000));
    dsNhanVien.push_back(new HourlyEmployee("079111222333", "0901112233", "Hai Phong", 120, 60000));
    dsNhanVien.push_back(new MonthlyEmployee("079987654321", "0903004005", "Da Nang", 15000000, 2000000, 1.2));
    dsNhanVien.push_back(new MonthlyEmployee("079444555666", "0904445566", "Can Tho", 10000000, 1500000, 1.0));

    cout << "================ DANH SACH NHAN VIEN ================\n";
    for (const auto& nv : dsNhanVien) {
        nv->displayInfo();
        cout << "-----------------------------------\n";
    }

    // Bài mở rộng 4: Tính tổng quỹ lương
    double tongQuyLuong = 0;
    for (const auto& nv : dsNhanVien) {
        tongQuyLuong += nv->tinhLuong();
    }
    cout << "\n[Bai 4] Tong quy luong cua cong ty: " << tongQuyLuong << " VND\n";

    // Bài mở rộng 5: Tìm nhân viên lương cao nhất & thấp nhất
    if (!dsNhanVien.empty()) {
        Employee* maxNV = dsNhanVien[0];
        Employee* minNV = dsNhanVien[0];

        for (size_t i = 1; i < dsNhanVien.size(); ++i) {
            if (dsNhanVien[i]->tinhLuong() > maxNV->tinhLuong()) maxNV = dsNhanVien[i];
            if (dsNhanVien[i]->tinhLuong() < minNV->tinhLuong()) minNV = dsNhanVien[i];
        }

        cout << "\n[Bai 5] Nhan vien co LUONG CAO NHAT (" << maxNV->tinhLuong() << " VND):\n";
        maxNV->displayInfo();

        cout << "\n[Bai 5] Nhan vien co LUONG THAP NHAT (" << minNV->tinhLuong() << " VND):\n";
        minNV->displayInfo();
    }

    // Bài mở rộng 6: Đếm số lượng nhân viên từng loại
    int countHourly = 0, countMonthly = 0;
    for (const auto& nv : dsNhanVien) {
        if (nv->getType() == "HourlyEmployee") countHourly++;
        else if (nv->getType() == "MonthlyEmployee") countMonthly++;
    }
    cout << "\n[Bai 6] So luong HourlyEmployee: " << countHourly << "\n";
    cout << "[Bai 6] So luong MonthlyEmployee: " << countMonthly << "\n";

    // Bài mở rộng 7: Tìm và hiển thị danh sách NV có lương > X
    double luongNguong;
    cout << "\n[Bai 7] Nhap muc luong toi thieu can tim: ";
    cin >> luongNguong;

    cout << "---> Danh sach nhan vien co luong > " << luongNguong << " VND:\n";
    bool found = false;
    for (const auto& nv : dsNhanVien) {
        if (nv->tinhLuong() > luongNguong) {
            nv->displayInfo();
            cout << "-----------------------------------\n";
            found = true;
        }
    }
    if (!found) cout << "Khong co nhan vien nao dat muc luong nay.\n";

    // Bài mở rộng 8: Sắp xếp danh sách nhân viên theo lương giảm dần
    sort(dsNhanVien.begin(), dsNhanVien.end(), [](Employee* a, Employee* b) {
        return a->tinhLuong() > b->tinhLuong();
    });

    cout << "\n[Bai 8] DANH SACH NHAN VIEN SAU KHI SAP XEP GIAM DAN THEO LUONG:\n";
    for (const auto& nv : dsNhanVien) {
        nv->displayInfo();
        cout << "-----------------------------------\n";
    }

    // Giải phóng bộ nhớ
    for (auto nv : dsNhanVien) {
        delete nv;
    }

    return 0;
}
