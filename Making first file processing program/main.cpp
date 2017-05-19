// Fig. 17.15: main.cpp
// This program reads a random access file sequentially, updates
// data previously written to the file, creates data to be placed
// in the file, and deletes data previously in the file.
#include <iostream>
#include <fstream>
#include <cstdlib> 
using namespace std;


int main() {

	ofstream file("client.dat", ios::binary);

	fstream inOutCredit("credit.dat", ios::in | ios::out);


	return 0;
}
