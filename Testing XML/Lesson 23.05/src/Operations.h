/*
 * Operations.h
 *
 *  Created on: 23.05.2017 �.
 *      Author: IVY
 */

#ifndef OPERATIONS_H_
#define OPERATIONS_H_
#include <vector>
#include <iostream>
#include "pugixml.hpp"
#include "Book.h"
using namespace std;

class Operations {
private:
	vector<Book*> shelf;
	static bool isItCalled;
public:
	Operations();
	virtual ~Operations();

	// methods
	void traverse(const char*);
	void print();
	const Book& cheapest() const;
	const Book& theMostExpenesive() const;
	void printInFile(double) const;

	// setters & getters
	const vector<Book*>& getShelf() const;
	void setShelf(const vector<Book*>& shelf);
};

#endif /* OPERATIONS_H_ */
