#include <iostream>
#include <string>

using namespace std;

// =========================================================================
// 1. Insert a String
// =========================================================================
void exercise1() {
    cout << "--- [Bài 1: Insert a String] ---" << endl;
    string original = "Hello World!";
    string toInsert = "C++ ";
    int position = 6;

    // Chèn chuỗi toInsert vào vị trí index số 6
    original.insert(position, toInsert);

    cout << "Result: \"" << original << "\"" << endl;
    cout << endl;
}

// =========================================================================
// 2. Find a Substring
// =========================================================================
void exercise2() {
    cout << "--- [Bài 2: Find a Substring] ---" << endl;
    string text = "I love C++ programming";
    string substring = "C++";

    // Tìm vị trí của chuỗi con
    size_t pos = text.find(substring);

    if (pos != string::npos) {
        cout << "Result: Position: " << pos << " (starts at index " << pos << ")" << endl;
    } else {
        cout << "Result: Not found!" << endl;
    }
    cout << endl;
}

// =========================================================================
// 3. Count Characters
// =========================================================================
void exercise3() {
    cout << "--- [Bài 3: Count Characters] ---" << endl;
    string text = "Hello C++";

    // 1. Đếm tổng số ký tự (bao gồm cả khoảng trắng)
    int countWithSpaces = text.length();

    // 2. Đếm số ký tự không tính khoảng trắng
    int countWithoutSpaces = 0;
    for (char c : text) {
        if (c != ' ') {
            countWithoutSpaces++;
        }
    }

    cout << "Result:" << endl;
    cout << "  " << countWithSpaces << " (with spaces)" << endl;
    cout << "  " << countWithoutSpaces << " (without spaces)" << endl;
    cout << endl;
}

// =========================================================================
// 4. Replace a Substring
// =========================================================================
void exercise4() {
    cout << "--- [Bài 4: Replace a Substring] ---" << endl;
    string original = "I like Java";
    string substring = "Java";
    string newString = "C++";

    // Tìm vị trí của từ cần thay thế trước
    size_t pos = original.find(substring);

    if (pos != string::npos) {
        // replace(vị trí bắt đầu, độ dài chuỗi cũ cần xóa, chuỗi mới cần thay vào)
        original.replace(pos, substring.length(), newString);
        cout << "Result: \"" << original << "\"" << endl;
    } else {
        cout << "Substring not found to replace." << endl;
    }
    cout << endl;
}

// =========================================================================
// 5. Extract a Substring
// =========================================================================
void exercise5() {
    cout << "--- [Bài 5: Extract a Substring] ---" << endl;
    string text = "Computer Science";
    int startPosition = 9;
    int length = 7;

    // Cắt chuỗi con bằng substr(vị trí bắt đầu, độ dài)
    string result = text.substr(startPosition, length);

    cout << "Result: \"" << result << "\"" << endl;
    cout << endl;
}

// =========================================================================
// Hàm main chính để chạy thử nghiệm toàn bộ bài tập
// =========================================================================
int main() {
    exercise1();
    exercise2();
    exercise3();
    exercise4();
    exercise5();

    return 0;
}

