#ifndef __INTEGRAL_H__
#define __INTEGRAL_H__

#include <iostream>
#include "FunzioneBase.h"

using namespace std;

// Base class : "integrator" generico

class Integral {

 public:
  
  Integral (double a, double b){
    checkInterval (a,b);
    m_nstep = 0;
    h = 0; 
    sum = 0;
    m_integral =0;
  }

  virtual double Integra(unsigned int nstep, FunzioneBase& f) = 0;

 protected:

  void checkInterval (double a, double b){

		m_a = min (a,b);
		m_b = max (a,b);
		if (a > b) { m_sign = -1; }
			else { m_sign = 1; }
		
  }

  unsigned int m_nstep;
  double m_a, m_b;
  double sum, m_integral, h;
  int m_sign;
};

// derived class : Midpoint integrator

class Simpson : public Integral {

 public:

  Simpson (double a, double b) : Integral (a, b){;};

  double Integra(unsigned int nstep, FunzioneBase& func) override{

		m_nstep = nstep;
		h = (m_b-m_a)/(nstep);

		//cout << nstep << endl;
		//cout << m_nstep << endl;
		
		sum =( (1./3.)*func.Eval(m_a) + (1./3.)*func.Eval(m_b) );

		for (int i = 0; i < nstep; i++) {
			sum += ((2. + 2.*(i % 2))/ 3.)*func.Eval(m_a + (i)*h);}
/*		double sumdispari = 0.;

		for (int i =1; i < m_nstep; i++) {

			if (i%2 != 0) {
				sumdispari += (4./3.)*func.Eval(m_a + (i*h));  
			}
			if (i%2 == 0) {
				sumpari += (2./3.)*func.Eval(m_a + (i*h));
			}
		}		
		sum = ((1./3.)*func.Eval(m_a) + sumpari + sumdispari + (1./3.)*func.Eval(m_b));*/
			//cout << func.Eval(m_a + (i*h)) << endl;
			//cout << sum << endl;
/*	double b ;
		for (int i = 2 ; i < m_nstep ; i++) {
			b = b + (2./3.)*(func.Eval((m_a) + (i*h)));
		}
		double c;
		for (int i = 1 ; i < m_nstep ; i++) {
			b = b + (4./3.)*(func.Eval((m_a) + (i*h)));
		}
		double a = (1./3.) * func.Eval(m_a);
		double d = (1./3.) * func.Eval(m_b); 
*/
		
		m_integral = m_sign*sum*h;

		cout << m_sign << " " << h <<endl;

		if (nstep == 0) {cout << "Numero step non accettato" << endl; exit (-1);}
		
		return m_integral;
  };

};

#endif // __INTEGRAL_H__
