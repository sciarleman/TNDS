#include "PuntoMateriale.h"
#include <cmath>
#include <iostream>

PuntoMateriale::PuntoMateriale(double massa, double carica, const Posizione& r) {

	Particella(massa, carica), Posizione(r);
	
}

PuntoMateriale::PuntoMateriale(double massa, double carica, double x, double y, double z) {

	Particella(massa, carica), Posizione(x, y, z);

}

PuntoMateriale::~PuntoMateriale(){
	
}

CampoVettoriale PuntoMateriale::CampoElettrico(const Posizione& r) const {
	
	/*double C = 8.99E9;
	double carica = -(2*1.60217653E-19);
	double eo = 8.85418781E-12;
 	CampoVettoriale ValoreCampoElettricoX = (C*carica.GetValueCarica())/pow(.GetValueFx(),2);
	double Ex = GetComponentX() + (carica*C)/(Distanza(r)*cos(GetAnglePhi())*sin(GetAngleTheta()))*(Distanza(r)*cos(GetAnglePhi())*sin(GetAngleTheta()));
	double Ey = GetComponentY() + (carica*C)/((Distanza(r)*sin(GetAnglePhi())*sin(GetAngleTheta()))*(Distanza(r)*sin(GetAnglePhi())*sin(GetAngleTheta())));
	double Ez = GetComponentZ() + (carica*C)/((Distanza(r)*cos(GetAngleTheta()))*(Distanza(r)*cos(GetAngleTheta())));

	CampoVettoriale E = Ex + Ey + Ez;
	
	return E;*/

	double Ex = ;
	double Ey = ;
	double Ez = ;

	return CampoVettoriale(r.GetComponentX() , r.GetComponentY() , r.GetComponentZ(), Ex, Ey, Ez);
}

CampoVettoriale PuntoMateriale::CampoGravitazionale(const Posizione& r) const {

	/*double G = 6.67259*pow(10,-11);
	double ValoreCampoGravitazionale = (G*massa.GetValueMassa()/pow(r.GetValueRaggio(),2));

	return ValoreCampoGravitazionale;*/

	double Gx = ;
	double Gy = ;
	double Gz = ;

	return CampoVettoriale (r.GetComponentX() , r.GetComponentY() , r.GetComponentZ() , Gx , Gy , Gz);
	
}
