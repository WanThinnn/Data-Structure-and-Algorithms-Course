#include <iostream>
#include <algorithm>

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

Node *CreateNode2 (char x)
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

int Pop(List &s)
{
    Node *p;
    int trave;
    if (IsEmpty(s) != true)
    {
        p = s.Head;
        trave = p->info;
        s.Head = s.Head->Next;
        delete p;
        return trave;
    }
    return 0;
}

void PrinTList(List l)
{
    Node* p;
    p = l.Head;
    while (p != NULL)
    {
        cout << p->info << "";
        p = p->Next;
    }
}

void DecToBi(int n)
{
    List L;
    CreateList(L);
    int N;
    string kq = "";
    while (n != 0)
    {
        N = n%2;
        Push(L, CreateNode(N));
        n = n/2;
    }
    PrinTList(L);
    cout << endl;
    while (IsEmpty(L) == false)
    {
        cout << Pop(L) << "";
    }
}

void DecToHex(List L, int n)
{
    int N;
    char t;
    string st = "";
    while (n != 0)
    {
        N = n%16;
        if (N >= 10 and N <= 15)
        {
            t = char(N+55);
            st = st + t;
        }
        else
            st = st + to_string(N);
        n = n/16;
    }
    reverse(st.begin(), st.end());
    cout << st;
}




int main()
{
    List L;
    int n;
    cin >> n;
    CreateList(L);
    DecToBi(n);
    cout << endl;
    DecToHex(L, n);
    cout << endl;
}
