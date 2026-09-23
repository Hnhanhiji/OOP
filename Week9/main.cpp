#include <iostream>//
#include <string>
#include <iomanip>//

using namespace std;

/// Cấu trúc dữ liệu theo yêu cầu
struct Food {//
    string id;       // mã món
    string name;     // tên món
    double price;    // đơn giá
    int quantity;    // số lượng còn lại
};

struct Order {
    string id;             // mã đơn hàng
    string customerName;   // tên khách hàng
    string address;        // địa chỉ giao hàng
    Food food;             // món ăn được đặt
    int quantity;          // số lượng
    string status;         // trạng thái (Ví dụ: "Dang xu ly", "Hoan thanh")
};

struct Restaurant {//
    string name;           // tên cửa hàng
    string address;        // địa chỉ
    string phone;          // số điện thoại
    Food foods[100];       // danh sách món ăn
    int foodCount = 0;
    Order orders[100];     // danh sách đơn hàng
    int orderCount = 0;
};

// 1. Nhập thông tin cửa hàng[cite: 1]
void inputRestaurantInfo(Restaurant &r) {
    cout << "\n--- NHAP THONG TIN CUA HANG ---\n";
    cout << "Ten cua hang: ";
    getline(cin, r.name);
    cout << "Dia chi: ";
    getline(cin, r.address);
    cout << "So dien thoai: ";
    getline(cin, r.phone);
    cout << "Cap nhat thong tin cua hang thanh cong!\n";
}

// 2. Thêm món ăn mới[cite: 1]
void addFood(Restaurant &r) {
    if (r.foodCount >= 100) {
        cout << "Danh sach mon an da day!\n";
        return;
    }
    Food newFood;
    cout << "\n--- THEM MON AN MOI ---\n";
    cout << "Ma mon: ";
    getline(cin, newFood.id);//
    cout << "Ten mon: ";
    getline(cin, newFood.name);
    cout << "Don gia: ";
    cin >> newFood.price;
    cout << "So luong: ";
    cin >> newFood.quantity;
    cin.ignore(); // Xóa bộ đệm

    r.foods[r.foodCount] = newFood;
    r.foodCount++;
    cout << "Da them mon an thanh cong!\n";
}

// 3. Hiển thị danh sách món ăn[cite: 1]//
void displayFoods(const Restaurant &r) {
    cout << "\n--- DANH SACH MON AN ---\n";
    cout << left << setw(10) << "Ma mon" 
         << setw(25) << "Ten mon" 
         << setw(15) << "Don gia" 
         << "So luong" << endl;
    for (int i = 0; i < r.foodCount; i++) {
        cout << left << setw(10) << r.foods[i].id 
             << setw(25) << r.foods[i].name 
             << setw(15) << r.foods[i].price 
             << r.foods[i].quantity << endl;
    }
}

// 4. Tìm món ăn theo mã hoặc tên[cite: 1]
void searchFood(const Restaurant &r) {
    string keyword;
    cout << "\nNhap ma hoac ten mon can tim: ";
    getline(cin, keyword);
    
    bool found = false;
    cout << left << setw(10) << "Ma mon" << setw(25) << "Ten mon" << setw(15) << "Don gia" << "So luong" << endl;
    for (int i = 0; i < r.foodCount; i++) {
        if (r.foods[i].id == keyword || r.foods[i].name.find(keyword) != string::npos) {
            cout << left << setw(10) << r.foods[i].id 
                 << setw(25) << r.foods[i].name 
                 << setw(15) << r.foods[i].price 
                 << r.foods[i].quantity << endl;
            found = true;
        }
    }
    if (!found) cout << "Khong tim thay mon an phu hop.\n";//
}

// 5. Cập nhật giá hoặc số lượng món ăn[cite: 1]
void updateFood(Restaurant &r) {
    string id;
    cout << "\nNhap ma mon can cap nhat: "; //
    getline(cin, id);
    
    for (int i = 0; i < r.foodCount; i++) {
        if (r.foods[i].id == id) {
            cout << "1. Cap nhat gia\n2. Cap nhat so luong\nChon (1/2): ";
            int choice;
            cin >> choice;
            if (choice == 1) {
                cout << "Nhap gia moi: ";
                cin >> r.foods[i].price;
            } else if (choice == 2) {
                cout << "Nhap so luong moi: ";
                cin >> r.foods[i].quantity;
            }
            cin.ignore();
            cout << "Cap nhat thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay ma mon an.\n";
}

// 7. Kiểm tra món ăn có tồn tại và đủ số lượng[cite: 1]
// Trả về vị trí (index) của món ăn nếu hợp lệ, ngược lại trả về -1
int checkFoodAvailability(const Restaurant &r, string foodId, int reqQuantity) {
    for (int i = 0; i < r.foodCount; i++) {
        if (r.foods[i].id == foodId) {
            if (r.foods[i].quantity >= reqQuantity) {
                return i;
            } else {
                cout << "Loi: So luong mon an trong kho khong du!\n";
                return -1;
            }
        }
    }
    cout << "Loi: Khong tim thay mon an nay!\n";
    return -1;
}

// 8. Tính tổng tiền của đơn hàng[cite: 1]
double calculateOrderTotal(const Order &o) {
    return o.food.price * o.quantity;
}

// 6. Tạo đơn hàng mới[cite: 1]
void createOrder(Restaurant &r) {
    if (r.orderCount >= 100) {
        cout << "Danh sach don hang da day!\n";
        return;
    }
    
    Order newOrder;
    cout << "\n--- TAO DON HANG MOI ---\n";
    cout << "Ma don hang: ";
    getline(cin, newOrder.id);
    cout << "Ten khach hang: ";
    getline(cin, newOrder.customerName);
    cout << "Dia chi giao hang: ";
    getline(cin, newOrder.address);
    
    string foodId;
    cout << "Nhap ma mon an muon dat: ";
    getline(cin, foodId);
    cout << "Nhap so luong: ";
    cin >> newOrder.quantity;
    cin.ignore();

    // Gọi chức năng 7 để kiểm tra[cite: 1]
    int foodIndex = checkFoodAvailability(r, foodId, newOrder.quantity);
    
    if (foodIndex != -1) {
        newOrder.food = r.foods[foodIndex];
        newOrder.status = "Dang xu ly";
        
        // Trừ đi số lượng trong kho
        r.foods[foodIndex].quantity -= newOrder.quantity;
        
        r.orders[r.orderCount] = newOrder;
        r.orderCount++;
        
        cout << "Tao don hang thanh cong! Tong tien can thanh toan: " 
             << fixed << setprecision(0) << calculateOrderTotal(newOrder) << " VND\n"; // Gọi chức năng 8[cite: 1]
    }
}

// 9. Hiển thị danh sách các đơn hàng[cite: 1]
void displayOrders(const Restaurant &r) {
    cout << "\n--- DANH SACH DON HANG ---\n";
    cout << left << setw(10) << "Ma DH" 
         << setw(20) << "Khach hang" 
         << setw(20) << "Ten mon" 
         << setw(10) << "So luong" 
         << setw(15) << "Trang thai" << endl;
    for (int i = 0; i < r.orderCount; i++) {
        cout << left << setw(10) << r.orders[i].id 
             << setw(20) << r.orders[i].customerName 
             << setw(20) << r.orders[i].food.name 
             << setw(10) << r.orders[i].quantity 
             << setw(15) << r.orders[i].status << endl;
    }
}

// 10. Tìm đơn hàng theo mã[cite: 1]
void searchOrder(const Restaurant &r) {
    string id;
    cout << "\nNhap ma don hang can tim: ";
    getline(cin, id);
    
    for (int i = 0; i < r.orderCount; i++) {
        if (r.orders[i].id == id) {
            cout << "Thong tin don hang:\n";
            cout << "- Khach hang: " << r.orders[i].customerName << "\n";
            cout << "- Dia chi: " << r.orders[i].address << "\n";
            cout << "- Mon an: " << r.orders[i].food.name << " (SL: " << r.orders[i].quantity << ")\n";
            cout << "- Tong tien: " << calculateOrderTotal(r.orders[i]) << " VND\n";
            cout << "- Trang thai: " << r.orders[i].status << "\n";
            return;
        }
    }
    cout << "Khong tim thay don hang.\n";
}

// 11. Cập nhật trạng thái đơn hàng[cite: 1]
void updateOrderStatus(Restaurant &r) {
    string id;
    cout << "\nNhap ma don hang can cap nhat: ";
    getline(cin, id);
    
    for (int i = 0; i < r.orderCount; i++) {
        if (r.orders[i].id == id) {
            cout << "Trang thai hien tai: " << r.orders[i].status << "\n";
            cout << "Nhap trang thai moi (VD: Dang giao, Hoan thanh): ";
            getline(cin, r.orders[i].status);
            cout << "Cap nhat trang thai thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay don hang.\n";
}

// 12. Thống kê tổng doanh thu của các đơn đã hoàn thành[cite: 1]
void calculateRevenue(const Restaurant &r) {
    double totalRevenue = 0;
    for (int i = 0; i < r.orderCount; i++) {
        if (r.orders[i].status == "Hoan thanh") {
            totalRevenue += calculateOrderTotal(r.orders[i]);
        }
    }
    cout << "\n=== THONG KE DOANH THU ===\n";
    cout << "Tong doanh thu tu cac don hang [Hoan thanh]: " 
         << fixed << setprecision(0) << totalRevenue << " VND\n";
}

// Hàm Main thiết kế Menu điều khiển
int main() {
    Restaurant myRestaurant;
    int choice;

    do {
        cout << "\n========== QUAN LY CUA HANG GIAO DO AN ==========\n";
        cout << "1. Nhap thong tin cua hang\n";
        cout << "2. Them mon an moi\n";
        cout << "3. Hien thi danh sach mon an\n";
        cout << "4. Tim mon an theo ma hoac ten\n";
        cout << "5. Cap nhat gia hoac so luong mon an\n";
        cout << "6. Tao don hang moi (Bao gom kiem tra & tinh tien)\n";
        cout << "7. Hien thi danh sach cac don hang\n";
        cout << "8. Tim don hang theo ma\n";
        cout << "9. Cap nhat trang thai don hang\n";
        cout << "10. Thong ke tong doanh thu\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "=================================================\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: inputRestaurantInfo(myRestaurant); break;
            case 2: addFood(myRestaurant); break;
            case 3: displayFoods(myRestaurant); break;
            case 4: searchFood(myRestaurant); break;
            case 5: updateFood(myRestaurant); break;
            case 6: createOrder(myRestaurant); break;
            case 7: displayOrders(myRestaurant); break;
            case 8: searchOrder(myRestaurant); break;
            case 9: updateOrderStatus(myRestaurant); break;
            case 10: calculateRevenue(myRestaurant); break;
            case 0: cout << "Dang thoat chuong trinh...\n"; break;
            default: cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);

    return 0;
}
