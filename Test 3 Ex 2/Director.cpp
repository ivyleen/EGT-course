/*
 * Director.cpp
 *
 *  Created on: 10.05.2017 ã.
 *      Author: IVY
 */

#include "Director.h"

Director::Director() {
	setFirstName("John");
	setLastName("Doe");
	setRating(0.0);
}

Director::Director(string firstName, string lastName, double rating) {
	setFirstName(firstName);
	setLastName(lastName);
	setRating(rating);
}

const string& Director::getFirstName() const {
	return firstName;
}

void Director::setFirstName(const string& firstName) {
	this->firstName = firstName;
}

const string& Director::getLastName() const {
	return lastName;
}

void Director::setLastName(const string& lastName) {
	this->lastName = lastName;
}

double Director::getRating() const {
	return rating;
}

void Director::setRating(double rating) {
	this->rating = rating;
}

Director::~Director() {
	// TODO Auto-generated destructor stub
}

void Director::print() const {
	cout << "First name: " << getFirstName() << endl <<
			"Last name: " << getLastName() << endl <<
			"Rating: " << getRating() << endl;
}
