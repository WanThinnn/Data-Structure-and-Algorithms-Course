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


int FindX(List l, int x)
{
    Node *p = l.Head;
    while (p != NULL)
    {
        if (p->info == x)
            return 1;
        else
            p = p->Next;
    }
    return 0;
}

void RemoveHead(List &l)
{
    Node *p = l.Head;
    if (l.Head != NULL)
    {
        l.Head = l.Head->Next;
        delete p;
        if (l.Head == NULL)
            l.Tail = NULL;
    }
}

void RemoveTail(List &l)
{
    Node *p = l.Head;
    Node *q = p;
    while (p->Next != NULL)
    {
        q = p;
        p = p->Next;
    }
    q->Next = NULL;
    l.Tail = q;
}

void RemoveAfter(List &l, int k)
{
    Node *p = nullptr;
    Node *q = l.Head;
    if (FindX(l, k) == true)
    {
        while (q != NULL)
        {
            if (q->info == k)
            {
                p = q->Next;
                if (p != NULL)
                {
                    if (p == l.Tail)
                        l.Tail = q;
                    q->Next = p->Next;
                    delete p;
                }
                break;
            }
            else
                q = q->Next;
        }
    }
    else
        cout << "Khong co phan tu " << k << " trong danh sach.";
        
}

void RemoveList(List &l)
{
    Node *p;
    while (l.Head != NULL)
    {
        p = l.Head;
        l.Head = p->Next;
        delete p;
    }
    cout << "Da xoa toan bo danh sach.\n";
}

void Add_X_To_K(List &l, int x, int k)
{
    Node *q = CreateNode(x);
    Node *p = l.Head;
    for (int i = 0; i < k-1; i++)
    {
        p = p->Next;
    }
    q->Next = p->Next;
    p->Next = q;
    
}

void RemoveNode(List &l, int x)
{
    Node *p = l.Head;
    Node *q = NULL;
    while (p != NULL)
    {
        if (p->info == x)
            break;
        q = p;
        p = p->Next;
    }
    
    if (p == NULL)
        cout << "Khong xoa duoc";
    
    if (q != NULL)
    {
        if (p == l.Tail)
            l.Tail = q;
        else
            q->Next = p->Next;
        delete p;
    }
    
    else
    {
        l.Head = p->Next;
        if (l.Head == NULL)
            l.Tail = NULL;
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


int main()
{
    int n, a, b, c, x, k;
    List L;
    CreateList(L);
    InputList(L, n);
//    cout << "a = "; cin >> a;
//    cout << "b = "; cin >> b;
    
//    if (FindX(L, b) == true)
//        InsertAfter(L, a, b);
//    RemoveHead(L);
//    PrintList(L);
//    cout << endl;
//
//    RemoveTail(L);
//    PrintList(L);
//    cout << endl;
//
//    RemoveAfter(L, a);
//    PrintList(L);
//    cout << endl;
//
//    cout << "x = "; cin >> x;
//    cout << "Vi tri k = "; cin >> k;
//    Add_X_To_K(L, x, k);
//    PrintList(L);
//    cin >> x;
//    RemoveNode(L, x);
//    PrintList(L);
//    RemoveList(L);
//    cout << endl;
    QuickSort(L);
    PrintList(L);
    
}

