#include <bits/stdc++.h>
using namespace std;
int t[1001][1001];
bool isPalindrome(string s, int i, int j)
{
    while(i < j)
    {
      if(s[i] != s[j])
         return false; 
      i++;
      j--;
     
    }
    return true;
}
int min_partition_pallindrome(string s, int i, int j)
{
    int mn = INT_MAX;
    if (i >= j || isPalindrome(s,i,j)){
        return 0;
    }
    if(t[i][j] != -1){
        return t[i][j];
    }
    for (int k = i; k <= j - 1; k++)
    {
        int left,right;
        if(t[i][k] != -1){
             left = t[i][k];
        }else{
            left = min_partition_pallindrome(s, i, k);
            t[i][k] = left;
        }

        if(t[k+1][j] != -1){
            right = t[k+1][j];
        }else{
            right =  min_partition_pallindrome(s, k + 1, j);
            t[k+1][j] = right;
        }
        int tempAns = left + right + 1;
        
        if(tempAns<mn)
        mn = tempAns;
    }
    
    return t[i][j] = mn;
}


int main()
{
    memset(t,-1,sizeof(t));
    string s = "nitik";
    cout<<min_partition_pallindrome(s,0,s.size()-1);
   
}