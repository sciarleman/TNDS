#include <iostream>
#include <fstream>
#include <cstdlib>

#include "funzioni.h"

using namespace std;

int main (int argc, char** argv) {

	if ( argc < 2 ) {
    cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
    return -1 ;
  }

	char *data_output;
	
	if ( argc == 2 ) {
	vector<double> vet = ReadAll <double>( argv[1] );	

  //cout << "stampa dati richiesti" ; 
	//Print( vet ); cout << endl;

  cout << "media    = " << calcmedia<double>( vet ) << endl;
  cout << "varianza = " << calcvarianza<double>( vet ) << endl;
  cout << "mediana  = " << calcmediana<double>( vet ) << endl; 

	//cout << "stampa vettore dati richiesti riordinato in ordine crescente";
  //Print( vet ); cout << endl;

	//print in un file di testo esterno
	Print(vet, data_output);

	return 0;
	}


	if ( argc == 3 ) {
	vector<double> vet = read <double>( atoi(argv[1]), argv[2] );	

  //cout << "stampa dati richiesti" ; 
	//Print( vet ); cout << endl;

  cout << "media    = " << calcmedia<double>( vet ) << endl;
  cout << "varianza = " << calcvarianza<double>( vet ) << endl;
  cout << "mediana  = " << calcmediana<double>( vet ) << endl; 

	//cout << "stampa vettore dati richiesti riordinato in ordine crescente";
  //Print( vet ); cout << endl;

	//print in un file di testo esterno
	Print(vet, data_output);
  
	return 0;
	}


}
