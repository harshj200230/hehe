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

int sum(struct Node * p){
    int s = 0;
    while (p!=0)
    {
        s = s + (p->data);
        p = p->next;
    }
    return s;
    
}
int sumR(struct Node *p){
    // int s = 0;
    if (p==NULL)
    {
        return 0;
    }
    return p->data + sumR(p->next);
    
    

    
}

int main(){
     int A[] = {1,2,3,4,5};
    create(A,5);
    cout<<"The sum is : "<<sumR(first);
    return 0;
}