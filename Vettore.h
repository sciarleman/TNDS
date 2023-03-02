#ifndef __Vettore_h__
#define __Vettore_h__

#include <iostream>

using namespace std;

class Vettore {

public:
  Vettore();                 // costruttore base
  Vettore(unsigned int Num); // costruttore vettore con definita dimensione
  Vettore(const Vettore &);  // costruttore con argomento un altro vettore

  ~Vettore(); // distruttore

  Vettore &operator=(const Vettore &); // overloading operatore di assegnazione

  unsigned int GetNum() const { return dim; }

  double &operator[](unsigned int) const; // assegna operatore[]

  void SetCompo(unsigned int, double); // rimpiazza componenete i-esimo
  double Getcompo(unsigned int) const; // individua componente i-esimo

  void scambia(unsigned int, unsigned int); // funzione scambia

private:
  unsigned int dim; // dimensione del vettore
  double *punt;     // puntatore all'array
};

#endif
