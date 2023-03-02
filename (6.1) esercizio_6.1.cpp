
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>

#include "FunzioneBase.h"
#include "Parabola.h"

using namespace std;

int main(int argc, char **argv) {

  if (argc < 4) {
    std::cerr << "Utilizzo: " << argv[0] << " <a> <b> <c>" << endl;
    return -1;
  }

  double a = atof(argv[1]);
  double b = atof(argv[2]);
  double c = atof(argv[3]);

	Parabola curva (a, b, c);

	double valoreVx = -b/(2*a);
	double valoreVy = curva.Eval(valoreVx);

	cout << "equazione con forma: (" << a << ")x^2 + (" << b << ")x + (" << c << ") = 0 \n" << endl;  
	
	cout << "vertice posizionato in x = " << valoreVx << endl;
	cout << "valore in y del vertice (valore f(x)) = \n" << valoreVy << endl;

	return 0;
	
}

