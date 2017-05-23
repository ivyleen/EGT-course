/*
 * Start.cpp
 *
 *  Created on: 9.05.2017 ã.
 *      Author: IVY
 */

#include "Start.h"
using namespace std;

/*
Start::Start() {
	// TODO Auto-generated constructor stub

}
*/

const vector<Athletes*>& Start::getAthletes() const {
	return athletes;
}

void Start::setAthletes(const vector<Athletes*>& athletes) {
	this->athletes = athletes;
}

TYPE Start::getCompStart() const {
	return compStart;
}

void Start::setCompStart(TYPE compStart) {
	this->compStart = compStart;
}

const Date& Start::getDate() const {
	return date;
}

void Start::setDate(const Date& date) {
	this->date = date;
}

const Time& Start::getTime() const {
	return time;
}

Start::Start(Date& d, Time& t, Disciplines& dn, vector <Athletes*>& athl, TYPE comp)
: date(d),
  time(t),
  discp(dn),
  athletes(athl),
  compStart(comp)
{

}

void Start::setTime(const Time& time) {
	this->time = time;
}

Start::~Start() {
	// TODO Auto-generated destructor stub
}
