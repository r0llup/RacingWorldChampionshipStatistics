#include "DataXY.h"

using namespace std;

DataXY::DataXY(void)
{
	setValeurX(0);
	setEffectifX(0);
	setValeurY(0);
	setEffectifY(0);
}

DataXY::DataXY(int xi, int nxi, int yi, int nyi)
{
	setValeurX(xi);
	setEffectifX(nxi);
	setValeurY(yi);
	setEffectifY(nyi);
}

DataXY::DataXY(const DataXY &d)
{
	setValeurX(d.getValeurX());
	setEffectifX(d.getEffectifX());
	setValeurY(d.getValeurY());
	setEffectifY(d.getEffectifY());
}

DataXY & DataXY::operator=(const DataXY &d)
{
	cout << "Operateur = (DataXY)" << endl;
	setValeurX(d.getValeurX());
	setEffectifX(d.getEffectifX());
	setValeurY(d.getValeurY());
	setEffectifY(d.getEffectifY());
	return *this;
}

bool DataXY::operator<(const DataXY &d)
{
	cout << "Operateur < (DataXY)" << endl;
	return getValeurX() < d.getValeurX();
}

bool DataXY::operator<=(const DataXY &d)
{
	cout << "Operateur <= (DataXY)" << endl;
	return getValeurX() <= d.getValeurX();
}

bool DataXY::operator==(const DataXY &d)
{
	cout << "Operateur == (DataXY)" << endl;
	return getValeurX() == d.getValeurX();
}

bool DataXY::operator>(const DataXY &d)
{
	cout << "Operateur > (DataXY)" << endl;
	return getValeurX() > d.getValeurX();
}

bool DataXY::operator>=(const DataXY &d)
{
	cout << "Operateur >= (DataXY)" << endl;
	return getValeurX() >= d.getValeurX();
}

ostream & operator<<(ostream &s, DataXY &d)
{
	cout << "Operateur << (DataXY)" << endl;
	s << "ValeurX : " << d.getValeurX() << endl;
	s << "EffectifX : " << d.getEffectifX() << endl;
	s << "ValeurY : " << d.getValeurY() << endl;
	s << "EffectifY : " << d.getEffectifY() << endl;
	return s;
}

istream & operator>>(istream &s, DataXY &d)
{
	cout << "Operateur >> (DataXY)" << endl;
	cout << "ValeurX : ";
	s >> d.valeurX;
	cout << "EffectifX : ";
	s >> d.effectifX;
	cout << "ValeurY : ";
	s >> d.valeurY;
	cout << "EffectifY : ";
	s >> d.effectifY;
	return s;
}
