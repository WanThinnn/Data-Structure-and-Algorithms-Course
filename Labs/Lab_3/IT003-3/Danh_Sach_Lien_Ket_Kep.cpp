#include <stdio.h>
#include <iostream>

using namespace std;

typedef struct tagDNode
{
    int info;
    struct tagDNode *Pre;
    struct tagDNode *Next;
} DNode;

typedef struct tagDList
{
    DNode *Head;
    DNode *Tail;
} DList;

void CreateDList(DList &L)
{
    L.Head = L.Tail = NULL;
}

DNode *CreateDNode(int x)
{
    DNode *temp;
    temp = new DNode;
    if(temp == NULL)
    {
        cout << "Khong du bo nho";
        exit(1);
    }
    else
    {
        temp->info = x;
        temp->Next = NULL;
        temp->Pre = NULL;
        return temp;
    }
}

void AddHead(DList &L, DNode *p)
{
    if (L.Head == NULL)
    {
        L.Head = p;
        L.Tail = L.Head;
    }
    else
    {
        p->Next = L.Head;
        L.Head->Pre = p;
        L.Head = p;
    }
}

void AddTail(DList &L, DNode *p)
{
    if (L.Head == NULL)
    {
        L.Head = p;
        L.Tail = L.Head;
    }
    else
    {
        p->Pre = L.Tail;
        L.Tail->Next = p;
        L.Tail = p;
        
    }
}

void AddLastQ(DList &l,DNode *temp, DNode *q)
{
    DNode *p;
    p = q->Next;
    if (q != NULL)
    {
        temp->Next = p;
        temp->Pre = q;
        q->Next = temp;
        if(p != NULL)
            p->Pre = temp;
        
        if (q == l.Tail) //them vao sau danh sach lien ket.
            l.Tail = temp;
    }
    else
    {
        AddHead(l,temp);
    }
}

void AddBeforeQ(DList &l,DNode *tam,DNode *q)
{
    DNode *p;
    p = q->Pre;
    if(q != NULL)
    {
        tam->Next = q;
        tam->Pre = p;
        q->Pre = tam;
        if (p != NULL)
            p->Next = tam;
        if (q == l.Head)
            l.Head = tam;
    }
    else
    {
        AddTail(l,tam);
    }
}

void DeleteHead(DList &l)
{
    DNode *p;
    if (l.Head != NULL)
    {
        p = l.Head;
        l.Head = l.Head->Next;
        l.Head->Pre = NULL;
        delete p;
        if (l.Head == NULL)
            l.Tail = NULL;
    }
}

void DeleteTail(DList &l)
{
    DNode *p;
    if(l.Head != NULL)
    {
        p = l.Tail;
        l.Tail = l.Tail->Pre;
        l.Tail->Next = NULL;
        delete p;
        if(l.Tail == NULL)
            l.Head = NULL;
    }
}

void DeleteAfterQ(DList &l, DNode *q)
{
    DNode *p;
    if (q != NULL)
    {
        p = q->Next;
        if (p != NULL)
        {
            q->Next = p->Next;
            if (p == l.Tail)
                l.Tail = q;
            else
                p->Next->Pre = q->Next;
        }
    }
    else
        DeleteHead(l);
}

void DeleteBeforeQ(DList &l, DNode *q)
{
    DNode *p;
    if(q != NULL)
    {
        p = q->Pre;
        if(p != NULL)
        {
            q->Pre = p->Pre;
            if (p == l.Head)
                l.Head = q;
            else
                p->Pre->Next = q;
            delete p;
        }
    }
    else
        DeleteTail(l);
}

int DeleteX(DList &l, int x)
{
    DNode *p; DNode *q;
    q = NULL;
    p = l.Head;
    while(p != NULL)
    {
        if (p->info == x)
            break;
        q = p;
        p = p->Next;
    }
    if (q == NULL)
        return 0;
    if (q != NULL)
        DeleteAfterQ(l,q);
    else
        DeleteHead(l);
    return 1;
}

void swap(DNode *&p, DNode *&q)
{
    int temp;
    temp = p->info;
    p->info = q->info;
    q->info = temp;
}

void InterchangeSort(DList &l)
{
    DNode *p, *q;
    p = l.Head;
    while (p != l.Tail)
    {
        q = p->Next;
        while (q != NULL)
        {
            if (p->info > q->info)
                swap(p,q);
            q = q->Next;
        }
        p = p->Next;
    }
}


void InputList(DList &l)
{
    int x, n;
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        AddTail(l, CreateDNode(x));
    }
}


void PrintList(DList l)
{
    DNode *p = l.Head;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->Next;
    }
}

int main()
{
    DList L;
    CreateDList(L);
    InputList(L);
    PrintList(L);
}
/*
Giai thuat cong 2 so cuc lon:
DNode *p = L1.Tail;
DNode *q = L2.Tail;
temp = 0;
while (p != NULL and q != NULL)
 {
    kq = p->info + q->info + temp;
    AddHead(L3, kq%10);
    temp = kq/10;
    p=p->Pre;
    q = q->Pre;
 }
 
 while (p != NULL)
 {
    kq = p->info + temp;
    AddHead(L3, kq%10);
    temp = kq/10;
    p=p->Pre;
 }
 
 while (q != NULL)
 {
    kq = q->info + temp;
    AddHead(L3, kq%10);
    temp = kq/10;
    q=q->Pre;
 }
 
*/
