#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
} *first = NULL;

void create(int A[], int n)
{
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = first;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;

        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
void display(struct Node *p)
{
    do
    {
        cout << p->data << endl;
        p = p->next;
    } while (p != first);
}

void Insert(int pos, int n, Node *p)
{

    Node *t = new Node;
    t->data = n;

    if (pos == 0)
    {
        while (true)
        {
            p = p->next;
            if (p->next == first)
            {
                break;
            }
        }
        p->next = t;
        t->next = first;
        first = t;
    }
    else if (pos > 0)
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
    else
    {
        cout << "Invalid index entered!!!";
    }
}

void Delete(Node *p, int index)
{
    if (index == 0)
    {
        Node *q = p;
        while (p->next != first)
        {
            p = p->next;
        }
        p->next = first->next;
        first = first->next;
        q->next = NULL;
        cout<<"data at first node was : "<<q->data<<endl<<"New LL is : "<<endl;
        delete q;
    }
    else if (index>0)
    {
        Node* q;
        for (int i = 0; i < index-2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        delete q;
        cout<<"New LL is : "<<endl;

        
    }
    
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    // Insert(5, 25, first);
    Delete(first, 3);
    display(first);
    return 0;
}