#ifndef ECHANTILLONGRILLEARRIVEE_H
#define ECHANTILLONGRILLEARRIVEE_H
#include "DataSourceX.h"
#include "MyList.h"
#include "MySortedList.h"
#include "Race.h"

class EchantillonPositionGrilleArrivee : DataSourceX
{
	private:
		MySortedList<DataX> data;
		int nbreValDis;
	public:
		EchantillonPositionGrilleArrivee(void) { setNbreValDis(0); }
		EchantillonPositionGrilleArrivee(MyList<Race> &rc);
		~EchantillonPositionGrilleArrivee(void) { };
		DataX getData(const int i);
		const int getN(void) const { return nbreValDis; }
		const MySortedList<DataX> &getData(void) { return data; }
		inline const int getNbreValDis(void) const { return nbreValDis; }
		inline void setNbreValDis(const int nvd) { nbreValDis = nvd; }
};

#endif
