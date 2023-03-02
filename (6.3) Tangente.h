#ifndef __Parabola__
#define __Parabola__

#include <cmath>

class FunzioneBase {

  public:

  virtual double Eval (double) const = 0;
  virtual ~FunzioneBase() {;};

};

class Tangente : public FunzioneBase {

public:
	//costruttori e distruttore
  Tangente () {}
  ~Tangente () {}

  double Eval (double x) const override {return (sin(x) - x*cos(x)) ;}

private:

};

#endif // __Parabola__
