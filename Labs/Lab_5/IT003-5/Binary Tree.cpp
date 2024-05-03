#include <iostream>
using namespace std;

typedef struct tagTNode
{
    int Key;
    struct tagTNode* Left;
    struct tagTNode* Right;
} TNode;

typedef TNode *Tree;

void CreateTree(Tree &T) { T = NULL;}

TNode* CreateTNode (int x)
{
    TNode *p;
    p = new TNode; //cấp phát vùng nhớ động
    if (p == NULL)
        exit(1); // thoát else
    else
    {
        p->Key = x; //gán trường dữ liệu của nút = x
        p->Left = NULL;
        p->Right = NULL;
    }
    return p;
}

void NLR (Tree Root)
{
    if (Root != NULL)
    {
        //Xử lý Root - Xử lý tương ứng theo nhu cầu
        cout << Root->Key << " ";
        NLR(Root->Left);
        NLR(Root->Right);
    }
}

void NRL (Tree Root)
{
    if (Root != NULL)
    {
        //Xử lý Root - Xử lý tương ứng theo nhu cầu
        cout << Root->Key << " ";
        NRL(Root->Right);
        NRL(Root->Left);
    }
}

void LNR (Tree Root)
{
    if (Root != NULL)
    {
        //Xử lý Root - Xử lý tương ứng theo nhu cầu
        LNR(Root->Left);
        cout << Root->Key << " ";
        LNR(Root->Right);
    }
}

void RNL (Tree Root)
{
    if (Root != NULL)
    {
        //Xử lý Root - Xử lý tương ứng theo nhu cầu
        RNL(Root->Right);
        cout << Root->Key << " ";
        RNL(Root->Left);
    }
}

void LRN (Tree Root)
{
    if (Root != NULL)
    {
        //Xử lý Root - Xử lý tương ứng theo nhu cầu
        LRN (Root->Left);
        LRN (Root->Right);
        cout << Root->Key << " ";
    }
}

void RLN (Tree Root)
{
    if (Root != NULL)
    {
        //Xử lý Root - Xử lý tương ứng theo nhu cầu
        RLN (Root->Right);
        RLN (Root->Left);
        cout << Root->Key << " ";
    }
}

int insertNode(Tree &T, int X)
{
    if (T != NULL)
    {
        if (T->Key == X)
            return 0;
        if (X < T->Key)
            return insertNode(T->Left, X);
        else
            return insertNode(T->Right, X);
    }
    T = CreateTNode(X);
    return 1;
}

TNode* SearchTNode(Tree T, int x)
{
    if(T != NULL)
    {
        if (T->Key == x)
            return T;
        else if (x > T->Key)
            return SearchTNode(T->Right, x);
        else
            return SearchTNode(T->Left, x);
    }
    return NULL;
}

TNode* SearchTNode_2(Tree T, int x) //Khử đệ quy
{
    TNode* p = T;
    while (p != NULL)
    {
        if (x == p->Key)
            return p;
        else if (x < p->Key)
            p = p->Left;
        else
            p = p->Right;
    }
        return NULL;
}

void ThayThe1(Tree &p, Tree &T)
{
    if (T->Left != NULL)
        ThayThe1(p, T->Left);
    else
    {
        p->Key = T->Key; // Gán lại giá trị node bi xoá
        p = T;     // Trỏ đến node bị xoá thực sự
        T = T->Right; //Cô lập node bị xoá
    }
}

void DeleteNodeX1(Tree &T, int x)
{
    if (T != NULL)
    {
        if (x > T->Key)
            DeleteNodeX1(T->Right, x);
        else if (x < T->Key)
            DeleteNodeX1(T->Left, x);
        else //tim thấy Node có trường dữ liệu = x
        {
            TNode* p = T;
            if (T->Left == NULL)
                T = T->Right;
            else if(T->Right == NULL)
                T = T->Left;
            else
                ThayThe1(p, T->Right);// tìm bên cây con phải delete p;
            delete p;
        }
    }
        else
            printf("Khong tim thay phan can xoa tu");
}

 
int CountingTNode (Tree &T, int &dem) //NLR
{
    if (T != NULL)
    {
        dem++;
        CountingTNode(T->Left, dem);
        CountingTNode(T->Right, dem);
    }
    return dem;
}

int CountingTNode_2 (Tree &T, int &dem)
//NLR dem nut la <=> T->left = T->Right == NULL
{
    if (T != NULL)
    {
        if (T->Left == NULL and T->Right == NULL)
            dem++;
        CountingTNode_2(T->Left, dem);
        CountingTNode_2(T->Right, dem);
    }
    return dem;
}

int CountingTNode_3 (Tree T)
//Chia cay thanh 3 phan
{
    if (T == NULL)
        return 0;
    int a = CountingTNode_3(T->Left);
    int b = CountingTNode_3(T->Right);
    return a + b + 1;
}




int main(int argc, const char * argv[])
{
    Tree T;
    int a[] = {25, 17, 43, 24, 9, 28, 59, 7, 47, 12, 84, 8};
    int n = sizeof(a[n])/sizeof(a[0]);
    int x, k = 0;
    CreateTree(T);
    for (int i = 0; i < 12; i++)
    {
        insertNode(T, a[i]);
    }
    
    cout << "NRL: "; NRL(T); cout << endl;
    cout << "LRN: "; LRN(T); cout << endl;
    
//    cout << "NRL: "; NRL(T); cout << endl;
//
//    cout << "LNR: "; LNR(T); cout << endl;
//    cout << "RNL: "; RNL(T); cout << endl;
//
//    cout << "LRN: "; LRN(T); cout << endl;
//    cout << "RLN: "; RLN(T); cout << endl;
    
//    insertNode(T, 260);
//    cout << "NLR: "; NLR(T); cout << endl;
//
//    if (SearchTNode(T, 80) != NULL)
//        cout << "CO" << endl;
//    else
//        cout << "KHONG" << endl;
//
//    cout << CountingTNode(T, k) << endl;
//    cout << CountingTNode_3(T) << endl;
    return 0;
}
