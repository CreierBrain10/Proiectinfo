#include "c.cpp"
#include <iostream>
#ifdef _WIN32
#define cls clear
#include <windows.h>
#endif
using namespace std;
list a, b;
list *selectedList=nullptr;

//functions
void select();
void backOrExit();
void meniu();
void clear();
void selectList();
//endfuncitons

void select(){
	selectList();
	int n;
  cin>>n;
  clear();
  switch (n){
    case (1):
      break;
    case (2):
		int x;
		cout<<"Nodul cautat: ";
		cin>>x;

      break;
    case (3):

      break;
    case (4):

      break;
    case (5):

      break;
    case (6):
			exit(0);
      break;
		default:
			break;
  }
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
	cout<<"Selectati lista pe care efectuati operatia: \n";
	cout<<"1) pentru prima lista"<<"\n2) pentru a doua lista\n";
	cin>>x;
	if(x==1) selectedList=&a;
	else selectedList=&b;
}

void clear(){
	system("clear");
}

void meniu(){
  cout<<1<<") Verificare daca lista este vida"<<'\n';
  cout<<2<<") Cautarea unui nod in lista"<<'\n';
  cout<<3<<") Adaugarea unui nod in lista "<<'\n'; //la inceput sau final
  cout<<4<<") Stergerea tuturor nodurilor cu o anumita valoare"<<'\n';
  cout<<5<<") Concatenarea a doua liste"<<'\n';
  cout<<6<<") Iesire din program"<<'\n';
	select();
}
