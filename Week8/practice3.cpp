#include <iostream>
using namespace std;

int main() {
    int x = 3;
    int& y = x; // y là biến tham chiếu đến x (hai biến dùng chung một ô nhớ)
    x = 7;
    y = 2;
    
    cout << x << " " << y << endl;
    return 0;
}

