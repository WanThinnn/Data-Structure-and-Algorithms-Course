#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

string Name_of_DT[] = {"F(x)" , "G(x)"};
int ind = 0;

typedef struct tagNode
{
    float bac, heso;
    struct tagNode *Next;
} Node;


typedef struct tagList
{
    Node *Head;
    Node *Tail;
} List;


void CreateList(List &l)
{
    l.Head = l.Tail = NULL;
}


Node *CreateNode(int x, int y)
{
    Node *p = new Node;
    p->heso = x;
    p->bac = y;
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

void InputList(List &L1, List &L2, float &xo, float &xn)
{
    CreateList(L1);
    CreateList(L2);
    float x;
    cout << "MinB = ";
    cin >> xo;
    cout << "MaxB = ";
    cin >> xn;
    cout << "Vui long nhap da thuc F(x) theo he so thu tu bac tu MinB -> MaxB:  " << endl;
    cout << "F(x) = ";
    for (int i = xo; i <= xn; i++)
    {
        cin >> x;
        AddTail(L1, CreateNode(x, i));
    }
    
    cout << "Vui long nhap da thuc G(x) theo he so thu tu bac tu MinB -> MaxB:  " << endl;
    cout << "G(x) = ";
    for (int i = xo; i <= xn; i++)
    {
        cin >> x;
        AddTail(L2, CreateNode(x, i));
    }
}

void SumOfDT(List L1, List L2, List &L3, float &xo, float &xn)
{
    Node *F = L1.Head;
    Node *G = L2.Head;
    CreateList(L3);
    float i = xo;

    while (F != NULL)
    {
        AddTail(L3, CreateNode(F->heso+G->heso, i));
        i++;
        F = F->Next;
        G = G->Next;
    }
        
    
}

void PrintList(List l)
{
    Node *p;
    p = l.Head;
    
    if (p == l.Head)
    {
        if (p->heso < 0)
        {
            if (p->bac == 0)
            {
                cout << "- " << abs(p->heso) << "";
                p = p->Next;
            }
            else
            {
                cout << "- " << abs(p->heso) << "x^" << p->bac;
                p = p->Next;
            }
        }
        
        else if (p->heso >= 0)
        {
            if (p->bac == 0)
            {
                cout << " " << abs(p->heso) << "";
                p = p->Next;
            }
            else
            {
                cout << " " << abs(p->heso) << "x^" << p->bac;
                p = p->Next;
            }
        }
    }
    
    while (p != NULL)
    {
        if (p->heso < 0)
        {
            if (p->bac == 0)
            {
                cout << " - " << abs(p->heso) << "";
                p = p->Next;
            }
            else
            {
                cout << " - " << abs(p->heso) << "x^" << p->bac;
                p = p->Next;
            }
                
        }
        else if (p->heso >= 0)
        {
            if (p->bac == 0)
            {
                cout << " + " << p->heso << "";
                p = p->Next;
            }
            else
            {
                cout << " + " << p->heso << "x^" << p->bac;
                p = p->Next;
            }
        }
    }
    cout << endl;
}

int main()
{
    List L1, L2, L3;
    float n, m;
    InputList(L1, L2, n, m);
    cout << "F(x) = ";
    PrintList(L1);
    cout << "G(x) = ";
    PrintList(L2);
    SumOfDT(L1, L2, L3, n, m);
    cout << "F(x) + G(x) = ";
    PrintList(L3);
}
