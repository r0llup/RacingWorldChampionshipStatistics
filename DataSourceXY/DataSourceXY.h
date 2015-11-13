#ifndef DATASOURCEXY_H
#define DATASOURCEXY_H
#include "DataSource.h"
#include "DataXY.h"
#include "MySortedList.h"

class DataSourceXY : DataSource
{
	public:
		DataSourceXY() { }
		virtual ~DataSourceXY() { };
		virtual const int getN(void) const = 0;
		virtual DataXY getDataXY(const int i) = 0;
		virtual const int getDataX(const int i) = 0;
		virtual const int getDataY(const int i) = 0;
		virtual const MySortedList<DataXY> & getData(void) = 0;
};

#endif
