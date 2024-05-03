#include <iostream>
#include <stdio.h>

using namespace std;

class Don_Thuc
{
    private:
        int dau;
        float heso;
    public:
        int bac;
        void input();
        void output();
    
};

class Da_Thuc
{
    int n;
    Don_Thuc P[100];
public:
    void input_Fx();
    void quick_sort_bac(Don_Thuc a[], int left, int right);
    void output_Fx();
    
};

void Don_Thuc::input()
{
    cin >> dau;
    cin >> heso;
    cin >> bac;
    
}

void Da_Thuc::input_Fx()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        P[i].input();
}

void swap(Don_Thuc &x, Don_Thuc &y)
{
    Don_Thuc temp;
    temp = x;
    x = y;
    y = temp;
}

void Da_Thuc::quick_sort_bac(Don_Thuc P[], int left, int right)
{
    int i, j;
    Don_Thuc x;
    x = P[(left+right)/2];
    i = left;
    j = right;
    while (i < j)
    {
        while (P[i].bac < x.bac)
            i++;
        while (P[j].bac > x.bac)
            j--;
        if (i <= j)
        {
            swap(P[i], P[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quick_sort_bac(P, left, j);
    if (i < right)
        quick_sort_bac(P, i, right);
}

void Don_Thuc::output()
{
    if (dau == 0)
        cout << " -";
    else if (dau == 1)
        cout << " +";
    cout << heso << "x^";
    cout << bac;
}

void Da_Thuc::output_Fx()
{
    quick_sort_bac(P, 0, n-1);
    for (int i = 0; i < n; i++)
        P[i].output();
    cout << endl;
}


int main()
{
    Da_Thuc P;
    P.input_Fx();
    P.output_Fx();
}
