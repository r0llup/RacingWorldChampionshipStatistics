#include "OutOfBorneRangeException.h"

const int OutOfBorneRangeException::getVal(void) const
{
	return val;
}

void OutOfBorneRangeException::setVal(const int v)
{
	val = v;
}
