/*
 * Film.cpp
 *
 *  Created on: 3.06.2017 ã.
 *      Author: IVY
 */

#include "Film.h"

Film::Film() :
		filmName(), hall(), capacity(), soldTickets(), price() {
	// TODO Auto-generated constructor stub

}

Film::Film(string fileName, string hall, int idHall,
		int capacity, int soldTickets, double price) :
		filmName(fileName), hall(hall), idHall(idHall), capacity(
				capacity), soldTickets(soldTickets), price(
				price) {
}

Film::~Film() {
	// TODO Auto-generated destructor stub
}

int Film::getCapacity() const {
	return capacity;
}

const string& Film::getFilmName() const {
	return filmName;
}

const string& Film::getHall() const {
	return hall;
}

void Film::setHall(const string& hall) {
	this->hall = hall;
}

double Film::getPrice() const {
	return price;
}

void Film::setPrice(double price) {
	this->price = price;
}

int Film::getSoldTickets() const {
	return soldTickets;
}

void Film::setSoldTickets(int soldTickets) {
	this->soldTickets = soldTickets;
}

//methods

void Film::print() const {
	cout << "fileName " << filmName << endl
			<< "hall " << hall << endl
			<< "idHall " << idHall << endl
			<< "capacity "	<< capacity << endl
			<< "soldTickets " << soldTickets << endl
			<< "price " << price << endl;
}
