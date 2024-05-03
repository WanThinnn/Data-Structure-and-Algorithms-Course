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


void InputList(List &l, int &n)
{
    int x;
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

void Solve(List LA, List &LB, List &LC, int n)
{
    Node *p = LA.Head;
    CreateList(LB);
    CreateList(LC);
    int i = 1;
    while (p != NULL)
    {
        if (n % 2 == 0)
        {
            Node *q = CreateNode(p->info);
            if (i <= n/2)
                AddTail(LB, q);
            else if (i > n/2)
                AddTail(LC, q);
        }
        else if (n % 2 == 1)
        {
            Node *q = CreateNode(p->info);
            if (i <= n/2 + 1)
                AddTail(LB, q);
            else if (i > n/2 + 1)
                AddTail(LC, q);
        }
        p = p->Next;
        i++;
            
    }
}



int main()
{
    List LA, LB, LC;
    int n;
    CreateList(LA); CreateList(LB); CreateList(LC);
    InputList(LA, n);
    Solve(LA, LB, LC, n);
    PrintList(LB);
    cout << endl;
    PrintList(LC);
}

