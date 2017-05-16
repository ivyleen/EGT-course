//============================================================================
// Name        : Test3.cpp
// Author      : Ivy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Box.h"
using namespace std;

int main() {

	Box one;
	cin >> one;
	Box three(223,235,235);
	Box two;
	cin >> two;

	cout << one + three << endl;
	bool isEqual = (one!=three);
	cout << "Are they equal? " <<boolalpha <<isEqual << endl;

	bool isBigger = (three>one);
	cout << "Is one bigger? " << boolalpha <<isBigger << endl;

	return 0;
}
