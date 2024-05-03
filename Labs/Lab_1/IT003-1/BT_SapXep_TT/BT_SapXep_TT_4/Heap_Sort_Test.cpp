#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void heapify(int arr[], int n, int i, int &num_assignments, int &num_comparisons)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    num_comparisons += 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    
    num_comparisons += 2;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    
    if (largest != i) {
        num_assignments += 3;
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, num_assignments, num_comparisons);
    }
}

void heapSort(int arr[], int n, int &num_assignments, int &num_comparisons) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i, num_assignments, num_comparisons);

    for (int i = n-1; i > 0; i--) {
        num_assignments += 3;
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, num_assignments, num_comparisons);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int num_assignments = 0;
    int num_comparisons = 0;
    
    auto start = high_resolution_clock::now();
    heapSort(arr, n, num_assignments, num_comparisons);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    cout << "\nTime taken by function: " << duration.count() << " microseconds\n";
    cout << "Number of assignments: " << num_assignments << endl;
    cout << "Number of comparisons: " << num_comparisons << endl;

    return 0;
}
