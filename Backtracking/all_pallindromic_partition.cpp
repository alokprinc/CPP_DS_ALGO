#include <iostream>
using namespace std;
bool isPallindrome(string s){
    int i = 0;
    int j = s.length()-1;
    while(i<j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void solution(string str, string asf)
{
    if(str.length()==0){
        cout<<asf<<endl;
        return;
    }
		
        for(int i = 0 ; i < str.length(); i++){
            string pre = str.substr(0,i+1);
            string rem = str.substr(i+1);
            if(isPallindrome(pre)){
                solution(rem,asf+ "(" + pre+") ");
            }
        }
}

int main() 
{
  string str;    
  cin>>str;
  solution(str,"");
  return 0;
}