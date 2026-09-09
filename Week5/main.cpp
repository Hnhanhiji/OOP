#include <iostream>
using namespace std;

int main()
{
    int numStudents;

    
    while (true) {
        cout << "How many students? ";
        cin >> numStudents;

        // Kiểm tra xem số lượng học sinh có hợp lệ không (2 <= N <= 20)
        if (numStudents >= 2 && numStudents <= 20) {
            break;
        }

       
        cout << "Invalid number of students!" << endl;
        cout << "Please enter a number from 2 to 20." << endl;
        cout << endl; 
    }

   

    return 0;
}
