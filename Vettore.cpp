#include "Vettore.h"

Vettore::Vettore() {                        								//costruttore senza argomenti

    cout << "\nchiamando il costruttore senza argomenti " << endl;
    dim = 0;
    punt = NULL;

}

Vettore::Vettore(unsigned int Num) {        								//costruttore con argomenti

    cout << "\nchiamando il costruttore con argomenti (che accetta interi) \n" << endl;
    dim = Num;
    punt = new double[Num];
    for (int k = 0 ; k < Num ; k++) punt[k] = 0;

}

Vettore::~Vettore() {                    										//distruttore

    cout << "chiamando il distruttore " << endl;
    delete[] punt;

}

void Vettore::SetCompo(unsigned int i, double a) {          //funzione set component, scambia componente

    if (i < dim) {
        punt[i]=a;
    }
    else {
        cout << "Errore di indice i " << i << ", a dimensione " << dim << endl;
        exit (-1);
    }
}

double Vettore::Getcompo(unsigned int i) const {						//funzione get component, legge elemento in posizione richiesta

    if (i<dim) {
        return punt[i];
    }
    else {
        cout << "Errore all' indice " << i << ", con dimensione " << dim << endl;
        exit (-1);
    }
}

void Vettore::scambia(unsigned int uno, unsigned int due) {	//funzione scambia, trova e sostituisce elemento a posizione richiesta

    double dep = Getcompo(uno);
    SetCompo(uno, Getcompo(due));
    SetCompo(due, dep);

}

double& Vettore::operator[] (unsigned int j) const {				// definisce "[]" come operatore

    if (j < dim) {
        return punt[j];
    }
    else {
        cout << "Errore all' indice " << j << ", con dimensione " << dim << endl;
        exit (-1);
    }
    
}

Vettore::Vettore(const Vettore& Vector) {										//definisce un costruttore copyconstructor
    dim = Vector.GetNum();
    punt = new double[dim];
    for (int k=0; k<dim; k++) punt[k]=Vector.Getcompo(k);

}

Vettore& Vettore::operator=(const Vettore& Vector) {				//definise "=" come operatore

    dim = Vector.GetNum();
    if ( punt ) delete[] punt;
    punt = new double[dim];
    for (int z=0 ; z<dim ; z++) punt[z]=Vector.Getcompo(z);

    return *this;                                               

/*puntatore "this" indica un puntatore all'oggetto cui si sta applicando un metodo. 
E' particolarmente utile in alcune occasioni, come nel caso ell'operatore di assegnazione, in cui
si deve restituire una copia dell'oggetto corrente*/

}
