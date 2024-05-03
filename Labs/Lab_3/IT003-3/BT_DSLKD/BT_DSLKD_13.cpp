#include <iostream>
using namespace std;

typedef struct tagNode
{
    int info;
    struct tagNode* pNext;
}Node;

typedef struct tagList
{
    Node* pHead;
    Node* pTail;
}LIST;

void CreateList(LIST& l)
{
    l.pHead = l.pTail = NULL;
}

Node* CreateNode(int x)
{
    Node* p = new Node;
    p->info = x;
    p->pNext = NULL;
    return p;
}

void AddHead(LIST& l, Node* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = NULL;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void AddTail(LIST& l, Node* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void PrintList(LIST l)
{
    Node* p;
    p = l.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }

}

void InsertAfter(LIST &l, Node *p, Node *q)
{
    if (q != NULL)
    {
        p->pNext = q->pNext;
        q->pNext=p;
        if (l.pTail == q)
            l.pTail = q;
    }
    else AddHead(l, q);
}




void QuickSort(LIST &l)
{
    Node *p;
    Node *X;
    LIST L1;
    LIST L2;
    if (l.pHead == l.pTail)
        return;
    else
    {
        CreateList(L1);
        CreateList(L2);
        X = l.pHead;
        l.pHead = X->pNext;
        while (l.pHead != NULL)
        {
            p = l.pHead;
            l.pHead = p->pNext;
            p->pNext = NULL;
            if (p->info <= X->info)
                AddHead(L1, p);
            else
                AddHead(L2, p);
        }
        QuickSort(L1);
        QuickSort(L2);
        if (l.pHead != NULL)
        {
            l.pHead = L1.pHead;
            L1.pTail->pNext = X;
        }
        else
            l.pHead = X;
        X->pNext = L2.pHead;
        if (L2.pHead != NULL)
            l.pTail = L2.pTail;
        else
            l.pTail = X;
    }
}
//void SelectionSort(LIST &A)
//{
//    Node *qmin, *i, *j, *h;
//    h = NULL;
//    i = A.pHead;
//    while (i->pNext)
//    {
//        qmin = h; j = i;
//        while (j->pNext)
//        {
//            if (j->pNext->info < i->info)
//            {
//                qmin = j; i = qmin->pNext;
//            }
//            j = j->pNext;
//            int t;
//            RemoveAfter(A,qmin,t);
//            addAfter(A, CreateNode(t), h);
//            if (!h)
//                h = A.pHead;
//            else
//                h = h->pNext;
//            i = h->pNext;
//        }
//    }
//}

void InsertwithASC(LIST &l, int chen)
{
    if (chen <= l.pHead->info)
    {
        AddHead(l, CreateNode(chen));
        return;
    }
    Node *p = l.pHead;
    Node *q = NULL;
    while (p->info <= chen)
    {
        q = p;
        p = p->pNext;
    }
    if (p == NULL)
    {
        AddTail(l, CreateNode(chen));
    }
    else
    {
        Node *t = CreateNode(chen);
        t->pNext = p;
        q->pNext = t;
    }
}

int main()
{
    int n;
    int count = 0;
    LIST l;
    CreateList(l);
    cout << "Nhap dsach:\n";
    do
    {
        cin >> n;
        if (n == 0)
            break;
        count++;
        AddTail(l, CreateNode(n));
    }
    while (n != 0);
    int k;
    cin >> k;
    InsertwithASC(l, k);
    PrintList(l);
   
}
