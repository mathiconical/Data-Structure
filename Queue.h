#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Queue
{
    public:
        Queue() : n(0) { first = NULL; }
        virtual ~Queue() { while(!isEmpty())    qDeque(); }

        void show(){
            if(!isEmpty()){
                Node *q = first;
                while(q != NULL){
                    cout << q->data << " ";
                    q = q->next;
                }
                cout << '\n';
                delete q;
            }
            else
                cout << "\nFila vazia.\n";
        }

        bool isEmpty(){
            return n == 0;
        }

        void qDeque(){
            if(!isEmpty()){
                Node *q = first;
                first = first->next;
                delete q;
                n--;
            }
            else
                cout << "\nFila vazia.\n";
        }

        void enqueue(int data){
            Node *t = new Node;
            t->data = data;
            t->next = NULL;
            if(first == NULL){
                first = t;
                n++;
                return;
            }
            else if(first->next == NULL){
                first->next = t;
                n++;
                return;
            }
            else{
                Node *q = first;
                while(q->next != NULL)
                    q = q->next;
                q->next = t;
                q = NULL;
                delete q;
                n++;
            }
        }

    protected:

    private:
        int n;
        Node *first;
};

#endif // QUEUE_H
