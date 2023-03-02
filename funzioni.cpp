#include <cmath>
#include <fstream>
#include <iostream>

#include "funzioni.h"

using namespace std;

//funzione lettura file esterno
Vettore read(int numerodati, char const *nomefile) {

  Vettore data(numerodati);

  ifstream fileinput(nomefile);

// se file non si apre
  if (!fileinput) {
    cout << "errore apertura file " << nomefile << endl;
    exit(0);
  }

// se richiesta file troppo grande
  else {
    for (int k = 0; k < data.GetNum(); k++) {
      double t;
      fileinput >> t;
      data.SetCompo(k, t);
   
      if (fileinput.eof()) {
        cout << "Limite massimo raggiunto. Massimo 1000000 file" << endl;
        exit(0);
      }
    }
  }

 /* for (int k = 0; k < numerodati; k++)  controllo per vedere a schermo dati letti
    cout << data[k] << endl;*/

  return data;
}

// funzione calcolo media
double calcmedia(const Vettore &vet) {

  double sum = 0;
	
  for (int i = 0; i < vet.GetNum(); i++) {

		sum += vet[i];
		
  }

  return ( sum / vet.GetNum() );
}

// funzione calcolo varianza
double calcvarianza(const Vettore &vet) {
	
  double sum = 0;
	
  for (int i = 0; i < vet.GetNum(); i++) {
    sum += vet[i];
  }
  double media = (sum / vet.GetNum());

  double scarti = 0;

  for (int i = 0; i < vet.GetNum(); i++) {
		double radscarti = (vet[i] - media);
    scarti += pow((radscarti), 2);

		
  }
  return ( scarti / (vet.GetNum() ) );
}

// funzione riordino vettore
void sort_by_value(Vettore& vet) {
	
  for (int i = 0; i < vet.GetNum() - 1; i++) {
    for (int j = i + 1; j < vet.GetNum(); j++) {
      if (vet[i] > vet[j]) {
        double dep = vet[i];
        vet[i] = vet[j];
        vet[j] = dep;
      }
    }
  }
}

// funzione calcolo mediana (due casi se numero dati letti pari o dispari)
double calcmediana(Vettore& vet) {

	sort_by_value(vet);

	
  double mediana;
  if (vet.GetNum() % 2 == 0) {
    double pre = vet[(vet.GetNum() / 2) - 1];
    double post = vet[(vet.GetNum() / 2)];
    mediana = (pre + post) / 2;
  } else {

		double valormedio = vet.GetNum()/2;
    mediana = vet.Getcompo(valormedio);

  }

  return mediana;
}

//stampa vettore riordinato
void Print(const Vettore &vet) {
  for (int i = 0; i < vet.GetNum(); i++) {
    cout << vet[i] << endl;
  }
}

// stampa dati riordinati su file txt esterno
void Print(const Vettore &vet, const char *filename) { // overloading di funzioni

  ofstream fout(filename, ios::out);

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
