#include "EchantillonPositionGrilleArrivee.h"

using namespace std;

EchantillonPositionGrilleArrivee::EchantillonPositionGrilleArrivee(MyList<Race> &rc)
{
	int val;
	int valdis = 0;
	int valdistab[25] = {0};
	int offset = 0;
	int cpt;
	DataX d;

	IterList<Race> iterRc(rc);
	IterList<Race> iterOc(rc);

	if(!rc.empty())
	{
		iterRc.reset();

		while(!iterRc.end())
		{
			val = ((Race &) iterRc).getPositionArrivee();

			// position d'arrivée non encore calculée
			if((val != 0) && (valdistab[val] == 0))
			{
				valdistab[val] = 1;
				valdis++;

				// occurences (ni) de la position de départ (xi)
				iterOc.reset();
				cpt = 0;

				while((!iterOc.end()) && (cpt < offset))
				{
					iterOc++;
					cpt++;
				}

				iterOc++;
				cpt = 1;

				while(!iterOc.end())
				{
					if(((Race &) iterOc).getPositionArrivee() == val)
					{
						cpt++;
					}

					iterOc++;
				}

				// DataX
				d.setValeur(val);
				cout << "Valeur : " << d.getValeur() << endl;
				d.setEffectif(cpt);
				cout << "Effectif : " << d.getEffectif() << endl;
				// Liste triée
				data.insert(d);
			}

			iterRc++;
			offset++;
		}

		// valdis
		setNbreValDis(valdis);
	}
}

DataX EchantillonPositionGrilleArrivee::getData(const int i)
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
