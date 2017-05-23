/*
 * Disciplines.cpp
 *
 *  Created on: 9.05.2017 ã.
 *      Author: IVY
 */

#include "Disciplines.h"

Disciplines::Disciplines() {
	setName("NaN");
	setWorldRecord(0.0);
	setRecordOfCompetition(0.0);
}

const std::string& Disciplines::getName() const {
	return name;
}

void Disciplines::setName(const std::string& name) {
	this->name = name;
}

double Disciplines::getRecordOfCompetition() const {
	return recordOfCompetition;
}

void Disciplines::setRecordOfCompetition(double recordOfCompetition) {
	if ( recordOfCompetition < 0 ) {
		recordOfCompetition = 0;
	}
	this->recordOfCompetition = recordOfCompetition;
}

double Disciplines::getWorldRecord() const {
	return worldRecord;
}

Disciplines::Disciplines(std::string name, double worldRecord,
		double recordOfCompetition) {
	setName(name);
	setWorldRecord(worldRecord);
	setRecordOfCompetition(recordOfCompetition);
}

void Disciplines::setWorldRecord(double worldRecord) {
	this->worldRecord = worldRecord;
}

Disciplines::~Disciplines() {
	// TODO Auto-generated destructor stub
}

