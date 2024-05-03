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


void PrintList(List l)
{
    Node *p = l.Head;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->Next;
    }
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

void InsertAfter(List &l, int x, int k)
{
    Node *p = CreateNode(x);
    Node *q = l.Head;
    while (q != NULL)
    {
        if (q->info == k)
        {
            p->Next = q->Next;
            q->Next = p;
            break;
        }
        else
            q = q->Next;
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



void Solve(List L, List &EvenList, List &OddList)
{
    Node *p = L.Head;
    Node *evenTail = NULL;
    Node *oddTail = NULL;
    
    while (p != NULL)
    {
        if (p->info % 2 == 0)
        {
            if (EvenList.Head == NULL)
            {
                EvenList.Head = p;
                evenTail = p;
            }
            else
            {
                evenTail->Next = p;
                evenTail = p;
            }
        }
        else
        {
            if (OddList.Head == NULL)
            {
                OddList.Head = p;
                oddTail = p;
            }
            else
            {
                oddTail->Next = p;
                oddTail = p;
            }
        }
        p = p->Next;
    }
    
    if (evenTail != NULL)
        evenTail->Next = NULL;

    if (oddTail != NULL)
        oddTail->Next = NULL;
}

int main()
{
    List L, EvenList, OddList;
    CreateList(L);
    CreateList(EvenList);
    CreateList(OddList);
    InputList(L);
    Solve(L, EvenList, OddList);
    PrintList(EvenList);
    cout << endl;
    PrintList(OddList);
}



