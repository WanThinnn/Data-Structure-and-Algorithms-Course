#include <iostream>

using namespace std;

typedef struct tagNode
{
    int data;
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
    p->data = x;
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

bool IsEmpty(List l)
{
    return l.Head == NULL;
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
void PrintList(List l)
{
    Node *p = l.Head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->Next;
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
        if (p->data > X->data)
            AddTail(L1, p);
        else
            AddTail(L2, p);
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


void InputList(List &l)
{
    int x;
    do
    {
        cin >> x;
        if (x == -1)
            break;
        AddTail(l, CreateNode(x));
    }
    while (x != -1);
}


void TinhToan(List l)
{
    int S = 0, i = 0;
    int Min = l.Tail->data, Max = l.Head->data;
    float Avg = 0.0;
    Node* p = l.Head;
    if (IsEmpty(l) == true)
    {
        cout << "- The list is empty!\n";
        S = 0; Min = 0; Max = 0; Avg = 0.0;
    }
    else
    {
        while (p != NULL)
        {
            S = S + p->data;
            if (p->data > Max)
                Max = p->data;
            if (p->data < Min)
                Min = p->data;
            i++;
            p = p->Next;
        }
        Avg = float(S/i);
    }
    cout << "- Tong cac phan tu trong danh sach: " << S << endl;
    cout << "- Phan tu lon nhat trong danh sach: " << Max << endl;
    cout << "- Phan tu nho nhat trong danh sach: " << Min << endl;
    cout << "- Gia tri trung binh cac phan tu trong danh sach: " << Avg << endl;
}


int main()
{
    List L;
    CreateList(L);
    InputList(L);
    TinhToan(L);
    cout << "- List: ";
    QuickSort(L);
    PrintList(L);
    
}

