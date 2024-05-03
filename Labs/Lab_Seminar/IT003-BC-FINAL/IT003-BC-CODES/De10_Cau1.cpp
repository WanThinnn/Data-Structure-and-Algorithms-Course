#include <bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int n, int x)
{
    int left = 0, right = n - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(a[mid] == x)
        {
            return 1;
        }
        else if(a[mid] < x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return 0;
}

int main()
{
    int x = 8;
    int a[6] = {1, 4, 6, 13, 17, 19};
    cout << "Gia tri can tim kiem la: " << x << endl;
    cout << "Mang de cho la: ";
    for(int x : a)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "Neu ton tai gia tri x = " << x << " trong mang in ra 1, nguoc lai in ra 0: ";
    cout << binarySearch(a, 6, 8) << endl;
    system("pause");
    return 0;
}
