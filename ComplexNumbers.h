/*
 * Racio.h
 *
 *  Created on: 5.05.2017 ã.
 *      Author: IVY
 */

#ifndef COMPLEXNUMBERS_H_
#define COMPLEXNUMBERS_H_
#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumbers {

	friend ostream& operator<<(ostream& output, ComplexNumbers& racio);
	friend istream& operator>>(istream& input, ComplexNumbers& racio);

private:
	double real;
	double img;

public:
	ComplexNumbers();
	ComplexNumbers(double, double);
	virtual ~ComplexNumbers();

	ComplexNumbers& operator+(ComplexNumbers&);
	ComplexNumbers& operator-(ComplexNumbers&);
	ComplexNumbers& operator*(ComplexNumbers&);
	ComplexNumbers& operator/(ComplexNumbers&);
	bool operator==(ComplexNumbers&);

	double getImg() const;
	void setImg(double img);

	double getReal() const;
	void setReal(double real);
};

#endif /* COMPLEXNUMBERS_H_ */
