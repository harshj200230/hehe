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

int count(struct Node * p){
    int c = 0;
    while (p!= 0)
    {
        int count = 0;
        c++;
        p = p->next;
        
    }
    return c;
    
} 

int countR(struct Node *p){
    if (p==NULL)
    {
        return 0;
    }

    return 1+countR(p->next);
    
}

int main(){
    int A[] = {1,2,3,4,5};
    create(A,5);
    cout<<countR(first);
    return 0;
}