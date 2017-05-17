/*
 * Family.h
 *
 *  Created on: 10.05.2017 ã.
 *      Author: IVY
 */

#ifndef FAMILY_H_
#define FAMILY_H_
#include <iostream>
#include <string>
using namespace std;

#include "Car.h"

class Family: public Car {
private:
	double taxOfUse;
	double roadKm;
public:
	Family();
	Family(string,string,string,string, double,double, double);
	virtual ~Family();

	//setters & getters
	double getRoadKm() const;
	void setRoadKm(double roadKm);

	double getTaxOfUse() const;
	void setTaxOfUse(double taxOfUse);

	//methods
	virtual double price()const;
	virtual void print();
};

#endif /* FAMILY_H_ */
