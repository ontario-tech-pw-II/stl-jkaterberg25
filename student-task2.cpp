// Student class is implemented based on string and do not need any change

#include <set>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{  
	string file;
	if(argc == 2){
		file = argv[1];
	}else{
		cout << "Incorrect number of arguments" << endl;
		return 1;
	}

	ifstream fin(file);
	string name;
	double grade;

	set<string> c;

	//populate set with names of failing students
	if(fin.is_open()){
		while(fin >> name >> grade){
			if((grade < 50) && !(c.find(name) != c.end())){
				c.insert(name);
			}
		}
	}

	fin.close();//close file

	//print out contents of set
	set<string>::iterator i;
	cout << "Students with a grade below 50%:" << endl;
	for(i = c.begin(); i!=c.end();i++){
		cout << "\t" << *i << endl;
	}
	
	return 0;
}
