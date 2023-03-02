#include "Particella.h"
#include <cmath>
#include <iostream>

//costruttore vuoto 
Particella::Particella() {

	val_m=0.;
	val_q=0.;
	
}

//costruttore a partire da coordinate
Particella::Particella(double Massa, double Carica) {

	val_m=Massa;
	val_q=Carica;

}

//distruttore
Particella::~Particella(){
	
}

//informazioni particella
double Particella::GetValueMassa() const {
	return val_m;
}

double Particella::GetValueCarica() const {
	return val_q;
}

void Particella::Print() const {
	
	std::cout << "\nParticella con caratteristiche: \nMassa\t= " << val_m << "\nCarica\t= " << val_q << std::endl;
	
}

Elettrone::Elettrone() : Particella(9.1093826E-31, -1.60217653E-19) {
	
}

Elettrone::~Elettrone() {

}

void Elettrone::Print() const {

	std::cout << "\nElettrone con caratteristiche: \nMassa\t= " << 9.1093826E-31 << "\nCarica\t= " << -1.60217653E-19 << std::endl;
	
}
