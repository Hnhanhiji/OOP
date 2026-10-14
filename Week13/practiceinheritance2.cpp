#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// ==========================================
// 1. CLASS EMPLOYEE (Abstract Base Class)
// ==========================================
class Employee {
protected:
    string cccd;
    string sdt;
    string address;

public:
    Employee() { cccd = ""; sdt = ""; address = ""; }
    Employee(string c, string s, string a) : cccd(c), sdt(s), address(a) {}
    
    virtual ~Employee() {} // Destructor ảo

    // Hàm thuần ảo (Pure virtual)
    virtual double tinhLuong() const = 0;
    virtual string getType() const = 0;
    
    virtual void displayInfo() const {
        cout << "| CCCD: " << left << setw(15) << cccd 
             << "| SDT: " << setw(12) << sdt 
             << "| Dia chi: " << setw(12) << address;
    }

    // Getters & Setters
    string getCCCD() const { return cccd; }
    string getSDT() const { return sdt; }
    string getAddress() const { return address; }
};

// ==========================================
// 2. CLASS HOURLY EMPLOYEE
// ==========================================
class HourlyEmployee : public Employee {
private:
    int soGioLamViec;
    double donGia;

public:
    HourlyEmployee() : Employee(), soGioLamViec(0), donGia(0.0) {}
    HourlyEmployee(string c, string s, string a, int soGio, double dg)
        : Employee(c, s, a), soGioLamViec(soGio), donGia(dg) {}

    double tinhLuong() const override {
        return soGioLamViec * donGia;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "| Loai: Hourly  | Gio lam: " << setw(4) << soGioLamViec 
             << "| Luong: " << fixed << setprecision(0) << tinhLuong() << " VND" << endl;
    }

    string getType() const override { return "HourlyEmployee"; }
};

// ==========================================
// 3. CLASS MONTHLY EMPLOYEE
// ==========================================
class MonthlyEmployee : public Employee {
private:
    double luongCoBan;
    double phuCap;
    double heSoThuong;

public:
    MonthlyEmployee() : Employee(), luongCoBan(0.0), phuCap(0.0), heSoThuong(0.0) {}
    MonthlyEmployee(string c, string s, string a, double lcb, double pc, double hs)
        : Employee(c, s, a), luongCoBan(lcb), phuCap(pc), heSoThuong(hs) {}

    double tinhLuong() const override {
        return luongCoBan + phuCap + (luongCoBan * heSoThuong);
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "| Loai: Monthly | He so: " << setw(6) << heSoThuong 
             << "| Luong: " << fixed << setprecision(0) << tinhLuong() << " VND" << endl;
    }

    string getType() const override { return "MonthlyEmployee"; }
};

// ==========================================
// 4. CLASS COMPANY (Lớp quản lý - Đóng gói logic)
// ==========================================
class Company {
private:
    vector<Employee*> danhSachNV;

public:
    // Destructor để giải phóng bộ nhớ tự động
    ~Company() {
        for (Employee* nv : danhSachNV) {
            delete nv;
        }
    }

    void themNhanVien(Employee* nv) {
        danhSachNV.push_back(nv);
    }

    void hienThiDanhSach() const {
        cout << "========================== DANH SACH NHAN VIEN ==========================\n";
        for (Employee* nv : danhSachNV) {
            nv->displayInfo();
        }
    }

    // Bài 4: Tính tổng quỹ lương
    double tinhTongQuyLuong() const {
        double tong = 0;
        for (Employee* nv : danhSachNV) {
            tong += nv->tinhLuong();
        }
        return tong;
    }

    // Bài 5: Tìm nhân viên lương max/min
    void hienThiNhanVienMaxMinLuong() const {
        if (danhSachNV.empty()) return;

        Employee* maxNV = danhSachNV[0];
        Employee* minNV = danhSachNV[0];

        for (size_t i = 1; i < danhSachNV.size(); ++i) {
            if (danhSachNV[i]->tinhLuong() > maxNV->tinhLuong()) maxNV = danhSachNV[i];
            if (danhSachNV[i]->tinhLuong() < minNV->tinhLuong()) minNV = danhSachNV[i];
        }

        cout << "\n[Bai 5] Nhan vien luong CAO NHAT:\n"; maxNV->displayInfo();
        cout << "[Bai 5] Nhan vien luong THAP NHAT:\n"; minNV->displayInfo();
    }

    // Bài 6: Đếm số lượng nhân viên theo loại
    void thongKeLoaiNhanVien() const {
        int countHourly = 0, countMonthly = 0;
        for (Employee* nv : danhSachNV) {
            if (nv->getType() == "HourlyEmployee") countHourly++;
            else if (nv->getType() == "MonthlyEmployee") countMonthly++;
        }
        cout << "\n[Bai 6] So luong - Hourly: " << countHourly << " | Monthly: " << countMonthly << "\n";
    }

    // Bài 7: Liệt kê nhân viên có lương > mức lương cho trước
    void lietKeNhanVienLuongLonHon(double mucLuong) const {
        cout << "\n[Bai 7] Danh sach nhan vien co luong > " << mucLuong << " VND:\n";
        bool found = false;
        for (Employee* nv : danhSachNV) {
            if (nv->tinhLuong() > mucLuong) {
                nv->displayInfo();
                found = true;
            }
        }
        if (!found) cout << "-> Khong co nhan vien nao dat muc luong nay.\n";
    }

    // Bài 8: Sắp xếp danh sách giảm dần theo lương
    void sapXepGiamDanTheoLuong() {
        sort(danhSachNV.begin(), danhSachNV.end(), [](Employee* a, Employee* b) {
            return a->tinhLuong() > b->tinhLuong();
        });
        cout << "\n[Bai 8] DA SAP XEP DANH SACH NHAN VIEN THEO LUONG GIAM DAN.\n";
    }
};

// ==========================================
// 5. MAIN FUNCTION (Chỉ đóng vai trò Client)
// ==========================================
int main() {
    Company myCompany;

    // Thêm nhân viên vào công ty thông qua phương thức (Tính Đóng gói)
    myCompany.themNhanVien(new HourlyEmployee("079876543210", "0901002003", "Ha Noi", 160, 50000));
    myCompany.themNhanVien(new HourlyEmployee("079111222333", "0901112233", "Hai Phong", 120, 60000));
    myCompany.themNhanVien(new MonthlyEmployee("079987654321", "0903004005", "Da Nang", 15000000, 2000000, 1.2));
    myCompany.themNhanVien(new MonthlyEmployee("079444555666", "0904445566", "Can Tho", 10000000, 1500000, 1.0));

    // Thực thi các yêu cầu bằng cách gọi phương thức của đối tượng Company
    myCompany.hienThiDanhSach();
    
    cout << "\n[Bai 4] Tong quy luong cua cong ty: " << fixed << setprecision(0) << myCompany.tinhTongQuyLuong() << " VND\n";
    
    myCompany.hienThiNhanVienMaxMinLuong();
    
    myCompany.thongKeLoaiNhanVien();
    
    myCompany.lietKeNhanVienLuongLonHon(10000000);
    
    myCompany.sapXepGiamDanTheoLuong();
    myCompany.hienThiDanhSach();

    return 0; // Khi kết thúc main, myCompany bị hủy -> gọi hàm ~Company() tự động giải phóng vùng nhớ.
}
