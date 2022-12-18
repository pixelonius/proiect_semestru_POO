#include <iostream>
#include <string>
#include <iomanip>
#include "Bilet.h"
#include "Eveniment.h"
#include "Turnichet.h"

using namespace std;

int main() {
	int optiune;
	int sector;
	int rand;
	int loc;
	//initiere obiecte
	char* nume = new char[16];
	strcpy_s(nume, 16, "Finala mondial");
	Eveniment Stadion(nume, "18.12.2022", 4, 15, 30);
	int numarMaximBilete = Stadion.getLocuri() * Stadion.getRanduri() * Stadion.getSectoare();
	Bilet* vectorBilete = new Bilet[numarMaximBilete];
	cout << "Salutare!" << endl;
	cout << "Alege o optioune din meniul de mai jos<<: " << endl;
	cout << "1: Achizitioneaza un bilet" << endl << "2: Prezinta biletul pentru scanare "<<endl;
	cout << "Optiunea dumneavoastra: ";
	cin >> optiune;
	do {
	switch (optiune) {
		case 1: {
			cout << "Alege unde vrei biletul!" << endl << "1: Tribuna " << endl << "2: Peluza "<<endl;
			cout << "Optiunea dumnevoastra: ";
			cin >> sector;
			cout << "Alege te rog din locurile libere! Acestea sunt marcate cu 1: "<<endl;
			//formatarea si afisarea matricei de randuri libere
			cout << "   ";
			 for (int i = 0; i < Stadion.getLocuri(); i++)
				cout <<setw(5)<< i + 1;
			 cout << endl;
			for (int i = 0; i < 5.4*Stadion.getLocuri(); i++)
				cout << "-";
			cout << endl;
			for (int i = 0; i < Stadion.getRanduri(); i++) {
				cout <<setw(2)<< i+1<<"|";
				for (int j = 0; j < Stadion.getLocuri(); j++) {
					cout<<setw(5) <<Stadion.getMatriceLocuri(sector,i,j);
				}
				cout << endl;
			}
			

			cout << "Randul: ";
			cin >> rand;
			cout << "Locul: ";
			cin >> loc;
			//verificare daca locul este disponibil
			 int verificat =0;
			 do{
			 if(Stadion.getMatriceLocuri(sector,rand-1,loc-1)!= 1){
			 cout<<"Acest loc nu este liber! Va rugam alegeti altul!"<<endl;
			 cout << "Randul: ";
			cin >> rand;
			cout << "Locul: ";
			cin >> loc;
			 }
			 else verificat = 1;
			 } while(verificat == 0);
			// 
			// 
			//generare bilet
			 string sectorStr = to_string(sector);
			 vectorBilete[Bilet::getNrBileteEmise()].generareBilet(sectorStr, rand, loc);
			 Stadion.setMatriceLocuri(sector, rand, loc);
			//afisare informatii bilet
			 cout << vectorBilete[Bilet::getNrBileteEmise() - 1];
			 break;
		}
		case 2: {
			int nrBilet;
			int id;
			cout << "Pentru validarea biletului, va rugam sa prezentati numarul biletului: ";
			cin >> nrBilet;
			cout <<"Va rugam sa introduceti id-ul biletului: ";
			cin >> id;
			if (Bilet::getBileteEmise()[nrBilet - 1] != id) cout << "Ne pare rau, dar biletul nu este valid!"<<endl<<endl;
			else cout << "Acces permis! Distractie placuta!"<<endl;
			break;

		}
		default:
			cout << "Va rugam sa selectati una din optiunile de mai jos!"<<endl;
		}
	cout<< "Pentru achizitionarea altui bilet, apasati tasta 1!" << endl << "Pentru verificarea unui bilet, apsati tasta 2!"<<endl<< "Pentru iesire, apasati tasta 3!" << endl;
	cin >> optiune;
	} while (optiune != 3);
	
}

