#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// ==========================================
// 1. LỚP CƠ SỞ (BASE CLASS): Employee
// ==========================================
class Employee {
private:
    string id;
    string name;

public:
    // Constructors
    Employee() : id(""), name("") {}
    Employee(string id, string name) : id(id), name(name) {}

    // Destructor ảo (Virtual Destructor) - Rất quan trọng khi giải phóng bộ nhớ qua con trỏ lớp cha
    virtual ~Employee() {}

    // Getters
    string getId() const { return id; }
    string getName() const { return name; }

    // Setters
    void setId(const string& id) { this->id = id; }
    void setName(const string& name) { this->name = name; }

    //  (Pure Virtual Function) - Bắt buộc các lớp con phải override
    virtual double calculateSalary(int month, int year) const = 0;

    // Phương thức ảo hiển thị thông tin chung
    virtual void display() const {
        cout << "Mã NV: " << id << " | Họ tên: " << name;
    }
};

// ==========================================
// 2. LỚP CON 1: HourlyEmployee (Nhân viên làm theo giờ)
// ==========================================
class HourlyEmployee : public Employee {
private:
    double hours;
    double salaryPerHour;
    int month;
    int year;

public:
    // Constructor
    HourlyEmployee(string id, string name, double hours, double salaryPerHour, int month, int year)
        : Employee(id, name), hours(hours), salaryPerHour(salaryPerHour), month(month), year(year) {}

    // Getters
    double getHours() const { return hours; }
    double getSalaryPerHour() const { return salaryPerHour; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Setters
    void setHours(double hours) { this->hours = hours; }
    void setSalaryPerHour(double salaryPerHour) { this->salaryPerHour = salaryPerHour; }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; }

    // Ghi đè phương thức tính lương
    double calculateSalary(int m, int y) const override {
        if (this->month == m && this->year == y) {
            return hours * salaryPerHour;
        }
        return 0.0; // Nếu không phải tháng/năm cần tính
    }

    // Ghi đè phương thức hiển thị
    void display() const override {
        Employee::display(); // Gọi lại phần hiển thị của lớp cha
        cout << " | Loại: Theo giờ | Số giờ: " << hours 
             << " | Đơn giá/giờ: " << salaryPerHour 
             << " | Tháng/Năm: " << month << "/" << year;
    }
};

// ==========================================
// 3. LỚP CON 2: MonthlyEmployee (Nhân viên cố định tháng)
// ==========================================
class MonthlyEmployee : public Employee {
private:
    double monthlySalary;
    int month;
    int year;

public:
    // Constructor
    MonthlyEmployee(string id, string name, double monthlySalary, int month, int year)
        : Employee(id, name), monthlySalary(monthlySalary), month(month), year(year) {}

    // Getters
    double getMonthlySalary() const { return monthlySalary; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Setters
    void setMonthlySalary(double monthlySalary) { this->monthlySalary = monthlySalary; }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; }

    // Ghi đè phương thức tính lương
    double calculateSalary(int m, int y) const override {
        if (this->month == m && this->year == y) {
            return monthlySalary;
        }
        return 0.0;
    }

    // Ghi đè phương thức hiển thị
    void display() const override {
        Employee::display();
        cout << " | Loại: Theo tháng | Lương cố định: " << monthlySalary 
             << " | Tháng/Năm: " << month << "/" << year;
    }
};

// ==========================================
// 4. LỚP CON 3: DailyEmployee (Nhân viên làm theo ngày)
// ==========================================
class DailyEmployee : public Employee {
private:
    int numberOfDays;
    double salaryPerDay;
    int month;
    int year;

public:
    // Constructor
    DailyEmployee(string id, string name, int numberOfDays, double salaryPerDay, int month, int year)
        : Employee(id, name), numberOfDays(numberOfDays), salaryPerDay(salaryPerDay), month(month), year(year) {}

    // Getters
    int getNumberOfDays() const { return numberOfDays; }
    double getSalaryPerDay() const { return salaryPerDay; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Setters
    void setNumberOfDays(int numberOfDays) { this->numberOfDays = numberOfDays; }
    void setSalaryPerDay(double salaryPerDay) { this->salaryPerDay = salaryPerDay; }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; }

    // Ghi đè phương thức tính lương
    double calculateSalary(int m, int y) const override {
        if (this->month == m && this->year == y) {
            return numberOfDays * salaryPerDay;
        }
        return 0.0;
    }

    // Ghi đè phương thức hiển thị
    void display() const override {
        Employee::display();
        cout << " | Loại: Theo ngày | Số ngày làm: " << numberOfDays 
             << " | Đơn giá/ngày: " << salaryPerDay 
             << " | Tháng/Năm: " << month << "/" << year;
    }
};


// HÀM MAIN: DEMO TÍNH ĐA HÌNH (POLYMORPHISM)
// ==========================================
int main() {
    // Sử dụng vector chứa các con trỏ lớp cha Employee*
    vector<Employee*> listEmployee;

    // Khởi tạo các đối tượng thuộc các lớp con khác nhau
    listEmployee.push_back(new HourlyEmployee("NV01", "Nguyen Van A", 160, 50000, 10, 2026));
    listEmployee.push_back(new MonthlyEmployee("NV02", "Tran Thi B", 15000000, 10, 2026));
    listEmployee.push_back(new DailyEmployee("NV03", "Le Van C", 22, 400000, 10, 2026));
    listEmployee.push_back(new HourlyEmployee("NV04", "Pham Van D", 120, 45000, 9, 2026)); // Khác tháng

    int searchMonth = 10;
    int searchYear = 2026;

    cout << "=== DANH SÁCH NHÂN VIÊN VÀ LƯƠNG THÁNG " << searchMonth << "/" << searchYear << " ===" << endl << endl;

    double totalCompanySalary = 0;

    // THỂ HIỆN TÍNH ĐA HÌNH Ở ĐÂY:
    // Cùng một danh sách con trỏ Employee*, chỉ cần gọi emp->display() và emp->calculateSalary()
    for (const Employee* emp : listEmployee) {
        emp->display(); // C++ tự động thực thi đúng hàm display() của từng lớp con
        cout << endl;

        double salary = emp->calculateSalary(searchMonth, searchYear); // Tự động gọi đúng công thức riêng
        cout << "   --> Lương tháng " << searchMonth << "/" << searchYear << ": " 
             << fixed << setprecision(0) << salary << " VNĐ" << endl << endl;

        totalCompanySalary += salary;
    }

    cout << "==========================================" << endl;
    cout << "TỔNG LƯƠNG CÔNG TY PHẢI TRẢ (THÁNG " << searchMonth << "/" << searchYear << "): " 
         << fixed << setprecision(0) << totalCompanySalary << " VNĐ" << endl;

    // Giải phóng bộ nhớ động
    for (Employee* emp : listEmployee) {
        delete emp; // Virtual destructor ~Employee() đảm bảo giải phóng đúng đối tượng lớp con
    }
    listEmployee.clear();

    return 0;
}
chạy code này ra cho tôi đi 
