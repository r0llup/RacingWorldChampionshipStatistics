#ifndef PARAMETRESTATISTIQUE1D_H
#define PARAMETRESTATISTIQUE1D_H
#include "EchantillonPositionGrilleDepart.h"
#include "DataX.h"
#include "ExceptionBase.h"
#include <iostream>
#include <map>
#include <string>
#include <math.h>
#include <fstream.h>

class ParametreStatistique1D
{
	private:
		std::map<std::string, double> stats;
	public:
		ParametreStatistique1D(EchantillonPositionGrilleDepart &epgd);
		~ParametreStatistique1D(void) { };
		inline const double getMoyenne(void) { return stats["moyenne"]; }
		inline const double getMode(void) { return stats["mode"]; }
		inline const double getMediane(void) { return stats["mediane"]; }
		inline const double getEcartType(void) { return stats["ecartType"]; }
		inline const double getEtendue(void) { return stats["etendue"]; }
		inline const double getCoeffVariation(void) { return stats["coeffVariation"]; }
		inline void setMoyenne(const double m) { stats["moyenne"] = m; }
		void setMoyenne(EchantillonPositionGrilleDepart &epgd);
		inline void setMode(const double m) { stats["mode"] = m; }
		void setMode(EchantillonPositionGrilleDepart &epgd);
		inline void setMediane(const double m) { stats["mediane"] = m; }
		void setMediane(EchantillonPositionGrilleDepart &epgd);
		inline void setEcartType(const double e) { stats["ecartType"] = e; }
		void setEcartType(EchantillonPositionGrilleDepart &epgd);
		inline void setEtendue(const double e) { stats["etendue"] = e; }
		void setEtendue(EchantillonPositionGrilleDepart &epgd);
		inline void setCoeffVariation(const double c) { stats["coeffVariation"] = c; }
		void setCoeffVariation(void);
		void printResult(const std::string name);
};

#endif
