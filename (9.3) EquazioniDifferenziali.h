#ifndef __EQ_DIFF__
#define __EQ_DIFF__

#include "VectorOperations.h"
#include <cmath>

using namespace std;

// Classe astratta, restituisce la derivata nel punto x al tempo t

class FunzioneVettorialeBase {

public:
  virtual vector<double> Eval(double t, const vector<double> & x) const = 0;
};

// Caso fisico 

class OscillatoreArmonico : public FunzioneVettorialeBase {

public:

  OscillatoreArmonico(double omega0) { m_omega0 = omega0; };

  virtual vector<double> Eval(double t, const vector<double> &x) const override {	

		vector<double> der = {x[1], -(9.806/1.)*sin(x[0])};
		return der; 
		}

private:
  double m_omega0;
};

class pendolo : public FunzioneVettorialeBase {

  public:

  pendolo(double lunghezza) {m_lunghezza = lunghezza;};

  double g = 9.806;

  vector<double> Eval(double t, const vector<double> &x) const override {

  vector<double> v { x[1], -pow(sqrt(g/m_lunghezza), 2)*sin(x[0]) };

  return v;

  }

private:
  double m_lunghezza;
};

/*
class PendoloIdeale : public FunzioneVettorialeBase {

public:

  PendoloIdeale(double l) { m_L = l; };

  virtual vector<double> Eval(double t, const vector<double> &x) const override {	

		for (double i = 0 ; i < 3; i += 0.01) {

		vector<double> der = {x[i], (-9.806/m_L)*sin(x[0])};
		return der; 
			}

		return vector<double> ve = {0.};
		}

private:
  double m_L;
};*/

// Classe astratta per un integratore di equazioni differenziali

class EquazioneDifferenzialeBase {
public:
  virtual vector<double> Passo(double t, const vector<double> &x, double h, const FunzioneVettorialeBase &f) const = 0;
};

class RungeKutta : public EquazioneDifferenzialeBase {
public:

  virtual vector<double> Passo(double t, const vector<double> &x, double h, const FunzioneVettorialeBase &f) const override {

		
		vector<double>k1 = f.Eval(t, x);
		vector<double>k2 = f.Eval(t+h/2, x+ (k1*h/2.));
		vector<double>k3 = f.Eval(t+h/2, x+ (k2*h/2.));
		vector<double>k4 = f.Eval(t+h, x+ (k3*h));

		/*cout << "k1 = " ; Print (k1);
		cout << "\tk2 = " ;
		Print (k2) ;
		cout << "\tk3 = " ;
		Print (k3) ; 
		cout << "\tk4 = " ;
		Print (k4) ;*/

		//cout << "\nh = " << h << endl;
		//Print(x + (k1 + 2.*k2 + 2.*k3 + k4)*(h/6));

	return  (x + (k1 + 2.*k2 + 2.*k3 + k4)*(h/6));

  }
};

class Seno : public FunzioneVettorialeBase {

public:
	//costruttori e distruttore
  Seno () {}
  ~Seno () {}

	vector<double> Eval (double t, const vector<double> &x) const override {

		vector<double> confr;
		confr.push_back(sin(t));
	
		return confr;
	
		}
		
		
};



#endif // __EQ_DIFF__

