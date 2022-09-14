#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node * next;
}*first = NULL;


void Create(int A[], int n){
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

void Display(struct Node * p){
    while (p!=NULL)
    {
        cout<<p->data<<endl;
        p = p->next;

    }
    
}


int main(){
    int A[] = {1,2,3,4,5};
    Create(A,5);
    Display(first);
    // RDisplay(first);
    return 0;
}