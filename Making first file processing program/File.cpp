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

	switch (choice) {
	case PRINTINTFILE:
		File::printInFile();
		break;
	case COUT:
		break;
	case UPDATE:
		break;
	case NEW:
		break;
	case DELETE:
		break;
	case END:
		break;
	default:
		cerr << "Enter a correct choice" << endl;
		break;
	}
}

void File::printInFile() {
}

/*

 void File::cOut() const {
 }

 void File::printInFile() const {
 }

 void File::newRecond() {
 }

 void File::readFromFile() const {
 }


 void File::ifOpenFile() const {
 if (!file) {
 cerr << "File could not be opened." << endl;
 exit(1);
 }
 }

 void File::createTextFile() {
 file("client.dat", ios::binary);
 }

 void File::updateRecord() {
 }

 void File::deleteRecord() {
 }
 */
