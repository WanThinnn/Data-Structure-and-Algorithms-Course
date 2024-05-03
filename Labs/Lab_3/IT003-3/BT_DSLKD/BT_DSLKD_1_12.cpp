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
//    cout << endl;
//    cout << l.pHead << " ";
//    while (p != NULL)
//    {
//            cout << p->pNext << " ";
//            p = p->pNext;
//            if (p == NULL)
//                break;
//    }
//    cout << endl;
//
}

int FindValue(int a, LIST l)
{
    int temp = 999;
    Node* p;
    p = l.pHead;
    for (int i = 0; i <= a; i++)
    {
        temp = p->info;
        p = p->pNext;
    }
    return temp;
}

int FindX(int x, LIST l)
{
    Node *p = l.pHead;
    while (p != NULL and p->info != x)
        p = p->pNext;
    if (p != NULL)
        return 1;
    return 0;
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

void Add_x_behind_k(int x, int k, LIST& l)
{
    Node* q = CreateNode(x);
    Node* p;
    p = l.pHead;

    while (p != NULL)
    {
        if (p->info == k)
        {
            q->pNext = p->pNext;
            p->pNext = q;
            break;
        }
        else
            p = p->pNext;
    }
}

void Add_x_to_k_place(int x, int k, LIST& l)
{
    Node* q = CreateNode(x);
    Node* p;
    p = l.pHead;

    for (int i = 0; i < k - 1; i++)
    {
        p = p->pNext;
    }
    q->pNext = p->pNext;
    p->pNext = q;
}

LIST rev_L(LIST l)
{
    LIST rL;
    CreateList(rL);
    Node* p;
    p = l.pHead;

    while (p != NULL)
    {
        AddHead(rL, CreateNode(p->info));
        p = p->pNext;
    }
    return rL;
}


int RemoveNode(LIST& l, int x)
{
    Node* p = l.pHead;
    Node* q = NULL;
    while (p != NULL)
    {
        if (p->info == x)
            break;
        q = p;
        p = p->pNext;
    }
    if (p == NULL)
        return 0;
    if (q != NULL)
    {
        if (p == l.pTail)
            l.pTail = q;
        q->pNext = p->pNext;
        delete p;
    }
    else
    {
        l.pHead = p->pNext;
        if (l.pHead == NULL)
            l.pTail = NULL;
    }
    return 1;
}

int RemoveHead(LIST &l)
{
    Node *p; int x;
    if (l.pHead != NULL)
    {
        p = l.pHead;
        x = p->info;
        l.pHead = l.pHead->pNext;
        delete p;
        if (l.pHead == NULL)
            l.pTail = NULL;
        return 1;
    }
    return 0;
}

void RemoveTail(LIST l)
{
    Node* p = l.pHead;
    Node* q = p;

    while (p->pNext != NULL)
    {
        q = p;
        p = p->pNext;
    }

    q->pNext = NULL;
    l.pTail = q;
}

void RemoveList(LIST& l)
{
    Node* p;

    while (l.pHead != NULL)
    {
        p = l.pHead;
        l.pHead = p->pNext;
        delete p;
    }
    l.pTail = NULL;
    cout << "\n- Da xoa toan bo danh sach.";
}

int main()
{
    int n;
    int count = 0;
    LIST l;
    CreateList(l);
    
    //Bai 1
    cout << "Bai 1. Nhap dsach:\n";
    do
    {
        cin >> n;
        if (n == 0)
            break;
        count++;
        AddTail(l, CreateNode(n));
    }
    while (n != 0);
    //Bai 2
    cout << "Bai 2. Danh Sach Vua Nhap La: "; PrintList(l);
    cout << endl;
    
    //Bai 3
    cout << "Bai 3. So nut la: " << count << endl;
    
    //Bai 4
    cout << "Bai 4. Gia tri cua phan tu thu 3: " << FindValue(3, l) << endl;
    
    //Bai 5
    cout << "Bai 5: 1 - co/0 - khong: " << FindX(3, l) << endl;

    //Bai 6
    cout << "Bai 6. Them b sau phan tu a:\n";
    int a;
    cout << "- Nhap a: ";
    cin >> a;
    cout << "- Nhap b: ";
    int b;
    cin >> b;
    while (FindX(b, l) == 0)
    {
        cout << "Nhap sai! Gia tri " << b << " khong co trong danh sach.";
        cout << endl;
        exit(0);
    }
    Add_x_behind_k(b, a, l);
    cout << endl;
    cout << "List da them la: ";
    PrintList(l);
    cout << endl;
    //Bai 7
    
    cout << "Bai 7. Them x vao vi tri k:\n";
    int x, k;
    cout << "- Nhap x: ";
    cin >> x;
    cout << "- Nhap vi tri k: ";
    cin >> k;
    Add_x_to_k_place(x, k, l);
    cout << "List sau khi them la: ";
    PrintList(l);
    cout << endl;
    
    //Bai 8
    cout << "Bai 8. Danh sach dao nguoc: ";
    PrintList(rev_L(l));
    cout << endl;
    
    //Bai 9
    cout << "\nBai 9. Nhap gia tri muon xoa khoi danh sach: ";
    int giatri;
    cin >> giatri;
    if (RemoveNode(l, giatri) == 1)
        cout << "Xoa duoc." << endl;
    else
        cout << "Khum xoa duoc" << endl;
    PrintList(l);
    cout << endl;
    
    //Bai 10
    cout << "Bai  10. Danh sach sau khi xoa dau la: ";
    RemoveHead(l);
    PrintList(l);
    cout << endl;
    
    //Bai 11
    cout << "\n\nBai 11. Danh sach sau khi xoa duoi la: ";
    RemoveTail(l);
    PrintList(l);

    //Bai 12
    cout << "\n\nBai 12. Xoa  toan bo danh sach: ";
    RemoveList(l);
    PrintList(l);
    cout << endl;




}
