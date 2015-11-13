#include "ParametreStatistique1D.h"

using namespace std;

ParametreStatistique1D::ParametreStatistique1D(EchantillonPositionGrilleDepart &epgd)
{
	setMoyenne(epgd);
	setMode(epgd);
	setMediane(epgd);
	setEcartType(epgd);
	setEtendue(epgd);
	setCoeffVariation();
}

void ParametreStatistique1D::setMoyenne(EchantillonPositionGrilleDepart &epgd)
{
	DataX data;
	double inter = 0;

	for(int i=0; i < epgd.getNbreValDis(); i++)
	{
		data = epgd.getData(i);

		if(!data.getEffectif())
		{
			ExceptionBase eb("Effectif non positif (DataSourceX).");
			throw eb;
		}

		inter += data.getEffectif() * data.getValeur();
	}

	setMoyenne(inter/epgd.getNbreValDis());
}

void ParametreStatistique1D::setMode(EchantillonPositionGrilleDepart &epgd)
{
	DataX data;
	int val = 0;

	for(int i=0, max=0; i < epgd.getNbreValDis(); i++)
	{
		data = epgd.getData(i);

		if(!data.getEffectif())
		{
			ExceptionBase eb("Effectif non positif (DataSourceX).");
			throw eb;
		}

		if(data.getEffectif() > max)
		{
			val = data.getValeur();
			max = data.getEffectif();
		}
	}

	setMode(val);
}

void ParametreStatistique1D::setMediane(EchantillonPositionGrilleDepart &epgd)
{
	DataX data;
	int val = 0;
	int effTotal = 0;

	for(int i=0; i < epgd.getNbreValDis(); i++)
	{
		data = epgd.getData(i);

		if(!data.getEffectif())
		{
			ExceptionBase eb("Effectif non positif (DataSourceX).");
			throw eb;
		}

		effTotal += data.getEffectif();
	}

	for(int i=0, effCum=0; effCum < (effTotal/2); effCum+=data.getEffectif(), i++)
	{
		data = epgd.getData(i);
		val = data.getValeur();
	}

	setMediane(val);
}

void ParametreStatistique1D::setEcartType(EchantillonPositionGrilleDepart &epgd)
{
	DataX data;
	double inter = 0;

	for(int i=0; i < epgd.getNbreValDis(); i++)
	{
		data = epgd.getData(i);
		inter += data.getEffectif() * pow(data.getValeur() - getMoyenne(), 2);
	}

	setEcartType(sqrt(inter/epgd.getNbreValDis()));
}

void ParametreStatistique1D::setEtendue(EchantillonPositionGrilleDepart &epgd)
{
	setEtendue(epgd.getData(epgd.getNbreValDis()-1).getValeur()-epgd.getData(0).getValeur());

}

void ParametreStatistique1D::setCoeffVariation(void)
{
	setCoeffVariation((getEcartType()/getMoyenne())*100);
}

void ParametreStatistique1D::printResult(const string name)
{
	ofstream file(("ParametreStatistique1D_" + name + ".txt").c_str(), ios::out);

	file << name << endl << endl;
	file << "Moyenne : " << getMoyenne() << endl;
	file << "Mode : " << getMode() << endl;
	file << "Mediane : " << getMediane() << endl;
	file << "Ecart-type : " << getEcartType() << endl;
	file << "Etendue : " << getEtendue() << endl;
	file << "Coefficient de variation : " << getCoeffVariation() << endl;
	file.close();
}
