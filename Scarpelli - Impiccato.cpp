//Scarpelli Martina
#include <iostream>
#include <string>
using namespace std;
const int MASSI=100;
int lun=0;
char parola[MASSI];
char indovinate[MASSI];
char lut[MASSI]; //lettere gia' inserite
char lettera; //lettera inserita dall'utente
int tentativi=5; //tentativi dell'utente
int POS;
bool cont_lut;
void inserisci();
void impiccato();
void stampa_parziale();
void trovalun();
void controlla_vit();
void controlla_lut();
main(){
    inserisci();
	trovalun();
	impiccato();
}
void inserisci(){
	cout<<"\nInserire la parola: ";
	cin>>parola;
	system("CLS");
}
void impiccato(){
	bool presente=false; //sentinella controlla se c'e' o no
	while(tentativi!=0){ //se sono finiti i tentativi esce dal programma e rivela la parola
		presente=false;
		stampa_parziale();
		cout<<"\nInserisci la lettera: "<<"\n";
		cin>>lettera;
		controlla_lut();
		if(cont_lut==false){ //se e' una lettera "nuova" procede con il programma
				for(int pos=1; pos<lun; pos++){ 
			if(parola[pos]==lettera){ //controlla se ci sono lettere uguali
					indovinate[pos]=parola[pos]; //inserisce quella corrispondente nella cella del vettore parallelo con la parola che viene progressivamente indovinata
				presente=true;
				controlla_vit();
			}	
		}
if(presente==false){ //se non vi e' alcuna corrispondenza toglie un tentativo
				cout<<"\nSBAGLIATO!";
				tentativi--;
				cout<<"\nHai ancora "<< tentativi<< " tentativi\n\n";
		}
	}
		}
	cout<<"\n\nHAI PERSO!!\nLa parola era: ";
	for(int i=0; i<lun+1; i++){
		cout<<parola[i]<<" ";
	}
}
void trovalun(){ //trova la lunghezza della parola inserita 
	for(int posizione=1; parola[posizione]!=0; posizione++){
		lun++;
	}
	indovinate[0]=parola[0];
	indovinate[lun]=parola[lun];
}
void stampa_parziale(){ //traccia progresso della parola
	for(int stampa=0; stampa<lun+1; stampa++){
		if(indovinate[stampa]==0) indovinate[stampa]=95;
		cout<< indovinate[stampa]<<" ";
		}
	}
void controlla_vit(){ //controlla se ci siano ancora spazi vuoti del vettore - quindi se qualche lettera non e' stata ancora trovata
	bool vinto=true;
	for(int vittoria=0; vittoria<lun+1; vittoria++){
	if(indovinate[vittoria]==95) vinto=false;
	}
	if(vinto==true){ //se non ne trova significa che sono state trovate tutte - conferma vittoria e esce
		stampa_parziale();
			cout<<"\n\nCOMPLIMENTI HAI VINTO!";
			exit(0);
		}
	}
	void controlla_lut(){
	cont_lut=false;
	if(POS!=0){ //controlla solamente quando sono inserite almeno 2 lettere cosi' da non ripetere controllo sulla stessa lettera
		for(int i=0; i<POS; i++){
			if(lut[i]==lettera) cont_lut=true; //controlla che la lettera non fosse stata precedentemente usata
		}
	}
	if(cont_lut==true)cout<<"\nLettera gia' utilizzata. Inserisci nuovamente.\n";
	lut[POS]=lettera; //inserisce lettera inserita dall'utente nel vettore delle lettere utilizzate
	POS++; 
	}
