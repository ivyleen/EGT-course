/*
 * Athletes.h
 *
 *  Created on: 9.05.2017 ã.
 *      Author: IVY
 */

#ifndef ATHLETES_H_
#define ATHLETES_H_
#include <iostream>

class Athletes {
private:
	std::string firstName;
	std::string lastName;
	double best;
	std::string nacionality;

public:
	Athletes();
	Athletes(std::string, std::string, double, std::string);
	virtual ~Athletes();

	double getBest() const;
	void setBest(double best);

	const std::string& getFirstName() const;
	void setFirstName(const std::string& firstName);

	const std::string& getLastName() const;
	void setLastName(const std::string& lastName);

	const std::string& getNacionality() const;
	void setNacionality(const std::string& nacionality);
};

#endif /* ATHLETES_H_ */
