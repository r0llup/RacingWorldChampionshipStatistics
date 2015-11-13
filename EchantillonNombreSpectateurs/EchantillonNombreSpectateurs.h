#ifndef ECHANTILLONNOMBRESPECTATEURS_H
#define ECHANTILLONNOMBRESPECTATEURS_H
#include "DataSourceX.h"
#include "MyList.h"
#include "MySortedList.h"
#include "Race.h"
#include "OutOfBorneRangeException.h"

class EchantillonNombreSpectateurs : DataSourceX
{
	private:
		MySortedList<DataX> data;
		int nbreValDis;
	public:
		EchantillonNombreSpectateurs(void) { }
		EchantillonNombreSpectateurs(MyList<Race> &rc, const int ndc);
		EchantillonNombreSpectateurs(MyList<Race> &rc, const int ndc, \
			const int etd, const int brnInf);
		~EchantillonNombreSpectateurs(void) { };
		const int getN(void) const { return nbreValDis; };
		DataX getData(const int i);
		const MySortedList<DataX> &getData(void) { return data; }
		inline const int getNbreValDis(void) const { return nbreValDis; }
		inline void setNbreValDis(const int nvd) { nbreValDis = nvd; }
};

#endif
