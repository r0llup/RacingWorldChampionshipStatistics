#include "ParametreStatistique2D.h"

using namespace std;

ParametreStatistique2D::ParametreStatistique2D(EchantillonPositionArriveeDepart &epad)
{
	setMoyenneX(epad);
	setMoyenneY(epad);
	setEcartTypeX(epad);
	setEcartTypeY(epad);
	setEtendueX(epad);
	setEtendueY(epad);
	setCoeffCrl(epad);
	setParamRgA(epad);
	setParamRgB(epad);
}

void ParametreStatistique2D::setMoyenneX(EchantillonPositionArriveeDepart &epad)
{
	DataXY data;
	double inter = 0;

	for(int i=0; i < epad.getNbreValDis(); i++)
	{
		data = epad.getDataXY(i);

		if(!data.getEffectifX())
		{
			ExceptionBase eb("Effectif non positif (DataSourceX).");
			throw eb;
		}

		inter += data.getEffectifX() * data.getValeurX();
	}

	setMoyenneX(inter/epad.getNbreValDis());
}

void ParametreStatistique2D::setMoyenneY(EchantillonPositionArriveeDepart &epad)
{
	DataXY data;
	double inter = 0;

	for(int i=0; i < epad.getNbreValDis(); i++)
	{
		data = epad.getDataXY(i);

		if(!data.getEffectifY())
		{
			ExceptionBase eb("Effectif non positif (DataSourceX).");
			throw eb;
		}
 
		inter += data.getEffectifY() * data.getValeurY();
	}

	setMoyenneY(inter/epad.getNbreValDis());
}

void ParametreStatistique2D::setEcartTypeX(EchantillonPositionArriveeDepart &epad)
{
	DataXY data;
	double inter = 0;

	for(int i=0; i < epad.getNbreValDis(); i++)
	{
		data = epad.getDataXY(i);
		inter += data.getEffectifX() * pow(data.getValeurX() - getMoyenneX(), 2);
	}

	setEcartTypeX(sqrt(inter/epad.getNbreValDis()));
}

void ParametreStatistique2D::setEcartTypeY(EchantillonPositionArriveeDepart &epad)
{
	DataXY data;
	double inter = 0;

	for(int i=0; i < epad.getNbreValDis(); i++)
	{
		data = epad.getDataXY(i);
		inter += data.getEffectifY() * pow(data.getValeurY() - getMoyenneY(), 2);
	}

	setEcartTypeY(sqrt(inter/epad.getNbreValDis()));
}

void ParametreStatistique2D::setEtendueX(EchantillonPositionArriveeDepart &epad)
{
	setEtendueX(epad.getDataXY(epad.getNbreValDis()-1).getValeurX()-epad.getDataXY(0).getValeurX());
}

void ParametreStatistique2D::setEtendueY(EchantillonPositionArriveeDepart &epad)
{
	setEtendueY(epad.getDataXY(epad.getNbreValDis()-1).getValeurY()-epad.getDataXY(0).getValeurY());
}

void ParametreStatistique2D::setCoeffCrl(EchantillonPositionArriveeDepart &epad)
{
	DataXY data;
	double val1x = 0;
	double val1y = 0;
	double val2x = 0;
	double val2y = 0;
	double inter1 = 0;
	double inter2 = 0;

	for(int i=0; i < epad.getNbreValDis(); i++)
	{
		data = epad.getDataXY(i);
		val1x += data.getValeurX() - getMoyenneX();
		val1y += data.getValeurY() - getMoyenneY();
		inter1 += val1x * val1y;
	}

	for(int i=0; i < epad.getNbreValDis(); i++)
	{
		data = epad.getDataXY(i);
		val2x += pow(val1x, 2);
		val2y += pow(val1y, 2);
	}

	inter2 = sqrt(val2x) * sqrt(val2y);

	setCoeffCrl(inter1 / inter2);
}

void ParametreStatistique2D::setParamRgA(EchantillonPositionArriveeDepart &epad)
{
	DataXY data;
	double inter1 = 0;
	double inter2 = 0;
	double inter3 = 0;
	double inter4 = 0;

	for(int i=0; i < epad.getNbreValDis(); i++)
	{
		data = epad.getDataXY(i);
		inter1 += data.getValeurX() * data.getValeurY() - getMoyenneX();
	}

	for(int i=0; i < epad.getNbreValDis(); i++)
	{
		data = epad.getDataXY(i);
		inter2 += data.getValeurY();
	}

	inter3 = inter1 * inter2;
	inter1 = inter2 = 0;

	for(int i=0; i < epad.getNbreValDis(); i++)
	{
		data = epad.getDataXY(i);
		inter1 += pow(data.getValeurX(), 2)- getMoyenneX();
	}

	for(int i=0; i < epad.getNbreValDis(); i++)
	{
		data = epad.getDataXY(i);
		inter2 += data.getValeurX();
	}

	inter4 = inter1 * inter2;

	setParamRgA(inter3/ inter4);
}
		
void ParametreStatistique2D::setParamRgB(EchantillonPositionArriveeDepart &epad)
{
	setParamRgB(getMoyenneY() - getParamRgA() * getMoyenneX());
}

void ParametreStatistique2D::printResult(const string name)
{
	ofstream file(("ParametreStatistique2D_" + name + ".txt").c_str(), ios::out);

	file << name << endl << endl;
	file << "Moyenne pour x : " << getMoyenneX() << endl;
	file << "Moyenne pour y : " << getMoyenneY() << endl;
	file << "Ecart-type pour x : " << getEcartTypeX() << endl;
	file << "Ecart-type pour y : " << getEcartTypeY() << endl;
	file << "Etendue pour x : " << getEtendueX() << endl;
	file << "Etendue pour y : " << getEtendueY() << endl;
	file << "Coefficient de correlation lineaire : " << getCoeffCrl() << endl;
	file << "Parametres de regression : " << getParamRgA() << " (A) " << \
		getParamRgB() << " (B)" << endl;
	file.close();
}
