/*
 * Libraby.h
 *
 *  Created on: 27.06.2017 ã.
 *      Author: IVY
 */

#ifndef LIBFUNCTIONS_H_
#define LIBFUNCTIONS_H_
#include <iostream>
using std::cout;
using std::endl;

// print an array
template<class T>
void printArray(T * array, int numberOfRow, int numberOfCol)
{
	for (int i = 0; i < numberOfRow; i++)
	{
		if (numberOfCol != 0)
		{
			for (int j = 0; j < numberOfCol; j++)
			{
				cout << array[i][j] << " ";
			}
		} else {
			cout << array[i];
		}
		cout << endl;
	}
}


// find quotient and reminder from division
struct QAndR{
	int quotient;
	int remainder;
};

QAndR FindQuotinentAndReminder(int dividend, int divisor)
{
	QAndR result;

	result.quotient = dividend / divisor;
	result.remainder = dividend % divisor;

	return result;
}

// pick random number
template<class T>
T PickRandomNumber(T lowest, T biggest)
{
	srand ((unsigned) time(0));
	T resultNumber = (rand() % biggest) + lowest;

	return resultNumber;
}

#endif /* LIBFUNCTIONS_H_ */
