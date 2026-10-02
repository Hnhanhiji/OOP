// Week10_step3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Food {
private:
	string id;
	string name;
	double price;
	int quantity;
public:
public:
    Food(string id, string name, double price,
        int quantity);        // constructor
    void input();              // nhập thông tin
    void display() const;      // hiển thị thông tin
    void setPrice(double newPrice); // cập nhật giá
    bool reduceQuantity(int amount); // giảm số lượng
    bool isAvailable() const;  // kiểm tra còn hàng
    string getId() const;      // lấy mã món
    string getName() const;    // lấy tên món
    double getPrice() const;   // lấy giá
    int getQuantity() const;   // lấy số lượng
};

// ở bên ngoài


int main()
{	
	vector <Food> menu;
	int n;
	cout << "Enter number of food items: ";
	cin >> n;
	cin.ignore(); // bỏ ký tự xuống dòng
	for (int i = 0; i < n; i++) {
		cout << "Enter details for food item " << (i + 1) << ":" << endl;
		Food f("", "", 0.0, 0);
		f.input();
		menu.push_back(f);
	}
	cout << "\nMenu:\n";
	for (const auto& f : menu) {
		f.display();
		cout << endl;
	}
}

// định nghĩa hàm
Food::Food(string id, string name, double price, int quantity) {
	this->id = id;
	this->name = name;
	this->price = price;
	this->quantity = quantity;
}	
void Food::input() {
	cout << "Enter food ID: "; getline(cin, id);
	cout << "Enter food name: "; getline(cin, name);
	cin.ignore();
	cout << "Enter food price: ";
	cin >> price;
	cout << "Enter food quantity: ";
	cin >> quantity;
	cin.ignore(); // bỏ ksy tự xuống dòng
}
void Food::display() const {
	cout << "Food ID: " << id << endl;
	cout << "Food name: " << name << endl;
	cout << "Food price: " << price << endl;
	cout << "Food quantity: " << quantity << endl;
}
void Food::setPrice(double newPrice) {
	if (newPrice < 0) {
		cout << "Price cannot be negative!" << endl;
		return;
	}
	price = newPrice;
}
bool Food::reduceQuantity(int amount) {
	if (amount < 0) {
		cout << "Amount cannot be negative!" << endl;
		return false;
	}
	if (quantity - amount < 0) {
		cout << "Not enough quantity available!" << endl;
		return false;
	}
	quantity -= amount;
	return true;
}
bool Food::isAvailable() const {
	return quantity > 0;
}
string Food::getId() const {
	return id;
}
string Food::getName() const {
	return name;
}
double Food::getPrice() const {
	return price;
}
int Food::getQuantity() const {
	return quantity;
}
