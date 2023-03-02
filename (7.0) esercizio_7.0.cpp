#include <cmath>
#include <iostream>
#include <iomanip>

#include "Integral.h"
#include "Seno.h"

using namespace std;

int main(int argc, char * argv[] ) {
  
  if (argc != 2) {
    cerr << "Utilizzo del programma, specificare " << argv[0] << "<nstep>" << endl;
    return -1;
  }

  unsigned int nstep = atoi(argv[1]);

  Seno f;
  Midpoint myInt(0,M_PI);

  double I = myInt.Integra(nstep, f);

  cout << " Passi = " << setw(5) << nstep 
       << " I = "     << setw(5) << I
       << endl;
  
  return 0;
}
