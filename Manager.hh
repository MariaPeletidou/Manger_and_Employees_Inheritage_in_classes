#ifndef MANAGER_HH
#define MANAGER_HH

#include<vector>
#include <set>
#include<iostream>
#include <string>
using namespace std;
#include"Employee.hh"
#include<iterator> 

class Manager :public Employee {
public:
	Manager(const char* _name, double _salary):Employee(_name, _salary), subordinates() {
		
	}
	//Modifier
	void addSubordinate(Employee& empl) {
		subordinates.insert(&empl);
	}
	//Asccessor
	const set<Employee*>& listOfSubordinates() const {
		return subordinates;
	}

	void businessCard(ostream& os = cout) const{
		Employee::businessCard();
	  set<Employee*>::iterator iter= subordinates.begin();
	  os << "  is the Manager of:" << endl;
	  while (iter != subordinates.end()) {
		 os<<"   "<< (*iter)->name()<<endl;
		  ++iter;
	  }
	  os << endl;
	}
    
private:
	set<Employee*> subordinates;//The set is better choice to keep track of collection of subordinates as dublicates are not allowed
};




#endif
