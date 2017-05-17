/*
 * Car.h
 *
 *  Created on: 10.05.2017 ã.
 *      Author: IVY
 */

#ifndef CAR_H_
#define CAR_H_
#include <iostream>
#include <string>
using namespace std;

class Car {
private:
	string brand;
	string model;
	string color;
	string vin;
	double fuelCost;
public:
	Car();
	Car(string,string,string,string, double);
	virtual ~Car();

	//setters & getters
	const string& getBrand() const;
	void setBrand(const string& brand);

	const string& getColor() const;
	void setColor(const string& color);

	double getFuelCost() const;
	void setFuelCost(double fuelCost);

	const string& getModel() const;
	void setModel(const string& model);

	const string& getVin() const;
	void setVin(const string& vin);

	//methods
	virtual double price()const;
	virtual void print();
};

#endif /* CAR_H_ */
