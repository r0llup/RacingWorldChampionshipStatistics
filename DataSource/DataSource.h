#ifndef DATASOURCE_H
#define DATASOURCE_H
#include <string>

class DataSource
{
	protected:
		std::string nom;
		int effectif;
	public:
		const std::string getNom(void) const { return nom; }
		const int getEffectif(void) const { return effectif; }
		void setNom(const std::string n) { nom = n; }
		void setEffectif(const int e) { effectif = e; }
};

#endif
