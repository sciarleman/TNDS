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

// derived class : Simpson integrator

class Simpson : public Integral {

 public:

  Simpson (double a, double b) : Integral (a, b){;};

  double Integra(unsigned int nstep, FunzioneBase& func) override{

		m_nstep = nstep;
		h = (m_b-m_a)/(m_nstep);

		sum =( (1./3.)*func.Eval(m_a) + (1./3.)*func.Eval(m_b) );

		for (int i = 1; i <= nstep-1; i ++) {
			sum += ((2. + 2.*(i % 2))/ 3.)*func.Eval(m_a + i*h);
			
			//cout << i << " " << (2. + 2.*(i % 2))/ 3. << endl;	
		}
		
		m_integral = m_sign*sum*h;

		if (nstep == 0) {cout << "Numero step non accettato" << endl; exit (-1);}
		
		return m_integral;
  };

};

#endif // __INTEGRAL_H__
