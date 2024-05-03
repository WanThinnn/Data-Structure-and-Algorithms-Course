#include <iostream>
#include <algorithm>
using namespace std;


bool cmp(int a, int b)
{
    if(a % 2 == 0 and b % 2 == 0)
    {
        return a < b;
    }
    if(a % 2 != 0 and b % 2 != 0)
    {
        return a > b;
    }
    return true;
}
int main()
{
    int a[] = { 12, 8, 2, 14, 3, 5, 10, 15, 36 };
    int n = 9;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++) 
        {
            if(!cmp(a[i], a[j]))
                swap(a[i], a[j]);
        }
    }
    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
