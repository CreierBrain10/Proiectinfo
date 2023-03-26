#include "c.h"
#include <iostream> 
using namespace std;

void list::deleteFirstNod(){
nod*p=head;
head->next->prev=NULL;
head=head->next;
delete p;
num();
}

void list::deleteLastNod(){
nod*p=tail;
tail->prev->next=NULL;
tail=tail->prev;
delete p;
num();
}

void list::addFront(int a){
	nod *p=new nod;
	p->inf=a;
	p->next=head;
	head->prev=p;
	head=p;
	num();
}

void list::addBack(int a){
	nod *p=new nod;
	p->inf=a;
	p->prev=tail;
	tail->next=p;
	tail=p;
	num();
}

void list::copyNod(nod a){
	if(!head) addFront(a.inf);
		else addBack(a.inf);
		num();
}

nod* list::search(int a){
	nod *p=head;
	while(p){
		if(p->inf==a) return p;
		p=p->next;
	}
	return nullptr;
}

void list::insertBefore(int a, int b){
	if(head->inf==b) addFront(b);
	nod*p=new nod;
	nod*q=head;
	while(q)
	{
		if(q->next->inf==b){
			p->inf=a;
			p->next=q->next;
			p->prev=q;
			q->next=p;
			p->next->prev=p;
			return;
		}
		p=p->next;
	}
}

void list::insertAfter(int a, int b){
	if(tail->inf==b) addBack(b);
		nod*p=new nod;
		nod*q=head;
	while(q)
	{
		if(q->next->inf==b){
			p->inf=a;
			p->next=q->next;
			q->next->prev=p;
			p->prev=q;
			q->next=p;
			return;
		}
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
	num();
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
	num();
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

void list::afis(){
	nod*p=head;
	while(p){
		cout<<p->inf<<'\n';
		p=p->next;
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
	c.num();
}

list::list(int a){
	nod *p=new nod;
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