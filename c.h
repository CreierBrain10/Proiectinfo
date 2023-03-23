#ifndef C_H
#define C_H
#include<iostream>
using namespace std;
struct nod {int inf; nod *prev, *next;};
class list{
  private: nod *head, *tail;
  public:
  list(int a);
  list(list a);
  ~list();
	void copyNod(nod a);
	int esteVida(list a){return head==NULL;}
	list search(int a);
	void addFront(int a);
	void addBack(int a);
	void deleteFirstNod();
	void deleteLastNod();
	void deleteAllInf(int a);
	void deleteFirstInf(int a);
	void deleteLastInf(int a);
	void operator+=(list a, list b);
	friend ostream& operator<< (ostream& out, const list& elem);
	};
#endif