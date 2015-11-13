#include "EchantillonPositionArriveeDepart.h"

using namespace std;

EchantillonPositionArriveeDepart::EchantillonPositionArriveeDepart(MyList<Race> &rc)
{
	int val1;
	int val2;
	int valdis1 = 0;
	int valdis2 = 0;
	int valdistab1[25] = {0};
	int valdistab2[25] = {0};
	int offset = 0;
	int cpt;
	DataXY d;

	IterList<Race> iterRc(rc);
	IterList<Race> iterOc(rc);

	if(!rc.empty())
	{
		iterRc.reset();

		while(!iterRc.end())
		{
			val1 = ((Race &) iterRc).getPositionDepart();
			val2 = ((Race &) iterRc).getPositionArrivee();

			if(valdistab1[val1] == 0) // position de départ non encore calculée
			{
				valdistab1[val1] = 1;
				valdis1++;

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
					if(((Race &) iterOc).getPositionDepart() == val1)
					{
						cpt++;
					}

					iterOc++;
				}

				// DataXY
				d.setValeurX(val1);
				cout << "ValeurX : " << d.getValeurX() << endl;
				d.setEffectifX(cpt);
				cout << "EffectifX : " << d.getEffectifX() << endl;
			}

			// position d'arrivée non encore calculée
			if((val2 != 0) && (valdistab2[val2] == 0))
			{
				valdistab2[val2] = 1;
				valdis2++;

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
					if(((Race &) iterOc).getPositionArrivee() == val2)
					{
						cpt++;
					}

					iterOc++;
				}

				// DataXY
				d.setValeurY(val2);
				cout << "ValeurY : " << d.getValeurY() << endl;
				d.setEffectifY(cpt);
				cout << "EffectifY : " << d.getEffectifY() << endl;
			}

			// Liste triée
			data.insert(d);
			iterRc++;
			offset++;
		}

		// valdis
		setNbreValDis(valdis1);
	}
}

DataXY EchantillonPositionArriveeDepart::getDataXY(const int i)
{
	int cpt = 0;
	IterList<DataXY> iterDx(data);

	if(!data.empty())
	{
		iterDx.reset();

		while((!iterDx.end()) && (cpt < i))
		{
			iterDx++;
			cpt++;
		}
	}

	return (DataXY &) iterDx;
}
