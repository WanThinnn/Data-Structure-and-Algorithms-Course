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


int IsEmpty(List s)
{
    if (s.Head == NULL)
        return 1;//Stack rỗng return 1;
    else
        return 0;
}

int IsFull(List s)
{
    Node *p = s.Tail;
    if (p->Next == NULL)
        return  1;
    return 0;
}

void Push(List &s, Node *Tam)
{
    if(s.Head == NULL)
    {
        s.Head = Tam;
        s.Tail = s.Head;
    }
    else
    {
        Tam->Next = s.Head;
        s.Head = Tam;
    }
}

char Pop(List &s)
{
    Node *p;
    int trave;
    if (IsEmpty(s) != 1)
    {
        if (s.Head != NULL)
        {
            p = s.Head;
            trave = p->info;
            s.Head = s.Head->Next;
            if (s.Head == NULL)
                return 1;
            delete p;
        }
    }
    return 0;
}

void InputStack(List &L)
{
    int n;
    string N;
    cin >> n;
    N = to_string(n);
    for (int i = 0; i < N.length(); i++)
    {
        Push(L, CreateNode(N[i]));
    }
}

string ReV(List l)
{
    Node* p;
    p = l.Head;
    string kq = "";
    while (p != NULL)
    {
        kq = kq + char(p->info);
        p = p->Next;
    }
    return kq;
}

int main()
{
    List L;
    CreateList(L);
    InputStack(L);
    cout << ReV(L);
}
