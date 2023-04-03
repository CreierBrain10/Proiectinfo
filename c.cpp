#include "c.h"
#include <iostream> 
using namespace std;

nod* list::search(int a){
	nod*p=head;
	while(p){
		if(p->inf==a){
			return p;
		}
	}
	return nullptr;
}

void list::addFront(int a){
	nod*p=new nod;
	p->inf=a;
	p->next=head;
	head->prev=p;
	head=p;
	num();
}

void list::addBack(int a){
	nod*p=new nod;
	p->inf=a;
	tail->next=p;
	p->prev=tail;
	tail=p;
	num();
}

void list::insertBefore(int a, int reper){
	if(head->inf==reper){addFront(a); return;}
	nod*p=new nod;
	nod*q=head;
	while(q){
		if(q->inf==reper){
			p->next=q;
			p->prev=q->prev;
			p->prev->next=p;
			q->prev=p;
			num();
			return;
		}
	}
	delete p;
}

void list::insertAfter(int a, int reper){
	if(tail->inf==a) {addBack(a); return;}
	nod*p=new nod;
	p->inf=
	nod*q=head;
	while(q){
		if(q->inf==reper){
			p->next=q->next;
			p->next->prev=p;
			p->prev=q;
			q->next=p;
			num();
			return;
		}
	}
	delete p;
}

void list::deleteFirstNod(){
	if(head==tail==NULL) return;
	if(head==tail) {delete head; head=tail=NULL; return;}
	nod*p=head;
	head=head->next;
	delete p;
	num();
}

void list::deleteLastNod(){
	if(head==tail==NULL) return;
	if(head==tail) {delete tail; head=tail=NULL; return;}
	nod*p=tail;
	tail=tail->prev;
	delete p;
	num();
}

void list::deleteAllInf(int a){
	nod*p=head;
	while(p){
		if(p->inf==a){
			if(p==head) deleteFirstNod();
			else
			if(p==tail) deleteLastNod();
			else{
				p->prev->next=p->next;
				p->next->prev=p->prev;
			}
		}
	}
	num();
}

void list::deleteFirstInf(int a){
	if(head->inf==a) deleteFirstNod();
	else{
		nod*p=head;
		while(p){
			if(p->inf==a){
				p->prev->next=p->next;
				p->next->prev=p->prev;
				num();
				return;
			}
		}
	}
}

void list::deleteLastInf(int a){
	if(tail->inf==a) deleteLastNod();
	else{
		nod*p=head;
		while(p){
			if(p->inf==a){
				p->prev->next=p->next;
				p->next->prev=p->prev;
				num();
				return;
			}
		}
	}
}

void list::afis(){
	nod*p=head;
	while(p){
		cout<<'\n'<<p->inf<<'\n';
	}
}

void list::operator+=(list b){
	tail->next=b.head;
	b.head->prev=tail;
}

list::list(int a){
	nod *p=new nod;
	p->inf=a;
	p->next=p->prev=NULL;
	head=tail=p;
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

list::list(const list& b){
	~list();
	nod*p=b.head;
	while(p){
		addFront(p->inf);
	}
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