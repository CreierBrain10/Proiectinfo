#ifndef C_H
#define C_H
#include<iostream>
using namespace std;
struct nod {int inf,nr; nod *prev, *next;};
class list{
  private: nod *head, *tail;
  public:
	list(){head=tail=NULL;};
  list(int a);
  list(const list& a);
  ~list();
	void num(){nod*p=head;p->nr=1;p=p->next;while(p){p->nr=p->prev->nr+1;}}
	int esteVida(){return head==NULL;}
	nod* search(int a);
	void addFront(int a);
	void addBack(int a);
	void insertBefore(int a, int reper);
	void insertAfter(int a, int reper);
	void deleteFirstNod();
	void deleteLastNod();
	void deleteAllInf(int a);
	void deleteFirstInf(int a);
	void deleteLastInf(int a);
	void afis();
	void operator+=(list b);
};
	/*friend ostream& operator<< (ostream& out, const list& elem);
	*/
#endif