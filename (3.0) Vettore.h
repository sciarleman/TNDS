#ifndef __Vettore_h__
#define __Vettore_h__

#include <iostream>
#include <assert.h>

using namespace std;

template <typename T> class Vettore{

  public:

  	Vettore() {
			//cout << "\nchiamando il costruttore senza argomenti " << endl;
      dimensione = 0;
      puntatore = NULL;

    }
    
    Vettore(unsigned int Num) {
      //cout << "\nchiamando il costruttore con argomenti " << endl;
      dimensione = Num;
      puntatore = new double[Num];
      for (int k = 0 ; k < Num ; k++) {
				puntatore[k] = 0;
			} 
    }

    Vettore (const Vettore& vec) {
      dimensione = vec.GetNum();
      puntatore = new double[dimensione];
			for (int k=0; k<dimensione; k++ ) {
				puntatore[k] = vec.GetComponent(k);
			}

    }

    Vettore& operator= ( const Vettore& vec) {
      dimensione = vec.GetNum();
      if ( puntatore ) {delete[] puntatore;}
      
			puntatore = new double[dimensione];
      for (int z=0 ; z<dimensione ; z++) {
				puntatore[z] = vec.GetComponent(z);
			}

      return *this;

    }

    ~Vettore() {
      delete [] puntatore ;
    } 

    unsigned int GetNum() const {
      return dimensione;
    }

  	void SetComponent (unsigned int i, T a) {
      if (i < dimensione) {
        puntatore[i]=a;
      }
    	else {
      cout << "Errore di indice i: " << i << ", indice richiesto non esistente " << dimensione << endl;
      exit (-1);
  	  }
    }

    T GetComponent(unsigned int i) const {						//funzione che legge elemento in posizione richiesta

      if (i<dimensione) {
      	return puntatore[i];
      }
      else {
      	cout << "Errore di indice " << i << ": indice richiesto non esistente" << endl;
      	exit (-2);
      }
    }       

    void scambia(unsigned int uno, unsigned int due) {	//funzione scambia, trova e sostituisce elemento a posizione richiesta
      double dep = GetComponent(uno);
      SetComponent(uno, GetComponent(due));
      SetComponent(due, dep);
        
    }

    T& operator [] (unsigned int j) const {

      if (j < dimensione) {
        return puntatore[j];
      }
      else {
        cout << "Errore di indice " << j << ", indice richiesto non esistente " << dimensione << endl;
        exit (-3);
    	}

    }

  private:

    unsigned int dimensione;
    T* puntatore;

};

#endif 
