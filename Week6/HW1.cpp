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
// 4. Find the Second Highest Score (Tìm điểm cao thứ nhì - Không sắp xếp mảng)
// ============================================================================
void findSecondHighestScore(double scores[], int size) {
    double highest = -1.0;
    double secondHighest = -1.0;

    for (int i = 0; i < size; i++) {
        if (scores[i] > highest) {
            secondHighest = highest;
            highest = scores[i];
        }
        else if (scores[i] > secondHighest && scores[i] < highest) {
            secondHighest = scores[i];
        }
    }

    cout << "--- 4. Find the Second Highest Score ---\n";
    cout << "Highest score: " << highest << "\n";
    cout << "Second highest score: " << secondHighest << "\n\n";
}
// 5. Search for a Score (Tìm vị trí của một điểm số)
// ============================================================================
void searchForScore(double scores[], int size) {
    double target;
    cout << "--- 5. Search for a Score ---\n";
    cout << "Enter score to search: ";
    cin >> target;

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (scores[i] == target) {
            cout << "Found at:\nStudent " << i + 1 << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Score " << target << " not found in the array.\n";
    }
    cout << "\n";
}
// 6. Count Score Frequency (Đếm tần suất xuất hiện của một điểm số)
// ============================================================================
void countScoreFrequency(double scores[], int size) {
    double target;
    cout << "--- 6. Count Score Frequency ---\n";
    cout << "Enter score: ";
    cin >> target;

    int count = 0;
    for (int i = 0; i < size; i++) {
        if (scores[i] == target) {
            count++;
        }
    }
    cout << "Score " << target << " appears " << count << " times.\n\n";
}
// 7. Find First Failing Student (Tìm học sinh trượt đầu tiên < 5.0)
// ============================================================================
void findFirstFailingStudent(double scores[], int size) {
    cout << "--- 7. Find First Failing Student ---\n";
    bool hasFailing = false;
    for (int i = 0; i < size; i++) {
        if (scores[i] < 5.0) {
            cout << "First failing student:\nStudent " << i + 1 << ": " << scores[i] << "\n\n";
            hasFailing = true;
            break; // Thoát ngay khi tìm thấy người đầu tiên
        }
    }
    if (!hasFailing) {
        cout << "All students pass!\n\n";
    }
}
// 8. Compare Adjacent Students (So sánh điểm 2 học sinh đứng cạnh nhau)
// ============================================================================
void compareAdjacentStudents(double scores[], int size) {
    cout << "--- 8. Compare Adjacent Students ---\n";
    for (int i = 1; i < size; i++) {
        if (scores[i] > scores[i - 1]) {
            cout << "Student " << i + 1 << " improved compared to Student " << i << "\n";
        }
    }
    cout << "\n";
}
// 9. Find the Longest Pass Streak (Tìm chuỗi học sinh đỗ liên tiếp dài nhất)
// ============================================================================
void findLongestPassStreak(double scores[], int size) {
    int maxStreak = 0;
    int currentStreak = 0;

    for (int i = 0; i < size; i++) {
        if (scores[i] >= 5.0) {
            currentStreak++;
            if (currentStreak > maxStreak) {
                maxStreak = currentStreak;
            }
        }
        else {
            currentStreak = 0; // Đứt chuỗi, reset lại
        }
    }

    cout << "--- 9. Find the Longest Pass Streak ---\n";
    cout << "Longest pass streak: " << maxStreak << " students\n\n";
}
// 10. Create a Score Distribution (Vẽ biểu đồ phân phối điểm số)
// ============================================================================
void createScoreDistribution(double scores[], int size) {
    int r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0;

    for (int i = 0; i < size; i++) {
        if (scores[i] >= 0 && scores[i] < 5) r1++;
        else if (scores[i] >= 5 && scores[i] < 6.5) r2++;
        else if (scores[i] >= 6.5 && scores[i] < 8) r3++;
        else if (scores[i] >= 8 && scores[i] < 9) r4++;
        else if (scores[i] >= 9 && scores[i] <= 10) r5++;
    }

    cout << "--- 10. Create a Score Distribution ---\n";
    cout << "===== SCORE DISTRIBUTION =====\n";

    cout << "0 - <5   : "; for (int i = 0; i < r1; i++) cout << "*"; cout << " (" << r1 << ")\n";
    cout << "5 - <6.5 : "; for (int i = 0; i < r2; i++) cout << "*"; cout << " (" << r2 << ")\n";
    cout << "6.5 - <8 : "; for (int i = 0; i < r3; i++) cout << "*"; cout << " (" << r3 << ")\n";
    cout << "8 - <9   : "; for (int i = 0; i < r4; i++) cout << "*"; cout << " (" << r4 << ")\n";
    cout << "9 - 10   : "; for (int i = 0; i < r5; i++) cout << "*"; cout << " (" << r5 << ")\n\n";
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
    findSecondHighestScore(studentScores, MAX_STUDENTS);
    searchForScore(studentScores, MAX_STUDENTS);
    countScoreFrequency(studentScores, MAX_STUDENTS);
    findFirstFailingStudent(studentScores, MAX_STUDENTS);
    compareAdjacentStudents(studentScores, MAX_STUDENTS);
    findLongestPassStreak(studentScores, MAX_STUDENTS);
    createScoreDistribution(studentScores, MAX_STUDENTS);

}




















