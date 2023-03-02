
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include<iomanip>

#include "Parabola.h"
#include "Solutore.h"
#include "Bisezione.h"

using namespace std;

int main(int argc, char **argv) {

  if (argc < 5) {
    cerr << "Utilizzo: " << argv[0] << " <estremo inferiore> <estremo superiore> <precisione richiesta> <numero iterazioni> " << endl;
    return -1;
  }

	Parabola funzione ( 3 , 5 , -2);
	
  double inf = atof(argv[1]);
  double sup = atof(argv[2]);
  double prec = atof(argv[3]);
	double iterazioni = atof(argv[4]);

	Bisezione zerovero;
	double valore = zerovero.CercaZeri(inf, sup, funzione, prec);

	//sistema di controllo valore della funzione in quel punto sia vicino a zero con precisione prec
	if ( prec > 0.0001 && funzione.Eval(valore) > 10*prec) {
		cout << "Nessuno zero della funzione nell'intervallo scelto" << endl;
		exit(0);
	}
	else if ( funzione.Eval(valore) > 100*prec ) {
		cout << "Nessuno zero della funzione nell'intervallo scelto" << endl;
		exit(0); 
	}

	double cifre_significative = -log10(prec);
	cout << "Zero della funzione, nell'intervallo (" << inf << ", " << sup << ") in posizione x = " << fixed << setprecision(cifre_significative)<<  valore << endl; 
	//cout << funzione.Eval(valore);
	
	return 0;
	
}
