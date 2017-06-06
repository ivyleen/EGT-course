/*
 * CinemaOperations.cpp
 *
 *  Created on: 3.06.2017 ã.
 *      Author: IVY
 */

#include "CinemaOperations.h"

CinemaOperations::~CinemaOperations()
{
	// TODO Auto-generated destructor stub
}

CinemaOperations::CinemaOperations(vector<string> xmlFiles)
{
	for (int i = 0; i < (int) xmlFiles.size(); ++i)
	{
		sc.push_back(Screening(xmlFiles[i]));
	}
}

pair<int, int> CinemaOperations::maxIncomeInCinema()
{
	double maxIncome = 0.0;
	int cinema = 0;
	for (int i = 0; i < (int) sc.size(); ++i)
	{
		if (maxIncome < sc[i].screeningIncome())
		{
			maxIncome = sc[i].screeningIncome();
			cinema++;
		}
	}
	return make_pair(cinema, maxIncome);
}

Profit CinemaOperations::profitToFilm()
{

	Profit res;
	/*	for (int i = 0; i < (int) sc.size(); ++i)
	 {
	 Profit screening = sc[i].screeningIncome();
	 for (Profit::const_iterator it = screening.begin();
	 it != screening.end(); ++it)
	 {
	 string filmName = it->first;
	 int profit = it->second;

	 if (isKeyInMap(res, filmName))
	 {
	 putInMap(res, filmName,
	 getFromMap(res, filmName) + profit);
	 } else
	 {
	 putInMap(res, filmName, profit);
	 }

	 }
	 }*/
	return res;
}

void CinemaOperations::print() const
{
	for (int i = 0; i < (int) sc.size(); ++i)
	{
		cout << "---------------------" << endl;
		cout << "Cinema " << i << endl;
		sc[i].print();
	}
}

pair<int, int> CinemaOperations::maxIncomeInScreening()
{
	int screening = -1;
	int mostProfit = 0;
	for (int i = 0; i < (int) sc.size(); ++i)
	{
		if (mostProfit < sc[i].screeningIncome())
		{
			mostProfit = sc[i].screeningIncome();
			screening = i;
		}
	}
	return make_pair(screening, mostProfit);
}

FilmToProfit CinemaOperations::IncomeInFilms()
{
	FilmToProfit res;
	for (int i = 0; i < (int) sc.size(); ++i)
	{
		FilmToProfit temp = sc[i].IncomeInFilm();
		for (FilmToProfit::const_iterator itr =
				temp.begin(); itr != temp.end(); ++itr)
		{
			string filmName = itr->first;
			int income = itr->second;

			if (isKeyInMap(res, filmName))
			{
				putInMap(res, filmName,
						getFromMap(res, filmName)
								+ income);
			} else
			{
				putInMap(res, filmName, income);
			}
		}

	}
	return res;
}

template<typename Key, typename Value>
bool CinemaOperations::isKeyInMap(map<Key, Value> &theMap,
		const Key &key)
{
	return theMap.find(key) != theMap.end();
}

template<typename Key, typename Value>
Value &CinemaOperations::getFromMap(map<Key, Value> &theMap,
		const Key &key)
{
	return theMap.find(key)->second;
}

template<typename Key, typename Value>
void CinemaOperations::putInMap(map<Key, Value> &theMap,
		const Key &key, const Value &val)
{
	theMap[key] = val;
	// theMap.insert(make_pair(key, val));
}

template<typename Key, typename Value>
void CinemaOperations::delKeyInMap(map<Key, Value> theMap,
		const Key &key)
{
	theMap.erase(theMap.find(key));
}

