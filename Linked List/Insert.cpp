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

void Insert_at_first(int n){
    Node * t = new Node;
    t->data = n;
    t->next = first;
    first = t;
}
void Insert_at_any_position(int pos , int n){
    Node * p = first;
    Node * t = new Node;
    t->data = n;
    for (int i = 0; i < pos-1; i++)
    {
        p = p->next;
    }
    t->next = p->next;
    p->next = t;
}

void Insert(int pos , int n){
    Node * p = first;
    Node * t = new Node;
    t->data = n;
    if (pos == 0)
    {
        t->data = n;
        t->next = first;
        first = t;
    }

    else if(pos>0){
        for (int i = 0; i < pos-1; i++)
        {
            p = p->next;
        }
        if (p)
        {
            t->next = p->next;
            p->next = t;
        }
        
        

    }
    
}

int main(){
    int A[] = {2,3,4,5,6};
    create(A,5);
    // Insert_at_first(1);
    Insert(5,7);
    display(first);
    return 0;
}