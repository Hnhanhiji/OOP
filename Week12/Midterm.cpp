// Week12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

// 1) Define the Fish class
class Fish {
private:
    int id;
    string name;
    string color;
    string characteristic;

public:
    // 2) Implement Constructors

    // Default constructor (no parameters)
    Fish() {
        id = 0;
        name = "Unknown";
        color = "Unknown";
        characteristic = "Unknown";
    }

    // Constructor with 1 parameter
    Fish(int i) {
        id = i;
        name = "Unknown";
        color = "Unknown";
        characteristic = "Unknown";
    }

    // Constructor with 2 parameters
    Fish(int i, string n) {
        id = i;
        name = n;
        color = "Unknown";
        characteristic = "Unknown";
    }

    // Constructor with 3 parameters
    Fish(int i, string n, string c) {
        id = i;
        name = n;
        color = c;
        characteristic = "Unknown";
    }

    // Constructor with all 4 parameters
    Fish(int i, string n, string c, string ch) {
        id = i;
        name = n;
        color = c;
        characteristic = ch;
    }

    // 3) Implement Getter and Setter Methods

    int getId() { return id; }
    void setId(int i) { id = i; }

    string getName() { return name; }
    void setName(string n) { name = n; }

    string getColor() { return color; }
    void setColor(string c) { color = c; }

    string getCharacteristic() { return characteristic; }
    void setCharacteristic(string ch) { characteristic = ch; }

    // 4) Implement a Method to Display Fish Information
    void displayFishInfo() {
        cout << "-----------------------------" << endl;
        cout << "ID            : " << id << endl;
        cout << "Name          : " << name << endl;
        cout << "Color         : " << color << endl;
        cout << "Characteristic: " << characteristic << endl;
    }
};

// 5) Implement the main() Function
int main() {
    // 5.1: Create 5 Fish objects using the 5 different constructors
    Fish fish1;
    Fish fish2(101);
    Fish fish3(102, "Guppy");
    Fish fish4(103, "Betta", "Red");
    Fish fish5(104, "Koi", "Orange/White", "Peaceful");

    // 5.2: Call displayFishInfo() to display the information of all 5 objects
    cout << "=== INITIAL FISH INFORMATION ===" << endl;
    fish1.displayFishInfo();
    fish2.displayFishInfo();
    fish3.displayFishInfo();
    fish4.displayFishInfo();
    fish5.displayFishInfo();

    // 5.3: Use the setter methods to update the name, color, and characteristics of one object
    // Cập nhật thông tin cho đối tượng fish2
    fish2.setName("Goldfish");
    fish2.setColor("Gold");
    fish2.setCharacteristic("Hardy and popular");

    // 5.4: Use the getter methods to retrieve and print the information of the updated object
    cout << "\n=== RETRIEVING UPDATED FISH 2 USING GETTERS ===" << endl;
    cout << "Fish ID       : " << fish2.getId() << endl;
    cout << "Fish Name     : " << fish2.getName() << endl;
    cout << "Fish Color    : " << fish2.getColor() << endl;
    cout << "Characteristic: " << fish2.getCharacteristic() << endl;

    // 5.5: Call displayFishInfo() again to verify the changes
    cout << "\n=== VERIFYING FISH 2 USING displayFishInfo() ===" << endl;
    fish2.displayFishInfo();

    return 0;
}

