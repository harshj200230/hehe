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
int Delete(int pos){
    Node *p,*q;
    p = first;
    q = NULL;
    int x;
    if (pos == 1)
    {
        first = first->next;
         x = p->data;
        delete p;
    }
    else{
        for (int i = 0; i < pos-1; i++)
        {
            q = p;
            p = p->next;
        }
        if (p)
        {
            q ->next = p->next;
             x = p->data;
            delete p;
        }
        
        
    }
    return x;
    

}

int main(){
    int A[] = {1,2,3,4,5};
    create(A,5);
    Delete(1);
    display(first);
    return 0;
}