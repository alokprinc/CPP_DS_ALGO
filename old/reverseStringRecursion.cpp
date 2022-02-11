#include <iostream>
using namespace std;

void ros(string s)
{
    if(s.length() == 0){
        return;
    }
    string ans = s.substr(1);
    
   ros(ans);
   cout<<s[0];
}
int main(){

    ros("binod");
}