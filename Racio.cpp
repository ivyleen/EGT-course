/*
 * Racio.cpp
 *
 *  Created on: 5.05.2017 ã.
 *      Author: IVY
 */

#include "Racio.h"
#include <iostream>
#include <cmath>
using namespace std;

Racio::Racio() {
	setReal(0.0);
	setImg(0.0);
}

Racio::Racio(double real, double img) {
	setReal(real);
	setImg(img);
}

Racio::~Racio() {
}

Racio& Racio::operator +(Racio& newR) {

	double newReal = this->real + newR.real;
	double newImg = this->img + newR.img;

	Racio *added = new Racio(newReal, newImg);

	return *added;
}

Racio& Racio::operator -(Racio& newR) {

	double newReal = this->real - newR.real;
	double newImg = this->img - newR.img;

	Racio *added = new Racio(newReal, newImg);

	return *added;
}

Racio& Racio::operator *(Racio& newR) {

	double newReal = (this->real * newR.real) - (this->img * newR.img);
	double newImg = (this->real * newR.img) + (this->img * newR.real);

	Racio *added = new Racio(newReal, newImg);

	return *added;
}

Racio& Racio::operator /(Racio& newR) {

	double newReal = ((this->real * newR.real) + (this->img * newR.img))
			/ pow(newR.real, 2) + pow(newR.img, 2);
	double newImg = ((this->img * newR.real) - (this->real * newR.img))
		/ pow(newR.real, 2) + pow(newR.img, 2);

	Racio *added = new Racio(newReal, newImg);

	return *added;
}

bool Racio::operator ==(Racio& newR) {

	if (this->real == newR.real && this->img == newR.img){
		return true;
	}

	return false;
}

ostream& operator <<(ostream& output, Racio& newR) {
	output << newR.getReal() << ", " << newR.getImg();

	return output;
}

istream& operator >>(istream& input, Racio& newR) {
	input >> newR.real;
	input.ignore(2);
	input >> newR.img;

	return input;
}

double Racio::getImg() const {
	return img;
}

void Racio::setImg(double img) {
	this->img = img;
}

double Racio::getReal() const {
	return real;
}

void Racio::setReal(double real) {
	this->real = real;
}
