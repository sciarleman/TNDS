#include <iostream>
#include <fstream>
#include <cstdlib>

#include "funzioni.h"
#include "Vettore.h"

using namespace std;

int main ( int argc, char** argv ) {

  if ( argc < 4 ) {
    cout << "Uso del programma, inserire informazioni richieste : " << argv[0] << " <numero dati desiderati> <nome del file> <file dati riordinati" << endl;
    return -1 ;
  }

	int numerodati = atoi(argv[1]);
	char *nomefile = argv[2];
	char *fileout = argv[3];   

	Vettore Vect = read (numerodati, nomefile);

//	cout << "dato in quarta posizione:\n" << Vect[3] << "\n" << endl; //controllo elemento vettore in posizione deteminata
/*
	cout << "dati selezionati:" << endl;
	Print( Vect ); //stampa a schermo vettore originario
*/
	sort_by_value(Vect);

	cout << endl << "\ndati riordinati:" << endl;
	Print (Vect); //stampa a schermo vettore riordinato

	cout << endl << "Media	 = " << calcmedia (Vect) << endl;
	cout << "Varianza = " << calcvarianza (Vect) << endl;
	cout << "Mediana  = " << calcmediana (Vect) << "\n" << endl;

	Print(Vect, fileout);         	  //stampa sul file di uscita 

	return 0;
		
}
