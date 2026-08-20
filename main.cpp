#include  <iostream>     
using namespace std;

// Chương trình giới thiệu bản thân nâng cao với Icon và Màu sắc 
int main() {
    // Thiết lập các mã màu ANSI
    string RESET   = "\033[0m";
    string GREEN   = "\033[32m";
    string CYAN    = "\033[36m";
    string YELLOW  = "\033[33m"; // Thêm màu vàng cho các biểu tượng/thông điệp đặc biệt

    // 1. Phần tiêu đề chương trình 
    cout << GREEN << "╔═══════════════════════════════════════╗\n" << RESET;
    cout << GREEN << "║       🚀 HIEUNHAN'S SPACE 🚀          ║\n" << RESET;
    cout << GREEN << "╚═══════════════════════════════════════╝\n" << RESET;

    // 2. Phần thông tin cá nhân cơ bản
    cout << CYAN << "👤 Name: HieuNhan\n" << RESET;
    cout << CYAN << "📚 Course: OOP with C++\n" << RESET;
    cout << CYAN << "🏫 School: HCMUTE (HCMC University of Technology and Education)\n" << RESET;
    cout << CYAN << "📍 Hometown: Ho Chi Minh City, Vietnam\n" << RESET; // Thông tin mới 1

    // 3. Phần thông tin công nghệ & Sở thích
    cout << CYAN << "💻 OS Environment: Windows 11\n" << RESET; // Thông tin mới 2
    cout << CYAN << "🔥 Favorite Language: C++ & Python\n" << RESET;
    cout << CYAN << "🎮 Hobbies: Coding, Gaming & Tech Exploring\n" << RESET; // Thông tin mới 3

    // 4. Phần mục tiêu tương lai
    cout << CYAN << "🎯 My Goal: Become a Core Software Engineer\n" << RESET;
    cout << YELLOW << "💬 Message: 💡 Practice makes perfect. Never stop learning!\n\n" << RESET;

    // 5. Khung kết thúc ấn tượng
    cout << GREEN << "═════════════════════════════════════════\n" << RESET;
    cout << GREEN << "          ✨ KEEP CODING 💻 ✨           \n" << RESET;
    cout << GREEN << "═════════════════════════════════════════\n" << RESET;

    return 0;
}
