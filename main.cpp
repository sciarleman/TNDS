#include <iostream>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "FunzioneBase.h"
#include "SolutoreBis.h"
#include "integral.h"
#include "RandomGen.h"


#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TGraph.h"

using namespace std;

int main() {

  Funzione f_x;
  double inf1 = 0.5; 	double sup1 = 1.5;
  double inf2 = 2;		double sup2 = 3;
	double inf3 = 4;		double sup3 = 3;
  double prec = 0.001;
  // double iterazioni = atof(argv[4]);

  Bisezione zerovero;
	double valore [3];
 	valore[0] = zerovero.CercaZeri(inf1, sup1, f_x, prec);
  valore[1] = zerovero.CercaZeri(inf2, sup2, f_x, prec);
  valore[2] = zerovero.CercaZeri(inf3, sup3, f_x, prec);

  // punto 1
	double decimali = -log10(prec); 
	
	//cout << decimali << endl;
	cout.precision(decimali);
  cout << "Zeri della funzione x1 = " << valore[0] << "+/-" << prec << endl;
  cout << "Zeri della funzione x2 = " << valore[1] << "+/-" << prec << endl;
  cout << "Zeri della funzione x3 = " << valore[2] << "+/-" << prec << endl;

  // punto 2
	Trapezi myInt(valore[0], valore[1]);
	double integrale = myInt.Integra(prec, f_x);
  cout << "Calcolo integrale con metodo Trapezoidi per N = 4 intervalli = " << integrale << endl;

  // punto 3
	double err = myInt.StdDev( f_x, prec, integrale);
   cout << "Errore calcolo integrale con metodo Trapezoidi per N = 4 intervalli = " << err << endl;

  // punto 4
	Trapezi_hvariabile secndInt(valore[0], valore[1]);
	double passi = secndInt.Integra(0.0001, f_x);
   cout << "Numero intervalli richiesti per precisione 0.0001 = " << passi << endl;

  // punto 5
	IntegralMC thrdInt(1);
	double punti = thrdInt.puntiAVE(valore[0], valore[1], &f_x, 0.0001);
	double errmedia = thrdInt.StdDev(valore[0], valore[1], &f_x, punti);
  cout << "Numero punti per avere Integrale uguale a precedente con metodo della media a precisione = 0.0001 = " << punti << /*" +/- " << errmedia << */endl;
	cout << thrdInt.IntegraleAVE(valore[0], valore[1], &f_x, punti);
  // punto 6
	TApplication app("app", 0,0 );
	TGraph integ;

	

	for (double i = 0.1 ; i < valore[2] ; i += 0.1) {
		Trapezi frthInt(valore[0], i);
		integ.AddPoint(i, frthInt.Integra(prec, f_x) );
		
	}

	TCanvas can("Integrale", "Integrale");
	can.cd();
	integ.GetXaxis()->SetTitle("x [AU]");
	integ.GetYaxis()->SetTitle("N");
	integ.Draw();
	can.Print("IntegraleAVE.png");


	
	app.Run();


  // grafico o tabella

  // punto 7 :

  // cout << "Lo zero della funzione integrale t0 = " << zeroint << " +/- " <<
  // prec << endl;
}
