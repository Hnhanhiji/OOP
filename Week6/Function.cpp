// Function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
// khai bao kieu cau truc
struct ScoreInfo {
	double sum;
	double average;
	int count;
	double maxScore;
	double minScore;



};
// gọi hàm
ScoreInfo analyzeScores(const vector<double>& scores) {
	ScoreInfo result;
	result.sum = 0;
	result.count = scores.size();

	if (result.count == 0) {
		result.average = 0;
		result.maxScore = 0;
		result.minScore = 0;
		return result;
	}

	result.minScore = scores[0];
	result.maxScore = scores[0];

	for (double s : scores) {
		result.sum += s;
		if (s > result.maxScore) result.maxScore = s;
		if (s < result.minScore) result.minScore = s;
	}

	result.average = result.sum / result.count;
	return result; // return all results at once
}





// void showelcome
void  showWelcome()
{
	cout << "==============================\n";
	cout << "Welcome to Student Manager\n";
	cout << "==============================\n";
}
// void showMenu include display Students, Show statistics, exit
void showMenu()
{
	cout << "1. Display Students\n";
	cout << "2. Show Statistics\n";
	cout << "3. Exit\n";
}
// void showStudentsName(string name)
void showStudentsName(string name){ 
	
	cout << "hello, " << name << "!" << endl;
	cout << "Student Name: " << name << endl;
} 
// void printstudentInfo(string name)
void  printStudentInfo(string name, int id) {
	cout << " ------------" << endl;
	cout << "Name  :" << name << endl;
	cout << "id  :" << id << endl;
	cout << " ------------" << endl;
} 
//double calculateAverage
double calculateAverage(double score1, double score2) {
	double sum = score1 + score2;
	double avg = sum / 2.0;
	return avg;

}

int main()
{	// call the fucntion showWelcome
	showWelcome();
    showMenu();
	cout << "Let's get started!\n";
	string studentName;
	int studentID;
	cout << "enter your name:";
	getline(cin, studentName);
	showStudentsName(studentName);
	cout << "enter student name:";
	getline(cin, studentName);
	cout << "enter student id: ";
	cin >> studentID;
	printStudentInfo(studentName, studentID);

	// step 4
	double math, english;
	cout << "enter math score: ";
	cin >> math;
	cout << " enter english score: ";
	cin >> english;
	//call the function
	double average = calculateAverage(math, english);
	cout << " Average score =" << average << endl;
	// bước 5
	vector<double> scores = { 8.5, 7.0 , 9.5, 6.0, 8.0 };
	ScoreInfo info = analyzeScores(scores);
	cout << "Total: " << info.sum << endl;
	cout << "Average: " << info.average << endl;
	cout << "Max score: " << info.maxScore << endl;
	cout << "Min score: " << info.minScore << endl;




	return 0;
}






