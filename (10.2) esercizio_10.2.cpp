#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TGraph.h"

#include <iostream>
#include <string>
#include <fstream>

#include "RandomGen.h"
#include "IntegralMC.h"


using namespace std;

int main() {

	TApplication app("app", 0, 0);

	IntegralMC myInt(1);
	seno sin;
	int nmax = 10000;

	vector<unsigned int> npunti {100, 500, 1000, 5000, 10000};
	
//_____________________________________________________________________
	TH1F HoM("MCHoM", "MCHoM", 100, 1.5, 2.5);

	for (int i = 0 ; i < nmax ; i++) {
		HoM.Fill(myInt.IntegraleHoM(0, M_PI, 1, &sin, 100));
	}

	TCanvas can1("MCHoM", "MCHoM");
	can1.cd();
	HoM.GetXaxis()->SetTitle("valore integrale");
	HoM.GetYaxis()->SetTitle("occorrenze");
	HoM.Draw();
	can1.Print("IntegraleMCHoM_100punti.png");

	//_____________________________________________________________________
	TH1F AVE("MCAVE", "MCAVE", 100, 1.5, 2.5);

	for (int i = 0 ; i < nmax ; i++) {
		AVE.Fill(myInt.IntegraleAVE(0, M_PI, &sin, 100));
	
	}

	TCanvas can2("MCAVE", "MCAVE");
	can2.cd();
	AVE.GetXaxis()->SetTitle("valore integrale");
	AVE.GetYaxis()->SetTitle("occorrenze");
	AVE.Draw();
	can2.Print("IntegraleMCAVERAG_100puntiE.png");

	app.Run();


}
