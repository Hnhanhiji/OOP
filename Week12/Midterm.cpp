#include <iostream>
#include <string>
#include <vector>
#include <map> // Thư viện dùng để nhóm các loài cá theo màu sắc (Câu 6)

using namespace std;

// ==========================================
// CAU 7: Tao class Category (Danh muc ca)
// ==========================================
class Category {
private:
    int categoryId;
    string categoryName;
    string description;

public:
    // Constructors
    Category() {
        categoryId = 0;
        categoryName = "Chua co";
        description = "Chua co";
    }

    Category(int id, string name, string desc) {
        categoryId = id;
        categoryName = name;
        description = desc;
    }

    // Getters / Setters
    int getCategoryId() { return categoryId; }
    void setCategoryId(int id) { categoryId = id; }

    string getCategoryName() { return categoryName; }
    void setCategoryName(string name) { categoryName = name; }

    string getDescription() { return description; }
    void setDescription(string desc) { description = desc; }

    // Display info
    void displayCategoryInfo() {
        cout << "Category ID: " << categoryId 
             << " | Ten: " << categoryName 
             << " | Mo ta: " << description << endl;
    }
};

// ==========================================
// CAU 1-4: Update class Fish
// ==========================================
class Fish {
private:
    int id;
    string name;
    string color;
    string characteristic;
    int categoryId; // MOI THEM: de biet con ca thuoc danh muc nao (Cau 7)

public:
    // 1. Cac Ham tao (Constructors) - Cap nhat them categoryId = 0 mac dinh
    Fish() {
        id = 0;
        name = "Chua co";
        color = "Chua co";
        characteristic = "Chua co";
        categoryId = 0;
    }

    Fish(int id) {
        this->id = id;
        name = "Chua co";
        color = "Chua co";
        characteristic = "Chua co";
        categoryId = 0;
    }

    Fish(int id, string name) {
        this->id = id;
        this->name = name;
        color = "Chua co";
        characteristic = "Chua co";
        categoryId = 0;
    }

    Fish(int id, string name, string color) {
        this->id = id;
        this->name = name;
        this->color = color;
        characteristic = "Chua co";
        categoryId = 0;
    }

    Fish(int id, string name, string color, string characteristic) {
        this->id = id;
        this->name = name;
        this->color = color;
        this->characteristic = characteristic;
        categoryId = 0;
    }

    // 2. Getter va Setter
    int getId() { return id; }
    void setId(int id) { this->id = id; }

    string getName() { return name; }
    void setName(string name) { this->name = name; }

    string getColor() { return color; }
    void setColor(string color) { this->color = color; }

    string getCharacteristic() { return characteristic; }
    void setCharacteristic(string characteristic) { this->characteristic = characteristic; }

    // MOI THEM: Getter, Setter cho categoryId
    int getCategoryId() { return categoryId; }
    void setCategoryId(int id) { this->categoryId = id; }

    // 3. Ham hien thi thong tin ca
    void displayFishInfo() {
        cout << "----" << endl;
        cout << "ID ca: " << id << " | ID Danh muc: " << categoryId << endl;
        cout << "Ten ca: " << name << endl;
        cout << "Mau sac: " << color << endl;
        cout << "Dac diem: " << characteristic << endl;
    }
};

int main() {
    // ---------------------------------------------------------
    // PHAN BAI CU (Cau 5)
    // ---------------------------------------------------------
    Fish f1;
    Fish f2(101);
    Fish f3(102, "Ca bay mau");
    Fish f4(103, "Ca Betta", "Do");
    Fish f5(104, "Ca Koi", "Cam Trang", "Hien lanh, de nuoi");

    f2.setName("Ca Vang");
    f2.setColor("Vang kim");
    f2.setCharacteristic("Thich boi dan");

    // ---------------------------------------------------------
    // CAU 6: Tao danh sach (list) va them 10 loai ca nua
    // ---------------------------------------------------------
    vector<Fish> fishList;
    
    // Day 5 con ca cu vao list
    fishList.push_back(f1);
    fishList.push_back(f2);
    fishList.push_back(f3);
    fishList.push_back(f4);
    fishList.push_back(f5);

    // Them 10 con ca moi voi cac mau sac de test group
    fishList.push_back(Fish(105, "Ca La Han", "Do", "Dau gu"));
    fishList.push_back(Fish(106, "Ca Dia", "Do", "Dang det"));
    fishList.push_back(Fish(107, "Ca Neon", "Xanh lam", "Boi theo dan, phat sang"));
    fishList.push_back(Fish(108, "Ca Rong", "Vang kim", "Ca phong thuy de vuong"));
    fishList.push_back(Fish(109, "Ca Ba Duoi", "Cam Trang", "De thuong, re"));
    fishList.push_back(Fish(110, "Ca Ngua Van", "Soc trang den", "Boi rat nhanh"));
    fishList.push_back(Fish(111, "Ca Binh Tich", "Den", "De sinh san"));
    fishList.push_back(Fish(112, "Ca Lau Kieng", "Den", "Don be thuy sinh"));
    fishList.push_back(Fish(113, "Ca Than Tien", "Trang", "Dang dep, vay dai"));
    fishList.push_back(Fish(114, "Ca Ali", "Xanh lam", "Co tinh lanh tho cao"));

    // Group and display fish by color (Dung map de nhom cac con ca cung mau vao 1 list)
    cout << "\n=== CAU 6: NHOM VA HIEN THI CA THEO MAU SAC ===" << endl;
    map<string, vector<Fish>> fishGroupedByColor;
    for (int i = 0; i < fishList.size(); i++) {
        string color = fishList[i].getColor();
        fishGroupedByColor[color].push_back(fishList[i]);
    }

    for (auto pair : fishGroupedByColor) {
        cout << "\n>>> NHOM MAU: " << pair.first << " <<<" << endl;
        for (int i = 0; i < pair.second.size(); i++) {
            cout << " - " << pair.second[i].getName() << " (ID: " << pair.second[i].getId() << ")" << endl;
        }
    }

    // ---------------------------------------------------------
    // CAU 7: Tao Categories va gan categoryId cho tung con ca
    // ---------------------------------------------------------
    cout << "\n=== CAU 7: QUAN LY DANH MUC (CATEGORY) ===" << endl;
    
    // Tao it nhat 3 danh muc
    Category cat1(1, "Ca Nuoc Ngot", "Sinh song trong ao, ho, song");
    Category cat2(2, "Ca Thuy Sinh", "Kich thuoc nho, trong be thuy sinh");
    Category cat3(3, "Ca Phong Thuy", "Gia tri cao, mang lai may man");

    // Gan danh muc cho tat ca con ca trong fishList
    for (int i = 0; i < fishList.size(); i++) {
        string name = fishList[i].getName();
        // Phan loai don gian (Logic code sinh vien)
        if (name == "Ca Rong" || name == "Ca La Han") {
            fishList[i].setCategoryId(3); // Ca phong thuy
        } 
        else if (name == "Ca Neon" || name == "Ca Than Tien") {
            fishList[i].setCategoryId(2); // Ca thuy sinh
        } 
        else {
            fishList[i].setCategoryId(1); // Con lai cho vao Nuoc ngot
        }
    }

    // Hien thi danh sach Categories
    cout << "\n--- DANH SACH DANH MUC HIEN CO ---" << endl;
    cat1.displayCategoryInfo();
    cat2.displayCategoryInfo();
    cat3.displayCategoryInfo();

    // Hien thi cac con ca thuoc danh muc duoc chon
    int selectedCatId;
    cout << "\nNhap Category ID muon xem (1, 2, hoac 3): ";
    cin >> selectedCatId;

    cout << "\n--- TAT CA CA THUOC DANH MUC ID " << selectedCatId << " ---" << endl;
    int count = 0;
    for (int i = 0; i < fishList.size(); i++) {
        if (fishList[i].getCategoryId() == selectedCatId) {
            fishList[i].displayFishInfo();
            count++;
        }
    }
    
    if (count == 0) {
        cout << "Khong co con ca nao thuoc danh muc nay!" << endl;
    }

    return 0;
}
