#include "c.cpp"
#include <iostream>
using namespace std;
list a, b;
list *selectedList=nullptr;

//functions
void select();
void backOrExit();
void meniu();
void selectList();
void clear();
//endfuncitons

void select(){
	int n,x,numar;
  cin>>n;
  clear();
  switch (n){
    case (1):
			if(selectedList->esteVida()) cout<<"\nLista este vida\n";
				else cout<<"Lista nu este vida\n";
      break;
    case (2):
		cout<<"Nodul cautat: ";
		cin>>x;
		if(!selectedList->search(x)) cout<<"\nNodul "<<x<<" nu exista in lista selectata\n";
			else {
				cout<<"Nodul se afla in lista, intre elementele "<<selectedList->search(x)->prev<<" si "<<selectedList->search(x)->next<<"\n";
			}
      break;
    case (3):
			cout<<"1) pentru adaugare la inceput\n"<<"2) pentru adaugare la final\n";
			cin>>x;
				cout<< "Numarul care trebuie adaugat: ";
				cin>>numar;
			if(x==1)
				{selectedList->addFront(numar);
				break;}
			
			else
				{selectedList->addBack(numar);
				break;}

      break;
		case (4):
			cout<<"1) pentru adaugare inaintea un element\n"<<"2) pentru adaugare dupa un element\n";
			int reper;
			cin>>x;
			if(x==1){
				cout<<"Numarul inaintea caruia se va insera noul nod: ";
				cin>>reper;
				cout<<"\nNumarul ce trebuie inserat: ";
				cin>>numar;
				selectedList->insertBefore(numar,reper);
			}
			else{
				cout<<"Numarul dupa care se va insera noul nod: ";
				cin>>reper;
				cout<<"\nNumarul ce trebuie inserat: ";
				cin>>numar;
				selectedList->insertBefore(numar,reper);
			}
			selectedList->insertBefore(numar,reper);
			break;

    case (5):

      break;
    case (6):

      break;
		case (7):
			clear();
			selectedList->afis();
			break;
    case (8):
			exit(0);
      break;
		default:
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
	clear();
	selectList();
  cout<<1<<") Verificare daca lista este vida"<<'\n';
  cout<<2<<") Cautarea unui nod in lista"<<'\n';
  cout<<3<<") Adaugarea unui nod in lista"<<'\n'; //la inceput sau final
	cout<<4<<") Inserarea unui nod in lista"<<'\n'; //inainte / dupa un element
  cout<<5<<") Stergerea tuturor nodurilor cu o anumita valoare"<<'\n';
  cout<<6<<") Concatenarea a doua liste"<<'\n';
	cout<<7<<") Afisarea listei"<<"\n";
  cout<<8<<") Iesire din program"<<'\n';
	select();
}

void clear(){
#ifdef _WIN32
	system("cls");
	#else 
	system("clear");
#endif
}