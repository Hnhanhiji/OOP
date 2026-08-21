#include  <iostream>     
using namespace std;

// Chương trình giới thiệu bản thân nâng cao với Icon và Màu sắc 
int main() {
    // Thiết lập các mã màu ANSI
    string RESET   = "\033[0m";
    string GREEN   = "\033[32m";
    string CYAN    = "\033[36m"; // các dãy này là các mã màu ANSI để in ra màu sắc trên terminal, giúp làm nổi bật các thông điệp và biểu tượng trong chương trình.
    string YELLOW  = "\033[33m"; // Thêm màu vàng cho các biểu tượng/thông điệp đặc biệt

    // 1. Phần tiêu đề chương trình 
    cout << GREEN << "╔═══════════════════════════════════════╗\n" << RESET;
    cout << GREEN << "║       🚀 HIEUNHAN'S SPACE 🚀         ║\n" << RESET;
    cout << GREEN << "╚═══════════════════════════════════════╝\n" << RESET;

    // 2. Phần thông tin cá nhân cơ bản
    cout << CYAN << "👤 Name: HieuNhan\n" << RESET;
    cout << CYAN << "📚 Course: OOP with C++\n" << RESET;
    cout << CYAN << "🏫 School: HCMUTE (HCMC University of Technology and Education)\n" << RESET;
    cout << CYAN << "📍 Hometown: Ho Chi Minh City, Vietnam\n" << RESET; 

    // 3. Phần thông tin công nghệ & Sở thích
    cout << CYAN << "💻 OS Environment: Windows 11\n" << RESET; 
    cout << CYAN << "🔥 Favorite Language: C++ & Python\n" << RESET;
    cout << CYAN << "🎮 Hobbies: Coding, Gaming & Tech Exploring\n" << RESET; 

    // 4. Phần mục tiêu tương lai
    cout << CYAN << "🎯 My Goal: Become a Core Software Engineer\n" << RESET;
    cout << YELLOW << "💬 Message: 💡 Practice makes perfect. Never stop learning!\n\n" << RESET;

    // 5. Khung kết thúc
    cout << GREEN << "═════════════════════════════════════════\n" << RESET;
    cout << GREEN << "          ✨ KEEP CODING 💻 ✨           \n" << RESET;
    cout << GREEN << "═════════════════════════════════════════\n" << RESET;
    // 6. TIẾP TỤC LÀM POWERPOINT 4 
    int age = 20; // Thêm biến tuổi để minh họa
    double gpa = 8.5   ; // Thêm biến GPA để minh họa
    cout << CYAN << "📅 Age: " << age << " years old\n" << RESET;
    cout << CYAN << "📊 GPA: " << gpa << "\n" << RESET;
    





    return 0;
}
