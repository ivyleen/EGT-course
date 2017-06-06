//============================================================================
// Name        : 06.cpp
// Author      : Ivy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{

	/*	string text =
	 "Here in Sofia we are here in Sofia Sofia is the capital.";
	 //not in map => word 1
	 // in map => get value(word)++

	 vector<string> words;
	 words.push_back("Here");
	 words.push_back("in");
	 words.push_back("Sofia");
	 words.push_back("we");
	 words.push_back("are");
	 words.push_back("here");
	 words.push_back("in");
	 words.push_back("Sofia");
	 words.push_back("Sofia");
	 words.push_back("is");
	 words.push_back("the");
	 words.push_back("capital");

	 map<string, int> countingWords;
	 for (int i = 0; i < (int) words.size(); ++i)
	 {
	 string key = words[i];
	 int val = 1;
	 if (countingWords.find(key) != countingWords.end())
	 { // if in map
	 countingWords[key]++;
	 // OR:
	 val = countingWords[key];
	 val++;
	 countingWords[key] = val;
	 } else
	 {
	 countingWords[key] = val;
	 }

	 }

	 map<string, int>::iterator it;

	 for (it = countingWords.begin();
	 it != countingWords.end(); ++it)
	 {
	 cout << it->first << " " << it->second << endl;
	 }*/

	int f[] =
	{ 23, 35, 12, 34, 23, 27, 40, 24 };
	int s[] =
	{ 27, 12, 32, 34, 21, 24, 31, 25 };
	int t[] =
	{ 22, 30, 23, 40, 26, 27, 34, 24 };

	vector<int> temp1(f, f + 8);
	vector<int> temp2(s, s + 8);
	vector<int> temp3(t, t + 8);

	map<string, vector<int>, greater<string> > temperatures;
	temperatures["Sofia"] = temp1;
	temperatures["Plovdiv"] = temp2;
	temperatures["Varna"] = temp3;
	cout << "temperatures" << endl;

	for (map<string, vector<int> >::iterator it =
			temperatures.begin(); it != temperatures.end();
			++it)
	{
		cout << it->first << " " << endl;
		for (int i = 0; i < (int) it->second.size(); ++i)
		{
			cout << it->second[i] << " ";
		}
		cout << endl;
	}
	cout << endl;
	map<string, vector<int> > tempSorted;
	sort(temp1.begin(), temp1.begin() + temp1.size());

	sort(temp2.begin(), temp2.begin() + temp2.size());

	sort(temp3.begin(), temp3.begin() + temp3.size());

	map<string, vector<int> > tMap;
	tMap["Sofia"] = temp1;
	tMap["Plovdiv"] = temp3;
	tMap["Varna"] = temp2;

	cout << "tMap" << endl;
	for (map<string, vector<int> >::iterator it =
			tMap.begin(); it != tMap.end(); ++it)
	{
		cout << it->first << " " << endl;
		for (int i = 0; i < (int) it->second.size(); ++i)
		{
			cout << it->second[i] << " ";
		}
		cout << endl;
	}
	cout << endl;

	string city;
	int maxV = 0;
	for (map<string, vector<int> >::iterator it =
			tMap.begin(); it != tMap.end(); ++it)
	{
		vector<int> last = it->second;
		int maxP = last[last.size() - 1];
		//maxV = max(maxV, maxP);
		if (maxP > maxV)
		{
			maxV = maxP;
			city = it->first;
		}
	}
	vector<string> cities;
	for (map<string, vector<int> >::iterator it =
			tMap.begin(); it != tMap.end(); ++it)
	{
		vector<int> last = it->second;
		if (last[last.size() - 1] == maxV)
		{
			cities.push_back(it->first);
		}
	}

	for (int i = 0; i < (int) cities.size(); i++)
	{
		cout << "city is " << cities[i] << endl;
	}
	map < string, int > lowest;
	for (map<string, vector<int> >::iterator it =
			tMap.begin(); it != tMap.end(); ++it)
	{
		lowest[it->first] = it->second[0];
	}
	for (map<string, int >::iterator i =
			lowest.begin(); i != lowest.end(); ++i)
	{
		cout << i->first << " " << i->second<<endl;
	}


	return 0;
}
