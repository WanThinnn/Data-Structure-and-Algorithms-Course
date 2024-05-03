#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void selectionSort(int arr[], int n, int &num_assignments, int &num_comparisons) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            num_comparisons++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        num_assignments += 3;
        swap(arr[min_idx], arr[i]);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 13, 11, 9, 100, -10, -1928, -192};
    int n = sizeof(arr)/sizeof(arr[0]);
    int num_assignments = 0;
    int num_comparisons = 0;
    
    auto start = high_resolution_clock::now();
    selectionSort(arr, n, num_assignments, num_comparisons);
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
