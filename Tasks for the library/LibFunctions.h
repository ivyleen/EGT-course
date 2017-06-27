/*
 * Libraby.h
 *
 *  Created on: 27.06.2017 �.
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

#endif /* LIBFUNCTIONS_H_ */
