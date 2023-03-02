#ifndef __IntegralMC__
#define __IntegralMC__

#include <iostream>
#include <math.h>

#include "RandomGen.h"
#include "FunzioneBase.h"
using namespace std;

class IntegralMC {

	public: 
		IntegralMC(unsigned int seed) { m_myRand = new RandomGen(seed); m_error = 0.;};
		~IntegralMC() {;};


		double IntegraleHoM (double xmin, double xmax, double fmax, FunzioneBase *f, int punti) {

			double Nhit = 0.;
			double Ntot = 0.;

			for(;;){
				double y = m_myRand->Unif(0, fmax);
				double x = m_myRand->Unif(xmin, xmax);
				double fx = f->Eval(x) ;
				
				Ntot++;

				if (y<fx) {
			//		double xi = x;
					Nhit++;
			
				}	

				if (Ntot == punti){break;}

			}
			return (xmax - xmin) *  fmax * (Nhit / Ntot);
			
		}

		double IntegraleAVE (double xmin, double xmax, FunzioneBase *f, int punti) {
			double N = 1;
			double fsum = 0.;
			
			for (int i = 0. ; i < punti ; i++){
				N++;
				double x = m_myRand->Unif(xmin, xmax);
				fsum += f->Eval(x);
				}

			return (xmax - xmin)*(fsum/N);
				
		}


	private:
		RandomGen *m_myRand;
		double m_error;
		double m_points;
};
