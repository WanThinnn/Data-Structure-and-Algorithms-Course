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



int main()
{
    List L, LA, LB;
    CreateList(L); CreateList(LA); CreateList(LB);
    InputList(LA);
    InputList(LB);
    LA.Tail->Next = LB.Head;
    PrintList(LA);
}
