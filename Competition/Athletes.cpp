/*
 * Athletes.cpp
 *
 *  Created on: 9.05.2017 ã.
 *      Author: IVY
 */

#include "Athletes.h"

Athletes::Athletes() {
	setFirstName("John");
	setLastName("Doe");
	setBest(0.0);
	setNacionality("Planet Earth");
}

Athletes::Athletes(std::string firstName, std::string lastName, double best,
		std::string nacionality) {
	setFirstName(firstName);
	setLastName(lastName);
	setBest(best);
	setNacionality(nacionality);
}

double Athletes::getBest() const {
	return best;
}

void Athletes::setBest(double best) {
	if ( best < 0){
		best = 0;
	}
	this->best = best;
}

const std::string& Athletes::getFirstName() const {
	return firstName;
}

void Athletes::setFirstName(const std::string& firstName) {
	this->firstName = firstName;
}

const std::string& Athletes::getLastName() const {
	return lastName;
}

void Athletes::setLastName(const std::string& lastName) {
	this->lastName = lastName;
}

const std::string& Athletes::getNacionality() const {
	return nacionality;
}

void Athletes::setNacionality(const std::string& nacionality) {
	this->nacionality = nacionality;
}

Athletes::~Athletes() {
	// TODO Auto-generated destructor stub
}

