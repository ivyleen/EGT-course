/*
 * Triangle.cpp
 *
 *  Created on: 16.05.2017 ã.
 *      Author: IVY
 */

#include "Triangle.h"
#include <iomanip>
#include <iostream>
using namespace std;

Triangle::Triangle() {
	setA(0);
	setB(0);
	setC(0);
	setH(0);
}

Triangle::Triangle(int a, int b, int c, int h) {
	setA(a);
	setB(b);
	setC(c);
	setH(h);
}

Triangle::~Triangle() {
	// TODO Auto-generated destructor stub
}

// setters & getters
int Triangle::getA() const {
	return a;
}

void Triangle::setA(int a) {
	this->a = a;
}

int Triangle::getB() const {
	return b;
}

void Triangle::setB(int b) {
	this->b = b;
}

int Triangle::getC() const {
	return c;
}

void Triangle::setC(int c) {
	this->c = c;
}

int Triangle::getH() const {
	return h;
}

void Triangle::setH(int h) {
	this->h = h;
}

// methods

istream &operator>>(istream & input, Triangle & triangle) {
	// type -a-b-c-h
	input.ignore(1);
	cout << "A: " << endl;
	input >> setw(1) >> triangle.a;
	input.ignore(1);
	cout << "B: " << endl;
	input >> setw(1) >> triangle.b;
	input.ignore(1);
	cout << "C: " << endl;
	input >> setw(1) >> triangle.c;
	input.ignore(1);
	cout << "H: " << endl;
	input >> setw(1) >> triangle.h;

	return input;
}

ostream &operator<<(ostream & output, const Triangle & triangle) {

	output << "=> a: " << triangle.a << " - b: " << triangle.b << " - c: "
			<< triangle.c << " - h: " << triangle.h << endl;

	return output;
}

bool Triangle::operator !=(Triangle& triangle) {
	if (triangle.a == this->a && triangle.b == this->b && triangle.c == this->c
			&& triangle.h == this->h) {
		return false;
	}

	return true;
}

bool Triangle::operator ==(Triangle& triangle) {
	if (triangle.a == this->a && triangle.b == this->b && triangle.c == this->c
			&& triangle.h == this->h) {
		return true;
	}

	return false;
}
