#include "Particella.h"
#include <cmath>
#include <iostream>

//costruttore vuoto 
Particella::Particella() {

	massa_m = 0.;
	carica_q = 0.;
	
}

//costruttore a partire da coordinate
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
	
	std::cout << "\nParticella con caratteristiche: \nMassa\t= " << massa_m << "\nCarica\t= " << carica_q << std::endl;
	
}

Elettrone::Elettrone() : Particella (9.1093826E-31, -1.60217653E-19) {
		
}

Elettrone::~Elettrone() {

}

void Elettrone::Print() const {

	std::cout << "\nElettrone con caratteristiche: \nMassa\t= " << 9.1093826E-31 << "\nCarica\t= " << -1.60217653E-19 << std::endl;
	
}
