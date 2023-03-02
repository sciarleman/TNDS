#ifndef __INTEGRAL_H__
#define __INTEGRAL_H__

#include "FunzioneBase.h"
#include <cfloat>
#include <iostream>
#include <math.h>

using namespace std;

// Base class : "integrator" generico

class Integral {

public:
  Integral(double a, double b) {
    checkInterval(a, b);
    m_nstep = 0;
    h = 0;
    sum = 0;
    m_integral = 0;
  }

  
  virtual double Integra(double precision, FunzioneBase &func) = 0;

protected:
  void checkInterval(double a, double b) {

    m_a = min(a, b);
    m_b = max(a, b);
    if (a > b) {
      m_sign = -1;
    } else {
      m_sign = 1;
    }
  }

  unsigned int m_nstep;
  double m_a, m_b;
  double sum, m_integral, h;
  int m_sign;
};

//---------------------------------------------------------------------
// Derived class : metodo dei trapezi
class Trapezi : public Integral {

public:

  Trapezi(double a, double b) : Integral(a, b) { ; };
  
  double Integra (double precision, FunzioneBase &func) override {
	
    unsigned int m_nstep = 2;

    double In;
    double I2n;
		double fk = 0.5*func.Eval(m_a) + 0.5*func.Eval(m_b);
		
    do {

			h = (m_b-m_a)/m_nstep;
			//cout << m_nstep << endl;
       for(int k=1; k<m_nstep; k+=2) { 
        fk += func.Eval(m_a+k*h);
	        };

    		In = I2n;

        I2n = m_sign*fk*h;

        m_nstep *= 2;
      
    }

    while ((4. / 3.) * fabs(I2n - In) > precision);
    { return I2n; }
  }

};


#endif // __INTEGRAL_H__
