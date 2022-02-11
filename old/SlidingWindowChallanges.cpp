#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
using namespace std;

int MaxSumSubarray(int arr[], int n, int k, int x)
{
    int start = 0, end = k - 1, sum = 0, ans = INT_MIN;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    ans = max(sum, ans);
    while (end != n - 1)
    {
        if (ans < x)
        {
            start++;
            end++;
            sum = sum - arr[start - 1] + arr[end];
            if (sum > x)
            {
                break;
            }
            else
            {
                ans = max(sum, ans);
            }
        }
    }
    return ans;
}

int MinimumSubarraySize(int arr[], int n, int x)
{
    int start = 0, curr = start, sum = 0, ans = n + 1;

    for (int curr = 0; curr < n; curr++)
    {
        sum = sum + arr[curr];
        while (sum >= x)
        {
            ans = min(ans, curr + 1 - start);
            sum = sum - arr[start++];
        }
    }
    return (ans != n + 1) ? ans : 0;
}

void FormNumberDivisibleby3(vector<int> arr, int k)
{
    pair<int, int> ans;
    int sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    bool found = false;
    if (sum % 3 == 0)
    {
        ans = make_pair(0, k - 1);
        found = true;
    }
    int start = 0, end = k - 1;

    //    for (int i = k; i < arr.size(); i++)
    //    {
    //        if(found){
    //            break;
    //        }

    //        sum = sum - arr[i-k] + arr[i];

    //        if (sum%3 == 0)
    //        {
    //            ans = make_pair(i-k+1,i);
    //            found = true;
    //        }

    //    }
    while (end < arr.size())
    {
        if (found)
        {
            break;
        }

        sum = sum - arr[start++] + arr[end++];
        if (sum % 3 == 0)
        {
            ans = make_pair(start + 1, end + 1);
            found = true;
        }
    }

    if (!found)
    {
        ans = make_pair(-1, 0);
    }

    if (ans.first == -1)
    {
        cout << " Not divisible by 3" << endl;
    }
    else
    {
        for (int i = ans.first; i <= ans.second; i++)
        {
            cout << arr[i] << " ";
        }
    }
}

// Subarray with Palindromic Concatenation
bool isPalindrome(int num)
{

    int number = 0, temp = num;

    while (temp > 0)
    {
        number = number * 10 + temp % 10;
        temp = temp / 10;
    }

    if (number == num)
    {
        return true;
    }
    return false;
}

int SubarraywithPalindromicConcatenation(vector<int> arr, int k)
{
    int num = 0;
    // storing all numbers in array by concatinating
    for (int i = 0; i < k; i++)
    {
        num = num * 10 + arr[i];
    }

    if (isPalindrome(num))
    {
        return 0;
    }
    for (int i = k; i < arr.size(); i++)
    {
        num = (num % (int)pow(10, k - 1)) * 10 + arr[i];

        if (isPalindrome(num))
        {
            return i - k + 1;
        }
    }
    return -1;
}
// Perfect Number //
bool isPerfectNumber(int n)
{
    int sum = 1;
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i == n / i)
            {
                sum += i;
            }
            else
            {
                sum += i + n / i;
            }
        }
    }
    if(sum == n){
        return true;
    }
    return false;
}

int maxSum(int arr[], int n, int k)
{
    if(k>n){
        cout<<"invalid values"<<endl;
        return -1;
    }

    int res = 0;

    for (int i = 0; i < k; i++)
    {
        res += arr[i];
    }

    int sum = res;

    for (int i = k; i < n; i++)
    {
        sum = sum + arr[i] - arr[i - k];
        res = max(res, sum);
    }

    return res;
}
int maxPerfectNumber(int arr[], int n, int k)
{

    for (int i = 0; i < n; i++)
    {
        if (isPerfectNumber(arr[i]))
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = 0;
        }
    }

    return maxSum(arr, n, k);
}

int main()
{
    // int arr[] = {7,5,4,6,8,9};
    // int n = 6;
    // int k = 3;
    // cout<<"sum : "<<MaxSumSubarray(arr,n,k,20);

    // int arr[] = {1, 4, 45, 6, 10, 19};
    // int n = 6;
    // int x = 51;
    // cout << MinimumSubarraySize(arr, n, x);

    // vector<int> arr = {84, 23, 45, 12, 56, 82};
    // vector<int> arr2 = {84, 12, 45, 56, 7, 82};
    // int k = 3;
    // FormNumberDivisibleby3(arr2, k);

    // vector<int> arr = {2, 3, 5, 1, 1, 5};
    // int k = 4;
    // int ans = SubarraywithPalindromicConcatenation(arr, k);
    // if (ans == -1)
    // {
    //     cout << "No palindrome found" << endl;
    // }
    // else
    // {
    //     for (int i = ans; i < ans + k; i++)
    //     {
    //         cout << arr[i] << " ";
    //     }
    // }

    int arr[] = {28,2,3,6,496,99,8128,24};
    int k = 4;
    int n = 8;

    cout<<maxPerfectNumber(arr,n,k);
}
