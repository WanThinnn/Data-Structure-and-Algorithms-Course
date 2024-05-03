#include <iostream>
#include <queue>
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


void Replace(Tree &p, Tree &T)
{
    if (T->Left != NULL)
        Replace(p, T->Left);
    else
    {
        p->Key = T->Key; // Gán lại giá trị node bi xoá
        p = T;     // Trỏ đến node bị xoá thực sự
        T = T->Right; //Cô lập node bị xoá
    }
}

void DeleteNode(Tree &T, int x)
{
    if (T != NULL)
    {
        if (x > T->Key)
            DeleteNode(T->Right, x);
        else if (x < T->Key)
            DeleteNode(T->Left, x);
        else //tim thấy Node có trường dữ liệu = x
        {
            TNode* p = T;
            if (T->Left == NULL)
                T = T->Right;
            else if(T->Right == NULL)
                T = T->Left;
            else
                Replace(p, T->Right);// tìm bên cây con phải delete p;
            delete p;
        }
    }
        else
            printf("Khong tim thay phan can xoa tu");
}

void Input(Tree &T, int a[], int n)
{
    for (int i = 0; i < n; i++)
        insertNode(T, a[i]);
}

int CountingLeaves(Tree &T)
{
    if (T == NULL)
        return 0;
    int dem = 0;
    
    if (T != NULL)
    {
        if (T->Left == NULL or T->Right == NULL)
            dem++;
        dem += CountingLeaves (T->Left);
        dem += CountingLeaves (T->Right);
    }
    return dem;
}

int CountNodesWith2Children(Tree T)
{
    if (T == NULL)
        return 0;
    
    int count = 0;
    
    if (T->Left != NULL and T->Right != NULL)
        count++;
    
    count += CountNodesWith2Children(T->Left);
    count += CountNodesWith2Children(T->Right);

    return count;
}

int CountNodesWithOneChild(Tree T)
{
    if (T == NULL)
        return 0;
    
    int count = 0;
    
    if ((T->Left != NULL and T->Right == NULL) or (T->Left == NULL and T->Right != NULL))
        count++;
    count += CountNodesWithOneChild(T->Left);
    count += CountNodesWithOneChild(T->Right);

    return count;
}

int CountNodesWithOneChild_Left(Tree T)
{
    if (T == NULL)
        return 0;
    
    int count = 0;
    
    if (T->Left != NULL and T->Right == NULL)
        count++;
    
    count += CountNodesWithOneChild_Left(T->Left);
    count += CountNodesWithOneChild_Left(T->Right);

    return count;
}

int getHeight(Tree T)
{
    if (T == NULL)
        return 0;
    else
    {
        int leftHeight = getHeight(T->Left);
        int rightHeight = getHeight(T->Right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}
void printNodesByLevel(Tree T)
{
    if (T == NULL)
        return;
    
    queue <TNode*> q;
    q.push(T);
   
    while (!q.empty())
    {
        int size = q.size();
        
        for (int i = 0; i < size; i++)
        {
            TNode* current = q.front();
            q.pop();
            
            
            cout << current->Key << " ";
            
            if (current->Left != NULL)
                q.push(current->Left);
            if (current->Right != NULL)
                q.push(current->Right);
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[])
{
    Tree T;
    int a[] = {25, 17, 43, 24, 9, 28, 59, 7, 47, 12, 84, 8};
    int n = sizeof(a)/sizeof(a[0]);
    int x, k = 0;
    CreateTree(T);
    Input(T, a, n);
    cout << "LNR: "; LNR(T); cout << endl;
    cout << "NLR: "; NLR(T); cout << endl;
    cout << "RNL: "; RNL(T); cout << endl;
    

    cout << "Tong so Node la la: " << CountingLeaves(T) << endl;
    cout <<  "Tong so Node co 2 cay con la: " << CountNodesWith2Children(T) << endl;
    cout << "Tong so Node chi co 1 cay con trai la: " << CountNodesWithOneChild_Left(T) << endl;
    cout << "Tong so Node chi co 1 cay con la: " << CountNodesWithOneChild(T) << endl;
    
    cout << "X = "; cin >> x;
    DeleteNode(T, x);
    
    cout << "Chieu cao cua cay: " << getHeight(T) << endl;
    
    cout << "In cac Node tren tung muc cua cay: \n";
    printNodesByLevel(T);
    return 0;
}
