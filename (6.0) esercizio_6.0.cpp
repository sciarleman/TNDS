#include "Particella.h"
#include "Particella.cpp"
#include <iostream>

using namespace std;

int main (){

  Particella *a = new Particella(1.,2.);
  Elettrone  *e = new Elettrone();
  Particella *b = new Elettrone(); // puntatore a Particella punta a un Elettrone

  a->Print(); // Meteodo Print di Particella
  e->Print(); // Meteodo Print di Elettrone
  b->Print(); // ???

  delete a;
  delete e;
  delete b;

  return 0;
}
