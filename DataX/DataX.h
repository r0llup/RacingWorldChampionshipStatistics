#ifndef DATAX_H
#define DATAX_H
#include <iostream>

class DataX
{
	friend std::ostream & operator<<(std::ostream &s, DataX &d);
	friend std::istream & operator>>(std::istream &s, DataX &d);
	private:
		int valeur;
		int effectif;
	public:
		DataX(void);
		DataX(int xi, int ni);
		DataX(const DataX &d);
		~DataX(void) { };
		inline const int getValeur(void) const { return valeur; }
		inline const int getEffectif(void) const { return effectif; }
		inline void setValeur(const int v) { valeur = v; }
		inline void setEffectif(const int e) { effectif = e; }
		DataX & operator=(const DataX &d);
		bool operator<(const DataX &d);
		bool operator<=(const DataX &d);
		bool operator==(const DataX &d);
		bool operator>(const DataX &d);
		bool operator>=(const DataX &d);
};

#endif
