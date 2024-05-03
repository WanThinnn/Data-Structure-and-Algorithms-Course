#include <iostream>
using namespace std;

typedef struct tagNode
{
    int info;
    struct tagNode *Next;
} Node;

typedef struct tagStack
{
    Node *Top;
} Stack;

void CreateStack (Stack &s)
{
    s.Top = NULL;
}

Node* CreateNode(int x)
{
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    else
    {
        p->info = x;
        p->Next = NULL;
    }
    return p;
}


int IsEmpty(Stack s)
{
    if (s.Top == NULL)
        return 1;//Stack rỗng return 1;
    else
        return 0;
}


void Push(Stack &s, Node *Tam)
{
    if(s.Top == NULL)
        s.Top = Tam;
    else
    {
        Tam->Next = s.Top;
        s.Top = Tam;
    }
}

int Pop(Stack &s)
{
    Node *p;
    int trave;
    if (IsEmpty(s) == true)
    {
        return -1;
    }
    else
    {
        p = s.Top;
        trave = p->info;
        s.Top = s.Top->Next;
        if (s.Top == NULL)
        delete p;
    }
    return 1;
}

void PrintStack(Stack s)
{
    Node* p =s.Top;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->Next;
    }
}

int Top(Stack s)
{
    if (s.Top != NULL)
        return s.Top->info;
    return -1;
}


int main()
{
    Stack S;
    CreateStack(S);
    Push(S, CreateNode(1));
    Push(S, CreateNode(3));
    Push(S, CreateNode(7));
    Push(S, CreateNode(10));
    PrintStack(S);
    cout << endl;
    cout << Pop(S) << endl;
    cout << Top(S) << endl;
    PrintStack(S);

    
}
