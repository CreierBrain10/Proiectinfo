#ifndef C_H
#define C_H
class element{
  private: int inf;
  element *next,*prev;
  public:
  element(int a);
  element(element a);
  ~element(element a);
	int esteVida(element a){return head==NULL;}
	element search(int a);
	void addFront(int a);
	void addBack(int a);
	void deleteAllInf(int a);
	void deleteFirstInf(int a);
	void deleteLastInf(int a);
	void operator+=(element a, element b);
	friend ostream& operator<< (ostream& out, const element& elem);
	}

#endif