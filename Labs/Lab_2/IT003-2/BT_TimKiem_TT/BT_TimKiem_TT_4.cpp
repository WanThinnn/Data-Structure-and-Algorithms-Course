#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
int c = 0;
using namespace std;

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


int binary_search(int a[], int n, int X)
{
    int left, right, mid;
    left = 0;
    right = n - 1;
    while (left <= right)
    {
        mid = (left + right)/2;
        if (a[mid] == X)
            return mid;
        else if (a[mid] > X)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int count_binary_search(int a[], int n, int X, int &comparisons)
{
    int left = 0, right = n - 1;
    comparisons = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        comparisons++;
        if (a[mid] == X) {
            cout << "Da so sanh " << comparisons << " lan" << endl;
            return mid;
        }
        else if (a[mid] > X) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << "Da so sanh " << comparisons << " lan" << endl;
    return -1;
}


int binary_search_recursive(int arr[], int left, int right, int x)
{
    if (left <= right)
    {
        int mid = (right + left) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }

        else if (arr[mid] > x) {
            return binary_search_recursive(arr, mid + 1, right, x);
        }
        
        else {
            return binary_search_recursive(arr, left, mid - 1, x);
        }
    }
    return -1;
}


void quick_sort(int a[], int left, int right)
{
    int i, j, x;
    x = a[(left+right)/2];
    i = left;
    j = right;
    while (i < j)
    {
        while (a[i] > x)
            i++;
        while (a[j] < x)
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


void options(int a[], int n, int &option)
{
    int ctn, ctn2, result, result_2, x;
CAU_A:
    {
        cout << "* Cau a: \n";
        cout << "- Chon thuat toan:" << endl << "1. Binary Search (De Quy)." << endl << "2. Binary Search (Khong De Quy)." << endl << "3. Khong chon." << endl;
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
                cout << "- Phan tu can tim: ";
                cin >> x;
                result =  binary_search(a, n, x);
                if (result == -1) {
                        cout << "Khong tim thay phan tu " << x << endl;
                    }
                    else {
                        cout << "Tim thay phan tu " << x << " tai vi tri " << result << endl;
                    }
               
                break;
            case 2:
                cout << "- Phan tu can tim: ";
                cin >> x;
                result_2 = binary_search_recursive(a, 0, n - 1, x);
                if (result_2 == -1)
                        cout << "Khong tim thay phan tu " << x << endl;
                else
                        cout << "Tim thay phan tu " << x << " tai vi tri " << result_2 << endl;
                break;
            case 3:
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
        cout << "- Chon thuat toan :" << endl << "1. X dau day." << endl << "2. X giua day." << endl << "3. X cuoi day." << endl;
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
                count_binary_search(a, n, a[n/3], c);
                break;
            case 2:
                count_binary_search(a, n, a[n/2], c);
                break;
            case 3:
                count_binary_search(a, n, a[2*n/3], c);
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
    int n, o, X;
    input_arr(a, n);
    quick_sort(a, 0, n-1);
    output_arr(a,n);
    options(a, n, o);
}
