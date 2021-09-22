#include <iostream>
using namespace std;

int searchInRotatedArray(int arr[], int key, int left, int right)
{

    if (left > right)
    {
        return -1;
    }

    int mid = (left + right) / 2;

    if (key == arr[mid])
    {
        return mid;
    }

    if (arr[left] <= arr[mid])
    {
        if (key <= arr[mid] && key >= arr[left])
        {
            return searchInRotatedArray(arr, key, left, mid);
        }
        return searchInRotatedArray(arr, key, mid + 1, right);
    }

    if (key >= arr[mid] && key <= arr[right])
    {
        return searchInRotatedArray(arr, key, mid + 1, right);
    }
    return searchInRotatedArray(arr, key, left, mid);
}

int main()
{
    int arr[] = {30,40,50,10,20};
    int left = 0,right = 4,key = 40;
    int index = searchInRotatedArray(arr,key,left,right);
    if(index == -1){
        cout<<" Not found"<<endl;
    }else{
        cout<<"element found at index "<<index<<" value : "<<arr[index]<<endl;
    }
    return 0;
}