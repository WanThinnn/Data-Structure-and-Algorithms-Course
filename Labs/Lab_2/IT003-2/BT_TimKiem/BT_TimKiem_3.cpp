#include <iostream>
#include <cmath>
using namespace std;
bool Is_Prime(int n)
{
    if(n < 2)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int &x : a)
    {
        cin >> x;
    }
    for(int i = 0; i < n; i++)
    {
        if(Is_Prime(a[i]))
        {
            cout << a[i] << " ";
        }
    }
}
