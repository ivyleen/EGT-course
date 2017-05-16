/*
 * Director.h
 *
 *  Created on: 10.05.2017 ã.
 *      Author: IVY
 */

#ifndef DIRECTOR_H_
#define DIRECTOR_H_
#include <string>
#include <iostream>
using namespace std;

class Director {
private:
	string firstName;
	string lastName;
	double rating;
public:
	Director();
	Director(string,string,double);
	virtual ~Director();

	//getters & setters
	const string& getFirstName() const;
	void setFirstName(const string& firstName);

	const string& getLastName() const;
	void setLastName(const string& lastName);

	double getRating() const;
	void setRating(double rating);

	//methods
	void print() const;
};

#endif /* DIRECTOR_H_ */
