#include <iostream>
#include "Turnichet.h"

using namespace std;

//constructori
Turnichet::Turnichet() :id(0) {
	sectoareValidate = nullptr;
	nrSectoare = 0;
	functional = false;

}
Turnichet::Turnichet(int id, string sector1, string sector2, int nrSectoare) : id(id) {
	sectoareValidate = new string[nrSectoare];
	if (nrSectoare == 1) { sectoareValidate[0] = sector1; }
	else if (nrSectoare > 1) {
		sectoareValidate[1] = sector2;
		sectoareValidate[0] = sector1;
	}
}

Turnichet::Turnichet(const Turnichet& t) :id(t.id) {
	this->functional = t.functional;
	delete[] this->sectoareValidate;
	this->sectoareValidate = new string[nrSectoare];
	for (int i = 0; i < nrSectoare; i++) {
		this->sectoareValidate[i] = t.sectoareValidate[i];
	}

}

Turnichet::~Turnichet() {
	delete[] sectoareValidate;
	sectoareValidate = nullptr;
}

void Turnichet::inlocuireTurnichet(Turnichet turnichetDezafectat, Turnichet turnichetInlocuitor) {
	for (int i = 0; i < nrSectoare; i++) {
		if (turnichetDezafectat.sectoareValidate[i].compare(turnichetInlocuitor.sectoareValidate[i]) != 0) {
			turnichetInlocuitor.sectoareValidate[i] = turnichetDezafectat.sectoareValidate[i];
		}
		delete[] turnichetDezafectat.sectoareValidate;
		turnichetDezafectat.sectoareValidate = nullptr;
		turnichetDezafectat.functional = false;
	}
}


void Turnichet::pornireTurnichet() {
	functional = true;
}

int Turnichet::nrSectoare = 4;
//getteri
int Turnichet::getId() {
	return id;
 }

string* Turnichet::getSectoareValidate() {
	return sectoareValidate;
}

int Turnichet::getNrSectoare() {
	return nrSectoare;
}
bool Turnichet::getFunctional() {
	return functional;
}

//setteri
void Turnichet::setFunctional(bool functional) {
	this->functional = functional;
}
//operatori
void Turnichet::operator!() {
	functional = false;
}


Turnichet operator+ (string x, Turnichet& t) {
	if (t.functional) {
		for (int i = 0; i < t.nrSectoare; i++) {
			if (t.sectoareValidate[i].empty()) {
				t.sectoareValidate[i] = x;
				break;
			}
		}
	}
	return t;
}

ostream& operator<<(ostream& out, Turnichet t) {
	out << t.id;
	return out;
}

istream& operator>>(istream& in, Turnichet& t) {
	in >> t.functional;
	return in;
}

