#include <iostream>
#include <string>
#include "Bilet.h"


using namespace std;
bool admin;
//Bilet
istream& operator>>(istream& in, Bilet& b) {
	if (admin) {
		in >> b.id;
	}
	return in;
}
ostream& operator<<(ostream& out, Bilet b) {
	out << b.id;
	return out;
}




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
	Eveniment() {
		denumireEveniment = nullptr;
		dataEveniment = "";
		evenimentActiv = true;
		randuri = 0;
		locuri = 0;
		matriceLocuri = nullptr;
	}
	Eveniment(char* denumireEveniment, string dataEveniment, int nrSectoareLocatie, int randuri, int locuri) {
		this->denumireEveniment = new char[strlen(denumireEveniment) + 1];
		strcpy_s(this->denumireEveniment, strlen(denumireEveniment) + 1, denumireEveniment);
		this->dataEveniment = dataEveniment;
		evenimentActiv = true;
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
		for(int i=0;i<nrSectoareLocatie;i++)
			for (int j = 0; j < randuri; j++) {
				for (int z = 0; z < locuri; z++) {
					matriceLocuri[i][j][z] = z+1;
				}
			}
	}

	Eveniment(const Eveniment& eveniment) {
		this->dataEveniment = eveniment.dataEveniment;
		this->evenimentActiv = eveniment.evenimentActiv;
		if (eveniment.denumireEveniment != nullptr) {
			delete[] this->denumireEveniment;
			this->denumireEveniment = new char[strlen(eveniment.denumireEveniment) + 1];
			strcpy_s(this->denumireEveniment, strlen(eveniment.denumireEveniment) + 1, eveniment.denumireEveniment);
		}

	}

	~Eveniment() {
		delete[] denumireEveniment;
		for (int i = 0; i <=nrSectoareLocatie; i++)
		{
			for (int j = 0; j <= randuri; j++)
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
	char* getDenumireEveniment() {
		return denumireEveniment;
	}

	string getDataEveniment() {
		return dataEveniment;
	}

	//setteri
	void setDenumireEveniment(char* denumireEveniment) {
		if (denumireEveniment != nullptr) {
			delete[] this->denumireEveniment;
			this->denumireEveniment = new char[strlen(denumireEveniment) + 1];
			strcpy_s(this->denumireEveniment, strlen(denumireEveniment) + 1, denumireEveniment);
		}
	}

	void setDataEveniment(string dataEveniment) {
		if (!dataEveniment.empty()) {
			this->dataEveniment = dataEveniment;
		}
	}

	//metode
	void amanareEveniment(int nrZile) {
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

	void anulareEveniment() {
		evenimentActiv = !evenimentActiv;
	}

//operatori

	explicit operator string() {
		return dataEveniment;
	}

	Eveniment operator++() {
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


	Eveniment operator++(int i) {
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
	friend ostream& operator<<(ostream&, Eveniment);
	friend istream& operator>>(istream&, Eveniment&);


};

ostream& operator<<(ostream& out, Eveniment e){
	out << e.denumireEveniment;
	return out;
}

istream& operator>>(istream& in, Eveniment& e) {
	in >> e.dataEveniment;
	return in;
}

class Turnichet{
	const int id;
	string* sectoareValidate;
	static int nrSectoare;
	bool functional;

public:

//constructori
	Turnichet():id(0) {
		sectoareValidate = nullptr;
		nrSectoare = 0;
		functional = false;
	}
	Turnichet(int id, string sector1, string sector2, int nrSectoare): id(id){
		sectoareValidate = new string[nrSectoare];
		if(nrSectoare == 1){sectoareValidate[0] = sector1;}
		else if(nrSectoare>1){
			sectoareValidate[1] = sector2;
			sectoareValidate[0] = sector1;
		}
		
	}

	Turnichet(const Turnichet& t):id(t.id) {
		this->functional = t.functional;
		delete[] this->sectoareValidate;
		this->sectoareValidate = new string[nrSectoare];
		for (int i = 0; i < nrSectoare; i++) {
			this->sectoareValidate[i] = t.sectoareValidate[i];
		}

	}

	~Turnichet() {
		delete[] sectoareValidate;
		sectoareValidate = nullptr;
	}

//metode
	void inlocuireTurnichet(Turnichet turnichetDezafectat, Turnichet turnichetInlocuitor) {
		for (int i = 0; i < nrSectoare; i++) {
			if (turnichetDezafectat.sectoareValidate[i].compare(turnichetInlocuitor.sectoareValidate[i]) != 0) {
				turnichetInlocuitor.sectoareValidate[i] = turnichetDezafectat.sectoareValidate[i];
			}
			delete[] turnichetDezafectat.sectoareValidate;
			turnichetDezafectat.sectoareValidate = nullptr;
			turnichetDezafectat.functional = false;
		}
	}


	void pornireTurnichet() {
		functional = true;
	}

//operatori
	void operator!() {
		functional = false;
	}

	friend Turnichet operator+(string x, Turnichet);
	
//<<>>
	friend ostream& operator<<(ostream&, Turnichet);
	friend istream& operator>>(istream&, Turnichet&);

};

ostream& operator<<(ostream& out, Turnichet t) {
	out << t.id;
	return out;
}

istream& operator>>(istream& in, Turnichet& t) {
	in >> t.functional;
	return in;
}

Turnichet operator+(string x, Turnichet t) {
	if(t.functional){
		for (int i = 0; i < t.nrSectoare; i++) {
		if (t.sectoareValidate[i].empty()) {
			t.sectoareValidate[i] = x;
			break;
		}
	}
	}
	return t;
}
int main() {
	int optiune;
	int sector;
	int rand;
	int loc;
	//initiere obiecte
	cout << "Salutare!" << endl;
	cout << "Alege o optioune din meniul de mai jos<<: " << endl;
	cout << "1: Achizitioneaza un bilet" << endl << "2: Prezinta biletul pentru scanare";
	cin >> optiune;
	while (optiune != 3) {
	switch (optiune) {
		case 1: {
			cout << "Alege unde vrei biletul!" << endl << "1: Tribuna " << endl << "Peluza";
			cin >> sector;
			cout << "Alege te rog din locurile libere! Acestea sunt marcate cu 1";
			//cout matrice locuri libere
			/* for (int i = 0; i < Stadion.locuri; i++)
				cout << i + 1;
			for (int i = 0; i < Stadion.locuri; i++)
				cout << "-";
			for (int i = 0; i < Stadion.randuri; i++) {
				for (int j = 0; j < Stadion.locuri; j++) {
					cout << i << "| " << Stadion.matriceLocuri[i][j] << " ";
				}
			}
			*/

			cout << "Randul: ";
			cin >> rand;
			cout << "Locul: ";
			cin >> loc;
			//verificare daca locul este disponibil
			// int verificat =0;
			// do{
			// if(Stadion.matriceLocuri[sector][rand][loc] != 1){
			// cout<<"Acest loc nu este liber! Va rugam alegeti altul!";
			// cout << "Randul: ";
			//cin >> rand;
			//cout << "Locul: ";
			//cin >> loc;
			// }
			// else verificat = 1;
			// } while(verificat = 0);
			// 
			// 
			//generare bilet
			// 
			//afisare informatii bilet
		}
		case 2: {
			int nrBilet;
			int id;
			cout << "Pentru validarea biletului, va rugam sa prezentati" << endl << "Numarul biletului: ";
			cin >> nrBilet;
			cout << endl<<"Id-ul biletului: ";
			cin >> id;
			//verificare autenticitate

		}
		default:
			cout << "Va rugam sa selectati una din optiunile de mai sus!";
		}
	cin >> optiune;
	}
	
}

