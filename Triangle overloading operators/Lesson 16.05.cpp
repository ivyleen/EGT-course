//============================================================================
// Name        : 05.cpp
// Author      : Ivy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Triangle.h"
using namespace std;

int main() {

	Triangle *tr = new Triangle(1,2,3,4);
	cout << *tr << endl;

	return 0;
}
