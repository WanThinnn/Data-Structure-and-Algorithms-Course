//22521385 - Lai Quan Thien - Bai Kiem Tra N1

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
    p = new TNode;
    if (p == NULL)
        exit(1);
    else
    {
        p->Key = x;
        p->Left = NULL;
        p->Right = NULL;
    }
    return p;
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

int CountingTNode (Tree &T, int &dem)
{
    if (T != NULL)
    {
        if (T->Left != NULL and T->Right != NULL)
            dem++;
        CountingTNode(T->Left, dem);
        CountingTNode(T->Right, dem);
    }
    return dem;
}

int CountingTNode_2 (Tree &T, int &dem, int X)
{
    if (T != NULL)
    {
        if (T->Key < X)
            dem++;
        CountingTNode_2(T->Left, dem, X);
        CountingTNode_2(T->Right, dem, X);
    }
    return dem;
}

int main(int argc, const char * argv[])
{
    Tree T;
    int a[] = {25, 17, 43, 24, 9, 28, 59, 7, 47, 12, 84, 8};
    int x, k = 0, d = 0;
    
    CreateTree(T);
    
    for (int i = 0; i < 12; i++)
        insertNode(T, a[i]);
    
    //Cau D:
    cout << CountingTNode(T, k) << endl;
    
    //Cau E:
    cout << "X = ";
    cin >> x;
    cout << CountingTNode_2(T, d, x) << endl;
    
    return 0;
}
