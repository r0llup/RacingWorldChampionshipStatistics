#include "Race.h"

using namespace std;

Race::Race(void)
{
	cout << "Constructeur par defaut (Race)" << endl;
	setPays("default");
	setPositionDepart(0);
	setPositionArrivee(0);
	setNombreSpectateur(0);
}

Race::Race(string p, int pd, int pa, int ns)
{
	cout << "Constructeur d'initialisation (Race)" << endl;
	setPays(p);
	setPositionDepart(pd);
	setPositionArrivee(pa);
	setNombreSpectateur(ns);
}

Race::Race(const Race &r)
{
	cout << "Constructeur de copie (Race)" << endl;
	setPays(r.getPays());
	setPositionDepart(r.getPositionDepart());
	setPositionArrivee(r.getPositionArrivee());
	setNombreSpectateur(r.getNombreSpectateur());
}

Race::~Race(void)
{
	cout << "Destructeur (Race)" << endl;
}

string Race::getPays(void) const
{
	return pays;
}

int Race::getPositionDepart(void) const
{
	return positionDepart;
}

int Race::getPositionArrivee(void) const
{

	return positionArrivee;
}

int Race::getNombreSpectateur(void) const
{
	return nombreSpectateur;
}

void Race::setPays(const string p)
{
	pays = p;
}

void Race::setPositionDepart(const int pd)
{
	positionDepart = pd;
}

void Race::setPositionArrivee(const int pa)
{
	positionArrivee = pa;
}

void Race::setNombreSpectateur(const int ps)
{
	nombreSpectateur = ps;
}

Race & Race::operator=(const Race &r)
{
	cout << "Operateur = (Race)" << endl;
	setPays(r.getPays());
	setPositionDepart(r.getPositionDepart());
	setPositionArrivee(r.getPositionArrivee());
	setNombreSpectateur(r.getNombreSpectateur());
	return *this;
}

bool Race::operator<(const Race &r)
{
	cout << "Operateur < (Race)" << endl;
	return getPays() < r.getPays();
}

bool Race::operator<=(const Race &r)
{
	cout << "Operateur <= (Race)" << endl;
	return getPays() <= r.getPays();
}

bool Race::operator==(const Race &r)
{
	cout << "Operateur == (Race)" << endl;
	return getPays() == r.getPays();
}

bool Race::operator>(const Race &r)
{
	cout << "Operateur > (Race)" << endl;
	return getPays() > r.getPays();
}

bool Race::operator>=(const Race &r)
{
	cout << "Operateur >= (Race)" << endl;
	return getPays() >= r.getPays();
}

ostream & operator<<(ostream &s, Race &r)
{
	cout << "Operateur << (Race)" << endl;
	ofstream *tmp;
	tmp = dynamic_cast<ofstream *> (&s);

	if(tmp == 0)
	{
		s << "Pays : " << r.getPays() << endl;
		s << "Position de depart : " << r.getPositionDepart() << endl;
		s << "Position d\'arrivee : " << r.getPositionArrivee() << endl;
		s << "Nombre de spectateurs : " << r.getNombreSpectateur() << endl;
	}

	else
	{
		*tmp << r.getPays() << endl;
		*tmp << r.getPositionDepart() << endl;
		*tmp << r.getPositionArrivee() << endl;
		*tmp << r.getNombreSpectateur() << endl;
	}

	return s;
}

istream & operator>>(istream & s, Race & r)
{
	cout << "Operateur >> (Race)" << endl;
	ifstream *tmp;
	tmp = dynamic_cast<ifstream *> (&s);

	if(tmp == 0)
	{
		cout << "Pays : ";
		s >> r.pays;
		cout << "Position de depart : ";
		s >> r.positionDepart;
		cout << "Position d\'arrivee : ";
		s >> r.positionArrivee;
		cout << "Nombre de spectateur :";
		s >> r.nombreSpectateur;
	}

	else
	{
		*tmp >> r.pays;
		*tmp >> r.positionDepart;
		*tmp >> r.positionArrivee;
		*tmp >> r.nombreSpectateur;
	}

	return s;
}
