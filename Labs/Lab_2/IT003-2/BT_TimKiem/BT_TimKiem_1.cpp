
#include <iostream>
using namespace std;
int random(int minN, int maxN)
{
 return minN + rand() % (maxN + 1 - minN);
}

void input_arr(int a[], int &n, int &x)
{
    n = 10000;
    cout << "n = " << n << endl;
    cout << "x = ";
    cin >> x;
    cout << endl;
    int r;
    srand((int)time(0));
    for (int i = 0; i < n; i++)
    {
        r = random(-10000,10000);
        a[i] = r;
    }
}

int binary_search(int A[], int n, int X)
{
    int left, right, mid;
    left = 0; right = n - 1;
    do
    {
        mid = (left + right)/2;
        if (A[mid] == X)
            return 1;
        else if (A[mid] < X)
            left = mid + 1;
        else
            right = mid - 1;
    }
    while (left <= right);
    return 0;
}

int sequential_search(int A[], int n, int X)
{
    for (int i = 0; i < n; i++)
        if (X == A[i])
            return 1;
    return 0;
}


int main()
{
    int a[1000000], n, x;
    double time_use = 0.0;
    clock_t start, end;
    input_arr(a, n, x);
    sort(a, a + n);
    start = clock();
    int options;
    cout << "Chon thuat toan:" << endl << "1. Binary Search" << endl << "2. Sequential Search" << endl;
    cout << endl;
    cout << "Options: ";
    start = clock();
    do
    {
        cin >> options;
        if (options < 1 || options > 2) cout << "Loi, chon lai: ";
    } while (options < 1 || options > 2);

    switch (options)
    {
        case 1:
            if (binary_search(a, n, x) == 1)
                cout << "Co" << endl;
            else
                cout << "Khong" << endl;
        case 2:
            if (sequential_search(a, n, x) == 1)
                cout << "Co" << endl;
            else
                cout << "Khong" << endl;
    }
    
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
    cout << endl;
    cout << "Thoi gian chay chuong trinh: " << fixed << time_use << " giây" <<endl;
}



