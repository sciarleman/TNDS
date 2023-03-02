#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Vettore.h"
#include "funzioni.h"

int main ( int argc, char** argv ) {

  if ( argc < 3 ) {
    cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
    return -1 ;
  }

  int numerodati = atoi(argv[1]);
  char * nomefile = argv[2];
	
  Vettore <double> v = read<double>( numerodati , nomefile );

  //cout << "stampa dati richiesti" ; 
	//Print( v ); cout << endl;

  cout << "media    = " << calcmedia<double>( v ) << endl;
  cout << "varianza = " << calcvarianza<double>( v ) << endl;
  cout << "mediana  = " << calcmediana<double>( v ) << endl; 

	//cout << "stampa vettore dati richiesti riordinato in ordine crescente";
  //Print( v ); cout << endl;
  
  return 0;

}
