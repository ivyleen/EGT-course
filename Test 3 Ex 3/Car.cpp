/*
 * Car.cpp
 *
 *  Created on: 10.05.2017 ã.
 *      Author: IVY
 */

#include "Car.h"

Car::Car() {
	setBrand("Opel");
	setModel("Corsa");
	setColor("Green");
	setVin("SA0101PK");
	setFuelCost(0.0);
}

Car::Car(string brand, string model, string color, string vin,
		double fuelCost) {
	setBrand(brand);
	setModel(model);
	setColor(color);
	setVin(vin);
	setFuelCost(fuelCost);
}

Car::~Car() {
	// TODO Auto-generated destructor stub
}

const string& Car::getBrand() const {
	return brand;
}

void Car::setBrand(const string& brand) {
	this->brand = brand;
}

const string& Car::getColor() const {
	return color;
}

void Car::setColor(const string& color) {
	this->color = color;
}

double Car::getFuelCost() const {
	return fuelCost;
}

void Car::setFuelCost(double fuelCost) {
	this->fuelCost = fuelCost;
}

const string& Car::getModel() const {
	return model;
}

void Car::setModel(const string& model) {
	this->model = model;
}

const string& Car::getVin() const {
	return vin;
}

void Car::setVin(const string& vin) {
	this->vin = vin;
}

double Car::price() const {
	return 0;
}

void Car::print() {
	cout << "brand " << getBrand() << endl;
	cout << "model " << getModel() << endl;
	cout << "color " << getColor() << endl;
	cout << "vin " << getVin() << endl;
	cout << "fuelCost " << getFuelCost() << endl;
}
