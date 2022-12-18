#include <iostream>
#pragma once

using namespace std;

class Turnichet {
	const int id;
	string* sectoareValidate;
	static int nrSectoare;
	bool functional;

public:

	//constructori
	Turnichet();
	Turnichet(int, string, string, int);
	Turnichet(const Turnichet&);

	~Turnichet();

	//metode
	void inlocuireTurnichet(Turnichet, Turnichet);


	void pornireTurnichet();
	//getteri
	int getId();
	string* getSectoareValidate();
	int getNrSectoare();
	bool getFunctional();

	//seteri
	void setFunctional(bool);
	//operatori
	void operator!();

	friend Turnichet operator+(string, Turnichet&);

	//<<>>
	friend ostream& operator<<(ostream&, Turnichet);
	friend istream& operator>>(istream&, Turnichet&);

};
