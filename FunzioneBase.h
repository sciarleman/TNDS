#ifndef __FunzioneBase__
#define __FunzioneBase__

#include <math.h>

class FunzioneBase {

  public:

  virtual double Eval (double) const = 0;
  virtual ~FunzioneBase() {;};

};

class Funzione : public FunzioneBase {

public:
	//costruttori e distruttore
  Funzione() {};
	//Funzione (double a, double b) {}
  ~Funzione () {}

  double Eval (double x) const override {return ((x*cos(1.8*x))/(1+sqrt(x)));}


private:

};

#endif // __FunzioneBase__
