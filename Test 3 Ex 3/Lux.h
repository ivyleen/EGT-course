/*
 * Lux.h
 *
 *  Created on: 10.05.2017 ã.
 *      Author: IVY
 */

#ifndef LUX_H_
#define LUX_H_

#include "Car.h"

enum TAXExtra {chocolate = 40, wine = 50, champagne=100};

class Lux: public Car {
private:
	double taxOfUse;
	double roadKm;
	TAXExtra taxExtra;
public:
	Lux();
	Lux(string,string,string,string, double,double, double,TAXExtra);
	virtual ~Lux();

	// setters & getters
	double getRoadKm() const;
	void setRoadKm(double roadKm);

	double getTaxOfUse() const;
	void setTaxOfUse(double taxOfUse);

	TAXExtra getTaxExtra() const;
	void setTaxExtra(TAXExtra taxExtra);

	//methods
	virtual double price()const;
	virtual void print();
};

#endif /* LUX_H_ */
