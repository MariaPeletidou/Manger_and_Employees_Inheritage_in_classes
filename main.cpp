#include<iostream>
#include"Employee.hh"
#include"Manager.hh"//By mistake I named the headder file as Manageer.hh so I included it as it is.
using namespace std;

int main() {
	//Print the emplyees name and salary
	Employee emp1("Wouter",5000);
	emp1.businessCard();
	cout <<"   "<< emp1.salary() << endl;

	Employee emp2("Ivo", 500);
	emp2.businessCard();
	cout << "   " << emp2.salary() << endl;

	//Print the Manager's name and salary as an employee.
	Manager mngr1("Jo", 800000);//Manager behaves exactly like an employee as long as we use only employee-defined properties.
	mngr1.Employee::businessCard();//We use Employee::businessCard if we want to print the employee's businessCard version and not the Manager's version.
	cout << "   " << mngr1.salary() << endl;

	//Create the personnel hierarchy.
	Manager mngr2("Stan", 1000000);
    mngr2.addSubordinate(emp1);
	mngr2.addSubordinate(emp2);
	Manager mngr3("Frank", 5000000);
	mngr3.addSubordinate(mngr2);//Stan is a Manager but he is an employee as well so it can be put as an empoyee in the addSubordinates.
	mngr3.addSubordinate(mngr1);
	
	cout << endl;
	cout << "The personnel hierarchy of the buisiness is: " << endl;
	//Print the personnel hierarchy using manager's and employee's businessCard.
	mngr3.businessCard();
	mngr2.businessCard();
	mngr1.businessCard();//Jo is a manager but we didn't add any employee in his name. So the business card will not print any names bellow him.
	emp2.businessCard();
	emp1.businessCard();
	
	
	return 0;
}
