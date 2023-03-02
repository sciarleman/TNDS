#ifndef __posizione_h__
#define __posizione_h__


class Posizione {

public:

	Posizione();
	Posizione(double x, double y, double z);

	~Posizione();

	void SetX(double);
	void SetY(double);
	void SetZ(double);

	double GetComponentX() const;										//coordinate cartesiane
	double GetComponentY() const;
	double GetComponentZ() const;
	double GetValueRaggio() const;
	double GetAnglePhi() const;											//coordinate sferice
	double GetAngleTheta() const;
	double GetValueRho() const;											//raggio coordinate cilindriche
	double Distanza(const Posizione&) const;				//distanza fra due punti


private:

	double dim_x, dim_y, dim_z;
};

#endif
