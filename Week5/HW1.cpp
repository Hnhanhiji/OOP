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
	//counts student who passed and failed
	int passCount = 0;
	int failCount = 0;
	// vòng lặp để đếm số lượng học sinh đạt và không đạt
    for (int i = 0; i < numStudents; i++) {
        if (scores[i] >= 5) {
            passCount++;
        } else {
            failCount++;
        }
    }

	// caluclate the pass rate
	double passRate = (double)passCount / numStudents * 100;
	cout << "Pass rate: " << passRate << "%" << endl;
    // In ra kết quả 
    
    cout << "===== STATISTICS =====" << endl;
    cout << "Passed : " << passCount << " students" << endl;
    cout << "Failed : " << failCount << " students" << endl;
    cout << "Pass rate: " << passRate << "%" << endl;
	// find the highest and lowest score
	double highestScore = scores[0];
	double lowestScore = scores[0];
	for (int i = 1; i < numStudents; i++) {
		if (scores[i] > highestScore) {
			highestScore = scores[i];
		}
		if (scores[i] < lowestScore) {
			lowestScore = scores[i];
		}
	}


    cout << "Highest score: " << highestScore << endl;
    cout << "Lowest score: " << lowestScore << endl;
    //clarify students
        // --- PHẦN 7: XẾP LOẠI HỌC SINH ---
    cout << "===== CLASSIFICATION =====" << endl;

    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << (i + 1) << ": " << scores[i] << " -> ";

        // Sử dụng cấu trúc if - else if - else để phân loại điểm số
        if (scores[i] >= 9.0 && scores[i] <= 10.0) {
            cout << "Excellent" << endl;
        }
        else if (scores[i] >= 8.0) { // Điểm từ 8.0 đến dưới 9.0
            cout << "Very Good" << endl;
        }
        else if (scores[i] >= 6.5) { // Điểm từ 6.5 đến dưới 8.0
            cout << "Good" << endl;
        }
        else if (scores[i] >= 5.0) { // Điểm từ 5.0 đến dưới 6.5
            cout << "Average" << endl;
        }
        else {                       // Điểm dưới 5.0
            cout << "Fail" << endl;
        }
    }
	// Count excellent students
	int excellentCount = 0;
	for (int i = 0; i < numStudents; i++) {
		if (scores[i] >= 9.0) {
			excellentCount++;
		}
	}
	cout << "Number of excellent students: " << excellentCount << endl;
	cin.get(); // Wait for user input before closing the console window
	//Count students in a score range
	int countInRange = 0;
	double lowerBound, upperBound;
	cout << "Enter lower bound of score range: ";
	cin >> lowerBound;
	cout << "Enter upper bound of score range: ";
	cin >> upperBound;
	for (int i = 0; i < numStudents; i++) {
		if (scores[i] >= lowerBound && scores[i] <= upperBound) {
			countInRange++;
		}
	}
	cout << "Number of students in the score range [" << lowerBound << ", " << upperBound << "]: " << countInRange << endl;

    return 0;
}
