#include <iostream>

#include "EsperimentoPrisma.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TApplication.h"

#include "TCanvas.h"
#include "TAxis.h"
#include "TGraph.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TRatioPlot.h"

int main() {

	unsigned int numsimul = 10000;
	EsperimentoPrisma prism;
	
	TApplication appli("application", 0, 0);
	TH1F hA ("Distribuzione di A", "Distribuzione di A", 100, 2.68, 2.62);
	TH1F hB ("Distribuzione di B", "Distribuzione di B", 100, 2.68, 2.62);
	TH1F hd1 ("Distribuzione di d1", "Distribuzione di d1", 100, 2.68, 2.62);
	TH1F hd2 ("Distribuzione di d2", "Distribuzione di d2", 100, 2.68, 2.62);
	TH1F hn1 ("Distribuzione di n1", "Distribuzione di n1", 100, 2.68, 2.62);
	TH1F hn2 ("Distribuzione di n2", "Distribuzione di n2", 100, 2.68, 2.62);
	TH1F th0 ("Distribuzione di th0", "Distribuzione di th0", 100, 2.68, 2.62);
	TH1F th1 ("Distribuzione di th1", "Distribuzione di th1", 100, 2.68, 2.62);
	TH1F th2 ("Distribuzione di th2", "Distribuzione di th2", 100, 2.68, 2.62);

	TH2F R2d ("residui 2D", "residui 2D", 100, -0.002, 0.002, 100, -0.002, 0.002);
	TH2F Rn ("residui n1n2", "residui n1n2", 100,  -0.001, 0.001, 100, -0.001, 0.001);
	TH2F RAB ("residui AB", "residui AB", 100, -0.0085, -0.06, 100, -0, 0.001);

	//riempimento istogrammi
	for (int k = 0; k < numsimul; k++ ) {

		prism.Esegui();
		prism.Analizza();
		
		hA.Fill(prism.getrisA());
		hB.Fill(prism.getrisB());
		hd1.Fill(prism.getrisD1());
		hd2.Fill(prism.getrisD2());
		hn1.Fill(prism.getrisn1());
		hn2.Fill(prism.getrisn2());
		th0.Fill(prism.getth0());
		th1.Fill(prism.getth1());
		th2.Fill(prism.getth2());
		
	  R2d.Fill(prism.getrisD1(), prism.getrisD2());
		Rn.Fill(prism.getrisn1(), prism.getrisn2());
		RAB.Fill(prism.getrisA(), prism.getrisB());
	}
	
//_______________________________________________________________
	//calcolo correlazione <xy> - <x><y> / sigmaxsigmay
	double AB, As,Bs;
	double n1s, n2s, n1n2;
	double d1s, d2s, d1d2;
	
	for (int k = 0; k < numsimul; k++ ) {

		prism.Esegui();
		prism.Analizza();
	
		AB += (prism.getrisA()*prism.getrisB()); As += prism.getrisA(); Bs += prism.getrisB();
		n1n2 += (prism.getrisn1()*prism.getrisn2()); n1s += prism.getrisn1(); n2s += prism.getrisn2();
		d1d2 += (prism.getrisD1()*prism.getrisD2()); d1s += prism.getrisD1(); d2s += prism.getrisD2();
	}
	
	double sigA = hA.GetStdDev(); double sigB = hB.GetStdDev();
	double sign1 = hn1.GetStdDev(); double sign2 = hn2.GetStdDev();
	double sigd1 = hd1.GetStdDev(); double sigd2 = hd2.GetStdDev();

	double N = 10000.;
	double corrAB = 100*((AB/N) - ((As*Bs)/(N*N)))/(sigA*sigB);
	double corrn = 100*((n1n2/N) - ((n1s*n2s)/(N*N)))/(sign1*sign2);
	double corrd = 100*((d1d2/N) - ((d1s*d2s)/(N*N)))/(sigd1*sigd2);

	cout << "Correlazione tra A e B = " << corrAB << "%" <<endl;
	cout << "Correlazione tra n1 e n2 = " << corrn << "%" <<endl;
	cout << "Correlazione tra d1 e d2 = " << corrd << "%" <<endl;
	
//_______________________________________________________________
//	stampa del grafico
	TCanvas *vas = new TCanvas ("Risultati", "Risultati");
		
	vas->SetCanvasSize(2000, 2000);
  vas->SetWindowSize(1000, 1000);
	vas -> Divide (3, 4);

	//TCanvas can7("histoth0", "histoth0");
	vas->cd(1);
	th0.GetXaxis()->SetTitle("th0 [rad]");
	th0.GetYaxis()->SetTitle("occorrenze");
	th0.Draw();
	//can7.Print("histo_th0.png");

	//TCanvas can8("histoth1", "histoth1");
	vas->cd(2);
	th1.GetXaxis()->SetTitle("th1 [rad]");
	th1.GetYaxis()->SetTitle("occorrenze");
	th1.Draw();
	//can8.Print("histo_th1.png");

	//TCanvas can9("histoth2", "histoth2");
	vas->cd(3);
	th2.GetXaxis()->SetTitle("th2 [rad]");
	th2.GetYaxis()->SetTitle("occorrenze");
	th2.Draw();
	//can9.Print("histo_th2.png");

	//TCanvas can3("histod1", "histod1");
	vas->cd(4);
	hd1.GetXaxis()->SetTitle("errori d1 [rad]");
	hd1.GetYaxis()->SetTitle("occorrenze");
	hd1.Draw();
	//can3.Print("histo_hd1.png");
		
	//TCanvas can4("histod2", "histod2");
	vas->cd(5);
	hd2.GetXaxis()->SetTitle("errori d2 [rad]");
	hd2.GetYaxis()->SetTitle("occorrenze");
	hd2.Draw();
	//can4.Print("histo_hd2.png");

	//TCanvas can10("histoR2d", "histoR2d");
	vas->cd(6);
	R2d.GetXaxis()->SetTitle("d(l1)");
	R2d.GetYaxis()->SetTitle("d(l2)");
	R2d.Draw();
	//can10.Print("histo_R2d.png");

	//TCanvas can5("histon1", "histon1");
	vas->cd(7);
	hn1.GetXaxis()->SetTitle("n1");
	hn1.GetYaxis()->SetTitle("occorrenze");
	hn1.Draw();
	//can5.Print("histo_hn1.png");
		
	//TCanvas can6("histon2", "histon2");
	vas->cd(8);
	hn2.GetXaxis()->SetTitle("n2");
	hn2.GetYaxis()->SetTitle("occorrenze");
	hn2.Draw();
	//can6.Print("histo_hn2.png");
	
	//TCanvas can11("histoR2n", "histoR2n");
	vas->cd(9);
	Rn.GetXaxis()->SetTitle("n(l1)");
	Rn.GetYaxis()->SetTitle("n(l2)");
	Rn.Draw();
	//can11.Print("histo_Rn.png");
	
	//TCanvas can ("histoA", "histoA");
	vas->cd(10);
	hA.GetXaxis()->SetTitle("A");
	hA.GetYaxis()->SetTitle("occorrenze");
	hA.Draw();
	//can.Print("histo_hA.png");

	//TCanvas can2("histoB", "histoB");
	vas->cd(11);
	hB.GetXaxis()->SetTitle("B");
	hB.GetYaxis()->SetTitle("occorrenze");
	hB.Draw();
	//can2.Print("histo_hB.png");

	//TCanvas can12("histoRAB", "histoRAB");
	vas->cd(12);
	RAB.GetXaxis()->SetTitle("A");
	RAB.GetYaxis()->SetTitle("B [m^2]");
	RAB.Draw();
	//can12.Print("histo_RAB.png");

gROOT ->GetListOfCanvases() ->Draw();
vas->Print("risultati.png");
	
}
