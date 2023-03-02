#ifndef __INTEGRAL_H__
#define __INTEGRAL_H__

#include "FunzioneBase.h"
#include "SolutoreBis.h"
#include "RandomGen.h"
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

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
	
    unsigned int m_nstep = 4;

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
      //cout << (4. / 3.) * fabs(I2n - In) << endl;
    }

    while ((4. / 3.) * fabs(I2n - In) > precision);
    { return I2n; }
  }

	double StdDev (FunzioneBase &func, double precision, double Imedio) {
		
    unsigned int m_nstep = 4;

    double In;
    double I2n;
		double fk = 0.5*func.Eval(m_a) + 0.5*func.Eval(m_b);
		double scarti = 0;
    do {

			h = (m_b-m_a)/m_nstep;
			//cout << m_nstep << endl;
       for(int k=1; k<m_nstep; k+=2) { 
        fk += func.Eval(m_a+k*h);

				scarti += (func.Eval(m_a+k*h)-Imedio)*(func.Eval(m_a+k*h)-Imedio);
	        };

    		In = I2n;

        I2n = m_sign*fk*h;

        m_nstep *= 2;
      
    }

    while ((4. / 3.) * fabs(I2n - In) > precision);

		return (sqrt(scarti/(m_nstep-1)));
		
		}

};

//funzione Resto, di supporto per il calcolo del resto con metodo dei trapezi
double resto (double a, double b, double h){

	double deriv_seconda = 0;
	double R = ((b-a)/12.)*deriv_seconda* (h*h);

return R;
	
}

//---------------------------------------------------------------------
// Derived class : metodo dei trapezi con h variabile e precisione fissata
class Trapezi_hvariabile : public Integral {

public:

  Trapezi_hvariabile(double a, double b) : Integral(a, b) { ; };
  
  double Integra (double precision, FunzioneBase &func) override {
	
    unsigned int passi;

    double In = 0.;
    double I2n = 0.;
		double fk = 0.5*func.Eval(m_a) + 0.5*func.Eval(m_b);


		for(int m_nstep = 1 ; ; ){

			h = (m_b-m_a)/m_nstep;
			//cout << m_nstep << endl;
       for(int k=1; k<m_nstep; k+=2) { 
        fk += func.Eval(m_a+k*h);
	        };

    		In = I2n;

        I2n = m_sign*fk*h;

        m_nstep *= 2;
				passi = m_nstep;
			
		//cout << (4. / 3.) * fabs(I2n - In) << "\t" << passi << endl;

			if ((4. / 3.) * fabs(I2n - In) < precision) break;
  
    }
		//cout << passi << endl;
		//cout << m_nstep;
    return passi; 
  }

};


class IntegralMC {

	public: 
		IntegralMC(unsigned int seed) { m_myRand = new RandomGen(seed); m_error = 0.;};
		~IntegralMC() {;};

		double puntiAVE (double xmin, double xmax, FunzioneBase *f, double precisione) {
			double N = 1;
			double fsum = 0.;
			double punti = 0.;
			double precedente = 0.;
			
			for (int i = 0. ; ; i++){
				N++;
				precedente = fsum;
				double x = m_myRand->Unif(xmin, xmax);
				fsum += f->Eval(x);
				punti ++;

				//cout << fsum - precedente << endl;
				if (fabs(fsum - precedente) < precisione) break;
				}

			return punti;
				
		}

		double IntegraleAVE (double xmin, double xmax, FunzioneBase *f, int punti) {
			double N = 1;
			double fsum = 0.;
			
			for (int i = 0. ; i < punti ; i++){
				N++;
				double x = m_myRand->Unif(xmin, xmax);
				fsum += f->Eval(x);
				}

			return (xmax - xmin)*(fsum/N);
				
		}

		double StdDev (double xmin, double xmax, FunzioneBase *f, double punti) {
			
			double N = 1;
			double fsum = 0.;
			
			for (int i = 0. ; i < punti ; i++){
				N++;
				double x = m_myRand->Unif(xmin, xmax);
				fsum += f->Eval(x);
				}
			double scarti;
			
			for(int i = 0. ; i < punti ; i++){
				N++;
				double x = m_myRand->Unif(xmin, xmax);
				scarti += ((f->Eval(x))-fsum)*((f->Eval(x))-fsum);
				}

			double StdDev = sqrt (scarti/(punti-1));
			return (xmax - xmin)*(fsum/N);
				
		}


	private:
		RandomGen *m_myRand;
		double m_error;
		double m_points;
};





#endif // __INTEGRAL_H__
