/*
 * Start.h
 *
 *  Created on: 9.05.2017 ã.
 *      Author: IVY
 */

#ifndef START_H_
#define START_H_
#include <iostream>
#include <vector>
#include "Athletes.h"
#include "Date.h"
#include "Time.h"
#include "Disciplines.h"
using namespace std;

	enum TYPE {qualification, quarterfinal, semiFinal, final};

class Start {
private:
	TYPE compStart;
	vector <Athletes*> athletes;
	Date date;
	Time time;
	Disciplines discp;

public:
	//Start();
	Start(Date&, Time&, Disciplines&, vector <Athletes*>&, TYPE);
	virtual ~Start();

	//setters & getters
	const vector<Athletes*>& getAthletes() const;
	void setAthletes(const vector<Athletes*>& athletes);

	TYPE getCompStart() const;
	void setCompStart(TYPE compStart);

	const Date& getDate() const;
	void setDate(const Date& date);

	const vector<Disciplines*>& getDisciplines() const;
	void setDisciplines(const vector<Disciplines*>& disciplines);

	const Time& getTime() const;
	void setTime(const Time& time);

	// methods
	vector<Athletes*>& calculateRanking() const;
};

#endif /* START_H_ */
