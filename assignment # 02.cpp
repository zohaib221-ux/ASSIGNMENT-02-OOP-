#include<iostream>
using namespace std;
class employee {
private:
	string name;
	string id;
	double salary;
	const string company_name;
	static int employee_count;
public:
	employee(string n, string i, double s) :company_name("TechSolutions"), name(n), id(i), salary(s) {
		employee_count++;
	}
	employee(const employee& e) {
		this->name = e.name;
		this->id = e.id;
		this->salary = e.salary;
		employee_count++;
	}
	~employee() {
		employee_count--;
	}
	void display()const {
		cout << "_____________________________________________" << endl;
		cout << "-------" << company_name << "--------" << endl;
		cout << "_____________________________________________" << endl;
		cout << endl;
		cout << "--------EMPLOYEE DATA--------" << endl;
		cout << endl;
		cout << "EMPLOYEE NAME : " << name << endl;
		cout << "EMPLOYEE ID : " << id << endl;
		cout << "EMPLOYEE SALARY : " << salary << endl;
	}
	static int total_employee() {
		return employee_count;
	}
};
int employee::employee_count = 0;
void display_info(employee empl) {
	empl.display();
}
employee create_employee(string name, string id, double salary) {
	employee empl(name, id, salary);
	return empl;
}

int main() {
	cout << "_____________________________________________" << endl;
	cout << "------TECH SOLUTIONS -> EMPLOYEE INFORMATION-----" << endl;
	cout << "_____________________________________________" << endl;
	cout << "EMPLOYEES: " << employee::total_employee() << endl;
	employee* empl1 = new employee("SARA", "SE0010", 110000);
	employee* empl2 = new employee("ALI", "DS0011", 350000);
	employee* empl3 = new employee("AYAAN", "CSS0012", 150000);
	cout << "_________________________________________" << endl;
	cout << "EMPLOYEES CREATED THROUGH CONSTRUCTOR " << endl;
	cout << "_________________________________________" << endl;
	empl1->display();
	empl2->display();
	empl3->display();
	cout << "EMPLOYEES: " << employee::total_employee() << endl;
	cout << endl;
	cout << "_____________________________________________" << endl;
	cout << "\n" << "------COPY CONSTRUCTOR -------- !" << endl;

	employee empl4 = *empl1;
	employee empl5 = *empl2;

	empl4.display();
	empl5.display();
	cout << "EMPLOYEES: " << employee::total_employee() << endl;

	delete empl1;
	delete empl2;
	delete empl3;
	cout << "_____________________________________________" << endl;
	cout << "---PASSING OBJECTS AS FUNCTION ARGUMENTS----" << endl;
	cout << "_____________________________________________" << endl;
	display_info(empl4);
	cout << "_____________________________________________" << endl;
	cout << "---RETURNING AN OBJECT FROM A FUNCTION---" << endl;
	cout << "_____________________________________________" << endl;
	employee empl6 = create_employee("Reyan", "CS1010", 100000);
	cout << "RETURNED EMPLOYEE : " << endl;
	empl6.display();
    cout << "_____________________________________________" << endl;

	return 0;
}
