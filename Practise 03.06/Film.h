/*
 * Film.h
 *
 *  Created on: 3.06.2017 ã.
 *      Author: IVY
 */

#ifndef FILM_H_
#define FILM_H_
#include <iostream>
using namespace std;

class Film {
private:
	string filmName;
	string hall;
	int idHall;
	int capacity;
	int soldTickets;
	double price;

public:
	Film();
	Film(string fileName, string hall, int idHall,
			int capacity, int soldTickets, double price);
	virtual ~Film();

	//setters & getters
	int getCapacity() const;

	const string& getFilmName() const;

	const string& getHall() const;
	void setHall(const string& hall);

	double getPrice() const;
	void setPrice(double price);

	int getSoldTickets() const;
	void setSoldTickets(int soldTickets);

	//methods
	void print() const;
};

#endif /* FILM_H_ */
