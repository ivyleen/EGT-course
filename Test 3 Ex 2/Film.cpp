/*
 * Film.cpp
 *
 *  Created on: 10.05.2017 ã.
 *      Author: IVY
 */

#include "Film.h"

Film::Film() : director() {
	setNameOfFilm("NaN");
	setTypeOfFilm(comedy);
	setIsItFor18YoPeople(false);
	setId("0");
}

Film::Film(string nameOfFilm, TYPEOFFILM tYPEOFFILM,
		Director& director, bool isItFor18YOPeople,
		string id)
: director(director)
{
	setNameOfFilm(nameOfFilm);
	setTypeOfFilm(tYPEOFFILM);
	setIsItFor18YoPeople(isItFor18YOPeople);
	setId(id);
}


Film::~Film() {
	// TODO Auto-generated destructor stub
}

const Director& Film::getDirector() const {
	return director;
}

void Film::setDirector(const Director& director) {
	this->director = director;
}

const string& Film::getId() const {
	return id;
}

void Film::setId(const string& id) {
	this->id = id;
}

bool Film::isIsItFor18YoPeople() const {
	return isItFor18YOPeople;
}

void Film::setIsItFor18YoPeople(bool isItFor18YoPeople) {
	isItFor18YOPeople = isItFor18YoPeople;
}

const string& Film::getNameOfFilm() const {
	return nameOfFilm;
}

void Film::setNameOfFilm(const string& nameOfFilm) {
	this->nameOfFilm = nameOfFilm;
}

TYPEOFFILM Film::getTypeOfFilm() const {
	return typeOfFilm;
}

void Film::setTypeOfFilm(TYPEOFFILM typeOfFilm) {
	this->typeOfFilm = typeOfFilm;
}

//methods

void Film::showInfo() {
	director.print();
	cout << "ID: " << Film::id << endl <<
			"isItFor18YOPeople " << Film::isItFor18YOPeople << endl <<
			"nameOfFilm " << Film::nameOfFilm << endl <<
			"typeOfFilm" << Film::typeOfFilm << endl;
}
