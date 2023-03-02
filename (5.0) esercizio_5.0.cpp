#include "Posizione.h"
#include "Posizione.cpp"

#include <iostream>
#include <cstdlib>

using namespace std;

// Questo programma vuole com input da riga di comando le coordinate
// x, y e z di un punto e ne restituisce le coordinate sferiche
// e cilindiriche.

int main(int argc, char** argv) {

  // Controlla gli argomenti
  if ( argc!=4 ) {
    std::cerr << "Usage: " << argv[0] << " <x> <y> <z>" << endl;
    return -1;
  }

  double x = atof(argv[1]);
  double y = atof(argv[2]);
  double z = atof(argv[3]);

  // Crea un oggetto posizione ed accede ai vari metodi

  Posizione P(x,y,z);

  cout << "Coordinate cartesiane: " 
       << P.GetComponentX() << "," << P.GetComponentY() << "," << P.GetComponentZ() << endl;
  cout << "Coordinate cilindriche: " 
       << P.GetValueRho() << "," << P.GetAnglePhi()<< "," << P.GetComponentZ()<< endl;
  cout << "Coordinate sferiche: " 
       << P.GetValueRaggio() << "," << P.GetAnglePhi() << "," << P.GetAngleTheta() << endl;

  return 0;
}

