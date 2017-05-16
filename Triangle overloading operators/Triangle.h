 /*
 * Triangle.h
 *
 *  Created on: 16.05.2017 ã.
 *      Author: IVY
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <iostream>
using namespace std;

class Triangle {

	friend istream &operator>>(istream &, Triangle &);
	friend ostream &operator<<(ostream &, const Triangle &);

private:
	int a;
	int b;
	int c;
	int h;
public:
	Triangle();
	Triangle(int , int , int , int);
	virtual ~Triangle();

	// setters & getters
	int getA() const;
	void setA(int a);

	int getB() const;
	void setB(int b);

	int getC() const;
	void setC(int c);

	int getH() const;
	void setH(int h);

	// methods
	bool operator !=(Triangle&);
	bool operator ==(Triangle&);
};

#endif /* TRIANGLE_H_ */
