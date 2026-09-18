struct Sinhvien{
	int id;
	string name;
	string mobile;
	
	void inputInfo(){
		cin>>name;
		cin>>mobile;
		cin>id; 
	} 
	
	void outputInfo(){
		cout << name;
		cout << id;
		cout << mobile; 
		
}

struct ClassInfo{
	int idClass;
	String nameClass;
	int numStudents;
	Student[] students; 

	void inputClass(){
		cin>>idClass;
		cin >> nameClass;
		cin >> numStudents ; 

		for (....){
			cin >> students[i].id
			cin >> students[i].name
			cin >> students[i].mobile
		} 
	} 

	void outputClass(){
		cout << idclass
		... 
		for (...){
			cout << students[i].id
			cout << students[i].name
			cout << students[i].mobile
		} 
	} 	
	
	void addStudent(Sinhvien a){
		students[numStudents] = a;
		numStudents++; 
	} 

	void getStudentInfo(int idStudent){
		for(....)
			if(students[i].id == idStudent){
				cout>> 
			} 
	}

	Sinhvien getStudentInfo(int idStudent){
		for(....)
			if(students[i].id == idStudent){
				return students[i];
			} 
		//trong truong hop k tim thay thi tra ve nul
	} 

	Sinhvien[] getStudents(){
		return students; 
	}
	
} 	

void main(){
	ClassInfo oopclass; 
	oopclass.inputClass();
	oopclass.outputClass();
