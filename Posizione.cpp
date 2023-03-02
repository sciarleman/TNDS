#include "Posizione.h"
#include <cmath>

//costruttore vuoto 
Posizione::Posizione() {

	dim_x=0.;
	dim_y=0.;
	dim_z=0.;
	
}

//costruttore a partire da coordinate
Posizione::Posizione(double x, double y, double z) {

	dim_x=x;
	dim_y=y;
	dim_z=z;
	
}

//distruttore
Posizione::~Posizione(){
	
}

//coordinate cartesiane
double Posizione::GetComponentX() const {
	return dim_x;
}

double Posizione::GetComponentY() const {
	return dim_y;
}

double Posizione::GetComponentZ() const {
	return dim_z;
}

//coordinate sferiche
double Posizione::GetValueRaggio() const {
	return sqrt(pow(dim_x,2)+pow(dim_y,2)+pow(dim_z,2));
}

double Posizione::GetAnglePhi() const {
	return atan2(dim_y, dim_x);
}

double Posizione::GetAngleTheta() const {
	return acos(dim_z/GetValueRaggio());
}

//coordinate cilindriche (raggio)
double Posizione::GetValueRho() const {
	return sqrt(pow(dim_x,2)+pow(dim_y,2));
}

//distanza tra due punti
double Posizione::Distanza(const Posizione & b) const {
	return sqrt( (pow(GetComponentX() - b.GetComponentX(), 2)) + (pow(GetComponentX() - b.GetComponentX(), 2)) + (pow(GetComponentX() - b.GetComponentX(), 2) ));
}
