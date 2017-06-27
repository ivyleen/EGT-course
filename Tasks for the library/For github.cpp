//============================================================================
// Name        : For.cpp
// Author      : Ivy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "LibFunctions.h"
using namespace std;

int main()
{
	const string dayName[] = { "Sunday", "Monday",
			"Tuesday", "Wednesday", "Thursday", "Friday",
			"Saturday" };

	int chessBoard[8][8] = {
				{ 0, 1, 0, 1, 0, 1, 0, 1 },
				{ 1, 0, 1, 0, 1, 0, 1, 0 },
				{ 0, 1, 0, 1, 0, 1, 0, 1 },
				{ 1, 0, 1, 0, 1, 0, 1, 0 },
				{ 0, 1, 0, 1, 0, 1, 0, 1 },
				{ 1, 0, 1, 0, 1, 0, 1, 0 },
				{ 0, 1, 0, 1, 0, 1, 0, 1 },
				{ 1, 0, 1, 0, 1, 0, 1, 0 } };

	printArray(dayName, 7, 0);

	cout << endl;

	printArray(chessBoard, 8, 8);

	cout << endl;

	int divident = 55;
	int divisor = 9;

	QAndR result = FindQuotinentAndReminder(divident, divisor);

	cout <<"Devision between: "<< divident <<" and "<< divisor <<":"<< endl
			<< "Quotient: "	<< result.quotient << ", "
			<< "remainder: " << result.remainder << "."<< endl;


	return 0;
}
