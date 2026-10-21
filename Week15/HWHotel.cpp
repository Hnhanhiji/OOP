#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// ==========================================
// 1. LỚP CƠ SỞ (BASE CLASS): Room
// ==========================================
class Room {
private:
    // Properties cũ
    string roomId;
    double basePrice;
    int maxAdults;
    int maxChildren;
    
    // Properties MỚI thêm vào
    double roomArea;      // Diện tích phòng (m2)
    bool hasBalcony;      // Có ban công hay không
    int floorNumber;      // Tầng số mấy
    string viewType;      // Hướng nhìn (City View, Sea View, v.v.)

public:
    // Constructors
    Room(string id, double price, double area, bool balcony, int floor, string view, int maxA = 2, int maxC = 1)
        : roomId(id), basePrice(price), roomArea(area), hasBalcony(balcony), 
          floorNumber(floor), viewType(view), maxAdults(maxA), maxChildren(maxC) {}

    // Virtual Destructor
    virtual ~Room() = default;

    // Getters
    string getRoomId() const { return roomId; }
    double getBasePrice() const { return basePrice; }
    double getRoomArea() const { return roomArea; }
    bool getHasBalcony() const { return hasBalcony; }
    int getFloorNumber() const { return floorNumber; }
    string getViewType() const { return viewType; }
    int getMaxAdults() const { return maxAdults; }
    int getMaxChildren() const { return maxChildren; }

    // Setters
    void setRoomId(const string& id) { roomId = id; }
    void setBasePrice(double price) { basePrice = price; }
    void setRoomArea(double area) { roomArea = area; }
    void setHasBalcony(bool balcony) { hasBalcony = balcony; }
    void setFloorNumber(int floor) { floorNumber = floor; }
    void setViewType(const string& view) { viewType = view; }

    // Pure Virtual Function (Tính trừu tượng)
    virtual string getRoomType() const = 0;
    
    // Virtual Method
    virtual double calculatePrice() const {
        return basePrice;
    }

    virtual void displayInfo() const {
        cout << "Mã: " << roomId 
             << " | Tầng: " << floorNumber
             << " | Diện tích: " << roomArea << "m2"
             << " | View: " << viewType
             << " | Ban công: " << (hasBalcony ? "Có" : "Không")
             << "\n           => Giá phòng: " << fixed << setprecision(0) << calculatePrice() << " VNĐ";
    }
};

// ==========================================
// 2. LỚP CON 1: StandardRoom
// ==========================================
class StandardRoom : public Room {
public:
    // Standard Room mặc định: 25m2, không ban công, City View
    StandardRoom(string id, int floor) 
        : Room(id, 1000000, 25.0, false, floor, "City View") {}

    string getRoomType() const override { return "Standard Room"; }

    void displayInfo() const override {
        cout << "[Standard] ";
        Room::displayInfo();
    }
};

// ==========================================
// 3. LỚP CON 2: RelaxRoom
// ==========================================
class RelaxRoom : public Room {
private:
    int singleBeds; // 1 giường đơn lớn
    int doubleBeds; // 2 giường đôi

public:
    // Relax Room mặc định: 40m2, có ban công, Garden View
    RelaxRoom(string id, int floor) 
        : Room(id, 1600000, 40.0, true, floor, "Garden View"), singleBeds(1), doubleBeds(2) {}

    string getRoomType() const override { return "Relax Room"; }

    void displayInfo() const override {
        cout << "[Relax]    ";
        Room::displayInfo();
        cout << " | " << singleBeds << " giường đơn, " << doubleBeds << " giường đôi";
    }
};

// ==========================================
// 4. LỚP CON 3: LuxuryRoom
// ==========================================
class LuxuryRoom : public Room {
private:
    bool privateBathroom; // Có phòng tắm riêng tư cao cấp

public:
    // Luxury Room mặc định: 65m2, có ban công rộng, Sea View
    LuxuryRoom(string id, int floor) 
        : Room(id, 2500000, 65.0, true, floor, "Ocean/Sea View"), privateBathroom(true) {}

    string getRoomType() const override { return "Luxury Room"; }

    void displayInfo() const override {
        cout << "[Luxury]   ";
        Room::displayInfo();
        cout << " | VIP: " << (privateBathroom ? "Bồn tắm sục Jacuzzi riêng" : "Thường");
    }
};

// ==========================================
// HÀM MAIN
// ==========================================
int main() {
    int totalAdults = 30;
    int totalChildren = 20;

    cout << "========================================================================================\n";
    cout << "               HỆ THỐNG QUẢN LÝ PHÒNG KHÁCH SẠN MỞ RỘNG (C++ OOP)\n";
    cout << "========================================================================================\n";
    
    vector<Room*> hotelRooms;

    // 1. Tạo 10 phòng Standard (Tầng 1 và 2)
    for (int i = 1; i <= 10; ++i) {
        int floor = (i <= 5) ? 1 : 2; 
        hotelRooms.push_back(new StandardRoom("STD" + to_string(100 + i), floor));
    }

    // 2. Tạo 10 phòng Relax (Tầng 3 và 4)
    for (int i = 1; i <= 10; ++i) {
        int floor = (i <= 5) ? 3 : 4;
        hotelRooms.push_back(new RelaxRoom("RLX" + to_string(300 + i), floor));
    }

    // 3. Tạo 10 phòng Luxury (Tầng 5 và 6 - Tầng cao view biển)
    for (int i = 1; i <= 10; ++i) {
        int floor = (i <= 5) ? 5 : 6;
        hotelRooms.push_back(new LuxuryRoom("LUX" + to_string(500 + i), floor));
    }

    // ================= HIỂN THỊ DANH SÁCH TẤT CẢ 30 PHÒNG =================
    cout << "\nDANH SÁCH CHI TIẾT 30 PHÒNG CỦA KHÁCH SẠN:\n\n";
    
    double totalCost = 0.0;
    for (size_t i = 0; i < hotelRooms.size(); ++i) {
        // Đa hình: Tự động gọi hàm displayInfo() tương ứng của từng class con
        hotelRooms[i]->displayInfo();
        cout << "\n----------------------------------------------------------------------------------------\n";
        totalCost += hotelRooms[i]->calculatePrice();
    }

    // Thống kê
    cout << "\n========================================================================================\n";
    cout << " TỔNG SỐ PHÒNG : " << hotelRooms.size() << " phòng (10 Standard + 10 Relax + 10 Luxury)\n";
    cout << " TỔNG SỨC CHỨA : " << hotelRooms.size() * 2 << " Người lớn & " << hotelRooms.size() * 1 << " Trẻ em\n";
    cout << " TỔNG GIÁ TRỊ CỦA TẤT CẢ PHÒNG TRONG 1 ĐÊM: " << fixed << setprecision(0) << totalCost << " VNĐ\n";
    cout << "========================================================================================\n";

    // Giải phóng bộ nhớ động
    for (auto room : hotelRooms) {
        delete room;
    }
    hotelRooms.clear();

    return 0;
}
