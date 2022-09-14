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
int is_Loop(Node * f){
    Node *p,*q;
     p = q = f;
     do
     {
        p = p->next;
        q = q->next;
        q = q!=NULL?q->next:q;
     } while (p&&q&&p!=q);

     if (p==q)
     {
        return 1;
     }
     else
     {
        return 0;
     }
     
     
     
}
int main(){
    int A[] = {1,2,3,4,5};
    Node *t1,*t2;
    create(A,5);
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;
    cout<<is_Loop(first);
    // display(first);
    return 0;
}