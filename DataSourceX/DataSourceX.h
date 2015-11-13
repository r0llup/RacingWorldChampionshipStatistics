#ifndef DATASOURCEX_H
#define DATASOURCEX_H
#include "DataSource.h"
#include "DataX.h"
#include "MySortedList.h"

class DataSourceX : DataSource
{
	public:
		virtual const int getN(void) const = 0;
		virtual DataX getData(const int i) = 0;
		virtual const MySortedList<DataX> &getData(void) = 0;
};

#endif
