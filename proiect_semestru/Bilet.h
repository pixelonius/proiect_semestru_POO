#include <string>
#pragma once

using namespace std;

//Bilet
class Bilet {
	int id;
	int nrBilet;
	static string detaliiEveniment;
	static int* bileteEmise;
	static int nrBileteEmise;
	string sector;
	int rand;
	int loc;



public:
	//constructori
	Bilet();
	Bilet(int, int, string);
	Bilet(const Bilet&);
	~Bilet();




	//getteri
	int getRand();
	int getLoc();
	string getSector();
	static string getDetaliiEveniment();
	static int getNrBileteEmise();
	static int* getBileteEmise();

	//setteri
	void setRand(int);
	void setLoc(int);
	void setSector(string);
	//static void setDetaliiEveniment(Eveniment);

	//metode
	void setDetaliiEvenimenr(string);
	void anulareBilet();
	void generareBilet(string, int, int);
	static void biletNouEmis(int);
	

	//supraincarcari
	int operator[](int);
	bool operator>(const Bilet&);
	bool operator<(const Bilet&);
	bool operator>=(const Bilet&);
	bool operator<=(const Bilet&);
	bool operator==(const Bilet&);
	explicit operator int();

	//<<>>
	friend ostream& operator<<(ostream&, Bilet);
	friend istream& operator>>(istream&, Bilet&);
};