#include <iostream>
#include <string>
using namespace std;

int main() {
    // =========================================================================
    // 1. Get Length (length() / size())
    // =========================================================================
    cout << "--- 1. Get Length ---" << endl;
    string s_len = "Hello C++";
    cout << s_len.length() << endl; // Output: 9
    cout << s_len.size() << endl;   // Output: 9
    cout << endl;


    // =========================================================================
    // 2. Check if Empty (empty())
    // =========================================================================
    cout << "--- 2. Check if Empty ---" << endl;
    string s1_emp = "";
    string s2_emp = "Hi";
    cout << s1_emp.empty() << endl; // Output: 1 (true)
    cout << s2_emp.empty() << endl; // Output: 0 (false)
    cout << endl;


    // =========================================================================
    // 3. Find a Substring (find())
    // =========================================================================
    cout << "--- 3. Find a Substring ---" << endl;
    string text_find = "I love C++";
    size_t pos = text_find.find("C++");

    if (pos != string::npos) {
        cout << "Found at: " << pos << endl; // Output: Found at: 7
    } else {
        cout << "Not found!" << endl;
    }
    cout << endl;


    // =========================================================================
    // 4. Get a Substring (substr())
    // =========================================================================
    cout << "--- 4. Get a Substring ---" << endl;
    string s_sub = "Hello World";
    string part1 = s_sub.substr(0, 5); // Cắt từ vị trí 0, độ dài 5 ký tự -> "Hello"
    string part2 = s_sub.substr(6, 5); // Cắt từ vị trí 6, độ dài 5 ký tự -> "World"
    cout << part1 << endl;
    cout << part2 << endl;
    cout << endl;


    // =========================================================================
    // 5. Append Text (append())
    // =========================================================================
    cout << "--- 5. Append Text ---" << endl;
    string s_app = "Hello";
    s_app.append(" C++");
    cout << s_app << endl; // Output: Hello C++
    cout << endl;


    // =========================================================================
    // 6. Insert Text (insert())
    // =========================================================================
    cout << "--- 6. Insert Text ---" << endl;
    string s_ins = "Hello World";
    s_ins.insert(5, ", C++"); // Chèn vào sau từ "Hello" (vị trí thứ 5)
    cout << s_ins << endl;     // Output: Hello, C++ World
    cout << endl;


    // =========================================================================
    // 7. Erase Characters (erase())
    // =========================================================================
    cout << "--- 7. Erase Characters ---" << endl;
    string s_era = "Hello World";
    s_era.erase(5, 6); // Xóa từ vị trí 5, độ dài 6 ký tự (xóa " World")
    cout << s_era << endl; // Output: Hello
    cout << endl;


    // =========================================================================
    // 8. Replace Text (replace())
    // =========================================================================
    cout << "--- 8. Replace Text ---" << endl;
    string s_rep = "I like Java";
    s_rep.replace(7, 4, "C++"); // Thay thế từ vị trí 7, độ dài 4 ký tự ("Java") bằng "C++"
    cout << s_rep << endl;       // Output: I like C++
    cout << endl;


    // =========================================================================
    // 9. Compare Strings (compare())
    // =========================================================================
    cout << "--- 9. Compare Strings ---" << endl;
    string s1_comp = "apple";
    string s2_comp = "apple";
    string s3_comp = "banana";

    cout << s1_comp.compare(s2_comp) << endl; // Bằng nhau -> Output: 0
    cout << s1_comp.compare(s3_comp) << endl; // s1 < s3   -> Output: < 0 (-1)
    cout << s3_comp.compare(s1_comp) << endl; // s3 > s1   -> Output: > 0 (1)
    cout << endl;

    return 0;
}

