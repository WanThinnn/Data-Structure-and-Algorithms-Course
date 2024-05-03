//
//  Stack (Arr).cpp
//  Stack
//
//  Created by Thinnn on 21/06/2023.
//

#include <stdio.h>
#include <iostream>
#define Max 100

using namespace std;

struct Stack
{
    int Top;
    int A[Max];
};


void CreateStack (Stack &s)
{
    s.Top = -1;
}


int IsEmpty(Stack s)
{
    if (s.Top == -1)
        return 1;//Stack rỗng return 1;
    else
        return 0;
}

int IsFull(Stack s)
{
    if (s.Top == Max - 1)
        return  1;
    return 0;
}

void Push(Stack &s, int Tam)
{
    if (IsFull(s) == false)
    {
        s.Top++;
        s.A[s.Top] = Tam;
    }
}

int Pop(Stack &s)
{
    int trave;
    if (IsEmpty(s) == true)
    {
        return -1;
    }
    else
    {
        trave = s.A[s.Top];
        s.Top--;
    }
    return trave;
}

void PrintStack(Stack s)
{
    for(int i = s.Top; i > -1; i--)
    {
        cout << s.A[i] << " ";
    }
}

int Top(Stack s)
{
    int x;
    if (s.Top != -1)
    {
        x = s.A[s.Top];
        return x;
    }
    return -1;
}

void Input(Stack &s, int &n)
{
    cin >> n;
    for (int i = 0; i< n; i++){
        //thuc hien nhap gia tri vao bien x
        int x;
        printf("Nhap gia tri phan tu thu %d: ",i);
        scanf("%d",&x);
        Push(s,x);
    }
}

int main()
{
    Stack S;
    int n;
    CreateStack(S);
    Push(S, 1);
    Push(S, 3);
    Push(S, 5);
    Push(S, 7);
    PrintStack(S);
    cout << endl;
    cout << Pop(S) << endl;
    cout << Top(S) << endl;
    PrintStack(S);

}
