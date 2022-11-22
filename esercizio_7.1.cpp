
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
    cerr << "Utilizzo del programma, specificare " << argv[0] << "<nstep>"
         << endl;
    return -1;
  }

  unsigned int nstep = atoi(argv[1]);

  Seno f;
  Simpson myInt(0, M_PI);

  double I = myInt.Integra(nstep, f);

  cout << " Passi = " << setw(5) << nstep << " I = " << setw(5) << I << endl;

  int numstep;
  for (int i = 1; i <= nstep; i += 2) {
    numstep = i;
    double I = myInt.Integra(numstep, f);
    double x = abs(2 - I);
    myGraph.AddPoint(numstep, x);

    cout << " Passi = " << setw(10) << numstep << "  |  "
         << "I = " << setw(10) << I << endl;
  }

  TCanvas myCanvas("andamento differenza", " Andamento");
  myGraph.Draw("ALP");
  myCanvas.SetLogx();
  myCanvas.SetLogy();
  myGraph.SetLineColor(2);
  myGraph.SetMarkerColor(2);
//  myGraph.Scale(0.3, y);

  myApp.Run();

  return 0;
}
