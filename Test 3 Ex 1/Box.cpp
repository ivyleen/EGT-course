/*
 * Box.cpp
 *
 *  Created on: 10.05.2017 ã.
 *      Author: IVY
 */

#include "Box.h"
#include <iostream>
#include <iomanip>
using namespace std;

Box::Box() {
	setLength(100);
	setHight(100);
	setWide(100);
}

Box::Box(int length, int wide, int hight) {
	setLength(length);
	setWide(wide);
	setHight(hight);
}


int Box::getHight() const {
	return hight;
}

void Box::setHight(int hight) {
	if (hight < 100 || hight > 999){
		cout << "You need to enter a new value for high:" << endl;
		cin >> hight;
	}
	this->hight = hight;
}

int Box::getLength() const {
	return length;
}

void Box::setLength(int length) {
	if (length < 100 || length > 999){
		cout << "You need to enter a new value for length:" <<endl;
		cin >> length;
	}
	this->length = length;
}

int Box::getWide() const {
	return wide;
}

void Box::setWide(int wide) {
	if (wide < 100 || wide > 999){
		cout << "You need to enter a new value for wide:" << endl;
		cin >> wide;
	}
	this->wide = wide;
}

Box::~Box() {
	// TODO Auto-generated destructor stub
}

// overloading operators

istream &operator>>(istream & input, Box & box){
	// type 1,1,1
	cout << "Hight: " << endl;
	input >> setw(1) >> box.hight;
	input.ignore(1);
	cout << "Length: " << endl;
	input >> setw(1) >> box.length;
	input.ignore(1);
	cout << "Wide: " << endl;
	input >> setw(1) >> box.wide;
	return input;
}


ostream &operator<<(ostream & output, const Box & box){

	output << "High: "<< box.hight << endl
			<< "Length: " << box.length << endl
			<< "Wide: " << box.wide << endl;
	return output;
}

int Box::obem() const {
	return hight * length * wide;
}

Box& Box::operator +(Box& newBox) {

	int newLength = this->length + newBox.length;
	int newHight = this->hight + newBox.hight;
	int newWide = this ->wide + newBox.wide;

	Box *addedBox = new Box(newLength, newHight, newWide);

	return *addedBox;
}

bool Box::operator !=(Box& newBox) {
	if ( newBox.hight == this->hight &&
			newBox.length == this->length &&
			newBox.wide == this->wide){
		return true;
	}

	return false;
}

bool Box::operator >(Box& newBox) {
	if (this->hight > newBox.hight &&
			this->length > newBox.length &&
			this->wide > newBox.wide){
		return true;
	}
	return false;
}
