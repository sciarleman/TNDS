#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


double *read( const string& nomefile, int numerodati){          //se sai già la dimensione del file 
 
	fstream documento;
	double *out = new double[numerodati];

	if (!documento) {
		cout << "Errore in apertura file" << nomefile << endl;
		exit (11);
	}

	else {
    documento.open(nomefile, ios::in);

    for (int i = 0; i < numerodati; i++){
        documento >> out[i] ;
    	}

		if (documento.eof()) {
    	cout << "Limite massimo raggiunto. Massimo 1000000 file" << endl;
      exit(0);
		}
  return out;
	}
}

double calcmedia(double *m, int numerodati) {

    double sum = 0;
    for (int i = 0; i <  numerodati; i++){
        sum += m[i];
    }
    return sum/double (numerodati);
}

double calcvarianza(double *m, int numerodati){
    double sum = 0;
    for (int i = 0; i < numerodati; i++){
        sum += m[i];
    }
    double media = sum/numerodati;
    
    double scarti = 0;
    for(int i = 0; i < numerodati; i++){
        scarti += pow((m[i] - media),2);
    }
    return (scarti/(numerodati-1));
}

void riordina(double *m, int numerodati){
    for (int i = 0; i < numerodati - 1; i++){
        for (int j = i + 1; j < numerodati; j++){
            if (m[i] > m[j]){
                double dep = m[i];
                m[i] = m[j];
                m[j] = dep;
            }
        }   
    }
}

double calcmediana(double *m, int numerodati){
    double mediana;
    if(numerodati%2 == 0){
        double pre = m[(numerodati/2) -1];
        double post = m[(numerodati/2)];
        mediana = (pre + post)/2;
    }else {
        mediana = m[(numerodati+1)/2];
    }

    return mediana;
}

void print(const char* filename, double *m, int ntot){                  //overloading di funzioni
    fstream outfile(filename, ios::out);
    
    for( int i=0; i < ntot; i++){
        outfile << m[i] << endl;
    }
    outfile.close();
}

void print(double *m, int ntot){
    for(int i = 0; i < ntot; i++){
        cout << m[i] << endl;
    }
}
