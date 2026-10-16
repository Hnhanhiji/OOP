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
    Employee() : id(""), name("") {}
    Employee(string id, string name) : id(id), name(name) {}
    virtual ~Employee() {}

    string getId() const { return id; }
    string getName() const { return name; }

    void setId(const string& id) { this->id = id; }
    void setName(const string& name) { this->name = name; }

    // Phương thức ảo thuần túy tính lương theo năm
    virtual double calculateSalary(int year) const = 0;

    virtual void display() const {
        cout << "Mã NV: " << id << " | Họ tên: " << name;
    }
};

// ==========================================
// 2. LỚP CON 1: HourlyEmployee (Nhân viên làm theo giờ)
// ==========================================
class HourlyEmployee : public Employee {
private:
    double hours; // Tổng số giờ làm trong năm
    double salaryPerHour;
    int year;

public:
    HourlyEmployee(string id, string name, double hours, double salaryPerHour, int year)
        : Employee(id, name), hours(hours), salaryPerHour(salaryPerHour), year(year) {}

    double getHours() const { return hours; }
    double getSalaryPerHour() const { return salaryPerHour; }
    int getYear() const { return year; }

    void setHours(double hours) { this->hours = hours; }
    void setSalaryPerHour(double salaryPerHour) { this->salaryPerHour = salaryPerHour; }
    void setYear(int year) { this->year = year; }

    double calculateSalary(int y) const override {
        if (this->year == y) {
            return hours * salaryPerHour;
        }
        return 0.0;
    }

    void display() const override {
        Employee::display();
        cout << " | Loại: Theo giờ | Tổng giờ/năm: " << hours 
             << " | Đơn giá/giờ: " << salaryPerHour 
             << " | Năm: " << year;
    }
};

// ==========================================
// 3. LỚP CON 2: MonthlyEmployee (Nhân viên cố định tháng)
// ==========================================
class MonthlyEmployee : public Employee {
private:
    double monthlySalary;
    int year;

public:
    MonthlyEmployee(string id, string name, double monthlySalary, int year)
        : Employee(id, name), monthlySalary(monthlySalary), year(year) {}

    double getMonthlySalary() const { return monthlySalary; }
    int getYear() const { return year; }

    void setMonthlySalary(double monthlySalary) { this->monthlySalary = monthlySalary; }
    void setYear(int year) { this->year = year; }

    double calculateSalary(int y) const override {
        if (this->year == y) {
            return monthlySalary * 12; // Lương tháng nhân 12 để ra lương năm
        }
        return 0.0;
    }

    void display() const override {
        Employee::display();
        cout << " | Loại: Theo tháng | Lương cố định/tháng: " << monthlySalary 
             << " | Năm: " << year;
    }
};

// ==========================================
// 4. LỚP CON 3: DailyEmployee (Nhân viên làm theo ngày)
// ==========================================
class DailyEmployee : public Employee {
private:
    int numberOfDays; // Tổng số ngày làm trong năm
    double salaryPerDay;
    int year;

public:
    DailyEmployee(string id, string name, int numberOfDays, double salaryPerDay, int year)
        : Employee(id, name), numberOfDays(numberOfDays), salaryPerDay(salaryPerDay), year(year) {}

    int getNumberOfDays() const { return numberOfDays; }
    double getSalaryPerDay() const { return salaryPerDay; }
    int getYear() const { return year; }

    void setNumberOfDays(int numberOfDays) { this->numberOfDays = numberOfDays; }
    void setSalaryPerDay(double salaryPerDay) { this->salaryPerDay = salaryPerDay; }
    void setYear(int year) { this->year = year; }

    double calculateSalary(int y) const override {
        if (this->year == y) {
            return numberOfDays * salaryPerDay;
        }
        return 0.0;
    }

    void display() const override {
        Employee::display();
        cout << " | Loại: Theo ngày | Tổng ngày/năm: " << numberOfDays 
             << " | Đơn giá/ngày: " << salaryPerDay 
             << " | Năm: " << year;
    }
};

// ==========================================
// HÀM MAIN: DEMO
// ==========================================
int main() {
    vector<Employee*> listEmployee;

    // Khởi tạo dữ liệu (số giờ/ngày được tính gộp cho cả năm)
    listEmployee.push_back(new HourlyEmployee("NV01", "Nguyen Van A", 1920, 50000, 2026)); // ~160 giờ/tháng * 12
    listEmployee.push_back(new MonthlyEmployee("NV02", "Tran Thi B", 15000000, 2026));
    listEmployee.push_back(new DailyEmployee("NV03", "Le Van C", 264, 400000, 2026)); // ~22 ngày/tháng * 12
    listEmployee.push_back(new HourlyEmployee("NV04", "Pham Van D", 1200, 45000, 2025)); // Khác năm

    int searchYear = 2026;

    cout << "=== DANH SÁCH NHÂN VIÊN VÀ TỔNG LƯƠNG NĂM " << searchYear << " ===" << endl << endl;

    double totalCompanySalary = 0;

    for (const Employee* emp : listEmployee) {
        emp->display();
        cout << endl;

        double salary = emp->calculateSalary(searchYear); 
        cout << "   --> Tổng lương năm " << searchYear << ": " 
             << fixed << setprecision(0) << salary << " VNĐ" << endl << endl;

        totalCompanySalary += salary;
    }

    cout << "==========================================" << endl;
    cout << "TỔNG QUỸ LƯƠNG CÔNG TY PHẢI TRẢ (NĂM " << searchYear << "): " 
         << fixed << setprecision(0) << totalCompanySalary << " VNĐ" << endl;

    for (Employee* emp : listEmployee) {
        delete emp;
    }
    listEmployee.clear();

    return 0;
}

chạy code này ra cho tôi đii
