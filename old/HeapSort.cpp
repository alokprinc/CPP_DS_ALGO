#include <iostream>
#include <vector>
using namespace std;

void heapify(int arr[], int n, int i)
{

    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

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
void buildHeap(int arr[], int &n)
{

    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << "\n";
}
void HeapSort(int arr[], int n)
{
    buildHeap(arr, n);

    for (int i = n - 1; i >= 0; i--)
    {

        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{

    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    HeapSort(arr, n);
    cout << "Sorted array is \n";
    printArray(arr, n);
}