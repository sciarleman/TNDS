#ifndef __RANDOMGEN_H__
#define __RANDOMGEN_H__

#include <iostream>
#include <math.h>
using namespace std;

class RandomGen{

  public:
    RandomGen();
		RandomGen(unsigned int n) {
			m_a = 1664525;
    	m_c = 1013904223;
     	m_m = pow(2, 31) ;
			m_seed = n;
		}

    void SetA(unsigned int a) {m_a = a;}
    void SetC(unsigned int c) {m_c = c;}
    void SetM(unsigned int m) {m_m = m;}

//_____________________________________________________________________
    double Rand() {

			m_seed = ( m_a * m_seed + m_c) % m_m ;
			//cout << "\n\t" << x << "\n" << endl;
				
			return double(m_seed) / m_m;
		}

//_____________________________________________________________________
    double Unif(double xmin, double xmax) {

			return xmin + (xmax - xmin) * Rand();
		}

//_____________________________________________________________________
    double Gauss(double mean, double sigma) {

			double s = Rand();
			double t = Rand();
			double x = sqrt(-2. * log(1.-s)) * cos(2. * M_PI * t);

			return mean + (x * sigma);
		}

//_____________________________________________________________________
    double GaussAR(double mean, double sigma) {
			double min = -4 * sigma;
			double max = 4 * sigma;
			double gas_max = (1./(sigma * sqrt(2.*M_PI))) ;
			double xi = 0.;

			for (;;) {
				double y = Unif(0, gas_max);
				double x = Unif(min, max);
				double fx = (1./(sigma * sqrt(2.*M_PI))) * exp(-(pow((x-mean), 2) / (2. * pow ( sigma , 2)))) ;

				if (y<fx) {
					xi = x;
					break;
				}	
			}
			return xi;
		}

//_____________________________________________________________________
    double Exp(double mean) {
			
		return (-1./mean)*log(1-Rand());
		}

  private:
    unsigned int m_a, m_c, m_m;
    unsigned int m_seed;
};

//_____________________________________________________________________


#endif
