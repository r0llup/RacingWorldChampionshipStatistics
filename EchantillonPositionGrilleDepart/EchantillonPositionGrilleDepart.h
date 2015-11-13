#ifndef ECHANTILLONGRILLEDEPART_H
#define ECHANTILLONGRILLEDEPART_H
#include "DataSourceX.h"
#include "MyList.h"
#include "MySortedList.h"
#include "Race.h"

class EchantillonPositionGrilleDepart : DataSourceX
{
	private:
		MySortedList<DataX> data;
		int nbreValDis;
	public:
		EchantillonPositionGrilleDepart(void) { setNbreValDis(0); }
		EchantillonPositionGrilleDepart(MyList<Race> &rc);
		~EchantillonPositionGrilleDepart(void) { };
		DataX getData(const int i);
		const int getN(void) const { return nbreValDis; }
		const MySortedList<DataX> &getData(void) { return data; }
		inline const int getNbreValDis(void) const { return nbreValDis; }
		inline void setNbreValDis(const int nvd) { nbreValDis = nvd; }
};

#endif
