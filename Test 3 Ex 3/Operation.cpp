/*
 * Operation.cpp
 *
 *  Created on: 10.05.2017 ã.
 *      Author: IVY
 */

#include "Operation.h"
#include "Family.h"
#include "Lux.h"
#include <iostream>
using namespace std;

Operation::Operation() {
	// TODO Auto-generated constructor stub

}

Operation::~Operation() {
	// TODO Auto-generated destructor stub
}

const vector<Car*>& Operation::getCars() const {
	return cars;
}

void Operation::add(Car* add) {
	cars.push_back(add);
}

void Operation::setCars(const vector<Car*>& cars) {
	this->cars = cars;
}

void Operation::print() const {

	for (unsigned int i = 0; i < cars.size(); i++) {
		cars[i]->print();
		if (Lux* ptr = dynamic_cast<Lux*>(cars[i])) {
			cout << "TaxExtra: " << ptr->getTaxExtra();

		}
		cout << endl;
	}
}
