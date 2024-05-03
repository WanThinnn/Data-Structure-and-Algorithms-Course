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

 


void PrintTree (Tree Root)
{
    if (Root != NULL)
    {
        cout << Root->Key << " ";
        PrintTree(Root->Left);
        PrintTree(Root->Right);
    }
}

void EvenTNode (Tree Root)
{
    if (Root != NULL)
    {
        if (Root->Key % 2 == 0)
            cout << Root->Key << " ";
        EvenTNode(Root->Left);
        EvenTNode(Root->Right);
    }
}

void EvenTNodeX (Tree Root, int X)
{
    if (Root != NULL)
    {
        if (Root->Key > X)
            cout << Root->Key << " ";
        EvenTNodeX(Root->Left, X);
        EvenTNodeX(Root->Right, X);
    }
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

TNode* findMaxNode(Tree T)
{
    if (T == NULL)
        return NULL;
    
    TNode* current = T;
    while (current->Right != NULL)
        current = current->Right;
    
    return current;
}

TNode* findMinNode(Tree T)
{
    if (T == NULL)
        return NULL;
    
    TNode* current = T;
    while (current->Left != NULL)
        current = current->Left;
    
    return current;
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

int CountNodesWithOneChild_Right(Tree T)
{
    if (T == NULL)
        return 0;
    
    int count = 0;
    
    if (T->Left == NULL and T->Right != NULL)
        count++;
    
    count += CountNodesWithOneChild_Right(T->Left);
    count += CountNodesWithOneChild_Right(T->Right);

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

int findPathLength(Tree T, int target)
{
    if (T == NULL)
        return -1;

    if (T->Key == target)
        return 0;

    int leftPathLength = findPathLength(T->Left, target);
    int rightPathLength = findPathLength(T->Right, target);

    
    if (leftPathLength != -1)
        return leftPathLength + 1;

    if (rightPathLength != -1)
        return rightPathLength + 1;

    return -1;
}


int CountPath(Tree T, int x)
{
    if (T == NULL)
        return 0;
    
    int count = 0;

    if (T->Key == x)
        return 0;
    
    if (T->Key != x)
        count++;
    
    if (x < T->Key)
        count += CountPath(T->Left, x);
    else if (x > T->Key)
        count += CountPath(T->Right, x);
    
    return count;
}

int main(int argc, const char * argv[])
{
    Tree T;
    int a[] = {25, 17, 43, 24, 9, 28, 59, 7, 47, 12, 84, 8};
    int n = sizeof(a) / sizeof(a[0]);
    int k[20] = {0};
    int x;
    CreateTree(T);
    for (int i = 0; i < n; i++)
        insertNode(T, a[i]);
    
    cout << "Tree: "; PrintTree(T); cout << endl;
    
    //Cau 1:
    cout << "Cau 1: In ra cac Node chan: "; EvenTNode(T); cout << endl;
    
    //Cau 2:
    cout << "X = "; x = 12;
    cout << "Cau 2: In ra cac Node > X: "; EvenTNodeX(T, x); cout << endl;
    
    //Cau 3:
    cout << "Cau 3: Tong so Node cua cay: " << CountingTNode(T, k[0]) << endl;
    
    //Cau 4:
    cout << "Cau 4: Chieu cao cua cay: " << getHeight(T) << endl;

    //Cau 5:
    cout << "Cau 5: ";
    if (SearchTNode(T, x) != NULL)
        cout << "Co X trong cay." << endl;
    else
        cout << "Khong co X trong cay." << endl;
    
    //Cau 6:
    cout << "Cau 6: Node co key lon nhat: " << findMaxNode(T)->Key << endl;
    
    //Cau 7:
    cout << "Cau 7: Node co key nho nhat ben phai: " << findMinNode(T->Right)->Key << endl;
    
    //Cau 8:
    cout << "Cau 8: Tong so Node la la: " << CountingLeaves(T) << endl;
    
    //Cau 9:
    cout << "Cau 9: Tong so Node chi co 1 cay con la: " << CountNodesWithOneChild(T) << endl;
    
    //Cau 10:
    cout << "Cau 10: Tong so Node chi co 1 cay con phai la: " << CountNodesWithOneChild_Right(T) << endl;
    
    //Cau 11:
    cout << "Cau 11: Tong so Node chi co 1 cay con trai la: " << CountNodesWithOneChild_Left(T) << endl;
    
    //Cau 12:
    cout << "Cau 12: Tong so Node co 2 cay con la: " << CountNodesWith2Children(T) << endl;
    
    //Cau 13:
    cout << "Cau 13: In cac Node tren tung muc cua cay: \n";
    printNodesByLevel(T);
    
    //Cau 14:
    int pathLength = CountPath(T, 12);
    cout << "Cau 14: Do dai duong di tu Goc den Node = 12: ";
    cout << pathLength << endl;
    return 0;
}
