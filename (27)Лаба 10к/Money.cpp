#include "Money.h"
Money::Money(void)
{
	rub = 0;
	kop = 0;
}
Money::~Money(void)
{
}
Money::Money(long R, int K)
{
	rub = R;
	kop = K;
}
Money::Money(const Money& money)
{
	rub = money.rub;
	kop = money.kop;
}
void Money::Set_rub(long R)
{
	rub = R;

}
void Money::Set_kop(int K)
{
	kop = K;
}

Money operator+(Money A, Money B)
{
	Money C(A.rub, A.kop);
	C.rub += B.rub;
	C.kop += B.kop;
	if (C.kop >= 100) {
		C.rub = C.rub + C.kop / 100;
		C.kop = C.kop % 100;
	}
	return C;
}
Money& Money::operator=(const Money& m)
{
	if (&m == this)return *this;
	rub = m.rub;
	kop = m.kop;
	return *this;
}
fstream& operator>>(fstream& fin, Money& m)
{
	fin >> m.rub;
	fin >> m.kop;
	return fin;
}
fstream& operator<<(fstream& fout, const Money& m)
{
	fout << m.rub << '\n' << m.kop << '\n';
	return fout;
}
istream& operator>>(istream& in, Money& m)
{
	cout << "\nРубли : "; in >> m.rub;
	cout << "\nКопейки : "; in >> m.kop;
	return in;
}
ostream& operator<<(ostream& out, const Money& m)
{
	out << m.rub << ',' << m.kop;
	out << "\n";
	return out;
}
bool operator>(const Money& m1, const Money& m2)
{
	return ((m1.rub * 100) + m1.kop > (m2.rub * 100) + m2.kop);
}

bool operator==(const Money& m1, const Money& m2)
{
	return ((m1.rub * 100) + m1.kop == (m2.rub * 100) + m2.kop);
}

bool operator<(const Money& m1, const Money& m2)
{
	return ((m1.rub * 100) + m1.kop < (m2.rub * 100) + m2.kop);
}
