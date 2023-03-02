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
    cerr << "Uso: " << argv[0]  << " <passo di integrazione (max value 70.0)>" << endl;
    return -1;
  }

  TApplication myApp("myApp",0,0);
	TGraph myGraph;
	TGraph myErr;
	
  RungeKutta myRK;

	double t = 0.;
  double h = atof(argv[1]);
	double T = 0.; //periodo
	double A = 0.; //ampiezza

	double wo = 10;
  double alpha = 1./30.;
 	double w = 5;
 // double tmax = 10 * (1/alpha);
	double tmax = 25;
	
	OscillatoreForzante osc(wo, alpha, w);
	
	vector<double> x { A, 0.}; //(theta, velocià angolare)

  while (t<=tmax) {

    x = myRK.Passo(t,x,h,osc);

    myGraph.AddPoint(t, x[0]);
//cout << t << "\t" << x[0] << endl;
    t = t + h;

	}
	
	TCanvas can;

	can.cd();

	string title = "Oscillatore armonico Posizione-Tempo (metodo di Runge-Kutta, h = " + to_string(h) + ")";
	myGraph.SetTitle(title.c_str());
	myGraph.GetXaxis()->SetTitle("Tempo [s]");
	myGraph.GetYaxis()->SetTitle("Posizione [rad]");
	myGraph.Draw("AL");
	can.Print("SpostamentoTempo.png");

	
	int nstep = 40;

	for(int i = 0; i<nstep; i++) {

	  w = 0.9*wo+(0.2*wo/nstep)*(i+1);
		t = 0.;
		x[0] = 0;
	  x[1] = 0;

 		OscillatoreForzante p(wo, alpha, w);

 		while (t<=tmax) {

    	x = myRK.Passo(t,x,h,p);
			double w2 = pow(wo, 2)- pow(w, 2);
			A = 1/(sqrt(pow(w2, 2)+pow(w,2)*pow(alpha, 2)));
			t = t + h;

   }

		myErr.SetPoint(i, w, A);
		
	}

	TCanvas can2;

	can2.cd();
			
  myErr.SetTitle("Lorentziana");
  myErr.GetXaxis()->SetTitle("Pulsazione [rad/s]");
  myErr.GetYaxis()->SetTitle("Ampiezza [...]");   
	myErr.Draw("ALP");

	can2.Print("lorentziana.png");
  
	myApp.Run();

  return 0;
}
