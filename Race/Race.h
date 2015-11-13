#ifndef RACE_H
#define RACE_H
#include <iostream>
#include <fstream>
#include <string>

class Race
{
	friend std::ostream & operator<<(std::ostream &s, Race &r);
	friend std::istream & operator>>(std::istream &s, Race &r);
	private:
		std::string pays;
		int positionDepart;
		int positionArrivee;
		int nombreSpectateur;
	public:
		Race(void);
		Race(std::string p, int pd, int pa, int ns);
		Race(const Race &r);
		~Race(void);
		std::string getPays(void) const;
		int getPositionDepart(void) const;
		int getPositionArrivee(void) const;
		int getNombreSpectateur(void) const;
		void setPays(const std::string p);
		void setPositionDepart(const int pd);
		void setPositionArrivee(const int pa);
		void setNombreSpectateur(const int ps);
		Race & operator=(const Race & r);
		bool operator<(const Race & r);
		bool operator<=(const Race & r);
		bool operator==(const Race & r);
		bool operator>(const Race & r);
		bool operator>=(const Race & r);
};

#endif
