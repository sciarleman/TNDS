#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>

#include "funzioni.h"

using namespace std;


int main(int argc, char** argv){

    if (argc < 4){
        cout << "Utilizzo programma " << argv[0] << " : inserire "<< "<numero dati richiesti>  <file di input>  <file di output (dei dati riordinati)>"<< endl;               
        return -1;
    }

    	//devo passare il numero dei dati e i nome del file tramite terminale con 
    int numerodati = atoi(argv[1]);           
    char *nomefile = argv[2]; 
    char *fileout = argv[3];           
                                             
    double *w = read (nomefile, numerodati);
    	/* for (int i= 0; i < 20 ; i ++){
        cout << w[i] << endl;              	 //controllo funzione read
    	}*/
	
    	//cout <<"numero dati = " << numerodati << endl;		//controllo se viene rispettata la quantità di dati messa in input
	
    cout << "MEDIA = " << calcmedia(w, numerodati) << endl;
    cout << "VARIANZA = " << calcvarianza(w, numerodati) << endl;
    riordina(w, numerodati);
    cout << "MEDIANA= " << calcmediana(w,numerodati) << endl;

    /*for (int i= 0; i < 5 ; i ++){
        cout << w[i] << endl;              		//controllo funzione riordino
    } */
    
    print(fileout, w, numerodati);         	  //stampa sul file di uscita 
    	//print(w, numerodati);              		  //stampa sul terminale dati riordinati (può causare rallentamenti con numeri elevati di adti richiesti))
    
    delete []w;

    return 0;
}
