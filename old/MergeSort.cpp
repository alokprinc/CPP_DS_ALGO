#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{  //  LENGTH OF INDEX FOR LEFT AND RIGHT ARRAY 
    int n1 = mid - l + 1;
    int n2 = r - mid;
  // TEMP ARRAY 
    int a[n1];
    int b[n2];
    //ASSIGNING VALUES TO TEMP ARRAY (LEFT)
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    //ASSIGNING VALUES TO TEMP ARRAY (RIGHT)
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    // ASSIGNING VALUE IN SOLUTION ARRAY AFTER SORTING TEMP ARRAYS
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
// ENSURING IF ANY OF TWO ARRAY'S INDEX EXAUSTES FIRST THEN REMAINING ELEMENTS MUST BE ADDED IN SOLUTION 
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l<r) // ensuring atleast two terms are in array
    {
        int mid = (l + r )/ 2; //dividing array in two pARTS    

        mergeSort(arr, l, mid);  //  CALLING FIRST PART OF ARRAY

        mergeSort(arr, mid + 1, r); // //  CALLING SECOND PART OF ARRAY
        merge(arr, l, mid, r); // MERGING BOTH ARRAY WITH SORTING IN ASCENDING ORDER
    }
}

int main()
{
    int arr[] = {5, 6, 1, 9, 2,3,4,7,8,0};
    mergeSort(arr, 0, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}