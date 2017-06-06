//============================================================================
// Name        : 06.cpp
// Author      : Ivy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include "Screening.h"
#include "CinemaOperations.h"
using namespace std;

typedef map<string, double> Profit;
typedef map<string, int> TypeToQuantity;
typedef map<string, double> ScreeningToProfit;

int main()
{

	Screening sc("Cinema1.xml");
	sc.print();
	double scIncome = sc.screeningIncome();
	cout << "All Film Income In Cinema 1: " << endl
			<< scIncome << "lv" << endl;

	cout << "___________________________________" << endl;
	cout << endl;

	vector<std::string> xmlFiles;
	xmlFiles.push_back("Cinema1.xml");
	xmlFiles.push_back("Cinema2.xml");
	xmlFiles.push_back("Cinema3.xml");
	CinemaOperations c(xmlFiles);
	c.print();

	/*	cout << "The most profitable cinema is: "
	 << c.mostProfitableCinema().first << endl <<
	 "with profit: "
	 << c.mostProfitableCinema().second << endl;

	 cout << endl;

	 cout << "The most profitable screening is: "
	 << c.mostProfitableScreening().first << endl <<
	 "with profit: "
	 << c.mostProfitableScreening().second << endl;

	 cout << endl;*/

	/*	FilmToProfit res = c.IncomeInFilms();

	 for (FilmToProfit::const_iterator itr = res.begin();
	 itr != res.end(); ++itr)
	 {
	 cout << itr->first << " " << itr->second << endl;
	 }*/

	cout << endl;

	ScreeningToProfit scr = sc.screeningToMoney();
	for (ScreeningToProfit::const_iterator itr =
			scr.begin(); itr != scr.end(); ++itr)
	{
		if (scr.empty())
		{
			cout << "Screen to Money is empty" << endl;
		} else
		{
			cout << itr->first << " " << itr->second
					<< endl;
		}
	}
	// KEY -> VALUE
	// is KEY in map
	// get VALUE for KEY
	// delete KEY from map

	return 0;
}
template<typename Key, typename Value>
bool isKeyInMap(map<Key, Value> &theMap, const Key &key)
{
	return theMap.find(key) != theMap.end();
}
template<typename Key, typename Value>
int getValueForKey(map<Key, Value> &theMap, const Key &key)
{
	return theMap.find(key)->second;
}
template<typename Key, typename Value>
void putInMap(map<Key, Value> &theMap, const Key &key,
		const Value &val)
{
	theMap[key] = val;
}
