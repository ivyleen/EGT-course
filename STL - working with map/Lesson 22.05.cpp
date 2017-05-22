//============================================================================
// Name        : 05.cpp
// Author      : Ivy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {

	std::map<int,int, std::less<int> > counters;
	// key : array element        value : how many times
	// 4 - 20

	map<int,int>::iterator it;

	int array[] = {2,5,79,66,55,2,66,5,66,1};
	vector < int > occur;
	for (int i = 0; i < 10; i++){
		occur.push_back(array[i]);
		cout << occur[i] << " " << endl;
	}

	for (unsigned int i = 0; i < occur.size(); i++){
		int key = occur[i];
		it = counters.find(key);
		if(it !=counters.end()){
			counters[key]++;
		} else{
			counters[key] = 1;
		}
	}

	cout << endl;
	cout << "Numbers" << "\t" << "Occurences" << endl;

	for (it = counters.begin(); it!=counters.end(); it++){
		cout << it->first << "\t" << it->second << endl;
	}

	for (unsigned int i = 0; i < occur.size(); i++){
		if (counters[occur[i]] %2 != 0 ){
			occur.erase(occur.begin()+i);
			i--;
		}
	}

	cout << endl;

	counters.clear();

	for (unsigned int i = 0; i < occur.size(); i++){
		int key = occur[i];
		it = counters.find(key);
		if(it !=counters.end()){
			counters[key]++;
		} else{
			counters[key] = 1;
		}
	}

	cout << "Now the vector looks like: " << endl;
	for (unsigned int i = 0; i < occur.size(); i++){
		cout << occur[i] << " " << endl;
	}

	cout << endl;

	for (it = counters.begin(); it!=counters.end(); it++){
		cout << it->first << "\t" << it->second << endl;
	}

	return 0;
}
