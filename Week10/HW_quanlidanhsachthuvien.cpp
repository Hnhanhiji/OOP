
#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Thư viện dùng để định dạng khoảng cách bảng (setw)

using namespace std;

// === THIẾT KẾ CLASS BOOK ===
class Book {
private:
    // Các thuộc tính đặt ở mức private
    string bookId;
    string title;
    string author;
    int year;

public:
    // Constructor khởi tạo sách với đầy đủ thông tin
    Book(string id, string t, string a, int y) {
        bookId = id;
        title = t;
        author = a;
        year = y;
    }

    // Các hàm public để lấy thông tin (getter) vì main không được truy cập trực tiếp
    string getBookId() const { return bookId; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }

    // Hàm hiển thị thông tin chi tiết 1 cuốn sách (dùng cho chức năng tìm kiếm)
    void displayDetail() const {
        cout << "Ma sach: " << bookId << "\n";
        cout << "Ten sach: " << title << "\n";
        cout << "Tac gia: " << author << "\n";
        cout << "Nam xuat ban: " << year << "\n";
    }
};

// === CHƯƠNG TRÌNH CHÍNH ===
int main() {
    // Lưu sách trong vector
    vector<Book> library;
    int choice;

    do {
        // Hiển thị Menu
        cout << "\n===== QUAN LY SACH THU VIEN =====\n";
        cout << "1. Them sach\n";
        cout << "2. Hien thi danh sach sach\n";
        cout << "3. Tim sach theo ma sach\n";
        cout << "4. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        if (choice == 1) {
            // 1. Thêm sách
            string id, title, author;
            int year;

            cout << "\nNhap thong tin sach:\n";
            cout << "Ma sach: ";
            cin >> id;
            cin.ignore(); // Xóa bộ nhớ đệm trước khi nhập chuỗi có khoảng trắng

            cout << "Ten sach: ";
            getline(cin, title);

            cout << "Tac gia: ";
            getline(cin, author);

            cout << "Nam xuat ban: ";
            
            cin >> year;

            // Tạo đối tượng Book bằng constructor và đưa vào vector
            Book newBook(id, title, author, year);
            library.push_back(newBook);

            cout << "Da them sach thanh cong!\n";

        }
        else if (choice == 2) {
            // 2. Hiển thị danh sách
            cout << "\n===== DANH SACH SACH =====\n";
            // In tiêu đề bảng với khoảng cách (setw)
            cout << left << setw(10) << "Ma sach"
                << setw(25) << "Ten sach"
                << setw(20) << "Tac gia"
                << "Nam\n";

            // Duyệt qua vector để in thông tin
            for (int i = 0; i < library.size(); i++) {
                cout << left << setw(10) << library[i].getBookId()
                    << setw(25) << library[i].getTitle()
                    << setw(20) << library[i].getAuthor()
                    << library[i].getYear() << "\n";
            }

        }
        else if (choice == 3) {
            // 3. Tìm sách theo mã
            string searchId;
            cout << "\nNhap ma sach can tim: ";
            cin >> searchId;

            bool found = false;
            for (int i = 0; i < library.size(); i++) {
                if (library[i].getBookId() == searchId) {
                    cout << "Thong tin sach:\n";
                    library[i].displayDetail();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Khong tim thay sach co ma " << searchId << "!\n";
            }

        }
        else if (choice != 4) {
            cout << "Lua chon khong hop le. Vui long chon lai!\n";
        }

    } while (choice != 4);

    cout << "Da thoat chuong trinh.\n";
    return 0;
}
