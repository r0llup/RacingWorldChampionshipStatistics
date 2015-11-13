#ifndef ECHANTILLONPOSITIONARRIVEEDEPART_H
#define ECHANTILLONPOSITIONARRIVEEDEPART_H
#include "DataSourceXY.h"
#include "MyList.h"
#include "MySortedList.h"
#include "Race.h"

class EchantillonPositionArriveeDepart : DataSourceXY
{
	private:
		MySortedList<DataXY> data;
		int nbreValDis;
	public:
		EchantillonPositionArriveeDepart(void) { setNbreValDis(0); }
		EchantillonPositionArriveeDepart(MyList<Race> &rc);
		~EchantillonPositionArriveeDepart(void) { };
		const int getDataX(const int i) { return getDataXY(i).getValeurX(); }
		const int getDataY(const int i) { return getDataXY(i).getValeurY(); }
		DataXY getDataXY(const int i);
		const int getN(void) const { return nbreValDis; }
		const MySortedList<DataXY> & getData(void) { return data; }
		inline const int getNbreValDis(void) const { return nbreValDis; }
		inline void setNbreValDis(const int nvd) { nbreValDis = nvd; }
};

#endif
