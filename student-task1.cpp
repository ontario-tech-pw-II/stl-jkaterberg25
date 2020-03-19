// Student class is implemented based on string and do not need any change

#include <iostream>
#include <string>
#include <list>

using namespace std;

// ----------------------------- Base class

class Person{
	protected:
		string name;
	    
	public:
		void setname(char const *);
		string getname();


		Person(); 				// default constructor
		Person(const char *);
		Person(const Person &); 		// copy constructor

		Person(const string &);

		virtual ~Person();

};

void Person::setname(char const *n)
{
	name = n;
}

string Person::getname()
{
	return name;
}


Person::Person()
{
	name = "";
}

Person::Person(char const *n)
{
	setname(n);
}

Person::Person(const string & n)
{
	name = n;
}

Person::~Person()
{
}

Person::Person(const Person &t):name(t.name)
{
}

// -----------------------------  Student class

class Student : public Person{
	private:
		double grade;

	public:
      	
      	void setgrade(double);
      	double getgrade();

      	Student();    // default constructor
		Student(char const *, double);
		Student(const Student &);  // copy constructor

		~Student();

	friend ostream & operator<<(ostream &, const Student &);

};

void Student::setgrade(double g)
{
	grade =g;
}

double Student::getgrade()
{
	return grade;
}

ostream & operator<<(ostream & out, const Student & s)
{
		out << s.name << "," << s.grade;
		return out;

}

Student::Student(): grade(0)
{
}

Student::Student(char const *n, double g): Person(n)
{
	setgrade(g);
}

Student::Student(const Student &t):Person(t.name)
{
	grade = t.grade;
}

Student::~Student()
{
}

int main()
{  
	// Write your code for Task 1
	list<Student> c;
	list<Student>::iterator i;
	bool exit = false;
	string name;
	double grade;

	while(!exit){
		//Get the student information from stdin
		cout << "Enter the student's name and grade: ";
		cin >> name;

		//Allow the program to exit
		if(name == "exit")return 0;
		
		cin >> grade;

		//Create a student object
		Student tmp(name.c_str(), grade);

		if((c.size() == 0) || ((*(--c.end())).getgrade() < tmp.getgrade())){
			c.push_back(tmp);
		}else{
			//Add the student object to proper position in the list
			for(i=c.begin(); i!=c.end(); ++i){
				if((*i).getgrade() >= tmp.getgrade()){
					c.insert(i, tmp);
					break;
				}
			}
		}

		//Print contents of the list
		cout << "\tCurrent students in list(ascending):" << endl;
		for(i=c.begin(); i!=c.end(); ++i){
			cout << "\t\t" << *i << endl;
		}
		cout << "\tCurrent students in list(descending):" << endl;
		list<Student>::reverse_iterator r;
		for(r=c.rbegin(); r != c.rend(); ++r){
			cout << "\t\t" << *r << endl;
		}
	}
	return 0;
}
