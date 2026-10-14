#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>  // Thu vien cho Smart Pointers
#include <iomanip> // Thu vien de format output (setw, setprecision)

using namespace std;

// ==========================================
// 1. CLASS EMPLOYEE (Abstract Base Class)
// ==========================================
class Employee {
protected:
    string cccd{};
    string sdt{};
    string address{};

public:
    Employee() = default;
    Employee(string c, string s, string a) : cccd(move(c)), sdt(move(s)), address(move(a)) {}
    
    virtual ~Employee() = default; // Chuan Modern C++ cho destructor ao

    // Ham thuan ao (Pure virtual) -> Bat buoc cac class con phai implement
    [[nodiscard]] virtual double tinhLuong() const = 0;
    
    virtual void displayInfo() const {
        cout << "| CCCD: " << left << setw(15) << cccd 
             << "| SDT: " << setw(12) << sdt 
             << "| Dia chi: " << setw(12) << address;
    }
    
    [[nodiscard]] virtual string getType() const = 0;

    // Getters
    [[nodiscard]] string getCCCD() const { return cccd; }
    [[nodiscard]] string getSDT() const { return sdt; }
    [[nodiscard]] string getAddress() const { return address; }
};

// ==========================================
// 2. CLASS HOURLY EMPLOYEE
// ==========================================
class HourlyEmployee final : public Employee {
private:
    int soGioLamViec{0};
    double donGia{0.0};

public:
    HourlyEmployee() = default;
    HourlyEmployee(string c, string s, string a, int soGio, double donGia)
        : Employee(move(c), move(s), move(a)), soGioLamViec(soGio), donGia(donGia) {}

    [[nodiscard]] double tinhLuong() const override {
        return soGioLamViec * donGia;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "| Loai: Hourly  | Gio lam: " << setw(4) << soGioLamViec 
             << "| Luong: " << fixed << setprecision(0) << tinhLuong() << " VND" << endl;
    }

    [[nodiscard]] string getType() const override { return "HourlyEmployee"; }
};

// ==========================================
// 3. CLASS MONTHLY EMPLOYEE
// ==========================================
class MonthlyEmployee final : public Employee {
private:
    double luongCoBan{0.0};
    double phuCap{0.0};
    double heSoThuong{0.0};

public:
    MonthlyEmployee() = default;
    MonthlyEmployee(string c, string s, string a, double lcb, double pc, double hs)
        : Employee(move(c), move(s), move(a)), luongCoBan(lcb), phuCap(pc), heSoThuong(hs) {}

    [[nodiscard]] double tinhLuong() const override {
        return luongCoBan + phuCap + (luongCoBan * heSoThuong);
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "| Loai: Monthly | He so: " << setw(6) << heSoThuong 
             << "| Luong: " << fixed << setprecision(0) << tinhLuong() << " VND" << endl;
    }

    [[nodiscard]] string getType() const override { return "MonthlyEmployee"; }
};

// ==========================================
// 4. MAIN FUNCTION (Modern C++ Implementation)
// ==========================================
int main() {
    // Dung smart pointer de quan ly bo nho tu dong (Zero memory leaks)
    vector<unique_ptr<Employee>> emps;

    emps.push_back(make_unique<HourlyEmployee>("079876543210", "0901002003", "Ha Noi", 160, 50000));
    emps.push_back(make_unique<HourlyEmployee>("079111222333", "0901112233", "Hai Phong", 120, 60000));
    emps.push_back(make_unique<MonthlyEmployee>("079987654321", "0903004005", "Da Nang", 15000000, 2000000, 1.2));
    emps.push_back(make_unique<MonthlyEmployee>("079444555666", "0904445566", "Can Tho", 10000000, 1500000, 1.0));

    cout << "========================== DANH SACH NHAN VIEN ==========================\n";
    for (const auto& emp : emps) {
        emp->displayInfo();
    }

    // Bai 4: Tinh tong quy luong bang std::accumulate (Hoac for range-based ngan gon)
    double tongQuyLuong = 0;
    for (const auto& emp : emps) tongQuyLuong += emp->tinhLuong();
    cout << "\n[Bai 4] Tong quy luong cua cong ty: " << tongQuyLuong << " VND\n";

    // Bai 5: Tim nhan vien max/min luong cuc nhanh bang std::max_element / std::min_element
    if (!emps.empty()) {
        auto cmpLuong = [](const unique_ptr<Employee>& a, const unique_ptr<Employee>& b) {
            return a->tinhLuong() < b->tinhLuong();
        };
        
        auto maxEmp = max_element(emps.begin(), emps.end(), cmpLuong);
        auto minEmp = min_element(emps.begin(), emps.end(), cmpLuong);

        cout << "\n[Bai 5] Nhan vien luong CAO NHAT:\n"; (*maxEmp)->displayInfo();
        cout << "[Bai 5] Nhan vien luong THAP NHAT:\n"; (*minEmp)->displayInfo();
    }

    // Bai 6: Dem so luong chuyen nghiep bang std::count_if
    int countHourly = count_if(emps.begin(), emps.end(), [](const auto& emp) { return emp->getType() == "HourlyEmployee"; });
    int countMonthly = emps.size() - countHourly;
    
    cout << "\n[Bai 6] So luong - Hourly: " << countHourly << " | Monthly: " << countMonthly << "\n";

    // Bai 7: Loc nhan vien theo nguong luong
    double luongNguong = 10000000; // Hardcode de chay thu thay vi bat nhap (hoac dung cin)
    cout << "\n[Bai 7] Danh sach nhan vien co luong > " << luongNguong << " VND:\n";
    bool found = false;
    for (const auto& emp : emps) {
        if (emp->tinhLuong() > luongNguong) {
            emp->displayInfo();
            found = true;
        }
    }
    if (!found) cout << "-> Khong co nhan vien nao dat muc luong nay.\n";

    // Bai 8: Sap xep giam dan va in bang STL Sort
    cout << "\n[Bai 8] DANH SACH NHAN VIEN SAP XEP LUONG GIAM DAN:\n";
    sort(emps.begin(), emps.end(), [](const unique_ptr<Employee>& a, const unique_ptr<Employee>& b) {
        return a->tinhLuong() > b->tinhLuong();
    });

    for (const auto& emp : emps) {
        emp->displayInfo();
    }

    // KHONG CAN DELETE BẰNG TAY: unique_ptr se tu dong don dep bo nho khi thoat ham main!
    return 0;
}
