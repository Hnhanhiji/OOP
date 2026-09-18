#include <iostream>
using namespace std;

// Truyền tham trị (pass by value)
void changeValue(int x) {
    x = 100;
}

// Truyền tham chiếu (pass by reference)
void changeRef(int& x) {
    x = 200;
}

int main() {
    int a = 5;
    
    changeValue(a);
    cout << "After changeValue: " << a << endl;
    
    changeRef(a);
    cout << "After changeRef: " << a << endl;
    
    return 0;
}

