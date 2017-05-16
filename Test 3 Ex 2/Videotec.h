/*
 * Videotec.h
 *
 *  Created on: 10.05.2017 ã.
 *      Author: IVY
 */

#ifndef VIDEOTEC_H_
#define VIDEOTEC_H_
#include "Director.h"
#include "Film.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Videotec {
private:
	vector <Film*> filmography;
	Film film;
public:
	Videotec();
	virtual ~Videotec();

	// methods
	void addFilm(Film*);
	bool searchIsThere(Film&,string) const;
	Film* searchByName(string) const;
	int howManyFilmsByType(TYPEOFFILM) const;
	void howManyFilms();

	// setters & getters
	const vector<Film*>& getFilmography() const;
	void setFilmography(const vector<Film*>& filmography);
};

#endif /* VIDEOTEC_H_ */
