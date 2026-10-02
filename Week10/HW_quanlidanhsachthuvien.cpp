#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Book {
private:
    string bookId;
    string title;
    string author;
    int year;

public:
    Book(string id, string t, string a, int y) {
        bookId = id;
        title = t;
        author = a;
        year = y;
    }

    string getBookId() const { return bookId; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }

    void displayDetail() const {
        cout << "Ma sach: " << bookId << "\n";
        cout << "Ten sach: " << title << "\n";
        cout << "Tac gia: " << author << "\n";
        cout << "Nam xuat ban: " << year << "\n";
    }
};

int main() {
    vector<Book> library;
    int choice;

    do {
        cout << "\n===== QUAN LY SACH THU VIEN =====\n";
        cout << "1. Them sach\n";
        cout << "2. Hien thi danh sach sach\n";
        cout << "3. Tim sach theo ma sach\n";
        cout << "4. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        if (choice == 1) {
            string id, title, author;
            int year;

            cout << "\nNhap thong tin sach:\n";
            
            // Xóa phím Enter còn sót lại từ lệnh cin >> choice ở trên
            cin.ignore(); 

            cout << "Ma sach: ";
            getline(cin, id);      // Đã chuyển sang dùng getline

            cout << "Ten sach: ";
            getline(cin, title);

            cout << "Tac gia: ";
            getline(cin, author);

            cout << "Nam xuat ban: ";
            cin >> year;

            Book newBook(id, title, author, year);
            library.push_back(newBook);

            cout << "Da them sach thanh cong!\n";

        } else if (choice == 2) {
            cout << "\n===== DANH SACH SACH =====\n";
            cout << left << setw(10) << "Ma sach" 
                 << setw(25) << "Ten sach" 
                 << setw(20) << "Tac gia" 
                 << "Nam\n";
            
            for (int i = 0; i < library.size(); i++) {
                cout << left << setw(10) << library[i].getBookId()
                     << setw(25) << library[i].getTitle()
                     << setw(20) << library[i].getAuthor()
                     << library[i].getYear() << "\n";
            }

        } else if (choice == 3) {
            string searchId;
            cout << "\nNhap ma sach can tim: ";
            
            // Tương tự, cần xóa phím Enter thừa trước khi getline
            cin.ignore(); 
            getline(cin, searchId); // Chuyển sang dùng getline khi tìm kiếm

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

        } else if (choice != 4) {
            cout << "Lua chon khong hop le. Vui long chon lai!\n";
        }

    } while (choice != 4);

    cout << "Da thoat chuong trinh.\n";
    return 0;
}
