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
void display(struct Node *p){
    if(p!=NULL){
        display(p->next);
        cout<<p->data<<endl;
    }
}


int main(){
    int A[] = {1,2,3,4,5};
    create(A,5);
    display(first);

    return 0;
}