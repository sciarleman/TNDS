#include <iostream>
#include <fstream> 
#include <cmath>
#include "Vettore.h"

using namespace std;

template <typename T> Vettore<T> read (unsigned int numerodati, char * nomefile) {

  Vettore <T> vettore(numerodati);

//	cout << nomefile << endl;
  ifstream fileinput(nomefile);

// se file non si apre
  if (!fileinput) {
    cout << "errore apertura file " << nomefile << endl;
    exit(1);
  }

// se richiesta file troppo grande
  else {
    for (unsigned int k = 0; k < numerodati; k++) {
      T valore = 0;
      fileinput >> valore;
      vettore.SetComponent(k, valore);
   
      if (fileinput.eof()) {
        cout << "Limite massimo dati nel file raggiunto" << endl;
        exit(0);
      }
    }
  }

 /* for (int k = 0; k < numerodati; k++)  controllo per vedere a schermo dati letti
    cout << data[k] << endl;*/

  return vettore;
}

// funzione calcolo media
template <typename T> double calcmedia( const Vettore<T> &vet) {

  double sum = 0;
  for (int i = 0; i < vet.GetNum(); i++) {
		sum += vet[i];		
  }
  return (sum / vet.GetNum());
}

//funzione calcolo varianza
template <typename T> double calcvarianza( const Vettore<T> &vet) {
	
  double sum = 0;
  for (int i = 0; i < vet.GetNum(); i++) {
    sum += vet[i];
  }
  T media = (sum / vet.GetNum());
	
  double scarti = 0;
  for (int i = 0; i < vet.GetNum(); i++) {
		double radscarti = (vet[i] - media);
    scarti += pow((radscarti), 2);

		
  }
  return ( scarti / (vet.GetNum() ) );
}


// funzione riordino vettore
template <typename T> void sort_by_value(Vettore<T> &vet) {
	
  for (int i = 0; i < vet.GetNum() - 1; i++) {
    for (int j = i + 1; j < vet.GetNum(); j++) {
      if (vet[i] > vet[j]) {
        T dep = vet[i];
        vet[i] = vet[j];
        vet[j] = dep;
      }
    }
  }
}

// funzione calcolo mediana (due casi se numero dati letti pari o dispari)
template <typename T> double calcmediana(Vettore<T> &vet) {

	sort_by_value(vet);

  double mediana;
  if (vet.GetNum() % 2 == 0) {
    T pre = vet[(vet.GetNum() / 2) - 1];
    T post = vet[(vet.GetNum() / 2)];
    mediana = (pre + post) / 2;
  } else {

		T valormedio = vet.GetNum()/2;
    mediana = vet.GetComponent(valormedio);

  }

  return mediana;
}

// stampa dati riordinati su file txt esterno
template <typename T> void Print( Vettore<T> &vet, const char *filename) { // overloading di funzioni

  ofstream fout("output_dati_riordinati.txt");
  for (int i = 0; i < vet.GetNum(); i++) {
		if (i<vet.GetNum()-1) {
    fout << vet[i] << endl;
			}
		else {
			fout << vet[i];
		}
  }
  fout.close();

}

//stampa vettore riordinato
template <typename T> void Print( Vettore<T> &vet) {
  for (int i = 0; i < vet.GetNum(); i++) {
    cout << vet[i] << endl;
  }
}



