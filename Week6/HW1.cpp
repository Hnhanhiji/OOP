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
// 2. Count student in a score range
void countStudentsInRange(double scores[], int size) {
    double a, b;
    cout << "--- 2. Count Students in a Score Range ---\n";
    cout << "Enter minimum score: ";
    cin >> a;
    cout << "Enter maximum score: ";
    cin >> b;

    int count = 0;
    for (int i = 0; i < size; i++) {
        if (scores[i] >= a && scores[i] <= b) {
            count++;
        }
    }
    cout << "Students in range: " << count << "\n\n";
}
// 3. Find Students Above Average (Tìm học sinh trên điểm trung bình)
// ============================================================================
void findStudentsAboveAverage(double scores[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    double average = sum / size;

    cout << "--- 3. Find Students Above Average ---\n";
    cout << "Average score: " << fixed << setprecision(2) << average << "\n";
    cout << "Students above average:\n";
    for (int i = 0; i < size; i++) {
        if (scores[i] > average) {
            cout << "Student " << i + 1 << ": " << scores[i] << "\n";
        }
    }
    cout << "\n";
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
    countStudentsInRange(studentScores, MAX_STUDENTS);
    findStudentsAboveAverage(studentScores, MAX_STUDENTS);
}







