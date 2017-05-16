/*
 * Film.h
 *
 *  Created on: 10.05.2017 ã.
 *      Author: IVY
 */

#ifndef FILM_H_
#define FILM_H_
#include "Director.h"
#include <string>
#include <iostream>
using namespace std;

enum TYPEOFFILM {comedy, action, drama, triler, documentary};

class Film {
private:
	string nameOfFilm;
	TYPEOFFILM typeOfFilm;
	Director director;
	bool isItFor18YOPeople;
	string id;

public:
	Film();
	Film(string, TYPEOFFILM, Director&, bool, string);
	virtual ~Film();

	// getters & setters
	const Director& getDirector() const;
	void setDirector(const Director& director);

	const string& getId() const;
	void setId(const string& id);

	bool isIsItFor18YoPeople() const;
	void setIsItFor18YoPeople(bool isItFor18YoPeople);

	const string& getNameOfFilm() const;
	void setNameOfFilm(const string& nameOfFilm);

	void setTypeOfFilm(TYPEOFFILM typeOfFilm);
	TYPEOFFILM getTypeOfFilm() const;

	// methods
	void showInfo();
};

#endif /* FILM_H_ */
