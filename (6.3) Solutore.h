#ifndef __solutore__
#define __solutore__

#include <iostream>
#include "Tangente.h"

using namespace std;

class Solutore {

public:

	// Costruttori 

	Solutore() {;};
	Solutore(double precisione){m_precisione=precisione;};

	// Distruttore virtuale

	virtual ~Solutore() {;}; 

	
  virtual double CercaZeri (double xmin, double xmax, const FunzioneBase& f, double prec, unsigned int nmax = 100 ) = 0 ;

	virtual double ContaZeri (double xmin, double xmax, const FunzioneBase& f, double prec, unsigned int nmax = 100 ) = 0 ;

  void SetPrecisione (double epsilon) { m_precisione=epsilon; }
  void SetNMaxiterazioni (unsigned int n) { m_nmax = n; }

  unsigned int GetNMaxiterations () {return m_nmax; }
  unsigned int GetNiterations () {return m_niterazioni; }
 	double GetPrecisione () { return m_precisione; }

protected:

  double m_a, m_b;
  double m_precisione;
  unsigned int m_nmax, m_niterazioni;
	
};

#endif // __solutore__
