#include <iostream>
using namespace std;

typedef struct tagNode
{
    int info;
    struct tagNode *Next;
} Node;

typedef struct tagQueue
{
    Node *Front;
    Node *Rear;
} Queue;

void CreateQueue (Queue &l)
{
    l.Front = l.Rear = NULL;
}

Node* CreateNode(int x)
{
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    else
    {
        p->info = x;
        p->Next = NULL;
    }
    return p;
}

int IsEmpty (Queue &Q)
{
    if (Q.Front == NULL)
        return 1; //Queue rỗng return 1;
    else
        return 0;
}

void EnQueue(Queue &Q, Node *Tam) //Thêm 1 phần tử vào Queue
{
    if(Q.Front == NULL)
    {
        Q.Front = Tam;
        Q.Rear = Tam;
    }
    else
    {
        Q.Rear->Next = Tam;
        Q.Rear = Tam;
    }
}

int DeQueue(Queue &Q) //Lay 1 phan tu khoi Queue
{
    Node *p;
    int trave;
    if (IsEmpty(Q) != 1)
        if (Q.Front != NULL)
        {
            p = Q.Front;
            trave = p->info;
            Q.Front = Q.Front->Next;
            Q.Rear = NULL;
            if(Q.Front == NULL)
                return 1;
            delete p;
        }
    return 0;
}
void PrintQueue(Queue q)
{
    Node* p = q.Front;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->Next;
    }
}

int main()
{
    Queue Q;
    CreateQueue(Q);
    EnQueue(Q, CreateNode(1));
    EnQueue(Q, CreateNode(3));
    EnQueue(Q, CreateNode(5));
    EnQueue(Q, CreateNode(7));
    PrintQueue(Q);
    DeQueue(Q);
    cout << endl;
    PrintQueue(Q);

}
