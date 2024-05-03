#include<iostream>
#define MAX 1000
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int &x : a)
    {
        cin >> x;
    }
    int pos = 0, cnt = 1, max = 1;
    int i = 1;
    while (i < n)
    {
        if(a[i] > a[i - 1])
        {
            cnt++;
            if (cnt > max)
            {
                max = cnt;
                pos = i - cnt + 1;
            }
        }
        else
        {
            cnt = 1;
        }
        i++;
    }
    for (int i = pos; i < pos + max; i++)
    {
        cout << a[i] << " ";
    }

    system("pause");
    return 0;
}
