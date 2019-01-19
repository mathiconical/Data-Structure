#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;


struct Node{
    int data;
    Node *prev, *next;
};


class LinkedList
{
    public:
        LinkedList() : n(0) { first = NULL; }
        virtual ~LinkedList() {while(!isEmpty()) rem(); }


        bool isEmpty(){
            return n == 0;
        }

        void rem(){
            if(!isEmpty()){
                Node *q = first;
                while(q->next != NULL){
                    q = q->next;
                }
                if(q->prev != NULL)
                    q->prev->next = NULL;
                else if(q->next == NULL && q->prev == NULL){
                    first = NULL;
                    q = NULL;
                }
                delete q;
                n--;
            }
            else
                cout << "\nLista vazia.\n";
        }

        void addBegin(int data){
            if(!isEmpty()){
                Node *t = new Node;
                t->data = data;
                t->next = first;
                first->prev = t;
                first = t;
                first->prev = NULL;
                n++;
            }
            else
                //cout << "\nLista vazia.\n";
                add(data);
        }

        void remBegin(){
            if(!isEmpty()){
                if(first->next != NULL){
                    Node *q = first;
                    first = first->next;
                    delete q;
                    first->prev = NULL;
                }
                else if(first != NULL && first->next == NULL){
                    Node *q = first;
                    delete q;
                    first = NULL;
                }
                n--;
            }
            else
                cout << "\nLista vazia.\n";
        }

        void addAt(int data, int local){
            if(!isEmpty()){
                int m;
                if(local > n)       m = n;
                else if(local < n)  m = 1;
                else                m = local;
                Node *q = first;
                Node *t = new Node;
                t->data = data;
                if(m == 1){
                    t->next = first;
                    first->prev = t;
                    t->prev = NULL;
                    first = t;
                }
                else if(m == n){
                    while(q->next != NULL){
                        q = q->next;
                    }
                    t->next = q->next;
                    q->next = t;
                    t->prev = q;
                }
                else{
                    while(m != 0){
                        q = q->next;
                        m--;
                    }
                    t->prev = q->prev;
                    q->prev->next = t;
                    t->next = q;
                    q->prev = t;
                }
                q = NULL;
                delete q;
                n++;
            }
            else
                //cout << "\nLista vazia.\n";
                add(data);
        }

        void add(int data){
            Node *t = new Node;
            t->data = data;
            t->next = t->prev = NULL;
            if(first == NULL){
                first = t;
                n++;
                return;
            }
            else if(first->next == NULL){
                first->next = t;
                t->prev = first;
                n++;
                return;
            }
            else{
                Node *q = first;
                while(q->next != NULL){
                    q = q->next;
                }
                t->prev = q;
                q->next = t;
                q = NULL;
                delete q;
                n++;
                return;
            }
        }

        void show(){
            if(!isEmpty()){
                Node *q = first;
                while(q != NULL){
                    cout << q->data << " -> ";
                    q = q->next;
                }
                delete q;
            }
            else
                cout << "\nLista vazia.\n";
        }

    protected:

    private:
        int n;
        Node *first;
};

#endif // LINKEDLIST_H
