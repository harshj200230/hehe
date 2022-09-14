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
    first->next = first;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t= new Node;
        
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
void display(struct Node * p){
    do
    {
        cout<<p->data;
        p= p->next;
    } while (p!=first);
    
}
void RDisplay(Node* p){
    static int flag = 0;
    if (p!=first || flag == 0)
    {
        flag = 1;
        cout<<p->data;
        p = p->next;
        RDisplay(p);
    }
    
}

int main(){
    int A[] = {1,2,3,4,5};
    create(A,5);
    display(first);
    // RDisplay(first);
    return 0;
}