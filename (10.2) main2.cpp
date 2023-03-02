#include "TApplication.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TGraph.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TRatioPlot.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "RandomGen.h"
#include "IntegralMC.h"

using namespace std;

int main() {

	TApplication myApp("myApp",0,0);
	
	IntegralMC integra (1);
	seno sin;
	
	double nmax = 10000;
	  vector <unsigned int> nextractions = {100,500,1000,5000,10000};
  	vector <TH1F> AVE(nextractions.size());
  	vector <TH1F> HOM(nextractions.size());
  	vector <double> devstdAVE(nextractions.size());
  	vector <double> devstdHOM(nextractions.size());

  	for(int i=0; i<nextractions.size(); i++){
    	string AVEname = "IntegraleMC AVE" + to_string(nextractions[i]);
    	AVE[i] = TH1F(AVEname.c_str(),AVEname.c_str(),100,1,3);
    	for(int j=0; j<nmax; j++){
    	AVE[i].Fill(integra.IntegraleAVE(0,M_PI,&sin,nextractions[i]));
    	}
    	AVE[i].StatOverflows(kTRUE);
    	devstdAVE[i] = AVE[i].GetStdDev();

  }

//----------------------------------------------------
  TCanvas c;
  c.Divide(2,3);
  for(int i=0; i<nextractions.size(); i++){
    c.cd(i+1);
    AVE[i].GetXaxis()->SetTitle("x [AU]");
    AVE[i].GetYaxis()->SetTitle("N");
    AVE[i].Draw();
  }

	double k;
	
  for(int i=0; i<nextractions.size(); i++){
    string HOMname = "IntegraleMC HOM" + to_string(nextractions[i]);
    HOM[i] = TH1F(HOMname.c_str(), HOMname.c_str() ,100, 1, 3);
    for(int j=0; j<nmax; j++){
    HOM[i].Fill(integra.IntegraleHoM(0,M_PI,1,&sin,nextractions[i]));
    }
    HOM[i].StatOverflows(kTRUE);
    devstdHOM[i] = HOM[i].GetStdDev();
		k += devstdHOM[i]*sqrt(nextractions[i]);  //calcolo parametro k dell'andamento errore (err = k/sqrt(Npunti)) usando come valore dell'errore la deviazione standard

  }
	k = k/nextractions.size();
	//cout << k << endl;
		
  TCanvas c1;
  c1.Divide(2,3);
  for(int i=0; i<nextractions.size(); i++){
    c1.cd(i+1);
    HOM[i].GetXaxis()->SetTitle("x [AU]");
    HOM[i].GetYaxis()->SetTitle("N");
    HOM[i].Draw();
  }
	
//----------------------------------------------------
  TGraph myGraph1;

  c.cd(6);

  for ( int k = 0 ; k < nextractions.size() ; k++ ) {
    double x = nextractions[k] ;
    double y =  devstdAVE[k];
    myGraph1.SetPoint(k, x, y);
  }

  myGraph1.SetTitle("Andamento dell'errore AVE");
  myGraph1.GetXaxis()->SetTitle("N");
  myGraph1.GetYaxis()->SetTitle("stddev");

  myGraph1.SetMarkerStyle(20);

  myGraph1.Draw("ALP");

//----------------------------------------------------
  TGraph myGraph2;

  c1.cd(6);

  for ( int k = 0 ; k < nextractions.size() ; k++ ) {
    double x = nextractions[k] ;
    double y =  devstdHOM[k];
    myGraph2.SetPoint(k, x, y);
  }

  myGraph2.SetTitle("Andamento dell'errore HOM");
  myGraph2.GetXaxis()->SetTitle("N");
  myGraph2.GetYaxis()->SetTitle("stddev");
  myGraph2.SetMarkerStyle(20);
  myGraph2.Draw("ALP");
	
	c.Print("integraliAVE.png");
	c1.Print("integraliHoM.png");

//------------------------------------------------------------
int j = 0;
	for (int p=0 ; p <=j ; p++ ) {
		
		double perror = k/sqrt(p);
		j++;
		if ( fabs(-perror) < 0.001) {
			j = p;
		}
	}
	cout << "numero punti necessari per ottenere precisione di 0.001: " << j << endl; 

//------------------------------------------------------------
	myApp.Run();

  return 0;

}
