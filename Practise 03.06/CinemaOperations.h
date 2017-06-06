/*
 * CinemaOperations.h
 *
 *  Created on: 3.06.2017 ã.
 *      Author: IVY
 */

#ifndef CINEMAOPERATIONS_H_
#define CINEMAOPERATIONS_H_
#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>
#include "Screening.h"
using namespace std;

typedef std::map<std::string, int> FilmToProfit;
typedef map<string, double> Profit;

class CinemaOperations
{
private:
	vector<Screening> sc;
public:
	CinemaOperations(vector<string> xmlFiles);
	virtual ~CinemaOperations();

	// methods
	Profit profitToFilm();
	pair<int, int> maxIncomeInCinema();
	void print() const;
	pair<int, int> maxIncomeInScreening();
	FilmToProfit IncomeInFilms();

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

#endif /* CINEMAOPERATIONS_H_ */
