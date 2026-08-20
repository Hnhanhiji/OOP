
#include <iostream>     
using namespace std;

int main() {
    // Định nghĩa các mã màu ANSI
    string RESET   = "\033[0m";  // Trở về màu trắng mặc định
    string GREEN   = "\033[32m"; // Màu xanh lá cây cho các đường kẻ và tiêu đề
    string CYAN    = "\033[36m"; // Màu xanh ngọc cho phần thông tin cá nhân

    // In phần tiêu đề với màu Xanh lá cây
    cout << GREEN << "=========================\n" << RESET;
    cout << GREEN << "    MY FIRST C++ APP     \n" << RESET;
    cout << GREEN << "=========================\n" << RESET;
    
    // In phần thông tin của bạn với màu Xanh ngọc
    cout << CYAN << "Name: HieuNhan\n" << RESET;
    cout << CYAN << "Course: OOP with C++\n" << RESET;
    cout << CYAN << "I'm ready to learn C++!\n" << RESET;
    
    return 0;
}
