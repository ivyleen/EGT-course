/*
 * Operations.h
 *
 *  Created on: 9.05.2017 ã.
 *      Author: IVY
 */

#ifndef OPERATIONS_H_
#define OPERATIONS_H_
#include <iostream>
#include "Athletes.h"
#include "Date.h"
#include "Time.h"
#include "Disciplines.h"
#include "Start.h"
using namespace std;

class Operations {
private:
	TYPE typeOfComp;
	vector <Athletes*> athlet;
	vector <Disciplines*> discipl;

public:
	Operations();
	virtual ~Operations();

	// methods
	vector<Athletes*>& calculateRanking() const;
};

#endif /* OPERATIONS_H_ */
