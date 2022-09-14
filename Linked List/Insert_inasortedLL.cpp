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
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;

        t->data = A[i];
        t->next = NULL; 
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}
// void Insort(int n)
// {

//     Node *p, *q, *t;
//     p = first;
//     q = NULL;

//     t->data = n;
//     t->next = NULL;

//     while (p && p->data < n)
//     {
//         q = p;
//         p = p->next;
//     }

//     t->next = q->next;
//     q->next = t;
// }
void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;

    t = new Node;
    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = p;
            q->next = t;
        }
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 6};
    create(A, 5);
    SortedInsert(first,7);
    display(first);
    return 0;
}