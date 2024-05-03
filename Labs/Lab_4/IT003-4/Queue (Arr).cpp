#include <iostream>
#define Max 100
using namespace std;

struct Queue
{
    int Front, Rear;
    int A[Max];
};


void CreateQueue (Queue &Q)
{
    Q.Front = 0;
    Q.Rear = -1;
}


int IsEmpty (Queue Q)
{
    if (Q.Front > Q.Rear)
        return 1; //Queue rỗng return 1;
    else
        return 0;
}

int IsFull (Queue Q)
{
    if (Q.Rear == Max-1)
    {
        return 1;
    }
    return 0;
}

void EnQueue (Queue &Q, int x)
{
    //Queue chưa đầy
    if (IsFull(Q) == false)
    {
        Q.Rear++;
        Q.A[Q.Rear] = x;
    }
}

int DeQueue(Queue &Q) //Lay 1 phan tu khoi Queue
{
    int x;
    if (IsEmpty(Q) == false)
    {
        x = Q.A[Q.Front];
        Q.Front++;
        return x;
    }
    return -1;
}

int Peek(Queue Q)
{
    if (!IsEmpty(Q))
        return Q.A[Q.Front];
    else
        exit(1);
}

void Input(Queue &Q, int &n)
{
    cin >> n;
    for (int i = 0; i< n; i++){
        //thuc hien nhap gia tri vao bien x
        int x;
        printf("Nhap gia tri phan tu thu %d: ",i);
        scanf("%d",&x);
        EnQueue(Q,x);
    }
}

void PrintQueue(Queue Q)
{
    for (int i = Q.Front; i <= Q.Rear; i++)
        cout << Q.A[i] << " ";
    cout << endl;
}

int main()
{
    Queue Q;
    CreateQueue(Q);
    EnQueue(Q, 1);
    EnQueue(Q, 3);
    EnQueue(Q, 5);
    EnQueue(Q, 7);
    EnQueue(Q, 9);
    PrintQueue(Q);
    cout << DeQueue(Q);
    cout << endl;
    PrintQueue(Q);
    cout << Peek(Q);
    cout << endl;
}
