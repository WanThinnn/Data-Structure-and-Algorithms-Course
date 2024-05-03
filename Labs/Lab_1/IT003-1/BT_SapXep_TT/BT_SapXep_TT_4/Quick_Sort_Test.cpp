#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
int num_comparisons;
int partition(int arr[], int low, int high, int &num_assignments, int &num_comparisons)
{
    int pivot = arr[high];
    int i = (low-1);

    for (int j = low; j <= high- 1; j++)
    {
        num_comparisons++;
        if (arr[j] < pivot)
        {
            i++;
            num_assignments += 3;
            swap(arr[i], arr[j]);
        }
    }
    num_assignments += 3;
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int &num_assignments, int &num_comparisons)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, num_assignments, num_comparisons);
        quickSort(arr, low, pi - 1, num_assignments, num_comparisons);
        quickSort(arr, pi + 1, high, num_assignments, num_comparisons);
    }
}

void QuickSort(int a[], int left, int right)
{
    int i, j, x;
    x = a[(left+right)/2];
    i = left;
    j = right;
    while (i < j)
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        QuickSort(a, left, j);
    if (i < right)
        QuickSort(a, i, right);
}




int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int num_assignments = 0;
    int num_comparisons = 0;
    double time_use = 0.0;
    clock_t start, end;
    start = clock();
    quickSort(arr, 0, n-1, num_assignments, num_comparisons);
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    cout << "\nTime taken by function: " << fixed << time_use << " seconds\n";
    cout << "Number of assignments: " << num_assignments << endl;
    cout << "Number of comparisons: " << num_comparisons << endl;

    return 0;
}
