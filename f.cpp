#include "c.cpp"
#include <iostream>
#include <fstream>
ifstream fina("lists/lista.txt");
ofstream fouta("lists/lista.txt");
ifstream finb("lists/listb.txt");
ofstream foutb("lists/listb.txt");
using namespace std;
list a, b;
list *selectedList=nullptr;

//functions
void select();
void backOrExit();
void meniu();
void selectList();
void clear();
void initFromFile();
void saveToFile();
//endfuncitons

void select(){
	int n,x,numar;
  cin>>n;
  clear();
  switch (n){
    case (1):
      break;
		case (2):
			break;

    case (3):
   	 break;

		case (4):
			break;

    case (5):
   	 break;

    case (6):
    	break;

		case (7):
			break;

		default:
		cout<<"Ati introdus o optiune inexistenta. Reincercati\n";
		meniu();
			break;
  }
	backOrExit();
}

void backOrExit(){
	int n;
	cout<<"1) Intoarcere in meniu"<<"\n2) pentru iesire din aplicatie\n";
	cin>>n;
	switch(n){
		case(1):
			clear();
			meniu();
		break;
		case(2):
			exit(0);
		break;
	}
}

void selectList(){
	int x;
	cout<<"\nSelectati lista pe care efectuati operatiile: \n";
	cout<<"1) pentru prima lista"<<"\n2) pentru a doua lista\n";
	cin>>x;
	if(x==1) selectedList=&a;
	else selectedList=&b;
	clear();
}

void meniu(){
	cout<<1<<") creare lista din fisierul local\n";
  cout<<2<<") Verificare daca lista este vida\n";
	cout<<3<<") Inserarea unui nod in lista\n"; //inainte / dupa un element / inceput/ final
  cout<<4<<") Cautarea unui nod in lista\n"; //primul cu o anumita valoare/ ultimul cu valoare/ toate cu valoarea
  cout<<5<<") Concatenarea celor doua liste\n";
	cout<<6<<") Afisarea listei"<<"\n";
	cout<<7<<") Schimbarea listei\n";
  cout<<8<<") Iesire din program\n";
	select();
}

void initFromFile(){
	if(selectedList==&a){
		int x;
		while(fina>>x){
			a.addBack(x);
		}
		else{
			int x;
		while(finb>>x){
			b.addBack(x);
			}
		}
	}
}

void saveToFile(){
	if(selectedList==&a){
		nod*p=a.head;
		while(p){
			fouta<<p->inf<<'\n';
			p=p->next;
		}
	}
	else{
		nod*p=b.head;
		while(p){
			foutb<<p->inf<<'\n';
			p=p->next;
		}
	}
}

void clear(){
#ifdef _WIN32
	system("cls");
	#else 
	system("clear");
#endif
}