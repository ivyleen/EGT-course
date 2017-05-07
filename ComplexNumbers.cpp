/*
 * Racio.cpp
 *
 *  Created on: 5.05.2017 ã.
 *      Author: IVY
 */

#include "ComplexNumbers.h"

#include <iostream>
#include <cmath>
using namespace std;

ComplexNumbers::ComplexNumbers() {
	setReal(0.0);
	setImg(0.0);
}

ComplexNumbers::ComplexNumbers(double real, double img) {
	setReal(real);
	setImg(img);
}

ComplexNumbers::~ComplexNumbers() {
}

ComplexNumbers& ComplexNumbers::operator +(ComplexNumbers& newR) {

	double newReal = this->real + newR.real;
	double newImg = this->img + newR.img;

	ComplexNumbers *added = new ComplexNumbers(newReal, newImg);

	return *added;
}

ComplexNumbers& ComplexNumbers::operator -(ComplexNumbers& newR) {

	double newReal = this->real - newR.real;
	double newImg = this->img - newR.img;

	ComplexNumbers *added = new ComplexNumbers(newReal, newImg);

	return *added;
}

ComplexNumbers& ComplexNumbers::operator *(ComplexNumbers& newR) {

	double newReal = (this->real * newR.real) - (this->img * newR.img);
	double newImg = (this->real * newR.img) + (this->img * newR.real);

	ComplexNumbers *added = new ComplexNumbers(newReal, newImg);

	return *added;
}

ComplexNumbers& ComplexNumbers::operator /(ComplexNumbers& newR) {

	double newReal = ((this->real * newR.real) + (this->img * newR.img))
			/ pow(newR.real, 2) + pow(newR.img, 2);
	double newImg = ((this->img * newR.real) - (this->real * newR.img))
		/ pow(newR.real, 2) + pow(newR.img, 2);

	ComplexNumbers *added = new ComplexNumbers(newReal, newImg);

	return *added;
}

bool ComplexNumbers::operator ==(ComplexNumbers& newR) {

	if (this->real == newR.real && this->img == newR.img){
		return true;
	}

	return false;
}

ostream& operator <<(ostream& output, ComplexNumbers& newR) {
	output << newR.getReal() << ", " << newR.getImg();

	return output;
}

istream& operator >>(istream& input, ComplexNumbers& newR) {
	input >> newR.real;
	input.ignore(2);
	input >> newR.img;

	return input;
}

double ComplexNumbers::getImg() const {
	return img;
}

void ComplexNumbers::setImg(double img) {
	this->img = img;
}

double ComplexNumbers::getReal() const {
	return real;
}

void ComplexNumbers::setReal(double real) {
	this->real = real;
}
