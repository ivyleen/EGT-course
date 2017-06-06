/*
 * Screening.cpp
 *
 *  Created on: 3.06.2017 ã.
 *      Author: IVY
 */

#include "Screening.h"

Screening::Screening(const string & xmlFile)
{

	pugi::xml_document doc;

	if (!doc.load_file(xmlFile.c_str()))
	{
		cerr << "The xml file couldn't be opened." << endl;
		exit(1);
	}

	pugi::xml_node cinema = doc.child("cinema");

	for (pugi::xml_node screening = cinema.first_child();
			screening; screening = screening.next_sibling())
	{
		string fileName =
				screening.child("filmName").text().as_string();
		string hall =
				screening.child("hall").text().as_string();
		int idHall = screening.attribute("id").as_int();
		int capacity =
				screening.child("capacity").text().as_int();
		int soldTickets =
				screening.child("soldTickets").text().as_int();
		double price =
				screening.child("pricePerTicket").text().as_int();

		Film filmTemp(fileName, hall, idHall, capacity,
				soldTickets, price);
		films.push_back(filmTemp);

	}

}

ScreeningToProfit Screening::screeningToMoney()
{
	ScreeningToProfit res;
	for (int i = 0; i < (int) films.size(); ++i)
	{
		string screening = films[i].getHall();
		double money = films[i].getPrice()
				* films[i].getSoldTickets();
		for (ScreeningToProfit::iterator itr = res.begin();
				itr != res.end(); itr++)
		{
			if (isKeyInMap(res, screening))
			{
				putInMap(res, screening,
						getFromMap(res, screening) + money);
			} else
			{
				putInMap(res, screening, money);
			}
		}
	}
	return res;
}

Screening::~Screening()
{
	// TODO Auto-generated destructor stub
}

void Screening::print() const
{
	for (int i = 0; i < (int) films.size(); ++i)
	{
		cout << "Screening ¹ " << i << endl;
		films[i].print();
		cout << endl;
	}
}

double Screening::screeningIncome() const
{
	double income = 0.0;
	for (int i = 0; i < (int) films.size(); ++i)
	{
		income = income
				+ (films[i].getPrice()
						* films[i].getSoldTickets());
	}

	return income;
}

double Screening::filmIncome(const string& nameOfFilm)
{
	double income = 0.0;
	for (int i = 0; i < (int) films.size(); ++i)
	{
		if (films[i].getFilmName() == nameOfFilm)
		{
			income = films[i].getPrice()
					* films[i].getSoldTickets();
		}
	}
	return income;
}

FilmToProfit Screening::IncomeInFilm()
{
	FilmToProfit res;
	for (int i = 0; i < (int) films.size(); ++i)
	{
		string filmName = films[i].getFilmName();
		int income = films[i].getPrice()
				* films[i].getSoldTickets();
		if (isKeyInMap(res, filmName))
		{
			putInMap(res, filmName,
					getFromMap(res, filmName) + income);
		} else
		{
			putInMap(res, filmName, income);
		}
	}
	return res;
}

template<typename Key, typename Value>
bool Screening::isKeyInMap(map<Key, Value> &theMap,
		const Key &key)
{
	return theMap.find(key) != theMap.end();
}

template<typename Key, typename Value>
Value &Screening::getFromMap(map<Key, Value> &theMap,
		const Key &key)
{
	return theMap.find(key)->second;
}

template<typename Key, typename Value>
void Screening::putInMap(map<Key, Value> &theMap,
		const Key &key, const Value &val)
{
	theMap[key] = val;
	// theMap.insert(make_pair(key, val));
}

template<typename Key, typename Value>
void Screening::delKeyInMap(map<Key, Value> theMap,
		const Key &key)
{
	theMap.erase(theMap.find(key));
}
