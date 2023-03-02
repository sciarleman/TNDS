
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>

#include "Tangente.h"
#include "Solutore.h"
#include "Bisezione.h"

using namespace std;

int main(int argc, char **argv) {

  if (argc < 3) {
    cerr << "Utilizzo: " << argv[0] << " <precisione richiesta> <numero iterazioni> " << endl;
    return -1;
  }

	Tangente funzione;
	
  double prec = atof(argv[1]);
	double iterazioni = atof(argv[2]);
	double inf;
	double sup;
	
	Bisezione numerozeri;
	double zeri = numerozeri.ContaZeri(inf, sup, funzione, prec);

	return 0;
	
}
