#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Stack
{
    public:
        Stack() : n(0) { top = NULL; }
        virtual ~Stack() { while(!isEmpty())    pop(); }

        bool isEmpty(){ return n == 0; }

        void push(int data){
            Node *t = new Node;
            t->data = data;
            t->next = NULL;
            if(top == NULL){
                top = t;
                n++;
                return;
            }
            t->next = top;
            top = t;
            n++;
        }

        void pop(){
            if(!isEmpty()){
                Node *q = top;
                top = top->next;
                //top->next = NULL;
                delete q;
                n--;
            }
            else{
                cout << "\nPilha vazia.\n";
            }
        }

        void show(){
            if(!isEmpty()){
                Node *q = top;
                while(q != NULL){
                    cout << q->data << " ";
                    q = q->next;
                }
                delete q;
                cout << '\n';
            }
            else
                cout << "\nPilha vazia.\n";
        }

        int atTop(){
            if(top != NULL)
                return top->data;
        }

        int sizeStack(){
            return n;
        }


    protected:

    private:
        int n;
        Node *top;
};

#endif // STACK_H
