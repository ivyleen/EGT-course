/*
 * Task1.h
 *
 *  Created on: 30.05.2017 ã.
 *      Author: IVY
 */

#ifndef TASK1_H_
#define TASK1_H_
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Task1 {
private:
	double currency;

public:
	Task1();
	virtual ~Task1();

	// setters & getters
	double getCurrency() const;
	void setCurrency(double currency);

	// methods
	string changeCurrency(const char wantedType,
			const string& crncy);
	string format(string, double);
	void printCurrency();
	string test();
};

#endif /* TASK1_H_ */
