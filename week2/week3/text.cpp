// array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;


int main()
{   
    const int N = 20;   // number of students
    string names[N];       // names[0]
	string ids[N];          // ids[0]  ....ids[5]
    string phones[N];

    // Gán thông tin cho 5 sinh viên đầu tiên (Chỉ số từ 0 đến 4)
    names[0] = "Nguyen Van A";
    ids[0] = "23110001";
    phones[0] = "0901234567";

    names[1] = "Tran Thi B";
    ids[1] = "23110002";
    phones[1] = "0912345678";

    names[2] = "Le Van C";
    ids[2] = "23110003";
    phones[2] = "0923456789";

    names[3] = "Pham Thi D";
    ids[3] = "23110004";
    phones[3] = "0934567890";

    names[4] = "Hoang Van E";
    ids[4] = "23110005";
    phones[4] = "0945678901";
    // In thông tin của 5 SV
    cout << "student 1: " << names[0] << "-" << ids[0] << "-" << phones[0] << endl;
    cout << "student 2: " << names[1] << "-" << ids[1] << "-" << phones[1] << endl;
    cout << "student 3: " << names[2] << "-" << ids[2] << "-" << phones[2] << endl;
    cout << "student 4: " << names[3] << "-" << ids[3] << "-" << phones[3] << endl;
    cout << "student 5: " << names[4] << "-" << ids[4] << "-" << phones[4] << endl;
    return 0;
  
}

