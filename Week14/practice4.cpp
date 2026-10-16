#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// ==========================================
// 1. LỚP CƠ SỞ (BASE CLASS): Vehicle
// ==========================================
class Vehicle {
private:
    string id;
    string brand;
    double pricePerDay;

public:
    // Default constructor
    Vehicle() : id(""), brand(""), pricePerDay(0.0) {}

    // Parameterized constructor
    Vehicle(string id, string brand, double pricePerDay)
        : id(id), brand(brand), pricePerDay(pricePerDay) {}

    // Virtual destructor - Đảm bảo giải phóng bộ nhớ đúng cho lớp con
    virtual ~Vehicle() = default;

    // Getters
    string getId() const { return id; }
    string getBrand() const { return brand; }
    double getPricePerDay() const { return pricePerDay; }

    // Setters
    void setId(const string& id) { this->id = id; }
    void setBrand(const string& brand) { this->brand = brand; }
    void setPricePerDay(double pricePerDay) { this->pricePerDay = pricePerDay; }

    // Phương thức ảo thuần túy tính phí thuê
    virtual double calculateRentalFee(int days) const = 0;

    // Phương thức ảo hiển thị thông tin chung
    virtual void displayInfo() const {
        cout << "Mã xe: " << id 
             << " | Hãng: " << brand 
             << " | Giá thuê/ngày: " << fixed << setprecision(0) << pricePerDay << " VNĐ";
    }
};

// ==========================================
// 2. LỚP CON: Car (Ô tô)
// ==========================================
class Car : public Vehicle {
private:
    int numberOfSeats; // Số chỗ ngồi

public:
    // Default constructor
    Car() : Vehicle(), numberOfSeats(4) {}

    // Parameterized constructor
    Car(string id, string brand, double pricePerDay, int numberOfSeats)
        : Vehicle(id, brand, pricePerDay), numberOfSeats(numberOfSeats) {}

    // Getter & Setter
    int getNumberOfSeats() const { return numberOfSeats; }
    void setNumberOfSeats(int numberOfSeats) { this->numberOfSeats = numberOfSeats; }

    // Ghi đè tính phí thuê: Giảm 10% nếu thuê từ 7 ngày trở lên
    double calculateRentalFee(int days) const override {
        double fee = days * getPricePerDay();
        if (days >= 7) {
            fee *= 0.90; // Giảm 10%
        }
        return fee;
    }

    // Ghi đè hiển thị thông tin
    void displayInfo() const override {
        Vehicle::displayInfo(); // Gọi hàm của lớp cha
        cout << " | Loại: Ô tô (" << numberOfSeats << " chỗ)";
    }
};

// ==========================================
// 3. LỚP CON: Motorbike (Xe máy)
// ==========================================
class Motorbike : public Vehicle {
private:
    int engineCapacity; // Dung tích xi lanh (cc)

public:
    // Default constructor
    Motorbike() : Vehicle(), engineCapacity(110) {}

    // Parameterized constructor
    Motorbike(string id, string brand, double pricePerDay, int engineCapacity)
        : Vehicle(id, brand, pricePerDay), engineCapacity(engineCapacity) {}

    // Getter & Setter
    int getEngineCapacity() const { return engineCapacity; }
    void setEngineCapacity(int engineCapacity) { this->engineCapacity = engineCapacity; }

    // Ghi đè tính phí thuê: Giảm 5% nếu thuê từ 5 ngày trở lên
    double calculateRentalFee(int days) const override {
        double fee = days * getPricePerDay();
        if (days >= 5) {
            fee *= 0.95; // Giảm 5%
        }
        return fee;
    }

    // Ghi đè hiển thị thông tin
    void displayInfo() const override {
        Vehicle::displayInfo(); // Gọi hàm của lớp cha
        cout << " | Loại: Xe máy (" << engineCapacity << " cc)";
    }
};

// ==========================================
// 4. LỚP CON: Truck (Xe tải)
// ==========================================
class Truck : public Vehicle {
private:
    double fixedShippingFee; // Phí vận chuyển cố định

public:
    // Default constructor
    Truck() : Vehicle(), fixedShippingFee(0.0) {}

    // Parameterized constructor
    Truck(string id, string brand, double pricePerDay, double fixedShippingFee)
        : Vehicle(id, brand, pricePerDay), fixedShippingFee(fixedShippingFee) {}

    // Getter & Setter
    double getFixedShippingFee() const { return fixedShippingFee; }
    void setFixedShippingFee(double fixedShippingFee) { this->fixedShippingFee = fixedShippingFee; }

    // Ghi đè tính phí thuê: Số ngày * đơn giá + Phí vận chuyển cố định
    double calculateRentalFee(int days) const override {
        return (days * getPricePerDay()) + fixedShippingFee;
    }

    // Ghi đè hiển thị thông tin
    void displayInfo() const override {
        Vehicle::displayInfo(); // Gọi hàm của lớp cha
        cout << " | Loại: Xe tải | Phí VC cố định: " << fixed << setprecision(0) << fixedShippingFee << " VNĐ";
    }
};

// ==========================================
// 5. HÀM MAIN
// ==========================================
int main() {
    // Tạo danh sách phương tiện bằng vector<Vehicle*>
    vector<Vehicle*> vehicles;

    // Khởi tạo các đối tượng xe
    vehicles.push_back(new Car("C01", "Toyota", 800000, 5));
    vehicles.push_back(new Car("C02", "Hyundai", 1200000, 7));
    vehicles.push_back(new Motorbike("M01", "Honda", 150000, 125));
    vehicles.push_back(new Motorbike("M02", "Yamaha", 200000, 150));
    vehicles.push_back(new Truck("T01", "Isuzu", 1500000, 500000));

    int rentalDays = 7; // Số ngày thuê thử nghiệm

    cout << "==========================================================================" << endl;
    cout << "                  DANH SÁCH PHƯƠNG TIỆN VÀ CHI PHÍ THUÊ (" << rentalDays << " NGÀY)" << endl;
    cout << "==========================================================================" << endl << endl;

    double totalRevenue = 0.0;
    Vehicle* maxFeeVehicle = nullptr;
    double maxFee = -1.0;

    // Duyệt qua danh sách bằng tính đa hình
    for (const Vehicle* v : vehicles) {
        // 1. Hiển thị thông tin phương tiện (gọi displayInfo của lớp con tương ứng)
        v->displayInfo();
        cout << endl;

        // 2. Tính phí thuê cho xe hiện tại
        double fee = v->calculateRentalFee(rentalDays);
        cout << "   --> Phí thuê (" << rentalDays << " ngày): " 
             << fixed << setprecision(0) << fee << " VNĐ" << endl << endl;

        // 3. Cộng dồn doanh thu
        totalRevenue += fee;

        // 4. Tìm phương tiện có phí thuê cao nhất
        if (fee > maxFee) {
            maxFee = fee;
            maxFeeVehicle = const_cast<Vehicle*>(v);
        }
    }

    cout << "==========================================================================" << endl;
    cout << " TỔNG DOANH THU THUÊ XE: " << fixed << setprecision(0) << totalRevenue << " VNĐ" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    
    if (maxFeeVehicle != nullptr) {
        cout << " PHƯƠNG TIỆN CÓ PHÍ THUÊ CAO NHẤT:" << endl << " ";
        maxFeeVehicle->displayInfo();
        cout << "\n --> Phí thuê: " << fixed << setprecision(0) << maxFee << " VNĐ" << endl;
    }
    cout << "==========================================================================" << endl;

    // Giải phóng bộ nhớ động
    for (Vehicle* v : vehicles) {
        delete v;
    }
    vehicles.clear();

    return 0;
}
