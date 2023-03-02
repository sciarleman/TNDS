#ifndef __Parabola__
#define __Parabola__

class FunzioneBase {

  public:

  virtual double Eval (double) const = 0;
  virtual ~FunzioneBase() {;};

};

class Parabola : public FunzioneBase {

public:
	//costruttori e distruttore
  Parabola (double a, double b, double c) {m_a=a; m_b=b; m_c=c;}
  ~Parabola () {}

  double Eval (double x) const override {return m_a*(x*x) + m_b*(x) + m_c;}
  double GetA () const {return m_a;}
  double GetB () const {return m_b;}
  double GetC () const {return m_c;}

private:

  double m_a, m_b, m_c;

};

#endif // __Parabola__
