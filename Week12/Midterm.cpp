#include <iostream>
#include <string>

using namespace std;

class Fish {
private:
    int id;
    string name;
    string color;
    string characteristic;

public:
    // 1. Cac Ham tao (Constructors)

    // Ham tao mac dinh (khong tham so)
    Fish() {
        id = 0;
        name = "Chua co";
        color = "Chua co";
        characteristic = "Chua co";
    }

    // Ham tao 1 tham so
    Fish(int id) {
        this->id = id;
        name = "Chua co";
        color = "Chua co";
        characteristic = "Chua co";
    }

    // Ham tao 2 tham so
    Fish(int id, string name) {
        this->id = id;
        this->name = name;
        color = "Chua co";
        characteristic = "Chua co";
    }

    // Ham tao 3 tham so
    Fish(int id, string name, string color) {
        this->id = id;
        this->name = name;
        this->color = color;
        characteristic = "Chua co";
    }

    // Ham tao du 4 tham so
    Fish(int id, string name, string color, string characteristic) {
        this->id = id;
        this->name = name;
        this->color = color;
        this->characteristic = characteristic;
    }

    // 2. Getter va Setter
    int getId() {
        return id;
    }
    void setId(int id) {
        this->id = id;
    }

    string getName() {
        return name;
    }
    void setName(string name) {
        this->name = name;
    }

    string getColor() {
        return color;
    }
    void setColor(string color) {
        this->color = color;
    }

    string getCharacteristic() {
        return characteristic;
    }
    void setCharacteristic(string characteristic) {
        this->characteristic = characteristic;
    }

    // 3. Ham hien thi thong tin ca
    void displayFishInfo() {
        cout << "----" << endl;
        cout << "ID: " << id << endl;
        cout << "Ten ca: " << name << endl;
        cout << "Mau sac: " << color << endl;
        cout << "Dac diem: " << characteristic << endl;
    }
};

int main() {
    // Cau 5.1: Tao 5 doi tuong ca bang 5 constructor khac nhau
    Fish f1;
    Fish f2(101);
    Fish f3(102, "Ca bay mau");
    Fish f4(103, "Ca Betta", "Do");
    Fish f5(104, "Ca Koi", "Cam Trang", "Hien hien, de nuoi");

    // Cau 5.2: In thong tin ca 5 con ca ban dau
    cout << "== DANH SACH CA BAN DAU ==" << endl;
    f1.displayFishInfo();
    f2.displayFishInfo();
    f3.displayFishInfo();
    f4.displayFishInfo();
    f5.displayFishInfo();

    // Cau 5.3: Cap nhat thong tin cho con ca thu 2 (f2) bang Setter
    f2.setName("Ca Vang");
    f2.setColor("Vang kim");
    f2.setCharacteristic("Thich boi dan");

    // Cau 5.4: Lay thong tin ca f2 ra in bang Getter
    cout << "\n= THONG TIN CA (DUNG GETTER)" << endl;
    cout << "ID: " << f2.getId() << endl;
    cout << "Ten ca: " << f2.getName() << endl;
    cout << "Mau sac: " << f2.getColor() << endl;
    cout << "Dac diem: " << f2.getCharacteristic() << endl;

    // Cau 5.5: Kiem tra lai f2 bang cach goi displayFishInfo()
    cout << "\n KIEM TRA LAI BANG DISPLAYFISHINFO() " << endl;
    f2.displayFishInfo();

    return 0;
}
