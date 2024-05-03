#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void merge(int arr[], int l, int m, int r, int &num_assignments, int &num_comparisons) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
        num_assignments++;
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1+ j];
        num_assignments++;
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        num_comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        num_assignments++;
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        num_assignments++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        num_assignments++;
    }
}

void mergeSort(int arr[], int l, int r, int &num_assignments, int &num_comparisons) {
    if (l < r) {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m, num_assignments, num_comparisons);
        mergeSort(arr, m+1, r, num_assignments, num_comparisons);
        merge(arr, l, m, r, num_assignments, num_comparisons);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int num_assignments = 0;
    int num_comparisons = 0;
    
    auto start = high_resolution_clock::now();
    mergeSort(arr, 0, n-1, num_assignments, num_comparisons);
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
