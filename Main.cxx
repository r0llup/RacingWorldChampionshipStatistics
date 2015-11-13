#include "Race.h"
#include "MyList.h"
#include "EchantillonPositionGrilleDepart.h"
#include "EchantillonPositionGrilleArrivee.h"
#include "ParametreStatistique1D.h"
#include "EchantillonNombreSpectateurs.h"
#include "EchantillonPositionArriveeDepart.h"
#include "ParametreStatistique2D.h"
#include "OutOfBorneRangeException.h"
#include <fstream.h>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file("MichaelSchumacher.csv", ios::in);

	if(!file) // tentative d'ouverture du fichier 'MichaelSchumacher.csv'
	{
		cout << "fichier 'MichaelSchumacher.csv' non trouve" << endl;
		return 1;
	}

	else
	{
		Race r;
		char line[25];
		int counter = 0;
		MyList<Race> rcList;

		while(file.getline(line, 99, ';'))
		{
			if(counter == 11) // fin de ligne
			{
				counter = 0;
				rcList.insertHead(r);
			}

			counter++;

			switch(counter)
			{
				case 3: // pays
					r.setPays(line);
					break;
				case 8: // positionDepart
					r.setPositionDepart(atoi(line));
					break;
				case 9: // positionArrivee
					if((strcmp(line, "ab") != 0) && (strcmp(line, "dsq") != 0))
					{
						r.setPositionArrivee(atoi(line));
					}

					else
					{
						r.setPositionArrivee(0);
					}
					break;
				case 11: // nombreSpectateur
					r.setNombreSpectateur(atoi(line));
					break;
			}
		}

		file.close();
		cout << "fichier 'MichaelSchumacher.csv' charge avec succes" << endl;
		rcList.affiche();
		cout << rcList.size() << endl;

		try
		{
			EchantillonPositionGrilleDepart epgd(rcList);
			ParametreStatistique1D ps1dd(epgd);
			ps1dd.printResult("EchantillonPositionGrilleDepart");
			EchantillonPositionGrilleArrivee epga(rcList);
			ParametreStatistique1D ps1da((EchantillonPositionGrilleDepart &) epga);
			ps1da.printResult("EchantillonPositionGrilleArrivee");
			EchantillonNombreSpectateurs ensp(rcList, 20, 100000, 50000);
			ParametreStatistique1D ps1ds((EchantillonPositionGrilleDepart &) ensp);
			ps1ds.printResult("EchantillonNombreSpectateurs");
		}

		catch(OutOfBorneRangeException oobre)
		{
			cout << "!!! OutOfBorneRangeException !!!" << endl;
			cout << oobre.getMessage() << " (" << oobre.getVal() << ")." << endl;
		}

		catch(ExceptionBase eb)
		{
			cout << "!!! ExceptionBase !!!" << endl;
			cout << eb.getMessage() << endl;
		}

		EchantillonPositionArriveeDepart epad(rcList);
		ParametreStatistique2D ps2d(epad);
		ps2d.printResult("EchantillonPositionArriveeDepart");
	}

	return 0;
}
