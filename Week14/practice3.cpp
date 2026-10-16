#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// ==========================================
// 1. LỚP CƠ SỞ RỘNG NHẤT: MenuItem
// ==========================================
class MenuItem {
protected:
    string name;
    double price;
    int quantity;
    int day, month, year;

public:
    MenuItem(string name, double price, int quantity, int day, int month, int year)
        : name(name), price(price), quantity(quantity), day(day), month(month), year(year) {}

    virtual ~MenuItem() = default;

    // Hàm ảo thuần túy phân loại nhóm sản phẩm (Drinks / Foods)
    virtual string getCategory() const = 0;

    // Phương thức ảo tính doanh thu theo ngày cụ thể
    virtual double calculateDailyRevenue(int d, int m, int y) const {
        if (this->day == d && this->month == m && this->year == y) {
            return price * quantity;
        }
        return 0.0;
    }

    virtual void display() const {
        cout << " - " << name << " | Đơn giá: " << fixed << setprecision(0) << price 
             << " VNĐ | SL: " << quantity 
             << " | Ngày: " << (day < 10 ? "0" : "") << day << "/" 
             << (month < 10 ? "0" : "") << month << "/" << year;
    }
};

// ==========================================
// 2. LỚP CHA 1: Drinks (Đồ uống)
// ==========================================
class Drinks : public MenuItem {
public:
    Drinks(string name, double price, int quantity, int day, int month, int year)
        : MenuItem(name, price, quantity, day, month, year) {}

    string getCategory() const override {
        return "Drinks";
    }
};

// các lớp con của Drinks
class Coffee : public Drinks {
public:
    Coffee(double price, int quantity, int day, int month, int year)
        : Drinks("Coffee", price, quantity, day, month, year) {}
};

class Tea : public Drinks {
public:
    Tea(double price, int quantity, int day, int month, int year)
        : Drinks("Tea", price, quantity, day, month, year) {}
};

class Smoothies : public Drinks {
public:
    Smoothies(double price, int quantity, int day, int month, int year)
        : Drinks("Smoothies", price, quantity, day, month, year) {}
};

class Juices : public Drinks {
public:
    Juices(double price, int quantity, int day, int month, int year)
        : Drinks("Juices", price, quantity, day, month, year) {}
};

// ==========================================
// 3. LỚP CHA 2: Foods (Thức ăn)
// ==========================================
class Foods : public MenuItem {
public:
    Foods(string name, double price, int quantity, int day, int month, int year)
        : MenuItem(name, price, quantity, day, month, year) {}

    string getCategory() const override {
        return "Foods";
    }
};

// Các lớp con của Foods
class Cake : public Foods {
public:
    Cake(double price, int quantity, int day, int month, int year)
        : Foods("Cake", price, quantity, day, month, year) {}
};

class Breads : public Foods {
public:
    Breads(double price, int quantity, int day, int month, int year)
        : Foods("Breads", price, quantity, day, month, year) {}
};

// ==========================================
// HÀM TÍNH TỔNG DOANH THU THEO NGÀY (ĐA HÌNH)
// ==========================================
void calculateTotalRevenueByDate(const vector<MenuItem*>& items, int day, int month, int year) {
    double totalDrinks = 0.0;
    double totalFoods = 0.0;

    // Duyệt danh sách qua con trỏ lớp cha MenuItem* (Thủ thuật Đa hình)
    for (const MenuItem* item : items) {
        double revenue = item->calculateDailyRevenue(day, month, year);
        
        if (item->getCategory() == "Drinks") {
            totalDrinks += revenue;
        } else if (item->getCategory() == "Foods") {
            totalFoods += revenue;
        }
    }

    cout << "==========================================" << endl;
    cout << " BÁO CÁO DOANH THU NGÀY " 
         << (day < 10 ? "0" : "") << day << "/" 
         << (month < 10 ? "0" : "") << month << "/" << year << endl;
    cout << "==========================================" << endl;
    cout << " - Drinks : " << fixed << setprecision(0) << totalDrinks << " VNĐ" << endl;
    cout << " - Foods  : " << fixed << setprecision(0) << totalFoods << " VNĐ" << endl;
    cout << "------------------------------------------" << endl;
    cout << " TỔNG CỘNG: " << fixed << setprecision(0) << (totalDrinks + totalFoods) << " VNĐ" << endl;
}

// ==========================================
// HÀM MAIN DEMO
// ==========================================
int main() {
    // Quản lý tập hợp tất cả món ăn/nước uống bằng mảng con trỏ MenuItem*
    vector<MenuItem*> menuList;

    // Nhóm Đồ uống (Drinks) bán trong ngày 15/10/2026
    menuList.push_back(new Coffee(30000, 15, 15, 10, 2026));    // 15 ly * 30,000 = 450,000
    menuList.push_back(new Tea(25000, 20, 15, 10, 2026));       // 20 ly * 25,000 = 500,000
    menuList.push_back(new Smoothies(40000, 10, 15, 10, 2026)); // 10 ly * 40,000 = 400,000
    menuList.push_back(new Juices(35000, 12, 15, 10, 2026));    // 12 ly * 35,000 = 420,000

    // Nhóm Thức ăn (Foods) bán trong ngày 15/10/2026
    menuList.push_back(new Cake(45000, 8, 15, 10, 2026));       // 8 cái * 45,000 = 360,000
    menuList.push_back(new Breads(20000, 25, 15, 10, 2026));     // 25 cái * 20,000 = 500,000

    // Đơn hàng ngày khác (để kiểm tra bộ lọc ngày)
    menuList.push_back(new Coffee(30000, 10, 16, 10, 2026));

    // Display danh sách các món đã nhập
    cout << "=== CHI TIẾT CÁC GIAO DỊCH ===" << endl;
    for (const MenuItem* item : menuList) {
        item->display();
        cout << endl;
    }
    cout << endl;

    // Tính toán doanh thu cho ngày 15/10/2026
    calculateTotalRevenueByDate(menuList, 15, 10, 2026);

    // Giải phóng bộ nhớ con trỏ
    for (MenuItem* item : menuList) {
        delete item;
    }
    menuList.clear();

    return 0;
}
