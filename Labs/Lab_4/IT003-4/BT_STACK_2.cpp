#include <iostream>
using namespace std;

typedef struct tagNode
{
    char info;
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

Node *CreateNode (char x)
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
    char trave;
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

void InputStack(List &s)
{
    string ST;
    cin >> ST;
    for (int i = 0; i < ST.length(); i++)
    {
        Push(s, CreateNode(ST[i]));
    }
}

void ReV(List l)
{
    Node* p;
    p = l.Head;
    string st = "";
    while (p != NULL)
    {
        st = st + p->info;
        p = p->Next;
    }
    cout << st;
}

int main()
{
    List L;
    CreateList(L);
    InputStack(L);
    ReV(L);
}
