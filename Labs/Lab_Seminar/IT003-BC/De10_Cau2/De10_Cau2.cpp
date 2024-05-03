#include <iostream>

using namespace std;

void selectionSort(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int max_pos = i;
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] > a[max_pos])
            {
                max_pos = j; 
            }
        }
        swap(a[i], a[max_pos]);
    }
}
int main()
{
    int a[8] = {2, 7, 10, 9, 5, 3, 8, 40};
    cout << "Mang ban dau la: ";
    for(int x : a)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "Mang sau khi sap xep giam dan la: ";
    selectionSort(a, 8);
    for(int x : a)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "Do phuc tap cua thuat toan nay la: " << "O(N^2)" << endl;
    system("pause");
    return 0;
}   
