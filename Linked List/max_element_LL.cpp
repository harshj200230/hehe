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

int maxElement(struct Node *p)
{
    int max = p->data;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}
int maxElementR(Node *p)
{
    int x = 0;

    if (p == 0)
        return INT32_MIN;
    x = maxElementR(p->next);
    if (x > p->data)
        return x;
    else
        return p->data;
}
int main()
{
    int A[] = {56, 332, 773463, 9568568, 10000};
    create(A, 5);
    cout << "The max element in the LL is : " << maxElementR(first) << endl;
    return 0;
}