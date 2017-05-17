/*
 * Operation.h
 *
 *  Created on: 10.05.2017 ã.
 *      Author: IVY
 */

#ifndef OPERATION_H_
#define OPERATION_H_
#include <vector>
#include <string>
#include <iostream>
#include <cstddef>
#include "Car.h"
using namespace std;

class Operation {
private:
	vector <Car*> cars;
public:
	Operation();
	virtual ~Operation();

	//methods
	virtual void print() const;
	void add(Car*);

	//setters & getters
	const vector<Car*>& getCars() const;
	void setCars(const vector<Car*>& cars);
};

#endif /* OPERATION_H_ */
