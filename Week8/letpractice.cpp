#include <iostream>
#include <string>
#include <sstream> // Thư viện dùng cho bài 3 (tách từ)
#include <cctype>  // Thư viện dùng để chuyển chữ in hoa (toupper)

using namespace std;

// =========================================================================
// 1. Student Profile
// =========================================================================
void exercise1() {
    cout << "\n--- [Bài 1: Student Profile] ---" << endl;
    string fullName, studentId, email, hometown;

    cout << "Nhập họ và tên: "; getline(cin, fullName);
    cout << "Nhập mã số sinh viên: "; getline(cin, studentId);
    cout << "Nhập email: "; getline(cin, email);
    cout << "Nhập quê quán: "; getline(cin, hometown);

    cout << "\n===== STUDENT PROFILE =====" << endl;
    cout << "Full name  : " << fullName << endl;
    cout << "Student ID : " << studentId << endl;
    cout << "Email      : " << email << endl;
    cout << "Hometown   : " << hometown << endl;
    cout << "===========================" << endl;
}

// =========================================================================
// 2. Greeting Message
// =========================================================================
void exercise2() {
    cout << "\n--- [Bài 2: Greeting Message] ---" << endl;
    string name;
    cout << "Nhập tên của bạn: ";
    getline(cin, name);

    // Ghép chuỗi sử dụng toán tử +
    string message = "Hello, " + name + "!\nWelcome to C++ programming!";
    cout << message << endl;
}

// =========================================================================
// 3. Initials
// =========================================================================
void exercise3() {
    cout << "\n--- [Bài 3: Initials] ---" << endl;
    string fullName;
    cout << "Nhập họ và tên đầy đủ: ";
    getline(cin, fullName);

    stringstream ss(fullName);
    string word;
    string initials = "";

    // Tách từng từ và lấy chữ cái đầu tiên chuyển thành in hoa
    while (ss >> word) {
        initials += toupper(word[0]);
        initials += ".";
    }

    // Xóa dấu chấm thừa ở cuối cùng nếu chuỗi không rỗng
    if (!initials.empty()) {
        initials.pop_back();
    }

    cout << "Initials: " << initials << endl;
}

// =========================================================================
// 4. Find a Word
// =========================================================================
void exercise4() {
    cout << "\n--- [Bài 4: Find a Word] ---" << endl;
    string sentence, word;

    cout << "Nhập một câu văn: "; getline(cin, sentence);
    cout << "Nhập từ cần tìm: "; getline(cin, word);

    size_t pos = sentence.find(word);

    if (pos != string::npos) {
        cout << "The word \"" << word << "\" is found at position " << pos << "." << endl;
    }
    else {
        cout << "The word \"" << word << "\" is not found." << endl;
    }
}

// =========================================================================
// 5. Create a Username
// =========================================================================
void exercise5() {
    cout << "\n--- [Bài 5: Create a Username] ---" << endl;
    string fullName, rawUsername = "";
    int birthYear;

    cout << "Nhập họ và tên: "; getline(cin, fullName);
    cout << "Nhập năm sinh: "; cin >> birthYear;
    cin.ignore(); // Xóa bộ nhớ đệm để không lỗi khi dùng getline sau đó

    // Bước 1: Loại bỏ khoảng trắng và chuyển toàn bộ thành chữ thường
    for (char c : fullName) {
        if (c != ' ') {
            rawUsername += tolower(c);
        }
    }

    // Bước 2: Kết hợp với năm sinh (chuyển số thành chuỗi bằng to_string)
    string username = rawUsername + to_string(birthYear);
    cout << "Username: " << username << endl;
}

// =========================================================================
// Hàm main chính điều khiển chương trình
// =========================================================================
int main() {
    // Lần lượt gọi từng bài tập để kiểm tra chạy thử
    exercise1();
    exercise2();
    exercise3();
    exercise4();
    exercise5();

    return 0;
}

