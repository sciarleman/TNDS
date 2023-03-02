#include "Particella.h"
#include <cmath>
#include <iostream>

using namespace std;

//costruttore vuoto 
Particella::Particella() {

	massa_m = 0.;
	carica_q = 0.;
	
}

//costruttore a partire da massa e carica
Particella::Particella(double Massa, double Carica) {

	massa_m = Massa;
	carica_q = Carica;

}

//distruttore
Particella::~Particella(){
	
}

//informazioni particella
double Particella::GetValueMassa() const {
	
	return massa_m;
}

double Particella::GetValueCarica() const {
	
	return carica_q;	
}

void Particella::Print() const {
	
	cout << "\nParticella con caratteristiche: \nMassa\t= " << massa_m << "\nCarica\t= " << carica_q << endl;
	
}

//Particella elettrone, quantità definita
Elettrone::Elettrone() : Particella (9.1093826E-31, -1.60217653E-19) {
		
}

Elettrone::~Elettrone() {

}

void Elettrone::Print() const {

	cout << "\nElettrone con caratteristiche: \nMassa\t= " << 9.1093826E-31 << "\nCarica\t= " << -1.60217653E-19 << endl;
	
}
