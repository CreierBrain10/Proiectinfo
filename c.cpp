#include "c.h"
#include <iostream> 
using namespace std;

nod* list::search(int a){
	nod*p=head;
	while(p){
		if(p->inf==a) return p;
		p=p->next;
	}
	return nullptr;
}

void list::addFront(int a){
    nod* p = new nod;
    p->inf = a;
    p->prev = NULL;
    p->next = head;
    if(head == NULL){
        head = tail = p;
    }
    else{
        head->prev = p;
        head = p;
    }
}

void list::addBack(int a){
    nod* p = new nod;
    p->inf = a;
    p->next = NULL;
    p->prev = tail;
    if(tail == NULL){
        head = tail = p;
    }
    else{
        tail->next = p;
        tail = p;
    }
}

void list::insertBefore(int a, int reper) {
    nod* p = new nod;
    p->inf = a;

    if (head == nullptr) {
        // If the list is empty, set both head and tail to the new node
        p->prev = nullptr;
        p->next = nullptr;
        head = p;
        tail = p;
    } else {
        nod* q = search(reper);
        if (q == nullptr) {
            // If the reference node is not found, do nothing
            delete p;
            return;
        }
        p->prev = q->prev;
        p->next = q;
        if (q->prev == nullptr) {
            // If the reference node is the head, set head to the new node
            head = p;
        } else {
            q->prev->next = p;
        }
        q->prev = p;
    }
}

void list::insertAfter(int a, int reper) {
    nod* p = new nod;
    p->inf = a;

    if (head == nullptr) {
        // If the list is empty, set both head and tail to the new node
        p->prev = nullptr;
        p->next = nullptr;
        head = p;
        tail = p;
    } else {
        nod* q = search(reper);
        if (q == nullptr) {
            // If the reference node is not found, do nothing
            delete p;
            return;
        }
        p->prev = q;
        p->next = q->next;
        if (q->next == nullptr) {
            // If the reference node is the tail, set tail to the new node
            tail = p;
        } else {
            q->next->prev = p;
        }
        q->next = p;
    }
}

void list::deleteFirstNod() {
    if (head == nullptr) {
        // If the list is empty, do nothing
        return;
    } else if (head == tail) {
        // If there is only one node in the list, delete it and set both head and tail to null
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        // Otherwise, delete the head node and update the head pointer
        nod* p = head;
        head = p->next;
        head->prev = nullptr;
        delete p;
    }
}

void list::deleteLastNod() {
    if (tail == nullptr) {
        // If the list is empty, do nothing
        return;
    } else if (head == tail) {
        // If there is only one node in the list, delete it and set both head and tail to null
        delete tail;
        head = nullptr;
        tail = nullptr;
    } else {
        // Otherwise, delete the tail node and update the tail pointer
        nod* p = tail;
        tail = p->prev;
        tail->next = nullptr;
        delete p;
    }
}

void list::deleteAllInf(int a){
    nod* p = head;
    while(p != NULL){
        if(p->inf == a){
            if(p == head){
                head = p->next;
                if(head != NULL){
                    head->prev = NULL;
                } else {
                    tail = NULL;
                }
            } else if(p == tail){
                tail = p->prev;
                if(tail != NULL){
                    tail->next = NULL;
                } else {
                    head = NULL;
                }
            } else {
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            nod* q = p;
            p = p->next;
            delete q;
        } else {
            p = p->next;
        }
    }
}


list::list(){
    head = tail = NULL;
}

list::list(int a){
    nod* p = new nod;
    p->inf = a;
    p->prev = NULL;
    p->next = NULL;
    head = tail = p;
}

list::list(const list& a){
    head = tail = NULL;
    nod* p = a.head;
    while(p != NULL){
        addBack(p->inf);
        p = p->next;
    }
}

list::~list(){
    nod* p = head;
    while(p != NULL){
        nod* q = p;
        p = p->next;
        delete q;
    }
    head = tail = NULL;
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