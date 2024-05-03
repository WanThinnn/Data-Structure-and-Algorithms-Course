#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
 
using namespace std;
int tmp = 0, t = 0;

int random(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}

void input_arr(int a[], int &n)
{
    cout << "n = ";
    cin >> n;
    int r;
    srand((int)time(0));
    for (int i = 0; i < n; i++)
    {
        r = random(-n,n);
        a[i] = r;
    }
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}



void count_sequential_search(int A[], int n, int X)
{
    int i = 0;
    while (A[i] != X)
    {
        i++;
        tmp++;
    }
    cout << "-> So lan so sanh: " << tmp << endl;
    tmp = 0;
}

void count_linear_search(int A[], int n, int X)
{
    int i = 0;
    A[n] = X;
    while (A[i] != X)
        i++;
    if (i == n)
        cout << "-> Khong tim thay X";
    else
        cout << "-> Tim thay X o vi tri thu: " << i;
    i = 0;
}


void quick_sort(int a[], int left, int right)
{
    int i, j, x;
    x = a[(left+right)/2];
    i = left;
    j = right;
    while (i < j)
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quick_sort(a, left, j);
    if (i < right)
        quick_sort(a, i, right);
}

void output_arr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}


void options(int a[], int n, int x, int &option)
{
    int ctn, ctn2;
CAU_A:
    {
        cout << "* Cau a: \n";
        cout << "- Chon thuat toan:" << endl << "1. X dau day." << endl << "2. X giua day." << endl << "3. X cuoi day." << endl;
        cout << "- Option: ";
        do
        {
            cin >> option;
            if (option < 1 or option > 3)
                cout << "Loi, chon lai: ";
        }
        while (option < 1 or option > 8);
        
        switch (option)
        {
            case 1:
                count_sequential_search(a, n, a[n/3]);
                cout << "-> Phan tu " << a[n/3]<< " can tim kiem o vi tri i thu " << n/3 << " trong day." << endl;
                break;
            case 2:
                count_sequential_search(a, n, a[n/2]);
                cout << "-> Phan tu " << a[n/2]<< " can tim kiem o vi tri i thu " << n/2 << " trong day." << endl;
                break;
            case 3:
                count_sequential_search(a, n, a[2*n/3]);
                cout << "-> Phan tu " << a[2*n/3]<< " can tim kiem o vi tri i thu " << 2*n/3 << " trong day." << endl;
                break;
        }
        cout << endl;
        cout << "* Ban co muon tiep tuc chuong trinh? \n";
        cout << "1. Tiep tuc" << endl << "2. Chuyen sang cau b." << endl << "3. Dung chuong trinh" << endl;
        cout << "* Option: ";
        do
        {
            cin >> ctn;
            if (ctn < 1 or ctn > 3)
                cout << "Loi, chon lai: ";
        }
        while (ctn < 1 or ctn > 3);
        if (ctn == 3)
            exit(0);
        if (ctn == 1)
            goto CAU_A;
        if (ctn == 2)
            goto CAU_B;
        
    }
    CAU_B:
    {
        cout << endl;
        cout << "* Cau b: \n";
        cout << "- Chon thuat toan da duoc cai tien:" << endl << "1. X dau day." << endl << "2. X giua day." << endl << "3. X cuoi day." << endl;
        cout << "- Option: ";
        do
        {
            cin >> option;
            if (option < 1 or option > 3)
                cout << "Loi, chon lai: ";
        }
        while (option < 1 or option > 3);

        switch (option)
        {
            case 1:
                count_linear_search(a, n/3+1, a[n/3]);
                break;
            case 2:
                count_linear_search(a, n/2+1, a[n/2]);
                break;
            case 3:
                count_linear_search(a, 2*n/3+1, a[n/2]);
                break;
        }

        cout << endl;
        cout << "* Ban co muon tiep tuc chuong trinh? \n";
        cout << "1. Tiep tuc" << endl << "2. Chuyen sang cau a." << endl << "3. Dung chuong trinh" << endl;
        cout << "* Option: ";
        do
        {
            cin >> ctn2;
            if (ctn2 < 1 or ctn2 > 3)
                cout << "Loi, chon lai: ";
        }
        while (ctn2 < 1 or ctn2 > 3);
        if (ctn2 == 3)
            exit(0);
        if (ctn2 == 2)
            goto CAU_A;
        if (ctn2 == 1)
            goto CAU_B;
    }
}


int main()
{
    int a[1000000];
    int n, o;
    input_arr(a, n);
    quick_sort(a, 0, n-1);
    output_arr(a,n);
    options(a, n, n, o);
    count_sequential_search(a, n, n);
}
