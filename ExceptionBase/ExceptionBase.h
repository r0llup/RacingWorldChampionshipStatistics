#ifndef EXCEPTIONBASE_H
#define EXCEPTIONBASE_H
#include <iostream>
#include <string>

class ExceptionBase
{
	private:
		std::string message;
	public:
		ExceptionBase(void);
		ExceptionBase(std::string msg);
		ExceptionBase(const ExceptionBase &e);
		~ExceptionBase(void);
		inline const std::string getMessage(void) const { return message; };
		inline void setMessage(const std::string msg) { message = msg; };
};

#endif
