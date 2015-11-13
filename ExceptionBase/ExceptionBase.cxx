#include "ExceptionBase.h"

using namespace std;

ExceptionBase::ExceptionBase(void)
{
	cout << "Constructeur par defaut (ExceptionBase)" << endl;
	setMessage("");
}

ExceptionBase::ExceptionBase(const string msg)
{
	cout << "Constructeur d'initialisation (ExceptionBase)" << endl;
	setMessage(msg);
}

ExceptionBase::ExceptionBase(const ExceptionBase &e)
{
	cout << "Constructeur de copie (ExceptionBase)" << endl;
	setMessage(e.getMessage());
}

ExceptionBase::~ExceptionBase(void)
{
	cout << "Destructeur (ExceptionBase)" << endl;
}
