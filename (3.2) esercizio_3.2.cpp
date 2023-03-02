#include <iostream>
#include <fstream>
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"

#include "funzioni.h"

int main( int argc , char** argv ) {

  if ( argc < 2 ) {
    cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
    return -1 ;
  }  
	
	if (argc == 3) {
		
  TApplication app("app",0,0);
  
  // leggo dati da file

  vector<double> vet = read<double>( atoi(argv[1]), argv[2] );

  // creo e riempio il vettore. L'opzione StatOvergflows permetter di calcolalare le informazioni statistiche anche se il dato sta fuori dal range di definizione dell'istogramma
  
  TH1F histo ("histo","istogramma", 100, -10, 100) ;
  histo.StatOverflows( kTRUE );
  for ( int k = 0 ; k < vet.size() ; k++ ) histo.Fill( vet[k] );
  
  // accedo a informazioni statistiche 

  cout << "Media dei valori caricati = " << histo.GetMean() << endl;

  // disegno

  TCanvas mycanvas ("Histo","istogramma");
  histo.Draw();
  histo.GetXaxis()->SetTitle("misure");

  app.Run();
		
	}	

	if (argc < 3) {
	
  // creo un processo "app" che lascia il programma attivo 		
  TApplication app("app",0,0);
  
  // leggo dati da file
	//cout << argv[1] << argv[2] << endl;
  vector<double> vet = ReadAll<double>(argv[1]);

  // creo e riempio il vettore. L'opzione StatOvergflows permetter di calcolalare le informazioni statistiche anche se il dato sta fuori dal range di definizione dell'istogramma
  
  TH1F histo ("histo","istogramma", 100, -10, 100) ;
  histo.StatOverflows( kTRUE );
  for ( int k = 0 ; k < vet.size() ; k++ ) histo.Fill( vet[k] );
  
  // accedo a informazioni statistiche 

  cout << "Media dei valori caricati = " << histo.GetMean() << endl;

  // disegno

  TCanvas mycanvas ("Histo","istogramma");
  histo.Draw();
  histo.GetXaxis()->SetTitle("measurement");

  app.Run();

	}
	
}
