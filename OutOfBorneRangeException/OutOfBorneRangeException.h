#ifndef OUTOFBORNERANGEEXCEPTION_H
#define OUTOFBORNERANGEEXCEPTION_H
#include "ExceptionBase.h"

class OutOfBorneRangeException : public ExceptionBase
{
	private:
		int val;
	public:
		OutOfBorneRangeException() : ExceptionBase()
		{
			std::cout << "Constructeur par defaut (OutOfBorneRangeException)" << std::endl;
			setVal(0);
		}
		OutOfBorneRangeException(const int v) : ExceptionBase()
		{
			std::cout << "Constructeur d'initialisation (1) (OutOfBorneRangeException)" << std::endl;
			setVal(v);
		}
		OutOfBorneRangeException(std::string msg, const int v) : ExceptionBase(msg)
		{
			std::cout << "Constructeur d'initialisation (2) (OutOfBorneRangeException)" << std::endl;
			setVal(v);
		}
		OutOfBorneRangeException(OutOfBorneRangeException &oobre) : ExceptionBase(oobre)
		{
			std::cout << "Constructeur de copie (OutOfBorneRangeException)" << std::endl;
			setVal(oobre.getVal());
		}
		const int getVal(void) const;
		void setVal(const int v);
};

#endif
