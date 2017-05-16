/*
 * Box.h
 *
 *  Created on: 10.05.2017 ã.
 *      Author: IVY
 */

#ifndef BOX_H_
#define BOX_H_
#include <istream>
#include <ostream>
using namespace std;

class Box {

	friend istream &operator>>(istream &, Box &);
	friend ostream &operator<<(ostream &, const Box &);

private:
	int length;
	int wide;
	int hight;
public:
	Box();
	Box(int,int,int);
	virtual ~Box();

	//setters & getters
	int getHight() const;
	void setHight(int high);

	int getLength() const;
	void setLength(int lenght);

	int getWide() const;
	void setWide(int wide);

	// methods
	int obem() const;

	// operators overloading
	Box& operator+(Box&);
	bool operator!=(Box&);
	bool operator>(Box&);
};

#endif /* BOX_H_ */
