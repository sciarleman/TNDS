#include <cmath>
#include <iomanip>
#include <iostream>

#include "TApplication.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TGraph.h"
#include "TLegend.h"

#include "Integral.h"
#include "Seno.h"

using namespace std;

int main(int argc, char *argv[]) {

  TApplication myApp("myApp", 0, 0);

  TGraph myGraph;

  if (argc != 2) {
    cerr << "Utilizzo del programma, specificare " << argv[0] << " <numero passi>" << endl;
    return -1;
  }

  unsigned int nstep = atoi(argv[1]);

  Seno f;
  Simpson myInt(0, M_PI);

  double I = myInt.Integra(nstep, f);

  cout << " Passi = " << setw(5) << nstep << ";\t I = " << setw(5) << I << endl;


  int numstep;
	
//  for (int i = 1; i <= nstep; i += 2) { // LC
	for (int i = 2; i <= nstep; i += 2) {
		numstep = i;
		
		//cout << numstep << endl; // controllo step
		if (numstep % 2 != 0) { cout << "errore algoritmo. Gli step devono essere pari " << endl; exit (3);}
		
    double I = myInt.Integra(numstep, f);
    double x = fabs(2. - I);
    myGraph.AddPoint(numstep, x);

		// per fare stampare una tabella che associa ad ogni passo (ogni pari, per necessità della costruzione di Simpson) il valore dell'integrale calcolato
//  cout << " Passi = " << setw(6) << numstep << "  |  " << "I = " << setw(10) << I << endl;

		// per fare stampare una tabella che associa ad ogni passo (ogni pari, per necessità della costruzione di Simpson) l'errore sul valore dell'integrale calcolato rispetto al valore vero (V_Integrale = 2)

    //cout << " Passi = " << setw(6) << numstep << "  |  " << "I = " << setw(10) << scientific <<fabs(I-2.) << endl;

	}

	
  TCanvas myCanvas("andamento differenza", " Andamento");
  
  myCanvas.SetLogx();
  myCanvas.SetLogy();
	myCanvas.SetGridy();
	myCanvas.SetGridx();
  myGraph.SetLineColor(2);
  myGraph.SetMarkerColor(2);
  myGraph.Draw("ALP");
	
  myApp.Run();

  return 0;
}
