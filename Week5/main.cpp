#include <iostream>
using namespace std;

int main()
{
    int numStudents;

    // --- PHẦN 1: NHẬP SỐ LƯỢNG HỌC SINH ---
    while (true) {
        cout << "How many students? ";
        cin >> numStudents;

        if (numStudents >= 2 && numStudents <= 20) {
            break;
        }

        cout << "Invalid number of students!" << endl;
        cout << "Please enter a number from 2 to 20." << endl;
        cout << endl;
    }

    // --- PHẦN 2: NHẬP ĐIỂM CHO TỪNG HỌC SINH ---
    double scores[20]; // Khai báo mảng tối đa 20 học sinh

    for (int i = 0; i < numStudents; i++) {
        // Yêu cầu nhập điểm cho học sinh thứ (i + 1)
        cout << "Enter score for student " << (i + 1) << ": ";
        cin >> scores[i];

        // Vòng lặp kiểm tra tính hợp lệ của điểm vừa nhập (0 <= score <= 10)
        while (scores[i] < 0 || scores[i] > 10) {
            
            cout << "Invalid score! Please enter a value from 0 to 10: ";
            cin >> scores[i];
        }
    }
    //3. Display the array
	cout << "Scores of students: ";

    for (int i = 0; i < numStudents; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;
    //pass or fail
    cout << "Pass or Fail: ";
    for (int i = 0; i < numStudents; i++) {
        if (scores[i] >= 5) {
            cout << "Pass ";
        } else {
            cout << "Fail ";
        }
    }
    cout << endl;

    return 0;
}

