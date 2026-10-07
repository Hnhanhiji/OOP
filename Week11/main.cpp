#include <iostream>
#include <string>
#include <vector>

using namespace std;

// định nghĩa struct and class
struct Date {
	int year, month, day;
	// constructor mặc định cho Dtae
	Date() : year(0), month(0), day(0) {}

	//Thêm constructor 3 tham số để gọi được Date{2000, 1, 1} trong hàm main
	Date(int y, int m, int d) : year(y), month(m), day(d) {}
};

class Student {
private:
	// properties
	string name;
	string address;
	Date birthdate; // date of birth: yyyy/mm/dd
	string cccd; // citizen card code

public:
	
	Student() {}

	// 1. constructor 4 tham số 
	
	Student(string n, string a, Date b, string c) : name(n), address(a), birthdate(b), cccd(c) {}

	
	// 2. constructor 3 tham số
	Student(string n, string a, Date b) : name(n), address(a), birthdate(b) {}

	// 3. constructor 2 tham số
	Student(string n, string a) : name(n), address(a) {}

	// 4. constructor 1 tham số
	Student(string n) : name(n) {}

	// methods
	void setStudentInfo() {
		// code to set student information
	}

	Student getStudentInfo(string cccd) {
		// code to get student information
		return Student("", "", Date(), "");
	}

	// dùng mảng động 
	vector<Student> getStudents(string name) { // mảng động lưu trữ danh sách sinh viên
		// code to get students
		return vector<Student>();
	}

	vector <Student> getStudentsByBirthdate(Date birthdate) {
		// code to get students by birthdate
		return vector<Student>();
	}

	vector <Student> getStudentsByAddress(string address) {
		// code to get students by address
		return vector<Student>();
	}

	vector <Student> getStudentsByCCCD(string cccd) {
		// code to get students by cccd
		return vector<Student>();
	}
	void displayInfo() {
		// code to print student information
		cout << "Name: " << name << endl;
		cout << "Address: " << address << endl;
		cout << "Birthdate: " << birthdate.year << "/" << birthdate.month << "/" << birthdate.day << endl;
		cout << "CCCD: " << cccd << endl;
	}
};


// OOP = Data hiding -> Encapsulation ( tính đóng gói)
int main() {
	Student student1;
	// test tham số 1
	Student student2("Nguyen Van A");
	// test tham số 2
	Student student3("Nguyen Van B", "Ha Noi");
	// test tham số 3
	Student student4("Nguyen Van C", "Ha Noi", Date{ 2000, 1, 1 });
	// test tham số 4
	Student student5("Nguyen Van D", "Ha Noi", Date{ 2000, 1, 1 }, "123456789");

	//In ra màn hình kiểm tra
	cout << "Student 1: \n"; student1.displayInfo();
	cout << "Student 2: \n"; student2.displayInfo();
	cout << "Student 3: \n"; student3.displayInfo();
	cout << "Student 4: \n"; student4.displayInfo();
	cout << "Student 5: \n"; student5.displayInfo();

	return 0;
}
