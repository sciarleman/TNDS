#ifndef __Particella_h__
#define __Particella_h__

class Particella {

public:

	Particella();
	Particella(double Massa, double Carica);

	~Particella();

	double GetValueMassa() const;				
	double GetValueCarica() const;

	void Print() const;

private:

	double val_m, val_q;

};

class Elettrone : public Particella {

public :

	Elettrone();
	~Elettrone();

	void Print() const;

};

#endif