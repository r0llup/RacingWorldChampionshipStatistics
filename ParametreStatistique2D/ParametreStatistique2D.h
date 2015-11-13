#ifndef PARAMETRESTATISTIQUE2D_H
#define PARAMETRESTATISTIQUE2D_H
#include "EchantillonPositionArriveeDepart.h"
#include "DataXY.h"
#include "ExceptionBase.h"
#include <iostream>
#include <map>
#include <string>
#include <math.h>

class ParametreStatistique2D
{
	private:
		std::map<std::string, double> stats;
	public:
		ParametreStatistique2D(EchantillonPositionArriveeDepart &epad);
		~ParametreStatistique2D(void) { };
		inline const double getMoyenneX(void) { return stats["moyenneX"]; }
		inline const double getMoyenneY(void) { return stats["moyenneY"]; }
		inline const double getEcartTypeX(void) { return stats["ecartTypeX"]; }
		inline const double getEcartTypeY(void) { return stats["ecartTypeY"]; }
		inline const double getEtendueX(void) { return stats["etendueX"]; }
		inline const double getEtendueY(void) { return stats["etendueY"]; }
		inline const double getCoeffCrl(void) { return stats["coeffcrl"]; }
		inline const double getParamRgA(void) { return stats["paramrga"]; }
		inline const double getParamRgB(void) { return stats["paramrgb"]; }
		inline void setMoyenneX(const double m) { stats["moyenneX"] = m; }
		inline void setMoyenneY(const double m) { stats["moyenneY"] = m; }
		void setMoyenneX(EchantillonPositionArriveeDepart &epad);
		void setMoyenneY(EchantillonPositionArriveeDepart &epad);
		inline void setEcartTypeX(const double e) { stats["ecartTypeX"] = e; }
		inline void setEcartTypeY(const double e) { stats["ecartTypeY"] = e; }
		void setEcartTypeX(EchantillonPositionArriveeDepart &epad);
		void setEcartTypeY(EchantillonPositionArriveeDepart &epad);
		inline void setEtendueX(const double e) { stats["etendueX"] = e; }
		inline void setEtendueY(const double e) { stats["etendueY"] = e; }
		void setEtendueX(EchantillonPositionArriveeDepart &epad);
		void setEtendueY(EchantillonPositionArriveeDepart &epad);
		inline void setCoeffCrl(const double r) { stats["coeffcrl"] = r; }
		void setCoeffCrl(EchantillonPositionArriveeDepart &epad);
		inline void setParamRgA(const double a) { stats["paramrga"] = a; }
		inline void setParamRgB(const double b) { stats["paramrgb"] = b; }
		void setParamRgA(EchantillonPositionArriveeDepart &epad);
		void setParamRgB(EchantillonPositionArriveeDepart &epad);
		void printResult(const std::string name);
};

#endif
