/*
 * Lux.cpp
 *
 *  Created on: 10.05.2017 ã.
 *      Author: IVY
 */

#include "Lux.h"

Lux::Lux() :
		Car() {
	setTaxOfUse(1.0);
	setRoadKm(1.0);
	setTaxExtra(chocolate);
}

Lux::Lux(string brand, string model, string color, string vin, double fuelCost,
		double taxOfUse, double roadKm, TAXExtra taxExtra) :
		Car(brand, model, color, vin, fuelCost) {
	setTaxOfUse(taxOfUse);
	setRoadKm(roadKm);
	setTaxExtra(taxExtra);
}

double Lux::getRoadKm() const {
	return roadKm;
}

void Lux::setRoadKm(double roadKm) {
	this->roadKm = roadKm;
}

double Lux::getTaxOfUse() const {
	return taxOfUse;
}

void Lux::setTaxOfUse(double taxOfUse) {
	this->taxOfUse = taxOfUse;
}

Lux::~Lux() {
	// TODO Auto-generated destructor stub
}

TAXExtra Lux::getTaxExtra() const {
	return taxExtra;
}

void Lux::setTaxExtra(TAXExtra taxExtra) {
	this->taxExtra = taxExtra;
}

double Lux::price() const {
	double koef = 0.0;
	if (getRoadKm() < 200) {
		koef = 0.6;
	} else {
		koef = 0.4;
	}
	return taxOfUse * koef * taxExtra;
}

void Lux::print() {
	Car::print();
	cout << "taxOfUse " << getTaxOfUse() << endl;
	cout << "taxExtra " << getTaxExtra()<< endl;
	cout << "RoadKm " << getRoadKm() << endl;
}
