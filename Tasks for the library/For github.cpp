//============================================================================
// Name        : For.cpp
// Author      : Ivy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "Task1.h"
using namespace std;

int main() {

	Task1 t;
	string currency = t.format("usd",32);
	t.changeCurrency('$', currency);


	return 0;
}
