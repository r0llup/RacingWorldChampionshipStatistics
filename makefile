.SILENT:
MV=MyVector
ML=MyList
MS=MySortedList
RC=Race
DS=DataSource
DX=DataSourceX
DT=DataX
EPGD=EchantillonPositionGrilleDepart
EPGA=EchantillonPositionGrilleArrivee
PS1D=ParametreStatistique1D
ENSP=EchantillonNombreSpectateurs
DTXY=DataXY
DSXY=DataSourceXY
EPAD=EchantillonPositionArriveeDepart
PS2D=ParametreStatistique2D
EXCB=ExceptionBase
OBRE=OutOfBorneRangeException
OBJS=MyVector.o MyList.o MySortedList.o Race.o DataX.o EchantillonPositionGrilleDepart.o EchantillonPositionGrilleArrivee.o ParametreStatistique1D.o EchantillonNombreSpectateurs.o DataXY.o EchantillonPositionArriveeDepart.o ParametreStatistique2D.o ExceptionBase.o OutOfBorneRangeException.o
CPP=c++ -Wno-deprecated  -I$(MV) -I$(ML) -I$(MS) -I$(RC) -I$(DS) -I$(DT) -I$(DX) -I$(EPGD) -I$(EPGA) -I$(PS1D) -I$(ENSP) -I$(DTXY) -I$(DSXY) -I$(EPAD) -I$(PS2D) -I$(EXCB) -I$(OBRE)

all:	Main

Main:	$(OBJS) Main.cxx
	echo Creation de Main ...
	$(CPP) Main.cxx $(OBJS) -o Main

MyVector.o:	$(MV)/MyVector.cxx $(MV)/MyVector.h
	echo Creation de MyVector.o ...
	$(CPP) $(MV)/MyVector.cxx -c

MyList.o:	$(ML)/MyList.cxx $(ML)/MyList.h
	echo Creation de MyList.o ...
	$(CPP) $(ML)/MyList.cxx -c

MySortedList.o:	$(MS)/MySortedList.cxx $(MS)/MySortedList.h
	echo Creation de MySortedList.o ...
	$(CPP) $(MS)/MySortedList.cxx -c

Race.o:	$(RC)/Race.cxx $(RC)/Race.h
	echo Creation de Race.o ...
	$(CPP) $(RC)/Race.cxx -c

DataSource.o:	$(DS)/DataSource.h
	echo Creation de DataSource.o ...
	$(CPP) $(DS)/DataSource.h -c

DataX.o:	$(DT)/DataX.cxx $(DT)/DataX.h
	echo Creation de DataX.o ...
	$(CPP) $(DT)/DataX.cxx -c

DataSourceX.o:	$(DX)/DataSourceX.h
	echo Creation de DataSourceX.o ...
	$(CPP) $(DX)/DataSource.h -c

EchantillonPositionGrilleDepart.o:	$(EPGD)/EchantillonPositionGrilleDepart.cxx $(EPGD)/EchantillonPositionGrilleDepart.h
	echo Creation de EchantillonPositionGrilleDepart.o ...
	$(CPP) $(EPGD)/EchantillonPositionGrilleDepart.cxx -c

EchantillonPositionGrilleArrivee.o:	$(EPGA)/EchantillonPositionGrilleArrivee.cxx $(EPGA)/EchantillonPositionGrilleArrivee.h
	echo Creation de EchantillonPositionGrilleArrivee.o ...
	$(CPP) $(EPGA)/EchantillonPositionGrilleArrivee.cxx -c

ParametreStatistique1D.o:	$(PS1D)/ParametreStatistique1D.cxx $(PS1D)/ParametreStatistique1D.h
	echo Creation de ParametreStatistique1D.o ...
	$(CPP) $(PS1D)/ParametreStatistique1D.cxx -c

EchantillonNombreSpectateurs.o:	$(ENSP)/EchantillonNombreSpectateurs.cxx $(ENSP)/EchantillonNombreSpectateurs.h
	echo Creation de EchantillonNombreSpectateurs.o ...
	$(CPP) $(ENSP)/EchantillonNombreSpectateurs.cxx -c

DataXY.o:	$(DTXY)/DataXY.cxx $(DTXY)/DataXY.h
	echo Creation de DataXY.o ...
	$(CPP) $(DTXY)/DataXY.cxx -c

DataSourceXY.o:	$(DSXY)/DataSourceXY.h
	echo Creation de DataSourceXY.o ...
	$(CPP) $(DSXY)/DataSourceXY.h -c

EchantillonPositionArriveeDepart.o:	$(EPAD)/EchantillonPositionArriveeDepart.cxx $(EPAD)/EchantillonPositionArriveeDepart.h
	echo Creation de EchantillonPositionArriveeDepart.o ...
	$(CPP) $(EPAD)/EchantillonPositionArriveeDepart.cxx -c

ParametreStatistique2D.o:	$(PS2D)/ParametreStatistique2D.cxx $(PS2D)/ParametreStatistique2D.h
	echo Creation de ParametreStatistique2D.o ...
	$(CPP) $(PS2D)/ParametreStatistique2D.cxx -c

ExceptionBase.o:	$(EXCB)/ExceptionBase.cxx $(EXCB)/ExceptionBase.h
	echo Creation de ExceptionBase.o ...
	$(CPP) $(EXCB)/ExceptionBase.cxx -c

OutOfBorneRangeException.o:	$(OBRE)/OutOfBorneRangeException.cxx $(OBRE)/OutOfBorneRangeException.h
	echo Creation de OutOfBorneRangeException.o	...
	$(CPP) $(OBRE)/OutOfBorneRangeException.cxx -c

clean:
	rm -f $(OBJS) core Main

clobber:	clean
	rm -f tags $(PROGRAM) *.txt
