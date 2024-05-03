//
//  main.cpp
//  IT003-OT
//
//  Created by Thinnn on 19/06/2023.
//

#include <iostream>
using namespace std;
void Swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void Selection_Sort(int a[], int n)
{
    int i, j;
    int min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[min] > a[j])
                min = j;
        if (min != i)
                Swap(a[min], a[i]);
    }
    
}

void Interchange_Sort(int a[], int n)
{
    for (int i = 0; i < n-1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[i])
                Swap(a[i], a[j]);
}

void Insertion_Sort(int a[], int n)
{
    int pos, i;
    int x;
    for (i = 1; i < n; i++)
    {
        x = a[i];
        pos = i -1;
        while (pos >= 0 and x < a[pos])
        {
            a[pos+1] = a[pos];
            pos--;
        }
        a[pos+1] = x;
    }
}

void Bubble_Sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j++)
            if (a[j]<a[j-1])
                Swap(a[j], a[j-1]);
}


void Shift(int a[], int l, int r)
{
    int i = l;
    int j = 2*i + 1;
    int x = a[i];
    while (j <= r)
    {
        if (j < r)
            if (a[j] < a[j+1])
                j++;
        if (a[j] <= x)
            return;
        else
        {
            a[i] = a[j];
            a[j] = x;
            i = j;
            j = 2*i + 1;
            x = a[i];
        }
    }
}

void CreateHeap(int a[], int n)
{
    int l = n/2 - 1;
    while (l >= 0)
    {
        Shift(a, l, n-1);
        l = l - 1;
    }
}

void HeapSort(int a[], int n)
{
    int r;
    CreateHeap(a, n);
    r = n - 1;
    while (r > 0)
    {
        Swap(a[0], a[r]);
        r--;
        if (r > 0)
            CreateHeap(a, r);
    }
}

void output(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}


void Quick_Sort(int a[], int l, int r)
{
    int x = a[(l+r)/2];
    int i = l;
    int j = r;
    while (i < j)
    {
        while (a[i] > x)
            i++;
        while (a[j] < x)
            j--;
        if (i <= j)
        {
            Swap(a[i], a[j]);
            i++; j--;
            
        }
    }
    
    if (l < j)
        Quick_Sort(a, l, j);
    if (i < r)
        Quick_Sort(a, i, r);
}

void SheLL_Sort(int a[], int n)
{
    int d, i, j, temp;
    for (d = n/2; d > 0; d /= 2){
        for (i = d; i < n; i++)
        {
            temp = a[i];
            for (j = i; j >= d and a[j - d] > temp; j -= d)
                a[j] = a[j - d];
            a[j] = temp;
        }
    }
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 and j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

int Linear_Search(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return -1;
}

int BinarySearch(int a[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    
    while (left <= right)
    {
        int mid = (left + right)/2;
        if (a[mid] == x)
            return 1;
        if (x > a[mid])
            left = mid + 1;
        else if (x < a[mid])
            right = mid - 1;
    }
    return -1;
}

int Binary_Search(int a[], int left, int right, int x)
{
    int mid = (left + right)/2;
    if (a[mid] == x)
        return 1;
    if (mid == right)
        return -1;
    if (x > a[mid])
        return Binary_Search(a, mid + 1, right, x);
    else
        return Binary_Search(a, left, mid - 1, x);
}

int LinearSearch(int a[], int n, int x)
{
    int i = 0;
    a[n] = x;
    while (a[i] != x)
        i++;
    if (i == n)
        return -1;
    else
        return i;
}


int main(int argc, const char * argv[])
{
    int a[] = {5, 3, 10, 6, 2, 4, 0, 9 ,1};
    int n = sizeof(a)/sizeof(a[0]);
  
    cout << endl << endl;
    Quick_Sort(a, 0, n-1);
    
    cout << endl << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    
    return 0;
}
