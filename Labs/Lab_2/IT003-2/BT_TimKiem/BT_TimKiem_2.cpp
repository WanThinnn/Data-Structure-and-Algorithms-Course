#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;



int binarySearchRecursive(int arr[], int low, int high, int target)
{
    if (low > high) {
        return -1;
    }
    
    int mid = low + (high - low) / 2;
    
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        return binarySearchRecursive(arr, mid + 1, high, target);
    }
    else
    {
        return binarySearchRecursive(arr, low, mid - 1, target);
    }
}


int main()
{
    int a[1000], n;
    int X;
    cout << "N = ";
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    cout << "X = ";
    cin >> X;
    
    int Y = binarySearchRecursive(a, 0, n-1, X);
    if (Y == -1)
        cout << "khong tim thay X";
    else
        cout << "Tim thay X tai vi tri: " << Y;
}
