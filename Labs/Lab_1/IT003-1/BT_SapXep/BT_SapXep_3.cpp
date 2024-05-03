#include <iostream>
#include <stdio.h>

using namespace std;

class Sinhvien
{
    private:
        int NS, GT;
        string HT;
    public:
        float dTB;
        int MSSV;
        void input();
        void output();
    
};

class DS_Sinhvien
{
    int n;
    Sinhvien a[1000];
public:
    void input_ds();
    void quick_sort_dTB(Sinhvien a[], int left, int right);
    void quick_sort_MSSV(Sinhvien a[], int left, int right);
    void output_ds();
    
};

void Sinhvien::input()
{
    cin >> MSSV;
    fflush(stdin);
    getline(cin, HT);
    cin >> GT;
    cin >> NS;
    cin >> dTB;
    
}

void DS_Sinhvien::input_ds()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        a[i].input();
}

void swap(Sinhvien &x, Sinhvien &y)
{
    Sinhvien temp;
    temp = x;
    x = y;
    y = temp;
}

void DS_Sinhvien::quick_sort_dTB(Sinhvien a[], int left, int right)
{
    int i, j;
    
    Sinhvien x;
    x = a[(left+right)/2];
    i = left;
    j = right;
    while (i < j)
    {
        while (a[i].dTB > x.dTB)
            i++;
        while (a[j].dTB < x.dTB)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quick_sort_dTB(a, left, j);
    if (i < right)
        quick_sort_dTB(a, i, right);
}

void DS_Sinhvien::quick_sort_MSSV(Sinhvien a[], int left, int right)
{
    int i, j;
    
    Sinhvien x;
    x = a[(left+right)/2];
    i = left;
    j = right;
    while (i < j)
    {
        while (a[i].MSSV < x.MSSV)
            i++;
        while (a[j].MSSV > x.MSSV)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quick_sort_MSSV(a, left, j);
    if (i < right)
        quick_sort_MSSV(a, i, right);
}

void Sinhvien::output()
{
    cout << MSSV << " " << HT << " " << GT << " " << NS << " " << dTB << " " << endl;
}

void DS_Sinhvien::output_ds()
{
    quick_sort_dTB(a, 0, n-1);
    for (int i = 0; i < n; i++)
        a[i].output();
    cout << endl;
    
    quick_sort_MSSV(a, 0, n-1);
    for (int i = 0; i < n; i++)
        a[i].output();
}


int main()
{
    DS_Sinhvien DSSV;
    DSSV.input_ds();
    DSSV.output_ds();
}
