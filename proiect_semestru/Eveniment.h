#include <string>
#include <iostream>
#pragma once

using namespace std;
//Eveniment
class Eveniment {

	char* denumireEveniment;
	string dataEveniment;
	bool evenimentActiv;
	int nrSectoareLocatie;
	int*** matriceLocuri;
	int randuri;
	int locuri;

public:
	//constructori
	Eveniment();
	Eveniment(char*, string, int, int, int);
	Eveniment(const Eveniment& );
	~Eveniment();

	//getteri
	char* getDenumireEveniment();
	string getDataEveniment();
	int getMatriceLocuri(int, int, int );
	int getLocuri();
	int getRanduri();
	int getSectoare();
	//setteri
	void setDenumireEveniment(char*);
	void setDataEveniment(string);
	void setMatriceLocuri(int, int, int);

	//metode
	void amanareEveniment(int );
	void anulareEveniment();

	//operatori
	explicit operator string();
	Eveniment operator++();
	Eveniment operator++(int i);

	//<<>>
	friend ostream& operator<<(ostream&, Eveniment);
	friend istream& operator>>(istream&, Eveniment&);


};


