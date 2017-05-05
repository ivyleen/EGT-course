//============================================================================
// Name        : 05.cpp
// Author      : Ivy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Racio.h"
using namespace std;

int main() {

	Racio x(2.3, 4.5);
	Racio y(1,2.3);
	cout << "Operator == test: " << boolalpha << (x==y)<< endl;
	cout << "Operator + test: " << (x+y) << endl;
	cout << "Operator - test: " << (x-y)<< endl;
	cout << "Operator * test: " << (x*y)<< endl;
	cout << "Operator / test: " << (x/y)<< endl;
	return 0;
}
