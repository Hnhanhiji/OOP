#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// =========================================================
// 1. LỚP CƠ SỞ TRỪU TƯỢNG (ABSTRACT BASE CLASS)
// =========================================================
class Vehicle {
protected:
    string id;
    string name;
    double rentalPrice;

public:
    Vehicle() : id(""), name(""), rentalPrice(0.0) {}
    Vehicle(string i, string n, double p) : id(i), name(n), rentalPrice(p) {}
    
    // Virtual destructor: Đảm bảo hủy đúng đối tượng lớp con khi dùng con trỏ lớp cha
    virtual ~Vehicle() = default;

    // Getters & Setters
    string getId() const { return id; }
    string getName() const { return name; }
    double getRentalPrice() const { return rentalPrice; }

    void setId(const string& i) { id = i; }
    void setName(const string& n) { name = n; }
    void setRentalPrice(double p) { rentalPrice = p; }

    // --- CÁC PHƯƠNG THỨC ẢO (VIRTUAL METHODS) THỂ HIỆN TÍNH ĐA HÌNH ---
    virtual string getType() const = 0;                     // Hàm thuần ảo phân loại xe
    virtual double calculateRentalFee(int days) const = 0;  // Hàm thuần ảo tính phí thuê
    
    virtual void displayInfo() const {
        cout << "Mã xe: " << id 
             << " | Tên: " << name 
             << " | Giá thuê/ngày: " << fixed << setprecision(0) << rentalPrice << " VND";
    }
};

// =========================================================
// 2. CÁC LỚP DẪN XUẤT (DERIVED CLASSES)
// =========================================================

// --- LỚP CAR ---
class Car : public Vehicle {
private:
    int seats;

public:
    Car() : Vehicle(), seats(0) {}
    Car(string i, string n, double p, int s) : Vehicle(i, n, p), seats(s) {}

    int getSeats() const { return seats; }
    void setSeats(int s) { seats = s; }

    string getType() const override { return "Car"; }

    // Ghi đè phương thức hiển thị
    void displayInfo() const override {
        cout << "[Ô TÔ]   ";
        Vehicle::displayInfo();
        cout << " | Số chỗ ngồi: " << seats;
    }

    // Ghi đè công thức tính tiền cho Ô tô (Giảm 10% từ 7 ngày)
    double calculateRentalFee(int days) const override {
        double fee = days * rentalPrice;
        if (days >= 7) {
            fee *= 0.9;
        }
        return fee;
    }
};

// --- LỚP MOTORBIKE ---
class Motorbike : public Vehicle {
private:
    int engineCC;

public:
    Motorbike() : Vehicle(), engineCC(0) {}
    Motorbike(string i, string n, double p, int cc) : Vehicle(i, n, p), engineCC(cc) {}

    int getEngineCC() const { return engineCC; }
    void setEngineCC(int cc) { engineCC = cc; }

    string getType() const override { return "Motorbike"; }

    // Ghi đè phương thức hiển thị
    void displayInfo() const override {
        cout << "[XE MÁY] ";
        Vehicle::displayInfo();
        cout << " | Dung tích: " << engineCC << " cc";
    }

    // Ghi đè công thức tính tiền cho Xe máy (Giảm 5% từ 5 ngày)
    double calculateRentalFee(int days) const override {
        double fee = days * rentalPrice;
        if (days >= 5) {
            fee *= 0.95;
        }
        return fee;
    }
};

// --- LỚP TRUCK ---
class Truck : public Vehicle {
private:
    double transportFee;

public:
    Truck() : Vehicle(), transportFee(0.0) {}
    Truck(string i, string n, double p, double t) : Vehicle(i, n, p), transportFee(t) {}

    double getTransportFee() const { return transportFee; }
    void setTransportFee(double t) { transportFee = t; }

    string getType() const override { return "Truck"; }

    // Ghi đè phương thức hiển thị
    void displayInfo() const override {
        cout << "[XE TẢI] ";
        Vehicle::displayInfo();
        cout << " | Phí VC cố định: " << fixed << setprecision(0) << transportFee << " VND";
    }

    // Ghi đè công thức tính tiền cho Xe tải (Cộng thêm phí vận chuyển)
    double calculateRentalFee(int days) const override {
        return (days * rentalPrice) + transportFee;
    }
};

// =========================================================
// 3. LỚP QUẢN LÝ (RENTAL MANAGER) - ĐÓNG GÓI XỬ LÝ ĐA HÌNH
// =========================================================
class RentalManager {
private:
    vector<Vehicle*> fleet; // Mảng chứa các con trỏ lớp cha Vehicle*

public:
    // Destructor tự động giải phóng vùng nhớ cho toàn bộ danh sách
    ~RentalManager() {
        for (Vehicle* v : fleet) {
            delete v;
        }
        fleet.clear();
    }

    // Thêm phương thức vào hệ thống
    void addVehicle(Vehicle* v) {
        fleet.push_back(v);
    }

    // MINH HỌA TÍNH ĐA HÌNH RÕ RÀNG NHẤT:
    // Hàm này duyệt qua danh sách Vehicle*, gọi v->displayInfo() và v->calculateRentalFee()
    // Cơ chế Dynamic Binding của C++ sẽ tự tìm đúng hàm của Car, Motorbike hoặc Truck để chạy.
    void processAndShowReport(int days) const {
        cout << "\n==========================================================================" << endl;
        cout << "              BÁO CÁO THUÊ XE HỆ THỐNG (" << days << " NGÀY)" << endl;
        cout << "==========================================================================" << endl << endl;

        double totalRevenue = 0.0;
        double maxFee = -1.0;
        const Vehicle* highestVehicle = nullptr;

        for (const Vehicle* v : fleet) {
            // 1. Gọi hàm hiển thị đa hình
            v->displayInfo();
            cout << endl;

            // 2. Gọi hàm tính tiền đa hình
            double fee = v->calculateRentalFee(days);
            cout << "   ---> Phí thuê (" << days << " ngày): " 
                 << fixed << setprecision(0) << fee << " VND\n\n";

            totalRevenue += fee;

            // 3. Tìm xe có chi phí cao nhất
            if (fee > maxFee) {
                maxFee = fee;
                highestVehicle = v;
            }
        }

        cout << "==========================================================================" << endl;
        cout << " TỔNG DOANH THU HỆ THỐNG : " << fixed << setprecision(0) << totalRevenue << " VND" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        
        if (highestVehicle != nullptr) {
            cout << " PHƯƠNG TIỆN CÓ PHÍ THUÊ CAO NHẤT:" << endl << " ";
            highestVehicle->displayInfo();
            cout << "\n ---> Tổng tiền: " << fixed << setprecision(0) << maxFee << " VND" << endl;
        }
        cout << "==========================================================================" << endl;
    }
};

// =========================================================
// 4. HÀM MAIN
// =========================================================
int main() {
    RentalManager manager;

    // Khởi tạo và thêm các đối tượng con vào lớp quản lý
    manager.addVehicle(new Car("C01", "Toyota", 1000000, 7));
    manager.addVehicle(new Car("C02", "Honda", 800000, 5));
    manager.addVehicle(new Motorbike("M01", "Honda Winner", 150000, 150));
    manager.addVehicle(new Motorbike("M02", "Yamaha Exciter", 120000, 155));
    manager.addVehicle(new Truck("T01", "Hyundai Truck", 2000000, 500000));
    manager.addVehicle(new Truck("T02", "Isuzu Truck", 2500000, 700000));

    int days;
    cout << "Nhap so ngay thue: ";
    cin >> days;

    if (days <= 0) {
        cout << "So ngay thue khong hop le!" << endl;
        return 0;
    }

    // Thực thi xử lý đa hình tập trung trong RentalManager
    manager.processAndShowReport(days);

    return 0;
}
