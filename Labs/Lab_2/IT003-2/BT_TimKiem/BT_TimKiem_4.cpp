#include <iostream>

using namespace std;

int random(int minN, int maxN)
{
 return minN + rand() % (maxN + 1 - minN);
}

void input_arr(int a[], int &n, int b[], int &m)
{
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "m = ";
    cin >> m;
    if (m > n)
        do
        {
            cout << "nhap lai m = ";
            cin >> m;
        }
    while (m > n);
    srand((int)time(0));
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
}



int * findSubArray(int arr[], int n, int b[], int m)
{
    int * result = NULL;
    for (int i = 0; i <= n - m; i++)
    {
        bool found = true;
        for (int j = 0; j < m; j++)
        {
            if (arr[i+j] != b[j])
            {
                found = false;
                break;
            }
        }
        if (found == true)
        {
            result = new int[m];
            for (int j = 0; j < m; j++)
            {
                result[j] = arr[i+j];
            }
            break;
        }
    }
    return result;
}

int main()
{
    int a[10000], b[10000], n, m;
    input_arr(a, n, b, m);
    int * sub_arr = findSubArray(a, n, b, m);
    if (sub_arr == NULL)
        cout << "Khong tim thay mang con B trong mang A\n";
    else
    {
        cout << "Mang con B trong mang A la: ";
        for (int i = 0; i < m; i++)
        {
            cout << sub_arr[i] << " ";
        }
        delete[] sub_arr;
    }
    return 0;
}
