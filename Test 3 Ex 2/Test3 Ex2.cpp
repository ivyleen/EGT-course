//============================================================================
// Name        : Test3.cpp
// Author      : Ivy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Director.h"
#include "Videotec.h"
#include "Film.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstddef>
using namespace std;


int main() {
	Director * firstDirector = new Director("Kenneth"," Branagh", 4.6);
	Film * firstFilm = new Film("Thor", action, *firstDirector, 0 ,"1A");
	Film * secondFilm = new Film("Macbeth", drama, *firstDirector, 0 ,"2B");

	Videotec* video = new Videotec();
	video->addFilm(firstFilm);
	video->addFilm(secondFilm);


	Film * thirdFilm;
	if (!(video->searchByName("Thor") == 0)){
		thirdFilm = new Film(*(video->searchByName("Thor")));
	}
	thirdFilm->showInfo();

	cout << endl;

	video->howManyFilmsByType(action);
	cout<<endl;
	video->howManyFilms();

	cout << "Is there a film " <<video->searchIsThere(*firstFilm, "1A");


	return 0;
}
