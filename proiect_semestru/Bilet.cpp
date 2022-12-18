#include "Bilet.h"
#include <iostream>
#include <string>


using namespace std;

Bilet::Bilet() {
	id = 0;
	rand = 0;
	loc = 0;
	sector = "0";
}

Bilet::Bilet(int rand, int loc, string sector) {
	this->rand = rand;
	this->loc = loc;
	this->sector = sector;
}

Bilet::Bilet(const Bilet& bilet) {
	this->id = bilet.id;
	this->sector = bilet.sector;
	this->rand = bilet.rand;
	this->loc = bilet.loc;
	this->nrBilet = bilet.nrBilet;
}

Bilet::~Bilet() {}


//getteri
int Bilet::getRand() {
	return rand;
}

int Bilet::getLoc() {
	return loc;
}

string Bilet::getSector() {
	return sector;
}


string Bilet::getDetaliiEveniment() {
	return detaliiEveniment;
}

int Bilet::getNrBileteEmise() {
	return nrBileteEmise;
}

int* Bilet::getBileteEmise() {
	return bileteEmise;
}
//setteri

void Bilet::setRand(int rand) {
	if(rand > 0) this->rand = rand;

}


void Bilet::setLoc(int loc) {
	if(loc>0) this->loc = loc;
}

void Bilet::setSector(string sector) {
	if (!sector.empty())
		this->sector = sector;
}

/*void Bilet::setDetaliiEveniment(Eveniment e) {
detaliiEveniment = "Denumire: " + e.denumireEveniment + "," + "Data: " + "e.dataEveniment";
}*/

//metode

void Bilet::setDetaliiEvenimenr(string detaliiEveniment) {
	if (!detaliiEveniment.empty())
		this->detaliiEveniment = detaliiEveniment;
}

void Bilet::anulareBilet() {
	id = 0;
	rand = 0;
	loc = 0;
	sector = "0";
	for (int i = nrBilet; i < nrBileteEmise - 1; i++) {
		bileteEmise[i] = bileteEmise[i + 1];
	}
	nrBileteEmise--;

}

void Bilet::generareBilet(string sector, int rand, int loc) {
	this->sector = sector;
	this->rand = rand;
	this->loc = loc;
	int sectorInt = atoi(sector.c_str());
	int idGenerat = rand * loc + sectorInt * rand - sectorInt * loc + sectorInt * 2002;
	this->id = idGenerat;
	biletNouEmis(idGenerat);
	this->nrBilet = Bilet::nrBileteEmise;
}

void Bilet::biletNouEmis(int id) {

	int* aux = new int[Bilet::nrBileteEmise];
	for (int i = 0; i < Bilet::nrBileteEmise; i++) {
		aux[i] = Bilet::bileteEmise[i];
	}
	delete[] Bilet::bileteEmise;
	bileteEmise = new int[Bilet::nrBileteEmise + 1];
	for (int i = 0; i < Bilet::nrBileteEmise; i++) {
		Bilet::bileteEmise[i] = aux[i];

	}
	Bilet::bileteEmise[nrBileteEmise] = id;
	Bilet::nrBileteEmise++;
	delete[] aux;

}

//operatori

int Bilet::operator[](int nrBilet) {
	if (nrBilet > 0 && nrBilet < nrBileteEmise) {
		return bileteEmise[nrBilet];
	}
	return -1;
}

bool Bilet::operator> (const Bilet& bilet) {
	if (bilet.rand > rand) return true;
	return false;
}


bool Bilet::operator<(const Bilet& bilet) {
	if (bilet.rand < rand) return true;
	return false;
}


bool Bilet::operator>=(const Bilet& bilet) {
	if (bilet.rand >= rand) return true;
	return false;
}

bool Bilet::operator<=(const Bilet& bilet) {
	if (bilet.rand <= rand) return true;
	return false;
}

bool Bilet::operator==(const Bilet& bilet) {
	if (bilet.rand == rand) return true;
	return false;
}

Bilet::operator int() {
	return bileteEmise[nrBilet];
}

int Bilet::nrBileteEmise = 0;
int* Bilet::bileteEmise = nullptr;
string Bilet::detaliiEveniment = "";



istream& operator>>(istream& in, Bilet& b) {
		in >> b.id;
	return in;
}
 ostream& operator<<(ostream& out, Bilet b){
	 out << "Detaliile evenimentuluiui: " << b.detaliiEveniment<<endl;
	 out << "Sector: " << b.sector<<" ";
	 out << "Randul: " << b.rand << " ";
	 out << "Locul: " << b.loc << " ";
	 out << endl;
	 out << "Id: " << b.id << " " << "Numarul biletului: " << b.nrBilet<<endl;
	return out;
}