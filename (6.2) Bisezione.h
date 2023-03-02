#ifndef __bisezione__
#define __bisezione__

#include <float.h> // Serve per includere DBL_MAX
#include "Solutore.h"

// funzione sign utile negli algoritmi di ricerca zeri. Potete aggiungerla come
// funzione che eredita da FunzionaBase 

int sign(double x){
  if(x<0)
    return -1;
  else
    return 1;
}

class Bisezione : public Solutore {

public:

// costruttori 

	Bisezione () : Solutore() {;} ;
	Bisezione (double a, double b, double prec) : Solutore (a,b,prec) { ; } ;

 	~Bisezione () {;};

	double CercaZeri (double depinf, double depsup, const FunzioneBase& f, double prec = 0.001, unsigned int nmax = 100 ) override {
		
		double zeropossibile;
		m_niterazioni = 0;
		m_a = depinf;
		m_b = depsup;
	
		if (depinf < depsup) { 
			m_a = depinf; m_b = depsup;
		}
				else {
					m_a = depsup ; m_b = depinf;
				}
			//cout << depinf << endl;
			//cout << depsup << endl;		
			while (double m_precisione = (abs(depinf - depsup)) > prec) {

			double a = f.Eval(m_a);
			double b = f.Eval(m_b);

			//	cout << f.Eval(m_a) << endl;
			//	cout << f.Eval(m_b) << endl;			
			//	cout << (m_a - m_b) << endl;
		
			zeropossibile = (depinf + depsup)/2;
			//	cout << zeropossibile << endl;
		
			if (m_niterazioni > m_nmax) break;
			
			m_niterazioni++;
			
			if (sign(f.Eval(zeropossibile)) * sign(f.Eval(depinf)) > 0) { depinf = zeropossibile; }
			else { depsup = zeropossibile;};
			//cout << zeropossibile << endl;
		
			}
		
		return zeropossibile;	
		
	}
};

#endif //__Bisezione.h__
