#include <iostream>

#include "TApplication.h"
#include "TCanvas.h" 
#include "TGraph.h"
#include "TAxis.h"

#include "EquazioniDifferenziali.h"

using namespace std;

int main(int argc, char** argv){
  
  if(argc != 2)
  {
    cerr << "Uso: " << argv[0]  << " <passo_di_integrazione (max value 70.0)> " << endl;
    return -1;
  }

  TApplication myApp("myApp",0,0);
	TGraph myGraph;
	TGraph myErr;
	
  RungeKutta myRK;
	//Seno sin;

  OscillatoreArmonico osc(1.0);

  double tmax = 70.0;
  double h = atof(argv[1]);
  vector<double> x {0.0, 1.0};
  double t = 0.0;

	int nstep = static_cast<int>(tmax/h + 0.5);

	/*cout << nstep << "\t" << h << "\t" << tmax << endl;
	Print(x); cout << endl;*/
  
  for (int step = 0; step < nstep; step++){

		//cout << /*t << "\t" <<*/ x[1] << /*"\t" << x[1] << */endl;
		//Print (x);				

		myGraph.SetPoint(step, t, x[0]);
		x = myRK.Passo(t,x,h,osc);
	  t = t+h;
		
	}

//	valuto errore 

	for ( double i = 0; i<10 ; i ++) {

		double kh = 0.1*pow(0.5,i);
		vector<double> x { 0., 1.};
		double t = 0.;
		double tmax = 70.;
		int nastep = int (tmax/kh + 0.5);

		for (int step = 0; step < nstep; step++) {
			x = myRK.Passo(t, x, kh,osc);
			t = t+kh;
		}
			
		double l = fabs(x[0] - (sin(t)) );

		//Print(x);
		//cout << sin(t) << endl;
		//cout << l << endl ;
		
		myErr.AddPoint( kh, l);

		}

	
	TCanvas can;
	
	can.cd();
	string titolo = " Errore Oscillatore armonico (metodo di Runge-Kutta, h = " + to_string(h) + ")";
	myErr.SetTitle(titolo.c_str());
	myErr.GetXaxis()->SetTitle("precisione");
	myErr.GetYaxis()->SetTitle("Errore su x [m]");
	can.SetLogx();
	can.SetLogy();
	can.SetGrid();
	myErr.Draw("ALP");

	
	TCanvas cen;

	cen.cd();
	string title = "Oscillatore armonico (metodo di Runge-Kutta, h = " + to_string(h) + ")";
	myGraph.SetTitle(title.c_str());
	myGraph.GetXaxis()->SetTitle("tempo [s]");
	myGraph.GetYaxis()->SetTitle("Poszione x [m]");
	myGraph.Draw("AL");

  myApp.Run();

  return 0;
}
