// MD5:Hf9FpxC2+o1LnxrooeIn9g==
// Verifikator 5.08
// Program:Projekt-seminar
// Pocetno vrijeme: 21:51 (internetsko) Završno vrijeme: 23:21 Preostalo: 5 +
// Opis zadatka:Kopiranje podataka iz dinamickog polja u tekstualnu datoteku
// Autor:Patrik Klaric
// Pocetno vrijeme:5/31/2023 9:52:31 PM
// Završno vrijeme:5/31/2023 11:16:10 PM
// Identifikatori:main,izbor,Prijave,sifra_prijave,prez_ime[50],naziv_predmeta[50],datum_ispita[20],generirajSluc,*,brojPrijava,i,j,unosRucPod,broj_prijava,IspisPod,kopiranjeDat,dat,dat.close,SortiranjePoSif,temp,IspisDat,prijava,cout,PretragaDat,sifraPrijave,pronadeno,if,sifra
// IP:fe80::5ad6:3adf:3b22:fa1b%15 ( 3575 )
// #:#include <iostream>,#include <fstream>,#include <ctime>,#include <cstdlib>,
// Uspješnih/neuspješnih prevodenja:42/9
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Prijave {
	int sifra_prijave;
	char prez_ime[50];
	char naziv_predmeta[50];
	char datum_ispita[20];
};


void generirajSluc(Prijave* prijave, int brojPrijava){
	srand(time(0));
	
	for (int i = 0; i < brojPrijava; i++){
	
		prijave[i].sifra_prijave = rand() % 9000 + 1000;
		
		for (int j = 0; j < 9; j++) {
			prijave[i].prez_ime[j] = 'A' + rand() % 26;
			}
		prijave[i].prez_ime[9] = '0';
		
		for (int j = 0; j < 9; j++) {
			prijave[i].naziv_predmeta[j] = 'A' + rand() % 26;
			}
		prijave[i].naziv_predmeta[9] = '0';
		
		for( int j = 0; j < 5; j++) {
			prijave[i].datum_ispita[j] = '0' + rand() % 10;
			}
		prijave[i].datum_ispita[5] = '0';		
	}
}

void unosRucPod(Prijave* prijave, int broj_prijava) {
		for(int i = 0; i< broj_prijava; i++) {
		
		cout << "Unesite sifru prijave: ";
		cin >> prijave[i].sifra_prijave;
		
		cout << endl;
		
		cout << "Unesite prezime i ime studenta: ";
		cin.ignore();
		cin.getline(prijave[i].prez_ime, 30);
		
		cout << endl;
		
		cout << "Unesite naziv predmeta: ";
		cin >> prijave[i].naziv_predmeta;
		
		cout << endl;
		
		cout << "Unesite datum ispita: ";
		cin >> prijave[i].datum_ispita;
		
	}
}

void IspisPod(Prijave* prijave, int brojPrijava){
	for (int i = 0; i < brojPrijava; i++){
		cout << "Sifra prijave: " << prijave[i].sifra_prijave << endl;
		cout << "Prezime i ime studenata: " << prijave[i].prez_ime << endl;
		cout << "Naziv predmeta: " << prijave[i].naziv_predmeta << endl;
		cout << "Datum ispita: " << prijave[i].datum_ispita << endl;
		cout << endl;
	}
}

void kopiranjeDat(Prijave*  prijave, int brojPrijava){
	fstream dat;
	dat.open("projekt.dat", ios::out | ios::binary);
	
	dat.write(reinterpret_cast<char*>(prijave), brojPrijava * sizeof(Prijave));
	dat.close();
}

void SortiranjePoSif(Prijave* prijave, int brojPrijava) {
	for (int i = 0; i < brojPrijava - 1; i++) {
		for ( int j = 0; j < brojPrijava - i -1; j++) {
			if ( prijave[j].sifra_prijave > prijave [j + 1].sifra_prijave){
				
				Prijave temp = prijave [j];
				prijave [j] = prijave [j+1];
				prijave [j + 1] = temp;
			}
		}
	}
}

void IspisDat() {
	fstream dat;
	dat.open("projekt.dat", ios::in | ios::binary);
	
	Prijave prijava;
	
	while (dat.read((char*)&prijava, sizeof(Prijave))) {
		cout << "Sifra prijave: " << prijava.sifra_prijave << endl;
		cout << "Prezime i ime studenta: " << prijava.prez_ime << endl;
		cout << "Naziv predmeta: " << prijava.naziv_predmeta << endl;
		cout << "Datum ispita: " << prijava.datum_ispita << endl;
		cout << endl;
	}
	dat.close();
}

void PretragaDat (int sifraPrijave) {
	fstream dat;
	dat.open("projekt.dat", ios::in | ios::binary);
	
	Prijave prijava;
	bool pronadeno = false;
	
	while (dat.read((char*)&prijava, sizeof(Prijave))){
		if(prijava.sifra_prijave == sifraPrijave) {
			cout << "Sifra prijave: " << prijava.sifra_prijave << endl;
			cout << "Prezime i ime studenta: " << prijava.prez_ime << endl;
			cout << "Naziv predmeta: " << prijava.naziv_predmeta << endl;
			cout << "Datum ispita: " << prijava.datum_ispita << endl;
			cout << endl;
			pronadeno = true;
			break;
			}
		}
		if(!pronadeno) {
			cout << "Zapis za unesenu sifru prijave nije pronaden. " << endl;
			}
			dat.close();
	}
// pocetak izvodenja programa
int main(){
	int brojPrijava;
	cout << "Molim da unesete broj prijava: ";
	cin >> brojPrijava;
	
	Prijave* prijave = new Prijave[brojPrijava];
	
	int izbor;

	do{
		
		cout << "1. Generiranje podataka" << endl;
		cout << "2. Rucni unos podataka" << endl;
		cout << "3. Ispis polja" << endl;
		cout << "4. Kopiranje u datoteku" << endl;
		cout << "5. Sortiranje podataka prema primarnom kljucu(sifri)" << endl;
		cout << "6. Ispis datoteke" << endl;
		cout << "7. Pretrazivanje datoteke" << endl;
		cout << "9. Izlaz" << endl;
		
		cin >> izbor;
		
		switch (izbor) {
			case 1: generirajSluc(prijave, brojPrijava); break;
			case 2: unosRucPod(prijave, brojPrijava); break;
			case 3: IspisPod(prijave, brojPrijava); break;
			case 4: kopiranjeDat(prijave, brojPrijava); break;
			case 5: SortiranjePoSif(prijave, brojPrijava); break;
			case 6: IspisDat(); break;
			case 7: 
				int sifra;
				cout << "Unesite sifru prijave koju zelite pronaci: ";
				cin >> sifra;
				PretragaDat(sifra); 
				break;
			case 9: break;
			
		}
	}
	
	while (izbor != 9);

	
	system("PAUSE");
	return 0;
}
