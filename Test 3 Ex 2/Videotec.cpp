/*
 * Videotec.cpp
 *
 *  Created on: 10.05.2017 г.
 *      Author: IVY
 */

#include "Videotec.h"
#include <cstddef>
#include <iostream>
using namespace std;

Videotec::Videotec() {

}

Videotec::~Videotec() {
	// TODO Auto-generated destructor stub
}

// methods

void Videotec::addFilm(Film* add) {
	// ако няма нищо във вектора, трябва да има един if (filmography.size()==0)[
	// push.back
	for (unsigned int i = 0; i < filmography.size(); i++) {
		if (filmography[i]->getId() == add->getId()) {
			return;
		}
	}
	filmography.push_back(add);
}

bool Videotec::searchIsThere(Film&, string id) const {
	bool correct = false;
	for (unsigned int i = 0; i < filmography.size(); i++) {
		if (filmography[i]->getId() == id) {
			correct = true;
		}
	}
	return correct;
}

Film* Videotec::searchByName(string name) const {
	for (unsigned int i = 0; i < filmography.size(); i++) {
		if (filmography[i]->getNameOfFilm() == name) {
			return filmography[i];
		}
	}

	return 0;
}

int Videotec::howManyFilmsByType(TYPEOFFILM type) const {
	int count = 0;
	for (unsigned int i = 0; i < filmography.size(); i++) {
		if (filmography[i]->getTypeOfFilm() == type) {
			count++;
		}
	}
	return count;
}


void Videotec::howManyFilms() {
	//for ( unsigned int i = 0; i < filmography.size(); i++){
	cout << "action " << howManyFilmsByType(action) << endl;
	cout << "drama " << howManyFilmsByType(drama) << endl;
	cout << "comedy " << howManyFilmsByType(comedy) << endl;
	cout << "triler " << howManyFilmsByType(triler) << endl;
	cout << "documentary " << howManyFilmsByType(documentary) << endl;
	//}
}


// setters & getters

const vector<Film*>& Videotec::getFilmography() const {
	return filmography;
}

void Videotec::setFilmography(const vector<Film*>& filmography) {
	this->filmography = filmography;
}
