#ifndef __funzioni__
#define __funzioni__

#include <iostream>
#include <fstream> 
#include "Vettore.h"

using namespace std;

Vettore read( int, char const* ) ;							//leggi da file esterno

double calcmedia( const Vettore & ) ;						//funzione calcola media
double calcvarianza( const Vettore & ) ;				//funzione calcolo varianza
double calcmediana( Vettore& ) ; 								//funzione calcolo mediana

void Print( const Vettore & ) ;									//stampa
void Print( const Vettore & , const char* ) ;		//stampa

void sort_by_value( Vettore & ); 							//funzione riordino

#endif
