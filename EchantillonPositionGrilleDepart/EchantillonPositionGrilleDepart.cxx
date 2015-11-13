#include "EchantillonPositionGrilleDepart.h"

using namespace std;

EchantillonPositionGrilleDepart::EchantillonPositionGrilleDepart(MyList<Race> &rc)
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
			val = ((Race &) iterRc).getPositionDepart();

			if(valdistab[val] == 0) // position de départ non encore calculée
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
					if(((Race &) iterOc).getPositionDepart() == val)
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

DataX EchantillonPositionGrilleDepart::getData(const int i)
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
