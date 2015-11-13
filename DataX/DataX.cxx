#include "DataX.h"

using namespace std;

DataX::DataX(void)
{
	setValeur(0);
	setEffectif(0);
}

DataX::DataX(int xi, int ni)
{
	setValeur(xi);
	setEffectif(ni);
}

DataX::DataX(const DataX &d)
{
	setValeur(d.getValeur());
	setEffectif(d.getEffectif());
}

DataX & DataX::operator=(const DataX &d)
{
	cout << "Operateur = (DataX)" << endl;
	setValeur(d.getValeur());
	setEffectif(d.getEffectif());
	return *this;
}

bool DataX::operator<(const DataX &d)
{
	cout << "Operateur < (DataX)" << endl;
	return getValeur() < d.getValeur();
}

bool DataX::operator<=(const DataX &d)
{
	cout << "Operateur <= (DataX)" << endl;
	return getValeur() <= d.getValeur();
}

bool DataX::operator==(const DataX &d)
{
	cout << "Operateur == (DataX)" << endl;
	return getValeur() == d.getValeur();
}

bool DataX::operator>(const DataX &d)
{
	cout << "Operateur > (DataX)" << endl;
	return getValeur() > d.getValeur();
}

bool DataX::operator>=(const DataX &d)
{
	cout << "Operateur >= (DataX)" << endl;
	return getValeur() >= d.getValeur();
}

ostream & operator<<(ostream &s, DataX &d)
{
	cout << "Operateur << (DataX)" << endl;
	s << "Valeur : " << d.getValeur() << endl;
	s << "Effectif : " << d.getEffectif() << endl;
	return s;
}

istream & operator>>(istream &s, DataX &d)
{
	cout << "Operateur >> (DataX)" << endl;
	cout << "Valeur : ";
	s >> d.valeur;
	cout << "Effectif : ";
	s >> d.effectif;
	return s;
}
