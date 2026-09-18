#include <cstdio>
#include <iostream>
using namespace std;

struct book {
  int id;
  char title[200];
  char author[50];
  double price;

  void inputbook() {
    cout << "Nhap ma sach : ";
    cin >> id;
    cin.ignore();
    cout << "Nhap ten sach: ";
    cin.getline(title, 200);
    cout << "Nhap tac gia : ";
    cin.getline(author, 50);
    cout << "Nhap price   : ";
    cin >> price;
    cin.ignore();
  }

  void outputbook() {
    printf("ID     : %d\n", id);
    printf("Sach   : %s\n", title);
    printf("Tac gia: %s\n", author);
    printf("Price  : %.1f\n", price);
  }
};

struct thuvien {
  int idlib;
  char namelib[100];
  int numbooks;
  book books[100];

  void inputlib() {
    cout << "Nhap ma thu vien : ";
    cin >> idlib;
    cin.ignore();
    cout << "Nhap ten thu vien: ";
    cin.getline(namelib, 100);
    cout << "So luong sach    : ";
    cin >> numbooks;
    cin.ignore();
    cout << endl;

    for (int i = 0; i < numbooks; i++) {
      cout << "--- Nhap thong tin quyen sach thu " << i + 1 << " ---\n";
      books[i].inputbook();
    }
    cout << endl;
  }

  void outputlibrary() {
    cout << "=== DANH SACH SACH TRONG: " << namelib << " (Ma: " << idlib
         << ") ===\n";
    for (int i = 0; i < numbooks; i++) {
      books[i].outputbook();
      cout << "---------------------\n";
    }
  }

  void addbook(book a) {
    if (numbooks < 100) {
      books[numbooks] = a;
      numbooks++;
    }
  }

  void printbookinfo(int searchid) {
    for (int i = 0; i < numbooks; i++) {
      if (books[i].id == searchid) {
        books[i].outputbook();
        return;
      }
    }
    cout << "Khong tim thay sach!\n";
  }

  book getbookinfo(int searchid) {
    for (int i = 0; i < numbooks; i++) {
      if (books[i].id == searchid) {
        return books[i];
      }
    }
    book emptybook;
    emptybook.id = -1;
    return emptybook;
  }

  book *getbooks() { return books; }
};

int main() {
  thuvien lib;
  lib.inputlib();
  lib.outputlibrary();

  book newbook;
  cout << "\n--- Nhap sach can them moi ---\n";
  newbook.inputbook();
  lib.addbook(newbook);
  cout << endl;

  int searchid;
  cout << "Nhap ID sach muon tim (in truc tiep): ";
  cin >> searchid;
  lib.printbookinfo(searchid);
  cout << endl;

  cout << "Nhap ID sach muon lay thong tin (tra ve doi tuong): ";
  cin >> searchid;
  book foundbook = lib.getbookinfo(searchid);
  if (foundbook.id != -1) {
    cout << "Tim thay:\n";
    foundbook.outputbook();
  } else {
    cout << "Khong tim thay!\n";
  }

  book *allbooks = lib.getbooks();
  cout << "Thong tin sach dau tien trong danh sach:\n";
  allbooks[0].outputbook();

  return 0;
}
