#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

string Name_of_DT[] = {"F(x)" , "G(x)"};
int ind = 0;

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


void InputList(List &L)
{
    CreateList(L);
    int x, n;
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        AddTail(L, CreateNode(x));
    }
}


void PrintList(List l)
{
    Node *p;
    p = l.Head;
    
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->Next;
    }
    cout << endl;
}


void RemoveHead(List &l)
{
    Node* p;

    if (l.Head != NULL)
    {
        p = l.Head;
        l.Head = l.Head->Next;
        delete p;
        if (l.Head == NULL)
            l.Tail = NULL;
    }
}

void RemoveTail(List l)
{
    Node* p = l.Head;
    Node* q = p;

    while (p->Next != NULL)
    {
        q = p;
        p = p->Next;
    }

    q->Next = NULL;
    l.Tail = q;
}

void DeleteList(List &l)
{
    Node* p;
    while (l.Head != NULL)
    {
        p = l.Head;
        l.Head = p->Next;
        delete p;
    }
    l.Tail = NULL;
}


void Shuffle (List &L)
{
    List L1, L2;
    CreateList(L1);
    CreateList(L2);
    int x, y;
    Node *p = L.Head;
    while (p != NULL and p->Next != NULL)
    {
        x = p->info;
        y = p->Next->info;
        AddTail(L1, CreateNode(x));
        AddTail(L2, CreateNode(y));
        p = p->Next->Next;
        if (p == L.Tail)
            AddTail(L1, L.Tail);
    }
    L2.Tail->Next = L1.Head;
    L.Head = L2.Head;
}

int main()
{
    List L, L1, L2;
    InputList(L);
    Shuffle(L);
    PrintList(L);

}
