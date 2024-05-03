//
//  Binary Tree.cpp
//  IT003-OT
//
//  Created by Thinnn on 21/06/2023.
//

#include <stdio.h>
#include <iostream>
using namespace std;

struct TNode
{
    int Key;
    TNode* Left;
    TNode* Right;
};

typedef TNode *Tree;

void CreateTree(Tree &T) { T = NULL; }

TNode* CreateTNode(int x)
{
    TNode* p;
    p = new TNode();
    if (p == NULL)
        exit(0);
    else{
        p->Key = x;
        p->Left = NULL;
        p->Right = NULL;
    }
    return p;
}

void NLR(Tree T)
{
    if (T != NULL)
    {
        cout << T->Key << " ";
        NLR(T->Left);
        NLR(T->Right);
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

int InsertTNode(Tree &T, int x)
{
    if (T != NULL)
    {
        if (T->Key == x)
            return 0;
        if (x < T->Key)
            return InsertTNode(T->Left, x);
        else
            return InsertTNode(T->Right, x);
    }
    T = CreateTNode(x);
    return 1;
}

TNode* SearchTNode(Tree T, int x)
{
    if (T != NULL)
    {
        if (T->Key == x)
            return T;
        if (x < T->Key)
            return SearchTNode(T->Left, x);
        if (x > T->Key)
            return SearchTNode(T->Right, x);
    }
    return NULL;
}

void Replace(Tree &p, Tree &T)
{
    if (T->Right != NULL)
        Replace(p, T->Right);
    p->Key = T->Key;
    p = T;
    T = T->Left;
}

void DeleteTNode(Tree &T, int x)
{
    if (T != NULL)
    {
        if (x < T->Key)
            DeleteTNode(T->Left, x);
        else if (x > T->Key)
            DeleteTNode(T->Right, x);
        else
        {
            TNode* p = T;
            if (T->Left == NULL)
                T = T->Right;
            else if (T->Right == NULL)
                T = T->Left;
            else
                Replace(p, T->Left);
            delete p;
        }
    }
    else
        cout << "Khong tim thay phan tu can xoa!\n";
}

int CountingTNode(Tree T, int &d)
{
    if (T == NULL)
        return -1;

   if ((T->Left == NULL and T->Right != NULL) or (T->Left != NULL and T->Right == NULL))
       d++;
    CountingTNode(T->Left, d);
    CountingTNode(T->Right, d);
    return d;
}

int CountingALLTNode(Tree T, int &d)
{
    if (T == NULL)
        return -1;

    d++;
    CountingTNode(T->Left, d);
    CountingTNode(T->Right, d);
    return d;
}

int CountingTNode_1Left(Tree T, int &d)
{
    if (T != NULL)
    {
       if (T->Left != NULL and T->Right == NULL)
           d++;
        CountingTNode_1Left(T->Left, d);
        CountingTNode_1Left(T->Right, d);
    }
    return d;
}
int CountingTNode_1Right(Tree T, int &d)
{
    if (T != NULL)
    {
       if (T->Left == NULL and T->Right != NULL)
           d++;
        CountingTNode_1Right(T->Left, d);
        CountingTNode_1Right(T->Right, d);
    }
    return d;
}

int GetLength(Tree T)
{
    if (T == NULL)
        return -1;
    
    int hL = GetLength(T->Left);
    int hR = GetLength(T->Right);
    if (hL > hR)
        return hL+1;
    else
        return hR+1;
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

int len(Tree T, int x)
{
    if (T == NULL)
        return -1;
    if (T->Key == x)
        return 0;
    
    int dl = len(T->Left, x);
    int dr = len(T->Right, x);
    if (dl != -1)
        return dl+1;
    if (dr != -1)
        return dr+1;
    return -1;
}

int SumbyLevel(Tree T, int k, int &s)
{
    if (T != NULL)
    {
        if (k == 0)
            s += T->Key;
        SumbyLevel(T->Left, k-1, s);
        SumbyLevel(T->Right, k-1, s);
    }
    return s;
}

void PrintbyLevel(Tree T, int k)
{
    if (T != NULL)
    {
        if (k == 0)
            cout << T->Key << " ";
        PrintbyLevel(T->Left, k-1);
        PrintbyLevel(T->Right, k-1);
    }
}

void PrintbyLevels(Tree T, int n)
{
    for (int i = 0; i <= n; i++)
    {
        PrintbyLevel(T, i);
        cout << endl;
    }
}

int main()
{
    Tree T;
    int a[] = {6,4,8,2,1,7,3,5,9};
    int n = sizeof(a)/sizeof(a[0]);
    CreateTree(T);
    int d1 = 0, d2 = 0, d3 = 0;
    for (int i = 0; i < n; i++)
    {
        InsertTNode(T, a[i]);
    }
    RNL(T);
    cout << endl;
    NRL(T);
    
    cout << endl;
//    cout << CountingTNode(T, d1) << endl;
//    cout << CountingTNode_1Left(T, d2) << endl;
//    cout << CountingTNode_1Right(T, d3) << endl;
//    cout << GetLength(T) << endl;
//    cout << getHeight(T) << endl;
//    cout << len(T, 28) << endl;
//    int s = 0;
//    SumbyLevel(T, 4, S);
//    cout << S << endl;
//    PrintbyLevel(T, 2);
//    cout << endl;
//    cout << SumbyLevel(T, 4, s) << endl;
    PrintbyLevels(T, 2);
//    cout << endl;
//    int d = 0;
//    cout << CountingTNode(T, d);
//    int f = 0;
//    cout << CountingALLTNode(T, f);

//    NRL(T);
//    cout << endl;

//    LNR(T);
//    cout << endl;
//    RNL(T);
//    cout << endl;
//
//    LRN(T);
//    cout << endl;
//    RLN(T);
//    cout << endl;
}
