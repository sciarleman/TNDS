#include "PuntoMateriale.h"
#include <cmath>
#include <iostream>

PuntoMateriale::PuntoMateriale(double massa, double carica, const Posizione& r) : Particella(massa, carica), Posizione(r) {
	
};

PuntoMateriale::PuntoMateriale(double massa, double carica, double x, double y, double z) : Particella(massa, carica), Posizione(x, y, z) {

};

//PuntoMateriale::~PuntoMateriale(){};

CampoVettoriale PuntoMateriale::CampoElettrico(const Posizione& r) const {

	/*CampoVettoriale E(r);
	double C = 8.99E9;

	double Ex = (GetValueCarica()*(4*M_PI*8.854187818E-12))*(r.GetComponentX()-GetComponentX())/pow(Distanza(r),3);
	double Ey = (GetValueCarica()*(4*M_PI*8.854187818E-12))*(r.GetComponentY()-GetComponentY())/pow(Distanza(r),3);
	double Ez = (GetValueCarica()*(4*M_PI*8.854187818E-12))*(r.GetComponentZ()-GetComponentZ())/pow(Distanza(r),3);*/
	//cout << carica_q << " " << Ex << " " << Ey << " " << Ez << " " << Distanza(r) << endl ;
	//E.SetComponent(Ex, Ey, Ez);

	  CampoVettoriale E(r);
    const double e0 = 8.854187818E-12;
    double Ex = (GetValueCarica()/(4*M_PI*e0))*((r.GetComponentX()-GetComponentX())/(pow(Distanza(r), 3)));
    double Ey = (GetValueCarica()/(4*M_PI*e0))*((r.GetComponentY()-GetComponentY())/(pow(Distanza(r), 3)));
    double Ez = (GetValueCarica()/(4*M_PI*e0))*((r.GetComponentZ()-GetComponentZ())/(pow(Distanza(r), 3)));
   
	return CampoVettoriale(r, Ex, Ey, Ez);;
}
