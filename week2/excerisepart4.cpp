#include <iostream>
using namespace std;

int main() {
    // 1. Khai báo hằng số (Yêu cầu 3)
    const int CURRENT_YEAR = 2026; 

    // 2. Khai báo biến với các kiểu dữ liệu khác nhau (Yêu cầu 1 & 2)
    string name = "Anna";
    int age = 20;
    double gpa = 8.5;
    char grade = 'A';

    // 3. Thực hiện phép tính toán (Yêu cầu 4)
    int birthYear = CURRENT_YEAR - age; // Tính năm sinh
    int nextAge = age + 1;              // Tính tuổi năm sau

    // 4. Minh họa cập nhật biến (Yêu cầu 5)
    int score = 80; 
    int updatedScore = 90; // Hoặc gán lại score = 90;

    // 5. In kết quả ra màn hình (Yêu cầu 6)
    cout << "==========================\n";
    cout << "    MY FIRST C++ APP\n";
    cout << "==========================\n";
    cout << "Name        : " << name << "\n";
    cout << "Age         : " << age << "\n";
    cout << "GPA         : " << gpa << "\n";
    cout << "Grade       : " << grade << "\n\n";
    cout << "Birth Year  : " << birthYear << "\n";
    cout << "Next Age    : " << nextAge << "\n\n";
    cout << "Initial Score: " << score << "\n";
    cout << "Updated Score: " << updatedScore << "\n";
    
    return 0;
}
