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
    string id;          // Mã phương tiện
    string brand;       // Hãng sản xuất
    double pricePerDay; // Đơn giá thuê theo ngày

public:
    // Default constructor
    Vehicle() : id(""), brand(""), pricePerDay(0.0) {}

    // Parameterized constructor
    Vehicle(string id, string brand, double pricePerDay)
        : id(id), brand(brand), pricePerDay(pricePerDay) {}

    // Destructor ảo: Giúp giải phóng đúng vùng nhớ lớp con khi dùng con trỏ lớp cha
    virtual ~Vehicle() = default;

    // Getters
    string getId() const { return id; }
    string getBrand() const { return brand; }
    double getPricePerDay() const { return pricePerDay; }

    // Setters
    void setId(const string& id) { this->id = id; }
    void setBrand(const string& brand) { this->brand = brand; }
    void setPricePerDay(double pricePerDay) { this->pricePerDay = pricePerDay; }

    // Hàm ảo thuần túy tính phí thuê (Pure Virtual Function)
    virtual double calculateRentalFee(int days) const = 0;

    // Hàm ảo hiển thị thông tin chung
    virtual void displayInfo() const {
        cout << "Mã xe: " << id 
             << " | Hãng: " << brand 
             << " | Đơn giá/ngày: " << fixed << setprecision(0) << pricePerDay << " VNĐ";
    }
};

// ==========================================
// 2. LỚP CON 1: Car (Ô tô)
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

    // Ghi đè hiển thị thông tin: Gọi lại hàm của lớp cha
    void displayInfo() const override {
        Vehicle::displayInfo(); // Gọi displayInfo() của lớp cha Vehicle
        cout << " | Loại: Ô tô (" << numberOfSeats << " chỗ)";
    }
};

// ==========================================
// 3. LỚP CON 2: Motorbike (Xe máy)
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

    // Ghi đè hiển thị thông tin: Gọi lại hàm của lớp cha
    void displayInfo() const override {
        Vehicle::displayInfo(); // Gọi displayInfo() của lớp cha Vehicle
        cout << " | Loại: Xe máy (" << engineCapacity << " cc)";
    }
};

// ==========================================
// 4. LỚP CON 3: Truck (Xe tải)
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

    // Ghi đè tính phí thuê: số ngày × đơn giá + phí vận chuyển cố định
    double calculateRentalFee(int days) const override {
        return (days * getPricePerDay()) + fixedShippingFee;
    }

    // Ghi đè hiển thị thông tin: Gọi lại hàm của lớp cha
    void displayInfo() const override {
        Vehicle::displayInfo(); // Gọi displayInfo() của lớp cha Vehicle
        cout << " | Loại: Xe tải | Phí VC cố định: " << fixed << setprecision(0) << fixedShippingFee << " VNĐ";
    }
};

// ==========================================
// 5. HÀM MAIN: THỂ HIỆN TÍNH ĐA HÌNH
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

    int rentalDays = 7; // Giả định thuê trong 7 ngày

    cout << "==========================================================================" << endl;
    cout << "          DANH SÁCH PHƯƠNG TIỆN VÀ PHÍ THUÊ DỰ KIẾN (" << rentalDays << " NGÀY)" << endl;
    cout << "==========================================================================" << endl << endl;

    double totalRevenue = 0.0;
    Vehicle* maxFeeVehicle = nullptr;
    double maxFee = -1.0;

    // TÍNH ĐA HÌNH THỂ HIỆN Ở ĐÂY:
    // Duyệt danh sách qua con trỏ lớp cha Vehicle*
    for (const Vehicle* v : vehicles) {
        // 1. Đa hình khi gọi displayInfo(): tự gọi đúng phương thức của lớp con tương ứng
        v->displayInfo();
        cout << endl;

        // 2. Đa hình khi gọi calculateRentalFee(): tự áp dụng công thức riêng của từng loại xe
        double fee = v->calculateRentalFee(rentalDays);
        cout << "   --> Phí thuê (" << rentalDays << " ngày): " 
             << fixed << setprecision(0) << fee << " VNĐ" << endl << endl;

        // 3. Cộng dồn tổng doanh thu
        totalRevenue += fee;

        // 4. Tìm xe có phí thuê cao nhất
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
