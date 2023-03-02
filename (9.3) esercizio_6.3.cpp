
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
    cerr << "Uso: " << argv[0]  << " <passo di integrazione (max value 70.0)> " << endl;
    return -1;
  }

  TApplication myApp("myApp",0,0);

	RungeKutta myRK;
	RungeKutta myErr;
	double l = 1;
  double tmax = 70;

  pendolo p (l);

  double h = atof(argv[1]);
    
  TGraph myGraph1;
  TGraph myGraph2;

	OscillatoreArmonico osc(1.0);

	//int nstep = static_cast<int>(tmax/h + 0.5);
	int nstep = 30;
	
	for (int step = 0; step < nstep; step++){

  double A = 0.1*(step + 1);
  double t = 0.0;
  double w = 0.;
  vector<double> x {-A,w};

  while ( x[1] >=0 ) {

    w = x[1];
    x = myRK.Passo(t,x,h,p);
    t = t + h;

  };

  double T = (((t-h)*x[1]-t*w)/(x[1]-w))*2;
//cout << T << "\t" << A << endl;
  myGraph1.SetPoint(step, A, T);

  }  

	//valuto errore
	
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
		
		myGraph2.AddPoint( kh, l);

		}

	TCanvas myCanvas ;

	myCanvas.cd();
	myGraph1.SetTitle("Pendolo");
  myGraph1.GetXaxis()->SetTitle("Ampiezza [rad]");
  myGraph1.GetYaxis()->SetTitle("Periodo [s]");
//	myCanvas.SetLogx();
//	myCanvas.SetLogy();
	myCanvas.SetGrid();  
  myGraph1.Draw("ALP"); 
	myCanvas.Print("SpostamentoTempo.png");

	
	TCanvas can;
	
	can.cd();
	string titolo = " Errore Oscillatore armonico (metodo di Runge-Kutta, h = " + to_string(h) + ")";
	myGraph2.SetTitle(titolo.c_str());
	myGraph2.GetXaxis()->SetTitle("precisione");
	myGraph2.GetYaxis()->SetTitle("Errore su x [m]");
	can.SetLogx();
	can.SetLogy();
	can.SetGrid();
	myGraph2.Draw("ALP");
	can.Print("AndamentoErrore.png");

	
	myApp.Run();

  return 0;
}
