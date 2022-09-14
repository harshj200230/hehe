#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node * next;
}*first = NULL;


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

void display(struct Node * p){
    while (p!=NULL)
    {
        cout<<p->data<<endl;
        p = p->next;

    }
    
}
void Reversing_elements(Node * p){
    int * arr = new int[5];
    int *move = arr;
    while (p!=NULL)
    {
        *move = p->data ;
        p = p->next;
        move++;
    }
        cout<<"array obtained is : "<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<*(arr+i)<<endl;
    }
    cout<<"***********************"<<endl;
    p = first;
    for (int i = 4; i >= 0; i--)
    {
        p->data = arr[i];
        p = p->next;
    }
    
    
}
void Reversing_links(Node * p){
    Node * q = NULL;
    Node * r = NULL;
    while (p!=NULL)
    {
        r= q;
        q = p;
        p = p->next;
        q->next = r;
        
    }
    first = q;
    
}

int main(){
    int A[] = {1,2,3,4,5};
    create(A,5);
    Reversing_links(first);
    display(first);
    return 0;
}