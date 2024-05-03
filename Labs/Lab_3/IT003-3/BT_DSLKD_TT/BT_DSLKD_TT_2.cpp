#include <stdio.h>
#include <iostream>

using namespace std;

typedef struct tagNode
{
    int info;
    struct tagNode *Next;
} Node;

typedef struct tagList
{
    Node *Head;
    Node *Tail;
} List;

void CreateList(List &l)
{
    l.Head = l.Tail = NULL;
}

Node *CreateNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->Next = NULL;
    return p;
}

void AddHead(List &l, Node *p)
{
    if (l.Head == NULL)
    {
        l.Head = p;
        l.Tail = NULL;
    }
    else
    {
        p->Next = l.Head;
        l.Head = p;
    }
}


void AddTail(List &l, Node *p)
{
    if (l.Head == NULL)
    {
        l.Head = p;
        l.Tail = l.Head;
    }
    else
    {
        l.Tail->Next = p;
        l.Tail = p;
    }
}


void InputList(List &l, int &n)
{
    CreateList(l);
    int x;
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        AddTail(l, CreateNode(x));
    }
}

void QuickSort(List &L)
{
    Node *p, *X;
    List L1, L2;
    
    if (L.Head == L.Tail)
        return;
    
    CreateList(L1);
    CreateList(L2);
    
    X = L.Head;
    L.Head = X->Next;
    
    while (L.Head != NULL)
    {
        p = L.Head;
        L.Head = p->Next;
        p->Next = NULL;
        if (p->info <= X->info)
            AddHead(L1, p);
        else
            AddHead(L2, p);
    }
    
    QuickSort(L1);
    QuickSort(L2);
    
    if (L1.Head != NULL)
    {
        L.Head = L1.Head;
        L1.Tail->Next = X;
    }
    else
        L.Head = X;
    
    X->Next = L2.Head;
    
    if (L2.Head != NULL)
        L.Tail = L2.Tail;
    else
        L.Tail = X;
}

void PrintList(List &l)
{
    Node *p = l.Head;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->Next;
    }
}

int main()
{
    List L;
    int n;
    InputList(L, n);
    QuickSort(L);
    PrintList(L);
}
