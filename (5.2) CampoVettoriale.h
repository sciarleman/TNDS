#ifndef __CampoVettoriale_h__
#define __CampoVettoriale_h__

#include "Posizione.h"
#include<iostream>
using namespace std;



class CampoVettoriale : public Posizione {

public:

  CampoVettoriale(const Posizione&);
  CampoVettoriale(const Posizione&, double Fx, double Fy, double Fz);
  CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz);
  ~CampoVettoriale();

  CampoVettoriale & operator+=( const CampoVettoriale & ) ;
  CampoVettoriale operator+( const CampoVettoriale & ) const;
  
  double GetFx() const {return dim_Fx;}
  double GetFy() const {return dim_Fy;}
  double GetFz() const {return dim_Fz;}

  double Modulo();
		
private:

  double dim_Fx, dim_Fy, dim_Fz;

};

#endif // __CampoVettoriale_h__ 
