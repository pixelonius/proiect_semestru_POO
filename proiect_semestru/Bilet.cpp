#include "Bilet.h"




Bilet::Bilet() {
	id = 0;
	rand = 0;
	loc = 0;
	sector = "0";
}

Bilet::Bilet(int rand, int loc, int sector, int id) {
	this->rand = rand;
	this->loc = loc;
	this->sector = sector;
}

Bilet::Bilet(const Bilet& bilet) {
	this->id = bilet.id;
	this->sector = bilet.sector;
	this->rand = bilet.rand;
	this->loc = bilet.loc;
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

int Bilet::getLoc() {
	return loc;
}

string Bilet::getDetaliiEveniment() {
	return detaliiEveniment;
}

int Bilet::getNrBileteEmise() {
	return nrBileteEmise;
}

//setteri

void Bilet::setRand(int rand) {
	this->rand = rand;
}


void Bilet::setLoc(int loc) {
	this->loc = loc;
}

void Bilet::setSector(string sector) {
	if (!sector.empty())
		this->sector = sector;
}

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

void Bilet::generareBilet(int sector, int rand, int loc) {
	int idGenerat = rand * loc + sector * rand - sector * loc + sector * 2002;
	this->id = idGenerat;
	nrBilet = nrBileteEmise + 1;
	biletNouEmis(idGenerat);
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

explicit Bilet::operator int() {
	return bileteEmise[nrBilet];
}

int Bilet::nrBileteEmise = 0;
