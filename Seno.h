#ifndef __Seno__
#define __Seno__

#include "FunzioneBase.h"
#include <cmath>

class Seno : public FunzioneBase {

public:
	//costruttori e distruttore
  Seno () {}
  ~Seno () {}

  double Eval (double x) const override {return sin(x);}


private:

};

#endif // __Seno__
        
