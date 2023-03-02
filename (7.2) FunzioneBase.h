#ifndef __FunzioneBase__
#define __FunzioneBase__

#include <math.h>

class FunzioneBase {

  public:

  virtual double Eval (double) const = 0;
  virtual ~FunzioneBase() {;};

};

class Seno : public FunzioneBase {

public:
	//costruttori e distruttore
  Seno() {};
	Seno (double a, double b) {}
  ~Seno () {}

  double Eval (double x) const override {return sin(x);}


private:

};

#endif // __FunzioneBase__
