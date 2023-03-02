#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TGraph.h"

#include <iostream>
#include <string>

#include "RandomGen.h"

using namespace std;

int main() {

	TApplication app("app", 0, 0);

	RandomGen myGen(1);
	int nmax = 10000;
	
//_____________________________________________________________________
	TH1F rand("Random", "random", 100, -0.1, 1.1);

	for (int i = 0 ; i < nmax ; i++) {
		rand.Fill(myGen.Rand());
		
	//	cout << myGen.Rand() << endl;
	}

	TCanvas can1("Random", "Random");
	can1.cd();
	rand.GetXaxis()->SetTitle("x [AU]");
	rand.GetYaxis()->SetTitle("N");
	rand.Draw();
	can1.Print("Distribuzione_numeri_randomici.png");
//_____________________________________________________________________
	TH1F unif("Uniforme", "Uniforme", 100, 0, 0);

	for (int i = 0 ; i < nmax ; i++) {
		unif.Fill(myGen.Unif(5, 10));
	}

	TCanvas can2("Uniforme", "Uniforme");
	can2.cd();
	unif.GetXaxis()->SetTitle("x [AU]");
	unif.GetYaxis()->SetTitle("N");
	unif.Draw();
	can2.Print("Distribuzione_uniforme.png");

//_____________________________________________________________________
TH1F gaussiana("Gaussiana", "Gaussiana", 100, 0, 0);

	for (int i = 0 ; i < nmax ; i++) {
		gaussiana.Fill(myGen.Gauss(1, 1));
	}

	TCanvas can3("Gaussiana", "Gaussiana");
	can3.cd();
	gaussiana.GetXaxis()->SetTitle("x [AU]");
	gaussiana.GetYaxis()->SetTitle("N");
	gaussiana.Draw();
	can3.Print("Distribuzione_gaussiana.png");

//_____________________________________________________________________
TH1F gaussianaAR("GaussianaAR", "GaussianaAR", 100, 0, 0);



	for (int i = 0 ; i < nmax ; i++) {
		
		myGen.GaussAR(1,1) ;
		gaussianaAR.Fill(myGen.GaussAR(1,1));
		myGen.GaussAR(1,1) ;
	
	}

	TCanvas can4("GaussianaAR", "GaussianaAR");
	can4.cd();
	gaussianaAR.GetXaxis()->SetTitle("x [AU]");
	gaussianaAR.GetYaxis()->SetTitle("N");
	gaussianaAR.Draw();
	can4.Print("Distribuzione_gaussiana_accept_reject5.png");

//_____________________________________________________________________
TH1F Esponenziale("Esponenziale", "Esponenziale", 100, 0, 10);

	for (int i = 0 ; i < nmax ; i++) {
		Esponenziale.Fill(myGen.Exp(1));
	}

	TCanvas can5("Esponenziale", "Esponenziale");
	can5.cd();
	Esponenziale.GetXaxis()->SetTitle("x [AU]");
	Esponenziale.GetYaxis()->SetTitle("N");
	Esponenziale.Draw();
	can5.Print("Distribuzione_esponenziale.png");


	
	app.Run();

}
