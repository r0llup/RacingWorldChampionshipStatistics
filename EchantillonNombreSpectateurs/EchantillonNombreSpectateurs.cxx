#include "EchantillonNombreSpectateurs.h"

using namespace std;

EchantillonNombreSpectateurs::EchantillonNombreSpectateurs(MyList<Race> &rc, const int ndc)
{
	int val = 0;
	int cpt = 0;
	const int pas = 50000/ ndc;
	DataX d;

	setNbreValDis(ndc);
	IterList<Race> iterRc(rc);

	for(int i=50000; i < 100000; i+=pas)
	{
		if(!rc.empty())
		{
			iterRc.reset();
			cpt = 0;

			while(!iterRc.end())
			{
				val = ((Race &) iterRc).getNombreSpectateur();

				if((val >= i) && (val < (i+pas)))
				{
					cpt++;
				}

				iterRc++;
			}

			d.setValeur(i+(pas/2));
			cout << "Valeur : " << d.getValeur() << endl;
			d.setEffectif(cpt);
			cout << "Effectif : " << d.getEffectif() << endl;
			data.insert(d);
		}
	}
}

EchantillonNombreSpectateurs::EchantillonNombreSpectateurs(MyList<Race> &rc, \
	const int ndc, const int etd, const int brnInf)
{
	int val = 0;
	int cpt = 0;
	const int pas = brnInf/ ndc;
	DataX d;

	setNbreValDis(ndc);
	IterList<Race> iterRc(rc);

	for(int i=brnInf; i < etd; i+=pas)
	{
		if(!rc.empty())
		{
			iterRc.reset();
			cpt = 0;

			while(!iterRc.end())
			{
				val = ((Race &) iterRc).getNombreSpectateur();

				if((val >= i) && (val < (i+pas)))
				{
					cpt++;
				}

				if(val < brnInf || val > etd)
				{
					OutOfBorneRangeException oobre("Valeur en dehors des classes.", val);
					throw oobre;
				}

				iterRc++;
			}

			d.setValeur(i+(pas/2));
			cout << "Valeur : " << d.getValeur() << endl;
			d.setEffectif(cpt);
			cout << "Effectif : " << d.getEffectif() << endl;
			data.insert(d);
		}
	}
}

DataX EchantillonNombreSpectateurs::getData(const int i)
{
	int cpt = 0;
	IterList<DataX> iterDx(data);

	if(!data.empty())
	{
		iterDx.reset();

		while((!iterDx.end()) && (cpt < i))
		{
			iterDx++;
			cpt++;
		}
	}

	return (DataX &) iterDx;
}
