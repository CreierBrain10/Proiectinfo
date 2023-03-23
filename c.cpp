#include "c.h"
#include <iostream>
using namespace std;

void list::deleteFirstNod(){
nod*p=head;
head->next->prev=NULL;
head=head->next;
delete p;
}

void list::deleteLastNod(){
nod*p=tail;
tail->prev->next=NULL;
tail=tail->prev;
delete p;
}

void list::addFront(int a){
	nod *p=new nod;
	p->inf=a;
	p->next=head;
	head->prev=p;
	head=p;
}

void list::addBack(int a){
	nod *p=new nod;
	p->inf=a;
	p->prev=tail;
	tail->next=p;
	tail=p;
}

void list::copyNod(nod a){
	if(!head) addFront(a.inf);
		else addBack(a.inf);
}

nod list::search(int a){
	nod*p=head;
	while(p){
		if(p->inf==a) return *p;
		p=p->next;
	}
}

void list::deleteAllInf(int a){
	nod*p=head;
	while(p){
		if(p->inf==a){
			if(p==head) deleteFirstNod();
			else if(p==tail) deleteLastNod();
			else{
				p=p->prev;
				nod *q=p->next;
				p->next=q->next;
				q->next->prev=p;
				delete q;
			}
		}
		p=p->next;
	}
}

void list::deleteFirstInf(int a){
	nod *p=head;
	if(p->inf==a){
		if(p==head)
		p=p->prev;
		nod*q=p->next;
		q->next->prev=p;
		p->next=q->next;
		delete q;
	}
}

void list::deleteLastInf(int a){
	nod *p=tail;
	while(p){
		if(p->inf){
			if(p==head) deleteFirstNod();
			p=p->prev;
			nod*q=p->next;
			q->next->prev=p;
			p->next=q->next;
			delete q;
		}
		p=p->prev;
	}

}

list list::operator+=(list b){
list c(b);
nod*p=tail;
while(p){
	c.addFront(p->inf);
	p=p->prev;
}
return c;

}

void meniu(){
  cout<<1<<"Verificare daca lista este vida"<<'\n';
  cout<<2<<"Cautarea unui nod in lista"<<'\n';
  cout<<3<<"Adaugarea unui nod in lista "<<'\n'; //la inceput sau final
  cout<<4<<"Stergerea tuturor nodurilor cu o anumita valoare"<<'\n';
  cout<<5<<"Concatenarea a doua liste"<<'\n';
  cout<<6<<"Iesire din program"<<'\n';
}

void select(){
	int n;
  cin>>n;
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
			exit(0);
      break;
		default:
			break;
  }
}

list::list(int a){
	nod*p=new nod;
	p->inf=a;
	p->next=p->prev=NULL;
	head=tail=p;
}

list::list(const list& a){
	nod*p=a.head;
	while(p){
		copyNod(*p);
		p=p->next;
	}
}

list::~list(){
	nod *p=tail;
	while(p){
		p=p->prev;
		delete p->next;
	}
	if(head) delete head;
	head=tail=NULL;
}

/*ostream& operator<< (ostream& out, const list& elem)
{
    nod *p=elem.head;
		while(p){
			out <<p->inf<<'\n'; 
			p=p->next;
		}
    return out;
}*/