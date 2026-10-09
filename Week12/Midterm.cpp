#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==========================================
// CLASS DATE (Phục vụ cho thuộc tính startdate của FishShop)
// ==========================================
class Date {
private:
    int day, month, year;
public:
    Date() {
        day = 1; month = 1; year = 2020;
    }
    Date(int d, int m, int y) {
        day = d; month = m; year = y;
    }
    // Getters
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }

    void displayDate() {
        cout << day << "/" << month << "/" << year;
    }
};

// ==========================================
// CAU 7 (Cũ): Tao class Category (Danh muc ca)
// ==========================================
class Category {
private:
    int categoryId;
    string categoryName;
    string description;

public:
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

    int getCategoryId() { return categoryId; }
    void setCategoryId(int id) { categoryId = id; }

    string getCategoryName() { return categoryName; }
    void setCategoryName(string name) { categoryName = name; }

    string getDescription() { return description; }
    void setDescription(string desc) { description = desc; }

    void displayCategoryInfo() {
        cout << "Category ID: " << categoryId
            << " | Ten: " << categoryName
            << " | Mo ta: " << description << endl;
    }
};

// ==========================================
// CAU 1-4 (Cũ): Class Fish
// ==========================================
class Fish {
private:
    int id;
    string name;
    string color;
    string characteristic;
    int categoryId;

public:
    Fish() {
        id = 0; name = "Chua co"; color = "Chua co";
        characteristic = "Chua co"; categoryId = 0;
    }

    Fish(int id, string name, string color, string characteristic) {
        this->id = id;
        this->name = name;
        this->color = color;
        this->characteristic = characteristic;
        categoryId = 0;
    }

    int getId() { return id; }
    void setId(int id) { this->id = id; }

    string getName() { return name; }
    void setName(string name) { this->name = name; }

    string getColor() { return color; }
    void setColor(string color) { this->color = color; }

    string getCharacteristic() { return characteristic; }
    void setCharacteristic(string characteristic) { this->characteristic = characteristic; }

    int getCategoryId() { return categoryId; }
    void setCategoryId(int id) { this->categoryId = id; }

    void displayFishInfo() {
        cout << "   - ID: " << id << " | Ten: " << name
            << " | Mau: " << color << " | Dac diem: " << characteristic << endl;
    }
};

// ==========================================
// PHAN MOI - QUESTION 1 & 2: Class FishShop
// ==========================================
class FishShop {
private:
    int id;
    string name;
    string address;
    string owner;
    Date startdate;
    vector<Category> categories; // Thay cho Category[] de de quan ly
    vector<Fish> fishes;         // Thay cho Fish[]

public:
    // Constructors
    FishShop() {
        id = 0;
        name = "Chua co";
        address = "Chua co";
        owner = "Chua co";
        startdate = Date();
    }

    FishShop(int id, string name, string address, string owner, Date startdate) {
        this->id = id;
        this->name = name;
        this->address = address;
        this->owner = owner;
        this->startdate = startdate;
    }

    // Getters va Setters
    int getId() { return id; }
    void setId(int id) { this->id = id; }

    string getName() { return name; }
    void setName(string name) { this->name = name; }

    string getAddress() { return address; }
    void setAddress(string address) { this->address = address; }

    string getOwner() { return owner; }
    void setOwner(string owner) { this->owner = owner; }

    Date getStartDate() { return startdate; }
    void setStartDate(Date startdate) { this->startdate = startdate; }

    vector<Category> getCategories() { return categories; }
    vector<Fish> getFishes() { return fishes; }

    // Ham ho tro them danh muc va them ca vao cua hang
    void addCategory(Category cat) {
        categories.push_back(cat);
    }

    void addFish(Fish f) {
        fishes.push_back(f);
    }

    // Display functions
    void displayShopInfo() {
        cout << "\n=============================================" << endl;
        cout << " THONG TIN CUA HANG CA: " << name << endl;
        cout << "=============================================" << endl;
        cout << "ID Cua hang : " << id << endl;
        cout << "Dia chi     : " << address << endl;
        cout << "Chu so huu  : " << owner << endl;
        cout << "Ngay mo cua : "; startdate.displayDate(); cout << endl;

        cout << "\n--- DANH SACH DANH MUC (CATEGORIES) ---" << endl;
        for (int i = 0; i < categories.size(); i++) {
            categories[i].displayCategoryInfo();
        }

        cout << "\n--- DANH SACH CA TRONG CUA HANG (PHAN THEO DANH MUC) ---" << endl;
        for (int i = 0; i < categories.size(); i++) {
            cout << "\n>> Thuoc danh muc: " << categories[i].getCategoryName() << " (ID: " << categories[i].getCategoryId() << ")" << endl;
            int count = 0;
            for (int j = 0; j < fishes.size(); j++) {
                if (fishes[j].getCategoryId() == categories[i].getCategoryId()) {
                    fishes[j].displayFishInfo();
                    count++;
                }
            }
            if (count == 0) cout << "   (Chua co ca nao trong danh muc nay)" << endl;
        }
    }
};

// ==========================================
// PHAN MOI - QUESTION 3: Ham main()
// ==========================================
int main() {
    // 1. Create a fish shop
    Date openDate(10, 10, 2026);
    FishShop myShop(1, "Aqua Sinh Vien", "Thu Duc, TP.HCM", "Nguyen Van A", openDate);

    // 2. Input data: 4 categories
    Category cat1(1, "Ca Nuoc Ngot", "Ca song o song, ho");
    Category cat2(2, "Ca Nuoc Man", "Ca song o bien, dai duong");
    Category cat3(3, "Ca Thuy Sinh", "Ca nho nuoi trong be thuy sinh");
    Category cat4(4, "Ca Phong Thuy", "Ca gia tri cao, mang lai tai loc");

    myShop.addCategory(cat1);
    myShop.addCategory(cat2);
    myShop.addCategory(cat3);
    myShop.addCategory(cat4);

    // 3. Input around 10 fishes for each category (Dung vong lap de sinh du lieu cho nhanh, chuan sinh vien)
    string colors[] = { "Do", "Vang", "Xanh", "Trang", "Den" };
    int fishIdCounter = 100; // Bat dau ID tu 100

    for (int catId = 1; catId <= 4; catId++) {
        for (int j = 1; j <= 10; j++) {
            // Tao ten ca tu dong
            string fishName = "Ca Loai " + to_string(catId) + " - So " + to_string(j);
            string fishColor = colors[j % 5]; // Random mau sac

            Fish newFish(fishIdCounter, fishName, fishColor, "Khoe manh, an tap");
            newFish.setCategoryId(catId); // Gan ID danh muc cho ca

            myShop.addFish(newFish);
            fishIdCounter++;
        }
    }

    // 4. Display information
    myShop.displayShopInfo();

    return 0;
}
