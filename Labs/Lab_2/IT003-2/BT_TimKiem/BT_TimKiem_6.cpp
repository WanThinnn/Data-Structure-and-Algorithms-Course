#include <iostream>
using namespace std;
int Dem_mang_con(int a[], int n)
{
    int length = 1;
    int result = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] > a[i])
        {
            ++length;
        }
        else
        {
            result += ((length) * (length - 1)) / 2;
            length = 1;
        }
    }
    if (length > 1)
    {
        result += ((length) * (length - 1)) / 2;
    }
    return result;
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
    cout << Dem_mang_con(a, n) << '\n';

    system("pause");
    return 0;
}
