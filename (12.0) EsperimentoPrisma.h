#ifndef _Esperimento_Prisma_h_
#define _Esperimento_Prisma_h_

#include "RandomGen.h"

class EsperimentoPrisma {

 public :

  EsperimentoPrisma() ;
  ~EsperimentoPrisma() {;} ;

  void Esegui() ;
  void Analizza() ;

  double getAmis() { return m_A_misurato; } ;
	double getBmis() { return m_B_misurato; } ;
	double getD1mis() { return m_dm1_misurato ; } ;
	double getD2mis() { return m_dm2_misurato ; } ;
	double getn1mis() { return m_n1_misurato ; } ;
	double getn2mis() { return m_n2_misurato ; } ;

	double getth0() { return m_th0_misurato ; } ;
	double getth1() { return m_th1_misurato ; } ;
	double getth2() { return m_th2_misurato ; } ;

	double getrisA() { return m_A_misurato-m_A_input; } ;
	double getrisB() { return m_B_misurato-m_B_input ; } ;
	double getrisn1() { return (m_n1_misurato - m_n1_input) ;}
	double getrisn2() { return (m_n2_misurato - m_n2_input) ;}
	double getrisD1() { return (m_dm1_misurato - m_dm1_input) ;}
	double getrisD2() { return (m_dm2_misurato - m_dm2_input) ;}


private:

  // generatore di numeri casuali                                           

  RandomGen m_rgen ;

  // parametri dell'apparato sperimentale                                                                                        
  double m_lambda1, m_lambda2, m_alpha, m_sigmat;

  // valori delle quantita' misurabili :                                     
	// input    : valori assunti come ipotesi nella simulazione               
	// misurato : valore dopo la simulazione di misura                                                                                     
	double m_A_input, m_A_misurato;
  double m_B_input, m_B_misurato;
  double m_n1_input, m_n1_misurato;
  double m_n2_input, m_n2_misurato;
  double m_dm1_input, m_dm1_misurato;
  double m_dm2_input, m_dm2_misurato;
  double m_th0_input, m_th0_misurato;
  double m_th1_input, m_th1_misurato;
  double m_th2_input, m_th2_misurato;

};

#endif
