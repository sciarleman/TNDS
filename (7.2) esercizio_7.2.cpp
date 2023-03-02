#include <iostream>
#include <cmath>
#include <iomanip>

#include "Integral.h"

using namespace std;

int main(int argc, char * argv[] ) {

  if (argc != 2) {
    cerr << "Utilizzo del programma, specificare " << argv[0] << " <precisione>" << endl;
    return -1;
  }

  double precisione = atof(argv[1]);	

  Trapezi myInt(0, M_PI);
	Seno sin(0, M_PI);

	double E = -log10(precisione);

	double I = myInt.Integra(precisione, sin);
  cout  << fixed << setprecision(E)<< " I = "     << setw(5) << I << " precisione: " << precisione << " " <<endl;

  return 0;
	
}
