#include "Eveniment.h"
#include <iostream>

using namespace std;

//constructori
Eveniment::Eveniment() {
	denumireEveniment = nullptr;
	dataEveniment = "";
	evenimentActiv = true;
	randuri = 0;
	locuri = 0;
	matriceLocuri = nullptr;
}

Eveniment::Eveniment(char* denumireEveniment, string dataEveniment, int nrSectoareLocatie, int randuri, int locuri) {
	this->denumireEveniment = new char[strlen(denumireEveniment) + 1];
	strcpy_s(this->denumireEveniment, strlen(denumireEveniment) + 1, denumireEveniment);
	this->dataEveniment = dataEveniment;
	evenimentActiv = true;
	this->randuri = randuri;
	this->locuri = locuri;
	this->nrSectoareLocatie = nrSectoareLocatie;
	//alocare matrice locuri
	matriceLocuri = new int** [nrSectoareLocatie];
	for (int i = 0; i < nrSectoareLocatie; i++) {
		matriceLocuri[i] = new int* [randuri];

		for (int j = 0; j < randuri; j++) {
			matriceLocuri[i][j] = new int[locuri];
		}
	}

	//popularea matricei
	for (int i = 0; i < nrSectoareLocatie; i++)
		for (int j = 0; j < randuri; j++) {
			for (int z = 0; z < locuri; z++) {
				matriceLocuri[i][j][z] = 1;
			}
		}
}

Eveniment::Eveniment(const Eveniment& eveniment) {
	this->dataEveniment = eveniment.dataEveniment;
	this->evenimentActiv = eveniment.evenimentActiv;
	if (eveniment.denumireEveniment != nullptr) {
		delete[] this->denumireEveniment;
		this->denumireEveniment = new char[strlen(eveniment.denumireEveniment) + 1];
		strcpy_s(this->denumireEveniment, strlen(eveniment.denumireEveniment) + 1, eveniment.denumireEveniment);
	}

}

Eveniment::~Eveniment() {
	delete[] denumireEveniment;
	for (int i = 0; i < nrSectoareLocatie; i++)
	{
		for (int j = 0; j < randuri; j++)
		{
			delete[] matriceLocuri[i][j];
		}
		delete[] matriceLocuri[i];

	}
	delete[] matriceLocuri;

	denumireEveniment = nullptr;
	matriceLocuri = nullptr;


}

//getteri
char* Eveniment::getDenumireEveniment() {
	return denumireEveniment;
}

string Eveniment::getDataEveniment() {
	return dataEveniment;
}

int Eveniment::getMatriceLocuri(int x, int y, int z) {
	return matriceLocuri[x][y][z];
}

int Eveniment::getLocuri() {
	return locuri;
}

int Eveniment::getRanduri() {
	return randuri;
}

int Eveniment::getSectoare() {
	return nrSectoareLocatie;
}

//setteri
void Eveniment::setDenumireEveniment(char* denumireEveniment) {
	if (denumireEveniment != nullptr) {
		delete[] this->denumireEveniment;
		this->denumireEveniment = new char[strlen(denumireEveniment) + 1];
		strcpy_s(this->denumireEveniment, strlen(denumireEveniment) + 1, denumireEveniment);
	}
}

void Eveniment::setDataEveniment(string dataEveniment) {
	if (!dataEveniment.empty()) {
		this->dataEveniment = dataEveniment;
	}
}

void Eveniment::setMatriceLocuri(int sector, int rand, int loc) {
	if(sector>0 && rand >0 && loc>0) matriceLocuri[sector][rand-1][loc-1] = 0;
}

//metode
void Eveniment::amanareEveniment(int nrZile) {
	string aux = dataEveniment.substr(0, 2);
	int zi = atoi(aux.c_str());
	aux = dataEveniment.substr(3, 2);
	int luna = atoi(aux.c_str());
	aux = dataEveniment.substr(6, 4);
	int an = atoi(aux.c_str());

	while (nrZile > 0) {
		if (luna == 2) {
			if (zi + nrZile > 28) {
				nrZile = nrZile - (28 - zi);
				if (nrZile == 0) zi = 1;
				else zi = 0;
				luna++;
				if (luna > 12) {
					luna = 1;
					an++;
				}
			}
			else zi += nrZile, nrZile = 0;

		}
		else if (luna == 7 || luna == 8) {
			if (zi + nrZile > 31) {
				nrZile = nrZile - (31 - zi);
				if (nrZile == 0) zi = 1;
				else zi = 0;
				luna++;
				if (luna > 12) {
					luna = 1;
					an++;
				}
			}
			else zi += nrZile, nrZile = 0;
		}

		else if (luna % 2 == 1) {
			if (zi + nrZile > 31) {
				nrZile = nrZile - (31 - zi);
				if (nrZile == 0) zi = 1;
				else zi = 0;
				luna++;
				if (luna > 12) {
					luna = 1;
					an++;
				}
			}
			else zi += nrZile, nrZile = 0;
		}

		else {
			if (zi + nrZile > 30) {
				nrZile = nrZile - (30 - zi);
				if (nrZile == 0) zi = 1;
				else zi = 0;
				luna++;
				if (luna > 12) {
					luna = 1;
					an++;
				}
			}
			else zi += nrZile, nrZile = 0;
		}
	}
	string ans = to_string(an);
	string lunas = luna < 10 ? ("0" + to_string(luna)) : to_string(luna);
	string zis = zi < 10 ? ("0" + to_string(zi)) : to_string(zi);

	dataEveniment = zis + "." + lunas + "." + ans;

}

void Eveniment::anulareEveniment() {
	evenimentActiv = !evenimentActiv;
}

//operatori
 Eveniment::operator string() {
	return dataEveniment;
}

Eveniment Eveniment::operator++() {
	string aux = dataEveniment.substr(0, 2);
	int zi = atoi(aux.c_str());
	aux = dataEveniment.substr(3, 2);
	int luna = atoi(aux.c_str());
	aux = dataEveniment.substr(6, 4);
	int an = atoi(aux.c_str());

	if (luna == 2) {
		if (zi + 1 > 28) {
			zi = 1;
			luna++;
			if (luna > 12) {
				luna = 1;
				an++;
			}
		}
		else zi++;
	}

	else if (luna == 7 || luna == 8) {
		if (zi + 1 > 31) {
			zi = 1;
			luna++;
			if (luna > 12) {
				luna = 1;
				an++;
			}
		}
		else zi++;
	}

	else if (luna % 2 == 1) {
		if (zi + 1 > 31) {
			zi = 1;
			luna++;
			if (luna > 12) {
				luna = 1;
				an++;
			}
		}
		else zi++;
	}

	else {
		if (zi + 1 > 30) {
			zi = 1;
			luna++;
			if (luna > 12) {
				luna = 1;
				an++;
			}
		}
		else zi++;
	}

	string ans = to_string(an);
	string lunas = luna < 10 ? ("0" + to_string(luna)) : to_string(luna);
	string zis = zi < 10 ? ("0" + to_string(zi)) : to_string(zi);

	dataEveniment = zis + "." + lunas + "." + ans;

	return *this;
}


Eveniment Eveniment::operator++(int i) {
	Eveniment copie = *this;
	string aux = dataEveniment.substr(0, 2);
	int zi = atoi(aux.c_str());
	aux = dataEveniment.substr(3, 2);
	int luna = atoi(aux.c_str());
	aux = dataEveniment.substr(6, 4);
	int an = atoi(aux.c_str());

	if (luna == 2) {
		if (zi + 1 > 28) {
			zi = 1;
			luna++;
			if (luna > 12) {
				luna = 1;
				an++;
			}
		}
		else zi++;
	}

	else if (luna == 7 || luna == 8) {
		if (zi + 1 > 31) {
			zi = 1;
			luna++;
			if (luna > 12) {
				luna = 1;
				an++;
			}
		}
		else zi++;
	}

	else if (luna % 2 == 1) {
		if (zi + 1 > 31) {
			zi = 1;
			luna++;
			if (luna > 12) {
				luna = 1;
				an++;
			}
		}
		else zi++;
	}

	else {
		if (zi + 1 > 30) {
			zi = 1;
			luna++;
			if (luna > 12) {
				luna = 1;
				an++;
			}
		}
		else zi++;
	}

	string ans = to_string(an);
	string lunas = luna < 10 ? ("0" + to_string(luna)) : to_string(luna);
	string zis = zi < 10 ? ("0" + to_string(zi)) : to_string(zi);

	dataEveniment = zis + "." + lunas + "." + ans;

	return copie;
}

//<<>>
ostream& operator<<(ostream& out, Eveniment e) {
	out << e.denumireEveniment;
	return out;
}

istream& operator>>(istream& in, Eveniment& e) {
	in >> e.dataEveniment;
	return in;
}