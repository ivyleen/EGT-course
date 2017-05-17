/*
 * Family.cpp
 *
 *  Created on: 10.05.2017 ã.
 *      Author: IVY
 */

#include "Family.h"

Family::Family() : Car() {
	setTaxOfUse(1.0);
	setRoadKm(1.0);
}


Family::Family(string brand, string model, string color, string vin,
	double fuelCost, double taxOfUse, double roadKm) :
	Car(brand, model, color, vin, fuelCost) {
setTaxOfUse(taxOfUse);
setRoadKm(roadKm);
}

double Family::getRoadKm() const {
return roadKm;
}

void Family::setRoadKm(double roadKm) {
this->roadKm = roadKm;
}

double Family::getTaxOfUse() const {
return taxOfUse;
}

void Family::setTaxOfUse(double taxOfUse) {
this->taxOfUse = taxOfUse;
}

Family::~Family() {
// TODO Auto-generated destructor stub
}

double Family::price() const {
	double koef =0.0;
	if (getRoadKm() < 500) {
		koef = 0.7;
	} else {
		koef = 0.4;
	}
	return taxOfUse * koef;
}

void Family::print() {
	Car::print();
	cout << "taxOfUse " << taxOfUse << endl;
	cout << "roadKm " <<  roadKm << endl;
}
