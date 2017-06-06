/*
 * Screening.h
 *
 *  Created on: 3.06.2017 ã.
 *      Author: IVY
 */

#ifndef SCREENING_H_
#define SCREENING_H_
#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>
#include "Film.h"
#include "pugixml.hpp"
using namespace std;

typedef map<string, int> FilmToProfit;
typedef map<string, double> Profit;
typedef map<string, double> ScreeningToProfit;

class Screening
{
private:
	vector<Film> films;
public:
	Screening(const string &);
	virtual ~Screening();

	// methods
	void print() const;
	ScreeningToProfit screeningToMoney();




















	// additional methods
	double screeningIncome() const;
	double filmIncome(const string & nameOfFilm);
	FilmToProfit IncomeInFilm();

	template<typename Key, typename Value>
	bool isKeyInMap(map<Key, Value> &theMap,
			const Key &key);

	template<typename Key, typename Value>
	void putInMap(map<Key, Value> &theMap, const Key &key,
			const Value &val);

	template<typename Key, typename Value>
	Value &getFromMap(map<Key, Value> &theMap,
			const Key &key);

	template<typename Key, typename Value>
	void delKeyInMap(map<Key, Value> theMap,
			const Key &key);
};

#endif /* SCREENING_H_ */
