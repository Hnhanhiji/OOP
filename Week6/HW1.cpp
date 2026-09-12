// HW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;
// khai báo hàm
// khai báo mảng mẫu
const int MAX_STUDENTS = 10;

//1 count excellent student
void countExcellentStudents(double scores[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (scores[i] >= 9.0) {
            count++;
        }
    }
    cout << "-1. Count Excellent Students\n";
    cout << "Number of excellent students: " << count << "\n\n";
}


int main()
{
    double studentScores[MAX_STUDENTS] = { 4.5, 7.5, 9.5, 3.0, 9.0, 8.0, 7.5, 6.0, 8.5, 5.5 };
    cout << "=== DATA MANG DIEM MAU ===\n";
    for (int i = 0; i < MAX_STUDENTS; i++) {
        cout << "Hoc sinh " << i + 1 << ": " << studentScores[i] << " | ";
    }
    cout << "\n\n";
    // Gọi lần lượt các hàm bài tập
    countExcellentStudents(studentScores, MAX_STUDENTS);


}



