#include <iostream>
#include <string>
using namespace std;

struct SinhVien
{
    int MSSV;
    string HT;
};

struct Node
{
    SinhVien SV;
    Node* Next;
};

struct List
{
    Node* Head;
    Node* Tail;
};

void CreateList(List& l)
{
    l.Head = NULL;
    l.Tail = NULL;
}

void AddNode(List& l, SinhVien sv)
{
    Node* newNode = new Node;
    newNode->SV = sv;
    newNode->Next = NULL;

    if (l.Head == NULL)
    {
        l.Head = newNode;
        l.Tail = newNode;
    }
    else
    {
        l.Tail->Next = newNode;
        l.Tail = newNode;
    }
}

void InputList(List& l)
{
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        SinhVien sv;
        cout << "MSSV: ";
        cin >> sv.MSSV;
        cin.ignore();
        cout << "Ho va Ten: ";
        getline(cin, sv.HT);
        AddNode(l, sv);
    }
}

void Swap(int &p, int &q)
{
    int t = p;
    p = q;
    q = t;
}

void Swap(string &p, string &q)
{
    string t = p;
    p = q;
    q = t;
}

void swap(Node *&p, Node *&q)
{
    int temp;
    temp = p->SV.MSSV;
    p->SV.MSSV = q->SV.MSSV;
    q->SV.MSSV = temp;
}
void SelectionSort(List& L)
{
    Node* p;
    Node* q;
    Node* min;

    for (p = L.Head; p != NULL; p = p->Next)
    {
        min = p;
        for (q = p->Next; q != NULL; q = q->Next)
        {
            if (q->SV.MSSV < min->SV.MSSV)
                min = q;
        }
        swap(min, p);
//        Swap(min->SV.HT, p->SV.HT);

    }
}



void PrintList(List L)
{
    Node* p = L.Head;
    while (p != NULL)
    {
        cout << "MSSV: " << p->SV.MSSV << endl;
        cout << "Ho va Ten: " << p->SV.HT << endl;
        p = p->Next;
    }
}

int main()
{
    List L;
//    CreateList(L);
    InputList(L);

    cout << endl;

//    SelectionSort(L);

    cout << "THONG TIN SINH VIEN\n";
    PrintList(L);

    return 0;
}
