/*
 * Disciplines.h
 *
 *  Created on: 9.05.2017 ã.
 *      Author: IVY
 */

#ifndef DISCIPLINES_H_
#define DISCIPLINES_H_
#include <iostream>

class Disciplines {

private:
	std::string name;
	double worldRecord;
	double recordOfCompetition;

public:
	Disciplines();
	Disciplines(std::string, double, double);
	virtual ~Disciplines();

	// getters & setters
	const std::string& getName() const;
	void setName(const std::string& name);

	double getRecordOfCompetition() const;
	void setRecordOfCompetition(double recordOfCompetition);

	double getWorldRecord() const;
	void setWorldRecord(double worldRecord);

};

#endif /* DISCIPLINES_H_ */
