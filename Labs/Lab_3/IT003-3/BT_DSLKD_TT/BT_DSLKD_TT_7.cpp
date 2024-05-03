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

void CreateList (List &l)
{
    l.Head = NULL;
    l.Tail = NULL;
}

Node *CreateNode (int x)
{
    Node *p;
    p = new Node;
    if (p == NULL)
        exit(1);
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


void InputList(List &l)
{
    int x, n;
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        AddTail(l, CreateNode(x));
    }
}

void PrintList(List l)
{
    Node *p = l.Head;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->Next;
    }
}
void RemoveHead(List &l)
{
    Node *p;

    if (l.Head != NULL)
    {
        p = l.Head;
        l.Head = l.Head->Next;
        delete p;
        if (l.Head == NULL)
            l.Tail = NULL;
    }
}

void MergerLists(List &L, List L1, List L2)
{
    Node *p = L.Head;
    Node *k1 = L1.Head;
    Node *k2 = L2.Head;
    
    while (k1 != NULL and k2 != NULL)
    {
        if (k1->info <= k2->info)
        {
            AddTail(L, k1);
            k1 = k1->Next;
        }
        else
        {
            AddTail(L, k2);
            k2 = k2->Next;
        }
    }
    
    while (k1 != NULL)
    {
        AddTail(L, k1);
        k1 = k1->Next;
    }
    
    while (k2 != NULL)
    {
        AddTail(L, k2);
        k2 = k2->Next;
    }
    
}

int main()
{
    List L1, L2, L3;
    CreateList(L1); CreateList(L2); CreateList(L3);
    InputList(L1);
    InputList(L2);
    MergerLists(L3, L1, L2);
    PrintList(L3);
}
