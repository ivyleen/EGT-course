/*
 * File.cpp
 *
 *  Created on: 17.05.2017 ã.
 *      Author: IVY
 */

#include "File.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

Choice File::choice = NEW;

void File::makeChoice() {
	File::choice = choice;
	switch (choice) {
	case PRINTINTFILE:
		File::printInFile();
		break;
	case COUT:
		File::cOut();
		break;
	case UPDATE:
		File::updateRecord();
		break;
	case NEW:
		File::newRecond();
		break;
	case DELETE:
		File::deleteRecord();
		break;
	case END:
		break;
	default:
		cerr << "Enter a correct choice" << endl;
		break;
	}

void File::printInFile() {
}

void File::cOut() {
}

void File::updateRecord() {
}

void File::newRecond() {
}

void File::deleteRecord() {
}

void File::createTextFile() {
	File::file("client2.dat", ios::binary);
}
