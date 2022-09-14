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

Node * Search(Node * p , int n){
    while (p!=NULL)
    {
        if(p->data == n){
            cout<<"Element found !! at address "<<p;
            return p;
        }
        p = p->next;
    }
    
}
Node * Search_Better(Node * p , int n){
    Node * q = NULL;
    while (p!=NULL)
    {
        if (n ==p->data)
        {
            q ->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
        
    }
    
}
void display(struct Node * p){
    while (p!=NULL)
    {
        cout<<p->data<<endl;
        p = p->next;

    }
    
}

int main(){
    int A[] = {1,2,3,4,5};
    create(A,5);
    Search_Better(first,4);
    display(first);
    return 0;
}