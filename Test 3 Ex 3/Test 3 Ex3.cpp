//============================================================================
// Name        : Test.cpp
// Author      : Ivy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Operation.h"
#include "Family.h"
#include "Lux.h"
using namespace std;

int main() {

	Operation op;
	Lux * lux = new Lux();
	Family * family = new Family();
	Family * family2 = new Family();
	op.add(family);
	op.add(family2);
	op.add(lux);
	op.print();

	return 0;
}
