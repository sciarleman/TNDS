#include <iostream>
#include <fstream> 
#include <cmath>
#include <assert.h>

#include <vector>
#include <algorithm>

using namespace std;

template <typename T> vector<T> read ( int numerodati, const char* nomefile) {

	vector<T> vettore;

	//cout << nomefile << endl;
	
	ifstream fileinput(nomefile);

	// se file non si apre
	if (!fileinput) {
    cout << "errore apertura file " << nomefile << endl;
    exit(11);
  	}
	else {
    for ( int i=0 ; i < numerodati ; i++) {
			T val = 0;
			fileinput >> val;
			vettore.push_back( val );
// se richiesta file troppo grande
			if (fileinput.eof()) {
				cout << "Fine file raggiunto" << endl;
				exit(12);
			}
		}
	}
	return vettore;
}

template <typename T> vector<T> ReadAll (const char * nomefile) {

	vector<T> vettore;
	
	ifstream fileinput(nomefile);

// se file non si apre
  if (!fileinput) {
    cout << "errore apertura file " << nomefile << endl;
    exit(32);
  }
  else {
    while (!fileinput.eof()) {
      T valore = 0;
      fileinput >> valore;
      vettore.push_back( valore );
    }
  }
	return vettore;
}

// funzione calcolo media
template <typename T> double calcmedia( const vector<T> &vet) {

  double sum = 0;
  for (int i = 0; i < vet.size(); i++) {
		sum += vet[i];
  }
  return ( sum / vet.size());
}

//funzione calcolo varianza
template <typename T> double calcvarianza( const vector<T> &vet) {
	
  double sum = 0;
  for (int i = 0; i < vet.size(); i++) {
    sum += vet[i];
  }
  T media = (sum / vet.size());

  double scarti = 0;
  for (int i = 0; i < vet.size(); i++) {
		double radscarti = (vet[i] - media);
    scarti += pow((radscarti), 2);
	
  }
  return ( scarti / (vet.size() ) );
}


// funzione riordino vettore. è implementata anche la funzione sort specifica di vector
/*template <typename T> void sort_by_value(vector<T> &vet) {
	
  for (int i = 0; i < vet.size() - 1; i++) {
    for (int j = i + 1; j < vet.size(); j++) {
      if (vet[i] > vet[j]) {
        T dep = vet[i];
        vet[i] = vet[j];
        vet[j] = dep;
      }
    }
  }
}*/

// funzione calcolo mediana (due casi se numero dati letti pari o dispari)
template <typename T> double calcmediana(vector<T> &vet) {

	//funzione sort_by_value(vet);
	sort ( vet.begin(), vet.end());
	
  double mediana;
  if (vet.size() % 2 == 0) {
    T pre = vet[(vet.size() / 2) - 1];
    T post = vet[(vet.size() / 2)];
    mediana = (pre + post) / 2;
  } else {

		T valormedio = vet.size()/2;
    mediana = vet[valormedio];

  }

  return mediana;
}

// stampa dati riordinati su file txt esterno
template <typename T> void Print( vector<T> &vet, const char *filename) { // overloading di funzioni

  ofstream fout("output_dati_riordinati.txt");

  for (int i = 0; i < vet.size(); i++) {

		if (i<vet.size()-1) {
    fout << vet[i] << endl;
		}
		else {
			fout << vet[i];
		}
  }
  fout.close();

}

//stampa a schermo vettore riordinato
template <typename T> void Print( vector<T> &vet) {
  for (int i = 0; i < vet.size(); i++) {
    cout << vet[i] << endl;
  }
}


