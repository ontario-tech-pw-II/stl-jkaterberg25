#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

int main(int argc, char** argv){
	string file;
	//Get the file name
	if(argc == 2){
		file = argv[1];
	}else{
		cout << "incorrect number of arguments" << endl;
		return 1;
	}

	//Figure out who has failed and how many times 
	map<string,int> c;

	ifstream fin(file);
	string name;
	double grade;

	if(fin.is_open()){
		while(fin >> name >> grade){
			if(c.find(name) == c.end()){
				c[name] = 0;
			}
			if(grade < 50){
				c[name]++;
			}
		}
	}

	//print out the findings
	map<string,int>::iterator i;
	for(i=c.begin(); i!=c.end(); ++i){
		cout << "\t" << i->first << " " << i->second << endl;
	}

	return 0;
}
