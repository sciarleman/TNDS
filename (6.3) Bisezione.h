#ifndef __bisezione__
#define __bisezione__

#include <vector>
#include <math.h>
#include <float.h> // Serve per includere DBL_MAX
#include<iomanip> // per il setprecision

#include "Solutore.h"
#include "Tangente.h"

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
	Bisezione (double prec) : Solutore (prec) { ; } ;

 	~Bisezione () {;};

	double CercaZeri (double depinf, double depsup, const FunzioneBase& f, double prec, unsigned int nmax = 100 ) override {
		
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
		while (double m_precisione = (abs(depinf - depsup)) > prec ) {
			
			zeropossibile = (depinf + depsup)/2;
			//cout << zeropossibile << endl;
			
			if (sign(f.Eval(zeropossibile)) * sign(f.Eval(depinf)) > 0) { depinf = zeropossibile; }
			else { depsup = zeropossibile;};
			//cout << zeropossibile << endl;

			if (m_niterazioni > nmax) break;
			m_niterazioni++;

		}
		
	return zeropossibile;	
		
	}

	double ContaZeri (double depinf, double depsup, const FunzioneBase& f, double prec, unsigned int nmax = 100 ) override {

		Tangente fn;
	
 		Bisezione centrozero;
		//double valore = centrozero.CercaZeri(depinf, depsup, fn, prec);

		for (int n = 1 ; n <= 20 ; n++) {
			depinf = n*M_PI;
			depsup = n*M_PI + (M_PI*0.5) ;
	
			double zero = centrozero.CercaZeri(depinf, depsup, fn, prec);
			double cifre_significative = -log10(prec);
			int m = n + 1;
			cout << "Zero numero " << m << " in posizione  x = "  << fixed << setprecision(cifre_significative) << zero << endl;

		}

	return -1;	
	}


};
#endif //__Bisezione.h__
