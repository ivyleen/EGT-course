/*
 * Racio.h
 *
 *  Created on: 5.05.2017 ã.
 *      Author: IVY
 */

#ifndef RACIO_H_
#define RACIO_H_
#include <iostream>
#include <cmath>
using namespace std;

class Racio {

	friend ostream& operator<<(ostream& output, Racio& racio);
	friend istream& operator>>(istream& input, Racio& racio);

private:
	double real;
	double img;

public:
	Racio();
	Racio(double, double);
	virtual ~Racio();

	Racio& operator+(Racio&);
	Racio& operator-(Racio&);
	Racio& operator*(Racio&);
	Racio& operator/(Racio&);
	bool operator==(Racio&);

	double getImg() const;
	void setImg(double img);

	double getReal() const;
	void setReal(double real);
};

#endif /* RACIO_H_ */
