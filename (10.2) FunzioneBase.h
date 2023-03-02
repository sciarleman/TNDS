#ifndef __FunzioneBase__
#define __FunzioneBase__

#include <math.h>

class FunzioneBase {

  public:

  virtual double Eval (double) const = 0;

  virtual ~FunzioneBase () {}

};

class seno : public FunzioneBase {
    
    public:

    double Eval(double x) const {

        return sin(x);
    }
};

class parametro : public FunzioneBase {


	public:

	double Eval(double x, double y) const {

		return sqrt(x)*y;
		
	}
};

#endif // __FunzioneBase__
