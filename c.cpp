#include <c.h>
using namespace std;
element *head=NULL, *tail=NULL;

void element::addFront(int a){
	element *p=new element;
	p->inf=a;
	p->next=head;
	p->next->prev=p;
	if(head->next==NULL) tail=head;
}

void element::addBack(int a){
	if(head==NULL) {addFront(a); return}
	element *p=new element;
	p->prev=tail;
	tail->next=p;
	tail=p;
}

element element::search(int a){
	element *p=head;
	while(p){
		if(a==p->inf) return p;
		p=p->next;
	}
}

void element::deleteAllInf(int a){
	element *p=head;
	if(p->inf==a) ~element(p);
	while(p){
		if(p->inf==a){
			p=p->prev;
			~element(p->next);
		}
		p=p->next;
	}
}

void element::deleteFirstInf(int a){
		element *p=head;
	while(p->inf!=a){
		p=p->next;
	}
	~element(p);
}

void element::deleteLastInf(int a){
	element *p=tail;
	while(p->inf!=a){
		p=p->prev;
	}
	~element(p);
}

void element::operator+=(element b){
	element *p=tail;
	p->next=b.head;
}

void meniu(){
  cout<<1<<"Verificare daca lista este vida"<<'\n';
  cout<<2<<"Cautarea unui nod in lista"<<'\n';
  cout<<3<<"Adaugarea unui nod in lista "<<'\n'; //la inceput sau final
  cout<<4<<"Stergerea tuturor nodurilor cu o anumita valoare"<<'\n';
  cout<<5<<"Concatenarea a doua liste"<<'\n';
  cout<<8<<"Iesire din program"<<'\n';
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

     break;
    case (7):

     break;
    case (8):

     break;
    default:
    break
  }
}

element::element(int a){
	element *p=new element;
		p->inf=a, p->next=NULL,p->prev-NULL;
  }

element::element(element a){
    inf=a.inf;
    next=a.next;
     prev=a.prev;
  }

element::~element(element a){
	element *p=head;
	while(p!=a){
		p=p->next;
	}
	element *q=next;
	q->prev=p;
	p->next=q;
	delete a;
}