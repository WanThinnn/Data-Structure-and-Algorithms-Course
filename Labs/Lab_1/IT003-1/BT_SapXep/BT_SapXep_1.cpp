#include <stdio.h>
#include <iostream>

int a[1000], b[1000], c[1000];
int m, n, k;

using namespace std;

void input(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
 
void selection_Sort(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        
        if (min != i)
            swap(arr[min], arr[i]);
    }
}

void insertion_sort(int a[], int n)
{
    int pos, i;
    int x;
    for (i = 1; i < n; i++)
    {
        x = a[i];
        pos = i - 1;
        while (pos >= 0 and a[pos] > x)
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos+1] = x;
    }
}


void interchange_sort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (a[j] < a[i])
                swap(a[i], a[j]);
}

void output(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}


int main()
{
    input(a, n);
    selection_Sort(a, n);
    output(a, n);
    
    input(b, m);
    insertion_sort(b, m);
    output(b, m);
    
    input(c, k);
    interchange_sort(c, k);
    output(c, k);
}
