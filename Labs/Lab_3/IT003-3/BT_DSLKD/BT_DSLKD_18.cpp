#include <iostream>

using namespace std;

struct SinhVien
{
    int MSSV;
    string Ten, Lop, HKiem;
    float dtb;
};

typedef struct tagNode
{
    SinhVien x;
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

Node *CreateNode (SinhVien SV)
{
    Node *p;
    p = new Node;
    if (p == NULL)
        exit(1);
    p->x = SV;
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


void RemoveHead(List &l)
{
    Node *p;

    if (l.Head != NULL)
    {
        p = l.Head;
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

void FindX(List L)
{
    Node *p = L.Head;
    while (p != NULL)
    {
        if (p->x.Lop == "IT003.N27")
        {
            cout << "Thong Tin Sinh Vien: ";
            cout << p->x.MSSV << "  " << p->x.Ten << "  " << p->x.Lop << "  " << p->x.HKiem << "  " << p->x.dtb;
            cout << endl;
            p = p->Next;
        }
        else
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
        if (p->x.MSSV <= X->x.MSSV)
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
    SinhVien x;
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x.MSSV;
        cin.ignore();
        getline(cin, x.Ten);
        getline(cin, x.Lop);
        getline(cin, x.HKiem);
        cin >> x.dtb;
        AddTail(l, CreateNode(x));
    }
}

void PrintList(List l)
{
    Node *p = l.Head;
    while (p != NULL)
    {
        cout << "Thong Tin Sinh Vien: ";
        cout << p->x.MSSV << "  " << p->x.Ten << "  " << p->x.Lop << "  " << p->x.HKiem << "  " << p->x.dtb;
        p = p->Next;
        cout << endl;
    }
    
}

int main()
{
    List L;
    int n;
    SinhVien SV;
    CreateList(L);
    InputList(L, n);
    
    cout << "DANH SACH SINH VIEN:" << endl;
    PrintList(L);
    cout << endl;
    
    cout << "SINH VIEN THUOC LOP IT003.N27:" << endl;
    FindX(L);
    cout << endl;
    
    cout << "SAP XEP SANH SACH THEO MSSV TANG DAN:" << endl;
    QuickSort(L);
    PrintList(L);
    cout << endl;
    
    cout << "XOA SINH VIEN CUOI CUNG RA KHOI DANH SACH:" << endl;
    RemoveTail(L);
    PrintList(L);
    cout << endl;
    
    
    
}

/*
 n = 5
 003
 Nguyen Van An
 IT003.N27
 Tot
 9.2
 001
 Nguyen Phuc Thuy Tien
 IT003.N27
 Tot
 9.2
 002
 Lai Quan Thien
 IT003.N17
 Tot
 9.12
 007
 O Lap Na Lap Nhu Y
 IT003.N27
 Tot
 7.8
 006
 Nuu Ho Loc Chan Hoan
 IT003.N272
 Tot
 9.5
 */


