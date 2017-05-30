/*
 * Task1.cpp
 *
 *  Created on: 30.05.2017 г.
 *      Author: IVY
 */

#include "Task1.h"

Task1::Task1() {
	// TODO Auto-generated constructor stub

}

double Task1::getCurrency() const {
	return currency;
}

void Task1::setCurrency(double currency) {
	this->currency = currency;
}

Task1::~Task1() {
	// TODO Auto-generated destructor stub
}

string Task1::format(string type, double currency) {
	string stringToReturn = "";

	cout << stringToReturn;
	ostringstream strs;
	strs << currency;
	stringToReturn = strs.str();

	if (type == "usd") {
		stringToReturn = "USD " + stringToReturn;
	}
	if (type == "euro") {
		stringToReturn = "EUR " + stringToReturn;

	}
	if (type == "pound") {
		stringToReturn = "UKP " + stringToReturn;

	}

	return stringToReturn;
}

string Task1::changeCurrency(const char wantedType,
		const string& crncy) {
	char type;
	double currency=0.0;
	string stringToReturn;

	istringstream iss(crncy);
	iss >> type >> currency;

	cout << type << endl;
	cout << currency << endl;

	if (type == wantedType) {
		cerr << "You want to convert same currency." << endl;
	} else {
		if (type == '$'){

		}
		if (type == 'E'){

		}
		if (type == 'U'){
			currency = currency*1.8;
		}
	}

	//return stringToReturn;
}

void Task1::printCurrency() {

}

string Task1::test() {
	string br = "test";
	return br;
}
