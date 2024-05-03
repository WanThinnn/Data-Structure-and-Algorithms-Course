#include <iostream>
using namespace std;

int random(int minN, int maxN);
void input_arr(int a[], int &n);
void swap(int &x, int &y);
void SelectionSort(int arr[], int n);
void InterchangeSort(int arr[], int n);
void InsertionSort(int arr[], int n);
void BubbleSort(int arr[], int n);
int partition(int arr[], int low, int high);
void QuickSort(int arr[], int low, int high);
void heapify(int arr[], int n, int i);
void HeapSort(int arr[], int n);
void ShellSort(int arr[], int n);
void merge(int arr[], int l, int m, int r);
void MergeSort(int arr[], int l, int r);

int random(int minN, int maxN)
{
 return minN + rand() % (maxN + 1 - minN);
}

void input_arr(int a[], int &n)
{
    cout << "n = ";
    cin >> n;
    cout << endl;
    int r;
    srand((int)time(0));
    for (int i = 0; i < n; i++)
    {
        r = random(-n,n);
        a[i] = r;
    }
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void SelectionSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int min_idx = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min_idx])
        min_idx = j;
    }
      swap(arr[min_idx],arr[i]);
    cout << "Mang sau khi " << i + 1 << " lan sap xep: ";
    for (int k = 0; k < n; k++) {
      cout << arr[k] << " ";
    }
    cout << endl;
  }
}

void InterchangeSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[i])
      {
          swap(arr[i], arr[j]);
      }
    }
    cout << "Mang sau khi " << i + 1 << " lan sap xep: ";
    for (int k = 0; k < n; k++) {
      cout << arr[k] << " ";
    }
    cout << endl;
  }
}

void BubbleSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = n-1; j > i; j--)
    {
      if (arr[j] < arr[j-1])
          swap(arr[j], arr[j-1]);
    }
    cout << "Mang sau khi " << i + 1 << " lan sap xep: ";
    for (int k = 0; k < n; k++) {
      cout << arr[k] << " ";
    }
    cout << endl;
  }
}

void InsertionSort(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
    cout << "Mang sau khi " << i << " lan sap xep: ";
    for (int k = 0; k < n; k++) {
      cout << arr[k] << " ";
    }
    cout << endl;
  }
}

void heapify(int arr[], int n, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

 
  if (left < n && arr[left] > arr[largest])
  {
    largest = left;
  }

  
  if (right < n && arr[right] > arr[largest])
  {
    largest = right;
  }

 
  if (largest != i)
  {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void HeapSort(int arr[], int n)
{

  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }
  for (int i = n - 1; i >= 0; i--)
  {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
    cout << "Mang sau khi " << n - i << " lan sap xep: ";
    for (int k = 0; k < n; k++) {
      cout << arr[k] << " ";
    }
    cout << endl;
  }
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

void QuickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);
    cout << "Mang sau khi chia tai vi tri " << pi << ": ";
    for (int k = low; k <= high; k++) {
      cout << arr[k] << " ";
    }
    cout << endl;
    QuickSort(arr, low, pi - 1);
    QuickSort(arr, pi + 1, high);
  }
}

void ShellSort(int arr[], int n)
{
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i < n; i++)
        {
            int key = arr[i];
            int j = i - gap;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + gap] = arr[j];
                j = j - gap;
            }
            arr[j + gap] = key;
        }
        cout << "Mang sau khi sap xep voi gap = " << gap << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
        gap /= 2;
    }
}

void merge(int arr[], int l, int m, int r)
{
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];
  for (int i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
  }
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void MergeSort(int arr[], int l, int r)
{
  if (l < r) {
    int m = l + (r - l) / 2;
    MergeSort(arr, l, m);
    MergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
    cout << "Mang sau khi sap xep: ";
    for (int k = l; k <= r; k++) {
      cout << arr[k] << " ";
    }
    cout << endl;
  }
}

void Options(int arr[], int n)
{
    int options;
    cout << "Chon thuat toan:" << endl << "1. Selection sort" << endl << "2. Insertion sort" << endl << "3. Interchange sort" << endl << "4. Bubble sort" << endl << "5. Quick sort" << endl << "6. Heap srot" << endl << "7. Shell sort" << endl << "8. Merge sort" << endl;
    cout << endl;
    cout << "Options: ";
    do
    {
        cin >> options;
        if (options < 1 || options > 8) cout << "Loi, chon lai: ";
    } while (options < 1 || options > 8);

    switch (options)
    {
        case 1:
            SelectionSort(arr, n);
            break;
        case 2:
            InsertionSort(arr, n);
            break;
        case 3:
            InterchangeSort(arr, n);
            break;
        case 4:
            BubbleSort(arr, n);
            break;
        case 5:
            QuickSort(arr, 0, n-1);
            break;
        case 6:
            HeapSort(arr, n);
            break;
        case 7:
            ShellSort(arr, n);
            break;
        case 8:
            MergeSort(arr, 0, n-1);
            break;
    }

}



int main() {
    int arr[100000], n;
    input_arr(arr, n);
    Options(arr, n);
    cout << endl;
    cout << "Mang ban dau: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Mang da sap xep: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
