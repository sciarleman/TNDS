#include "Particella.h"
#include "Particella.cpp"
#include <iostream> 

using namespace std;

int main() {

  Particella *a   = new Particella(1.,1.6E-19);
  Elettrone *e    = new Elettrone();
  
  // Metodi della classe base
  cout << "Particella " << a->GetValueMassa() << "," << a->GetValueCarica() << endl;
  a->Print(); 

  // Metodi della classe derivata
  cout << "Elettrone " << e->GetValueMassa() << "," << e->GetValueCarica() << endl;
  e->Print(); 

  Particella b(*a) ;  // costruisco una Particella a partire da una Particella
  Particella d(*e);   // costruisco una Particella a partire da un Elettrone

  return 0;

}
