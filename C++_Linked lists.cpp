// MD5:Yot0ZBBrmjAPWqP5PktMqQ==
// Verifikator 5.08
// Program:Vjezba1
// Poèetno vrijeme: 12:40 (internetsko) Završno vrijeme: 14:06 Preostalo: 5 +
// Opis zadatka:Vjezba1
// Autor:Patrik Klariæ
// Poèetno vrijeme:22.3.2023. 12:40:25
// Završno vrijeme:22.3.2023. 14:00:45
// Identifikatori:autor,autor_id,ime_prez[30],nas_rad[30],*sljedeci,main,dodaj,*glava,*novi,*zadnji,zadnji,ispis,*tekuci,pretrazi,id,izbor,glava,nid,brisanje,*brisi,*prethodni
// IP:fe80::4cd1:fcd1:de09:1de8%9 ( 3201 )
// #:#include <iostream>,#include <cmath>,
// Uspješnih/neuspješnih prevoðenja:45/25
#include <iostream>
#include <cmath>
using namespace std;

struct autor {
	int autor_id;
	char ime_prez[30];
	char nas_rad[30];
	autor *sljedeci;
};

void dodaj(autor *glava) {
	autor *novi, *zadnji;
	zadnji = glava;
	while (zadnji -> sljedeci)
		zadnji = zadnji -> sljedeci;
	novi = new autor;
	zadnji -> sljedeci = novi;
	novi -> sljedeci = NULL;
	cout << "Unesi id:";
	cin >> novi -> autor_id;
	cout << "Unesi ime:";
	cin >> novi -> ime_prez;
		cout << "Unesi naslov rada:";
	cin >> novi -> nas_rad;
	}
	
void pretrazi(autor *glava, int id){
	autor *tekuci = glava -> sljedeci;
	while(tekuci){
		if (tekuci -> autor_id == id){
		cout << "Sifra autora: " << tekuci -> autor_id << endl;
		cout << "Ime: " << tekuci -> ime_prez << endl;
		cout << "Naslov: " << tekuci -> nas_rad << endl;
}
	tekuci = tekuci -> sljedeci;
	}
}

void ispis (autor *glava ){

	autor *tekuci = glava -> sljedeci;
	while (tekuci) {
		cout << "Sifra autora: " << tekuci -> autor_id << endl;
		cout << "Ime: " << tekuci -> ime_prez << endl;
		cout << "Naslov: " << tekuci -> nas_rad << endl;
	tekuci = tekuci -> sljedeci;
	}
	cout << endl;
}

void brisanje ( autor *glava, int id){
	autor *brisi = glava -> sljedeci;
	autor *prethodni = glava;
	
	while (brisi) {
	if (brisi -> autor_id == id){
	prethodni -> sljedeci = brisi -> sljedeci;
	delete brisi;
	}
	prethodni = brisi;
	brisi = brisi -> sljedeci;
	}
	}
	
int main(){
autor *glava = new autor;
glava -> sljedeci = NULL;

	int id,nid, izbor;
	
	do {
		cout << "Izaberite:" << endl;
		cout << "1. Unos novog elementa " << endl;
		cout << "2. Ispis" << endl;
		cout << "3. Pretraživanje elemenata" << endl;
		cout << "4. Brisanje elemenata" << endl;
		cout << "9. Izlaz iz programa" << endl;
		cin >> izbor;
	
		switch (izbor){
		case 1: dodaj(glava); break;
		
		case 2: ispis(glava); break;
		
		case 3: cout <<"Broj: ";
				cin >> id;
			    pretrazi(glava, id); break;
    			
 		case 4: cout <<"Unesi broj: ";
				cin >> nid;
			    brisanje(glava, nid); break;
    	
		case 9: break;
     	}
	}
			
	while (izbor != 9);
	cout << "Kraj programa." << endl;
	
	system("PAUSE");
}
