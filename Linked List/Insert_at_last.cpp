#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node * next;
}*first,*last = NULL;


void create(int A[], int n){
    Node *t; 
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
void Inser_at_last(int n){            // inserting always at last using last point so  as to ensure constant TC rather than TC of order of n
    Node * t = new Node;
    t->data = n;
    t->next = NULL;
    if (first ==NULL)
    {
        first = last = t;
    }
    else
    {
        last ->next = t;
        last = t;
    }
}
int main(){
    int A[] = {1,2,3,4,5};
    // create(A,5);
    Inser_at_last(1);
    Inser_at_last(2);
    Inser_at_last(3);
    Inser_at_last(4);
    Inser_at_last(5);
    display(first);
    return 0;
}