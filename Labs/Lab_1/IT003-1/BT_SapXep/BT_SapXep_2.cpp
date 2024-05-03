#include <stdio.h>
#include <iostream>

int  n, k, q, t = 0;
int i, j;

using namespace std;

void input(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void luu_tru_mang_phu(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}

void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
 

void Selection_Sort_Giam(int arr[], int k, int n)
{
    int i, j, min;
    for (i = k; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
            if (arr[j] > arr[min])
                min = j;
        
        if (min != i)
            swap(arr[min], arr[i]);
    }
}


void Interchange_Sort_Tang(int a[], int k, int n)
{
    int i, j;
    for (i = k; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (a[j] < a[i])
                swap(a[i], a[j]);
}

bool comp(const int a, const int b){
   return a > b;
}

void solve_1(int a[], int n)
{
    sort(a, a + n);
    for (i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            k = i;
            break;
        }
    }
}

void solve_2(int a[], int n)
{
    sort(a, a + n, comp);
    for (j = 0; j < n; j++)
    {
        if (a[j] <= 0)
        {
            q = j+1;
            break;
        }
    }
            
}

void solve_3(int a[], int MP[], int c[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (MP[i] >= 0)
            c[i] = 1;
        if (MP[i] < 0)
            c[i] = 0;
    }
    
    sort(a, a + n, comp);
    for (j = 0; j < n; j++)
    {
        if (a[j] <= 0)
        {
            q = j+1;
            break;
        }
    }
}

void cau_a(int a[], int n)
{
    solve_1(a, n);
    Interchange_Sort_Tang(a, 0, k);
    Selection_Sort_Giam(a, k, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void cau_b(int a[], int n)
{
    solve_1(a, n);
    Selection_Sort_Giam(a, 0, k);
    Interchange_Sort_Tang(a, k, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void cau_c(int a[], int n)
{
    solve_2(a, n);
    Interchange_Sort_Tang(a, 0, q);
    Selection_Sort_Giam(a, q, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void cau_d(int a[], int n)
{
    solve_2(a, n);
    Interchange_Sort_Tang(a, q, n);
    Selection_Sort_Giam(a, 0, q);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}



void cau_e(int a[], int b[], int c[], int n)
{
    solve_3(a, b, c, n);
    Selection_Sort_Giam(a, 0, q);
    Selection_Sort_Giam(a, q, n);
    int i = 0, t = n-1;
    for (int j = 0; j < n; j++)
    {
        if (c[j] == 1)
        {
            c[j] = a[i];
            i++;
        }
        else if (c[j] == 0)
        {
            c[j] = a[t];
            t--;
        }
    }
    for (int i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << endl;
}



int main()
{
    int n;
    int a[1000], b[1000], c[1000];
    input(a, n);
    luu_tru_mang_phu(a, b, n);
    cout << "Am tang, duong giam: ";
    cau_a(a, n);
    
    cout << "Am giam, duong tang: ";
    cau_b(a, n);
    
    cout << "Duong tang, am giam: ";
    cau_c(a, n);
    
    cout << "Duong giam, am tang: ";
    cau_d(a, n);
    
    cout << "Duong giam, am tang, dam bao vi tri tuong doi: ";
    cau_e(a, b, c, n);
}
