#include <iostream>
#include <vector>
using namespace std;

void heapifyInsert(int arr[], int n, int i)
{

    int parent = (i) / 2;
    if (arr[parent] > 0)
    {
        if (arr[i] > arr[parent])
        {
            swap(arr[i], arr[parent]);

            heapifyInsert(arr, n, parent);
        }
    }
}

void heapifyDelete(int arr[], int n, int i)
{
    int largestNode = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largestNode])
    {
        largestNode = left;
    }
    if (right < n && arr[right] > arr[largestNode])
    {
        largestNode = right;
    }
    if (largestNode != i)
    {
        swap(arr[i], arr[largestNode]);
        heapifyDelete(arr, n, largestNode);
    }
}

void insert(int arr[], int &n, int key)
{
    n = n + 1;
    arr[n - 1] = key;

    heapifyInsert(arr, n, n - 1);
}

void Delete(int arr[], int &n)
{
    int last = arr[n - 1];
    arr[0] = last;
    n = n - 1;

    heapifyDelete(arr, n, 0);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << "\n";
}

int main()
{
    int arr[] = {10, 5, 3, 2, 4};

    int n = 5;

    int key = 15;

    insert(arr, n, key);

    printArray(arr, n);
    Delete(arr, n);
    Delete(arr, n);
    Delete(arr, n);
    printArray(arr, n);
}