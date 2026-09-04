// EX_Week4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
int n = 0;
string names[20];
string ids[20];
string phones[20];
void inputStudent() {
    cout << "Input the number of students:" <<endl;
    cin >> n;
    cin.ignore(); 
    cout<<"Name of myself: ";
    if (n > 0) {
        for (int i = 0; i < n;i++) {
            cout << "Enter information of student " << i + 1 << "\n";
            cout << "Name:";
            getline(cin, names[i]);
            cout << "ID:";
            getline(cin, ids[i]);
            cout << "Phone : ";
            getline(cin, phones[i]);
        }
        cout << "Number of inputted students: " << n;

    }
    else {
        cout << "The number of students must be more than 0";
    }
}

void outputStudents() {
    for (int i = 0; i < n;i++) {
        cout << "Student: " << i + 1 << "\n";
        cout << "Name: \n" << names[i] << "\n";
        cout << "ID: \n" << ids[i] << "\n";
        cout << "Phone: \n" << phones[i] << "\n";
    }
}
void PrintNamesmyself() {
    for (int i = 0; i < n; i++) {
        cout << "Name of myself " << i + 1 << ": " << names[i] << endl;
    }
}
int main()
{
   
    inputStudent();
    cout << n;
    outputStudents();
    PrintNamesmyself();
    return 0;
}

