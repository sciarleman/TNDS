#include "CampoVettoriale.h"
#include <cmath>

using namespace std;



//costruttore vuoto 
CampoVettoriale::CampoVettoriale(const Posizione & r) { //costruttore vettore nullo in punto assegnato

	Posizione a(r);
	dim_Fx=0.;
	dim_Fy=0.;
	dim_Fz=0.;
	
	
	
	
}

//costruttore a partire da coordinate
CampoVettoriale::CampoVettoriale(const Posizione& r, double Fx, double Fy, double Fz) : Posizione(r) {

	dim_Fx=Fx;
	dim_Fy=Fy;
	dim_Fz=Fz;

}

CampoVettoriale::CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz) : Posizione (x,y,z) {

	dim_Fx=Fx;
	dim_Fy=Fy;
	dim_Fz=Fz;
	
}


//distruttore
CampoVettoriale::~CampoVettoriale(){
	
}

CampoVettoriale CampoVettoriale::operator+ (const CampoVettoriale &v) const {
	
	if (( v.GetComponentX() != GetComponentX()) || (v.GetComponentY() != GetComponentY()) || (v.GetComponentZ() != GetComponentZ()) ) {
		cerr << "Non possibile effettuare somma di campi vettoriali in punti diversi" << endl;
		exit (-20);
	}

	CampoVettoriale Somme ( v );
	Somme.dim_Fx += GetFx();
	Somme.dim_Fy += GetFy();
	Somme.dim_Fz += GetFz();

	return Somme;
	
}

CampoVettoriale & CampoVettoriale::operator+= ( const CampoVettoriale &v ) {

	return (*this) = (*this) + v ;
}


double CampoVettoriale::Modulo() {

	double valore = sqrt(dim_Fx*dim_Fx+dim_Fy*dim_Fy+dim_Fz*dim_Fz);
	return valore;
	
}

/*//coordinate sferiche
double CampoVettoriale::GetValueRaggio() const {
	return sqrt(pow(dim_x,2)+pow(dim_y,2)+pow(dim_z,2));
}

double CampoVettoriale::GetAnglePhi() const {
	return atan2(dim_y, dim_x);
}

double CampoVettoriale::GetAngleTheta() const {
	return acos(dim_z/GetValueRaggio());
}

//coordinate cilindriche (raggio)
double CampoVettoriale::GetValueRho() const {
	return sqrt(pow(dim_x,2)+pow(dim_y,2));
}*/

//distanza tra due punti

