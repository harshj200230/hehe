#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node * next;
}*first = NULL, *second =NULL, *third = NULL;


void create(int A[], int n){
    Node *t, *last; 
    first = new Node;
    first->data = A[0]; 
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t= new Node;
        
        t->data = A[i];
        t->next = NULL;
        last ->next = t;
        last = t;
    }
}
void create2(int A[], int n){
    Node *t, *last; 
    second = new Node;
    second->data = A[0]; 
    second->next = NULL;
    last = second;

    for (int i = 1; i < n; i++)
    {
        t= new Node;
        
        t->data = A[i];
        t->next = NULL;
        last ->next = t;
        last = t;
    }
}

void display(struct Node * p){
    while (p!=NULL)
    {
        cout<<p->data<<endl;
        p = p->next;

    }
    
}

void Concat(Node* p ,Node*q){
    third = p;
    while (p->next!=NULL)
    {
        p = p->next;
    }
    p->next = q;
    
}

void Merge(Node* p , Node*q){
    Node * last = NULL;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else if (q->data < p->data)
    {
        third = q;
        q = q->next;
        third ->next = NULL;
    }
    while (p &&q)
    {
        if (p->data < q->data)
    {
        last->next = p;
        last = p;
        p = p->next;
        last->next = NULL;

    }
    else
    {
        last ->next = q;
        last = q; 
        q= q->next;
        last->next = NULL;
    }
    
    }
    if (p)
    {
        last->next = p;
    }
    if (q)
    {
        last -> next = q;
    }
}

int main(){
    int A[] = {1,5,8,13,33};
    int B[] = {2,9,15,17,77};
    create(A,5);
    create2(B,5);
    // Concat(first,second);
    // display(third);
    Merge(first,second);    
    display(third);
    // display(first);
    // display(second);
    return 0;
}