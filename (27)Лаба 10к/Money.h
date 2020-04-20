#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Money
{
public:
	Money(void);
public:
	virtual ~Money(void);
	Money(long, int);
	Money(const Money&);
	long Get_rub() { return rub; }
	int Get_kop() { return kop; }
	void Set_rub(long);
	void Set_kop(int);
	friend Money operator+(Money, Money);
	Money& operator=(const Money&);
	friend bool operator>(const Money& m1, const Money& m2);
	friend bool operator<(const Money& m1, const Money& m2);
	friend bool operator==(const Money& m1, const Money& m2);
	friend fstream& operator>>(fstream& fin, Money& m);
	friend fstream& operator<<(fstream& fout, const Money& m);
	friend ostream& operator<<(ostream& out, const Money& m);
	friend istream& operator>>(istream& in, Money& m);
protected:
	long rub;
	int kop;
};