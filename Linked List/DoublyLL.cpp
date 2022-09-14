#include <iostream>
using namespace std;

struct Node
{
    Node *prev, *next;
    int data;
} *first = NULL;

void Create(int A[], int n)
{
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        last->next = t;
        t->prev = last;
        last = t;
        last->next = NULL;
    }
}
void Display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

int Length(Node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

void Insert(Node *p, int pos, int n)
{
    Node *t = new Node;
    t->data = n;
    if (pos == 0)
    {
        t->next = first;
        t->prev = NULL;
        first->prev = t;
        first = t;
    }
    if (pos > 0)
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;
        if (p->next)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}

void Delete(Node *p, int index)
{
    if (index == 1)
    {
        first->next->prev = NULL;
        p = first->next;
        delete first;
        first = p;
    }
    else if (index > 0)
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }

        p->prev->next = p->next;
        if (p->next)
        {
            p->next->prev = p->prev;
        }
        delete p;
    }
}

void Reverse(Node *p)
{
    while (p != NULL)
    {

        Node *temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
        {
            first = p;
        }
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    Create(A, 5);
    // Insert(first, 5 , 10);
    // Delete(first , 5);
    Reverse(first);
    Display(first);
    // cout<<"Length of the Doubly LL is : "<<Length(first);
    return 0;
}