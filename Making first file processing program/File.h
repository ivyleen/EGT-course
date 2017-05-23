/*
 * File.h
 *
 *  Created on: 17.05.2017 ã.
 *      Author: IVY
 */

#ifndef FILE_H_
#define FILE_H_
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

enum Choice {
	PRINTINTFILE = 1, COUT, UPDATE, NEW, DELETE, END
};

class File {
private:
	static Choice choice;
	static ofstream file;

public:
	static void makeChoice() ;

private:
	static void ifOpenFile();
	static void createTextFile();
	static void readFromFile();
	static void printInFile();
	static void cOut();
	static void updateRecord();
	static void newRecond();
	static void deleteRecord();
};

#endif /* FILE_H_ */
